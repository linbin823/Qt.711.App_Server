#include "modbusmasterprotocoldriver.h"
#include "modbusmasterprotocoldriverui.h"
#include <QMap>
#include <QTimer>
#include <QVariant>
#include <QHostAddress>
#include <QSerialPortInfo>
#include <QModbusTcpClient>
#include <QModbusRtuSerialMaster>
#include <QSerialPort>

ModbusMasterProtocolDriver::ModbusMasterProtocolDriver(QObject *parent) :
    iDriver(parent),
    _pModbusDevice(nullptr),
    _pUI(nullptr),
    _scheduleTimer(nullptr)
{
    _initParameters();
    _setState(STAT_STOP);
}

ModbusMasterProtocolDriver::~ModbusMasterProtocolDriver(){
    stop();
}

void ModbusMasterProtocolDriver::_initParameters(){
    _parameters[ConnectionType] = Serial;
    _parameters[SlaveStationID] = 1;
    _parameters[ScheduleIntervMS] = 1000;

    QList<QSerialPortInfo> all = QSerialPortInfo::availablePorts();
    if(all.size() != 0){
        _parameters[SerialPortNameParameter] = all.at(0).portName();
    }else{
        _parameters[SerialPortNameParameter] = "";
    }
    _parameters[SerialParityParameter] = QSerialPort::NoParity;
    _parameters[SerialBaudRateParameter] = QSerialPort::Baud9600;
    _parameters[SerialDataBitsParameter] = QSerialPort::Data8;
    _parameters[SerialStopBitsParameter] = QSerialPort::OneStop;
    _parameters[NetworkPortParameter] = 502;
    _parameters[NetworkAddressParameter] = "127.0.0.1";
    _parameters[ResponseTimeOutMS] = 10*1000;
    _parameters[NumberOfRetries] = 3;
    _parameters[SerialInterFrameDelayMS] = -1;
    _parameters[DataAddressing] = ZeroBased;
    _parameters[DWordMapping] = BigEnd;
    /* Modbus_Application_Protocol_V1_1b.pdf (chapter 6 section 1 page 12)
     * Quantity of Coils to read (2 bytes): 1 to 2000 (0x7D0)
     * (chapter 6 section 11 page 29)
     * Quantity of Coils to write (2 bytes): 1 to 1968 (0x7B0)
     */
    _parameters[MaxReadInputPerMessage] = 1000;//<=2000
    _parameters[MaxWriteCoilPerMessage] = 1000;//<=1968
    /* Modbus_Application_Protocol_V1_1b.pdf (chapter 6 section 3 page 15)
     * Quantity of Registers to read (2 bytes): 1 to 125 (0x7D)
     * (chapter 6 section 12 page 31)
     * Quantity of Registers to write (2 bytes) 1 to 123 (0x7B)
     * (chapter 6 section 17 page 38)
     * Quantity of Registers to write in R/W registers (2 bytes) 1 to 121 (0x79)
     */
    _parameters[MaxReadRegistersPerMessage] = 100;//<=125
    _parameters[MaxWriteRegistersPerMessage] = 100;//<=123
    _parameters[MaxReadWriteRegistersPerMessage] = 100;//<=121
}

DriverInfo ModbusMasterProtocolDriver::driverInfo()const{
    DriverInfo info;
    info.driverType = "Modbus Master/Client";
    info.driverManufacturer = "Modicon";
    info.description = "Modbus Serial Master \nModbus Tcp Client \nDate:2017.9";
    info.majorVersion = QString::number(0);
    info.minorVersion = QString::number(0);
    info.microVersion = QString::number(1);
    return info;
}

void ModbusMasterProtocolDriver::save(iLoadSaveProcessor* processor){
    int num =_parameters.count();
    int key;
    QVariant value;
    QMap<int,QVariant>::const_iterator it;
    processor->writeValue("parametersNumber", num );
    int i=0;
    for(it = _parameters.constBegin(); it != _parameters.constEnd(); ++it,i++){
        processor->moveToInstance("parameters",QString::number(i));
        key = it.key();
        value=it.value();
        processor->writeValue("key",key );
        processor->writeValue("value",value );
        processor->moveBackToParent();
    }
}

void ModbusMasterProtocolDriver::load(iLoadSaveProcessor* processor){
    int ret=0,num =0;
    int key;
    QVariant value;
    ret = processor->readValue("parametersNumber", num);
    if(ret !=0 ) return;//not found num
    for(int i=0; i<num; i++){
        ret = processor->moveToInstance("parameters",QString::number(i));
        if(ret !=0 ) continue;//not found Instance
        ret = processor->readValue("key",key);
        if(ret !=0 ) continue;//not found num
        ret = processor->readValue("value",value);
        if(ret !=0 ) continue;//not found value
        _parameters.insert(key, value);
        processor->moveBackToParent();
    }
}

int ModbusMasterProtocolDriver::start(){
    if(_state != STAT_STOP) return -1;
    if(_pModbusDevice != nullptr) return -1;
    int type = _parameters[ConnectionType].toInt();
    if(type == Serial){
        _pModbusDevice = new QModbusRtuSerialMaster(this);

        _pModbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter,
            _parameters[SerialPortNameParameter].toString());
        _pModbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter,
            _parameters[SerialParityParameter].toInt());
        _pModbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,
            _parameters[SerialBaudRateParameter].toInt());
        _pModbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter,
            _parameters[SerialDataBitsParameter].toInt());
        _pModbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,
            _parameters[SerialStopBitsParameter].toInt());
        _pModbusDevice->setTimeout( _parameters[ResponseTimeOutMS].toInt());
        _pModbusDevice->setNumberOfRetries( _parameters[NumberOfRetries].toInt());
        static_cast<QModbusRtuSerialMaster*>(_pModbusDevice)->setInterFrameDelay(
            _parameters[SerialInterFrameDelayMS].toInt());

    }else if(type == Tcp){
        _pModbusDevice = new QModbusTcpClient(this);

        _pModbusDevice->setConnectionParameter(QModbusDevice::NetworkPortParameter,
            _parameters[NetworkPortParameter].toInt());
        _pModbusDevice->setConnectionParameter(QModbusDevice::NetworkAddressParameter,
            _parameters[NetworkAddressParameter].toString());
    }
    if(_pModbusDevice == nullptr){
        emit msgEventString(tr("启动失败。通信类型设置错误！"));
        _setState(STAT_ERR);
        return -2;
    }
    if (!_pModbusDevice->connectDevice()) {
        emit msgEventString(tr("启动失败。%1").arg(_pModbusDevice->errorString()) );
        _setState(STAT_ERR);
        return -3;
    }
    connect(_pModbusDevice, &QModbusClient::errorOccurred, [this](QModbusDevice::Error) {
        emit msgEventString(tr("ModbusMaster驱动运行错误。%1").arg(_pModbusDevice->errorString()) );
    });

    if(!_scheduleTimer){
        _scheduleTimer = new QTimer(this);
        _scheduleTimer->setSingleShot(false);
        _scheduleTimer->stop();
        connect(_scheduleTimer,&QTimer::timeout,this,&ModbusMasterProtocolDriver::_scheduleProcess);
    }
    _scheduleTimer->setInterval( _parameters[ScheduleIntervMS].toInt() );
    _scheduleTimer->start();

    _setState(STAT_RUN);
    return 0;
}

int ModbusMasterProtocolDriver::stop(){
    if (_pModbusDevice) {
        _pModbusDevice->disconnectDevice();
        _pModbusDevice->deleteLater();
        _pModbusDevice = nullptr;
    }
    if(_scheduleTimer){
        _scheduleTimer->stop();
        _scheduleTimer->deleteLater();
        _scheduleTimer = nullptr;
    }
    _setState(STAT_STOP);
    return 0;
}

int ModbusMasterProtocolDriver::restart(){
    stop();
    return start();
}

QList<int> ModbusMasterProtocolDriver::availableRWStrategy(void)const{
    QList<int> ret;
    ret<<iTagInfo::RWS_DISABLE<<iTagInfo::RWS_READ_ONLY
        <<iTagInfo::RWS_READ_WRITE<<iTagInfo::RWS_WRITE_ONLY;
    return ret;
}

QList<int> ModbusMasterProtocolDriver::availableRWStrategy(const QString& addr)const{
//    _coils address 0x0000
//    _discreteInputs address 1x0000
//    _inputRegisters address 3x0000
//    _holdingRegisters address 4x0000
    QList<int> ret;
    ret<<iTagInfo::RWS_DISABLE;
    if(isAddressCorrect(addr)){
        switch(_addressArea(addr)){
        case 0:
            ret<<iTagInfo::RWS_WRITE_ONLY;
            break;
        case 1:
        case 3:
            ret<<iTagInfo::RWS_READ_ONLY;
            break;
        case 4:
            ret<<iTagInfo::RWS_READ_ONLY<<iTagInfo::RWS_READ_WRITE<<iTagInfo::RWS_WRITE_ONLY;
            break;
        default:
            break;
        }
    }
    return ret;
}

bool ModbusMasterProtocolDriver::isAddressCorrect(const QString& addr) const{
    int area = _addressArea(addr);
    if(area>=0 && area<=4 && area!=2){
        int offset = _addressOffset(addr);
        if(_parameters.value(DataAddressing) == OneBased){
            if(offset>=1 && offset<=65536 )
                return true;
        }else if(_parameters.value(DataAddressing) == ZeroBased){
            if(offset>=0 && offset<=65535 )
                return true;
        }

    }
    return false;
}

QString ModbusMasterProtocolDriver::addressErrorString(const QString& addr)const{
    int area = _addressArea(addr);
    if(area<0 || area>4 || area==2)
        return tr("Area address should start with 0/1/3/4!");
    int offset = _addressOffset(addr);
    if(offset>0 && offset<65535 )
        return tr("Offset address is not decimal or is out of range!");
    return QString();
}

int ModbusMasterProtocolDriver::setRelatedTagAddresses(const QList<TagAddress *>& relatedTagAddresses){
    int count =0;
    _coils.clear();//address 0x0000
    _discreteInputs.clear();//address 1x0000
    _inputRegisters.clear();//address 3x0000
    _holdingRegisters.clear();//address 4x0000
    _coilsDataUnit.clear();
    _discreteInputsDataUnit.clear();
    _inputRegistersDataUnit.clear();
    _holdingRegistersDataUnit.clear();

    foreach (TagAddress* ta, relatedTagAddresses) {
        //check for correct address
        if(!isAddressCorrect(ta->address)) continue;
        switch(_addressArea( ta->address )){
        case 0:
            _coils<<ta;
            break;
        case 1:
            _discreteInputs<<ta;
            break;
        case 3:
            _inputRegisters<<ta;
            break;
        case 4:
            _holdingRegisters<<ta;
            break;
        default:
            continue;
        }
        count++;
    }
    //must sorted by raising address before using
    if(_coils.size()!=0){
        qSort(_coils.begin(), _coils.end(), compareTagAddress);
        _coilsDataUnit = _prepareDataUnit(QModbusDataUnit::Coils, _coils);
    }
    if(_discreteInputs.size()!=0){
        qSort(_discreteInputs.begin(), _discreteInputs.end(), compareTagAddress);
        _discreteInputsDataUnit = _prepareDataUnit(QModbusDataUnit::DiscreteInputs, _discreteInputs);
    }
    if(_inputRegisters.size()!=0){
        qSort(_inputRegisters.begin(), _inputRegisters.end(), compareTagAddress);
        _inputRegistersDataUnit = _prepareDataUnit(QModbusDataUnit::InputRegisters, _inputRegisters);
    }
    if(_holdingRegisters.size()!=0){
        qSort(_holdingRegisters.begin(), _holdingRegisters.end(), compareTagAddress);
        _holdingRegistersDataUnit = _prepareDataUnit(QModbusDataUnit::HoldingRegisters, _holdingRegisters);
    }
    return count;
}

void ModbusMasterProtocolDriver::showUI(bool show, QWidget* parent){
    if(_pUI == nullptr){
        _pUI = new ModbusMasterProtocolDriverUI(this, parent);
    }
    if(show){
        _pUI->show();
    }else{
        _pUI->hide();
    }
}

bool ModbusMasterProtocolDriver::compareTagAddress(const TagAddress* t1, const TagAddress* t2){
    return t1->address<t2->address;
}

void ModbusMasterProtocolDriver::_setState(enum_states state){
    if(_state != state){
        _state = state;
        emit stateChanged(state);
    }
}

void ModbusMasterProtocolDriver::_scheduleProcess(){
    if(_state != STAT_RUN) return;
    if(!_pModbusDevice) return;
    if(_pModbusDevice->state() != QModbusDevice::ConnectedState) return;

    //step 1: _coils address 0x0000 RWS_WRITE_ONLY
    if(_coils.size()!=0){
        foreach (QModbusDataUnit unit, _coilsDataUnit) {
            //prepare data
            _writeValues( _coils, unit);
            //write data
            if (auto *reply = _pModbusDevice->sendWriteRequest(unit, _parameters[SlaveStationID].toInt()) ){
                if (!reply->isFinished()) {
                    connect(reply, &QModbusReply::finished, this, [this, reply]() {
                        if (reply->error() == QModbusDevice::ProtocolError) {
                            emit msgEventString(tr("coil写入失败。%1(Mobus exception: 0x%2)")
                                                .arg(reply->errorString())
                                                .arg(reply->rawResult().exceptionCode()));
                        }else if(reply->error() != QModbusDevice::NoError) {
                            emit msgEventString(tr("coil写入失败。%1(code: 0x%2)")
                                                .arg(reply->errorString())
                                                .arg(reply->error()));
                        }
                        reply->deleteLater();
                    });
                } else {
                    // broadcast replies return immediately
                    delete reply;
                }
            } else {
                emit msgEventString(tr("coil写入失败。%1").arg(_pModbusDevice->errorString()));
            }
        }
    }
    //step 2: _discreteInputs address 1x0000 RWS_READ_ONLY
    if(_discreteInputs.size()!=0){
        foreach (QModbusDataUnit unit, _discreteInputsDataUnit) {
            if (auto *reply = _pModbusDevice->sendReadRequest(unit, _parameters[SlaveStationID].toInt()) )
            {
                if (!reply->isFinished())
                    connect(reply, &QModbusReply::finished, this, &ModbusMasterProtocolDriver::_readyRead);
                else{
                    delete reply; // broadcast replies return immediately
                }
            } else {
                emit msgEventString(tr("读取失败。%1").arg(_pModbusDevice->errorString()));
            }
        }
    }
    //step 3: _inputRegisters address 3x0000 RWS_READ_ONLY
    if(_inputRegisters.size()!=0){
        foreach (QModbusDataUnit unit, _inputRegistersDataUnit) {
            if (auto *reply = _pModbusDevice->sendReadRequest(unit,  _parameters[SlaveStationID].toInt()) ){
                if (!reply->isFinished())
                    connect(reply, &QModbusReply::finished, this, &ModbusMasterProtocolDriver::_readyRead);
                else{
                    delete reply; // broadcast replies return immediately
                }
            } else {
                emit msgEventString(tr("读取失败。%1").arg(_pModbusDevice->errorString()));
            }
        }
    }
    //step 4: _holdingRegisters address 4x0000 RWS_READ_WRITE
    if(_holdingRegisters.size()!=0){
        foreach (QModbusDataUnit unit, _holdingRegistersDataUnit) {
            //1st we read field device's newValue to buffer(unit),
            if (auto *reply = _pModbusDevice->sendReadRequest(unit, _parameters[SlaveStationID].toInt()) ){
                if (!reply->isFinished())
                    connect(reply, &QModbusReply::finished, this, &ModbusMasterProtocolDriver::_readyRead);
                else{
                    delete reply; // broadcast replies return immediately
                }
            } else {
                emit msgEventString(tr("读取失败。%1").arg(_pModbusDevice->errorString()));
            }
        }
    }
}

void ModbusMasterProtocolDriver::_readyRead(){
    auto reply = qobject_cast<QModbusReply *>(sender());
    if (!reply){
        return;
    }
    if (reply->error() == QModbusDevice::NoError) {
        QModbusDataUnit unit = reply->result();
        switch(unit.registerType() ){
        case QModbusDataUnit::DiscreteInputs:
            _readValues( _discreteInputs, unit );
            break;
        case QModbusDataUnit::InputRegisters:
            _readValues( _inputRegisters, unit );
            break;
        case QModbusDataUnit::HoldingRegisters:
            foreach(TagAddress* t, _holdingRegisters){
                //2nd we write value, which need to write to field device, to buffer,
                _writeValue(t, unit, ( _addressOffset( t->address ) - unit.startAddress() ));
                //3rd we read value, which is readable from buffer,
                _readValue(t, unit, ( _addressOffset( t->address ) - unit.startAddress() ));
            }
            //4th we write buffer to field device
            if (auto *secondReply = _pModbusDevice->sendWriteRequest(unit, _parameters[SlaveStationID].toInt()) )
            {
                if (!secondReply->isFinished()) {
                    connect(secondReply, &QModbusReply::finished, this, [this, secondReply]() {
                        if (secondReply->error() == QModbusDevice::ProtocolError) {
                            emit msgEventString(tr("HoldingRegisters写入失败。%1(Mobus exception: 0x%2)")
                                                .arg(secondReply->errorString())
                                                .arg(secondReply->rawResult().exceptionCode()));
                        }else if(secondReply->error() != QModbusDevice::NoError) {
                            emit msgEventString(tr("HoldingRegisters写入失败。%1(code: 0x%2)")
                                                .arg(secondReply->errorString())
                                                .arg(secondReply->error()));
                        }
                        secondReply->deleteLater();
                    });
                }else{
                    //broadcast replies return immediately
                    delete secondReply;
                }
            }else{
                emit msgEventString(tr("HoldingRegisters写入失败。%1").arg(_pModbusDevice->errorString()));
            }
            break;
        default:
            break;
        }
    } else if (reply->error() == QModbusDevice::ProtocolError) {
        emit msgEventString(tr("读取失败。%1 (Mobus exception: 0x%2)")
                            .arg(reply->errorString())
                            .arg(reply->rawResult().exceptionCode()));
    } else {
        emit msgEventString(tr("读取失败。%1 (code: 0x%2)")
                            .arg(reply->errorString())
                            .arg(reply->error()));
    }
    reply->deleteLater();
}

int  ModbusMasterProtocolDriver::_addressArea(const QString& addr)const{
    if(addr.isEmpty() || addr.isNull()) return -1;
    return addr.at(0).digitValue();
}

int  ModbusMasterProtocolDriver::_addressOffset(const QString& addr)const{
    QString offsetString = addr;
    offsetString.remove(0,1);
    if(addr.endsWith("+")){
        offsetString.chop(1);
    }else{
        return false;
    }
    int offset = offsetString.toInt();
    if(_parameters.value(DataAddressing) == OneBased) offset--;
    return offset;
}

bool ModbusMasterProtocolDriver::_dataQualifier(int dataType, const TagAddress * t)const{
    switch(dataType){
    case QModbusDataUnit::Coils:
        if( (t->RWStrategy == iTagInfo::RWS_READ_WRITE) || (t->RWStrategy == iTagInfo::RWS_WRITE_ONLY) )
            return true;
        else
            return false;
    case QModbusDataUnit::DiscreteInputs:
        if( (t->RWStrategy == iTagInfo::RWS_READ_WRITE) || (t->RWStrategy == iTagInfo::RWS_READ_ONLY) )
            return true;
        else
            return false;
    case QModbusDataUnit::InputRegisters:
        if( (t->RWStrategy == iTagInfo::RWS_READ_WRITE) || (t->RWStrategy == iTagInfo::RWS_READ_ONLY) )
            return true;
        else
            return false;
    case QModbusDataUnit::HoldingRegisters:
        if( t->RWStrategy != iTagInfo::RWS_DISABLE )
            return true;
        else
            return false;
    default:
        return false;
    }
}

QList<QModbusDataUnit> ModbusMasterProtocolDriver::_prepareDataUnit(int dataType, const QList<TagAddress *> &list) const
{
    QList<QModbusDataUnit> ret;
    if(list.size()<=0) return ret;
//init QModbusDataUnit
    QModbusDataUnit unit;
    unit.setRegisterType( QModbusDataUnit::RegisterType(dataType) );
//compute maxNumberPerMessage
    int maxNumberPerMessage;
    switch(dataType){
    case QModbusDataUnit::Coils:
        maxNumberPerMessage = _parameters[MaxWriteCoilPerMessage].toInt();
        break;
    case QModbusDataUnit::DiscreteInputs:
        maxNumberPerMessage = _parameters[MaxReadInputPerMessage].toInt();
        break;
    case QModbusDataUnit::InputRegisters:
        maxNumberPerMessage = _parameters[MaxReadRegistersPerMessage].toInt();
        break;
    case QModbusDataUnit::HoldingRegisters:
        maxNumberPerMessage = qMin<int>(_parameters[MaxReadRegistersPerMessage].toInt(),
                                   _parameters[MaxWriteRegistersPerMessage].toInt());
        break;
    default:
        maxNumberPerMessage=10;
        break;
    }
//get start index
    int startIndex;
    for (startIndex = 0; startIndex<list.size(); ++startIndex){
        //each data type has a acceptable RWStrategy, return true if a TagAddress meets the requirement.
        if( _dataQualifier(dataType, list.at(startIndex)) ) break;
    }
    if(startIndex == list.size()) return ret;
//get start offset(aka address) and lastOffset(aka address)
    int startOffset = _addressOffset( list.at(startIndex)->address );
    int lastOffset = startOffset;
//start main function
    switch (dataType) {
    case QModbusDataUnit::Coils:
    case QModbusDataUnit::DiscreteInputs:{
        int currentOffset;
        for (int i = (startIndex+1); i<list.size(); ++i){
            if( _dataQualifier(dataType, list.at(i)) ){
                //condition 1: must qualified
                currentOffset = _addressOffset( list.at(i)->address );
                if( currentOffset <= (lastOffset +1) &&
                        maxNumberPerMessage >= (lastOffset - startOffset + 1) ){
                    //condition 2: address continueous
                    //condition 3: not reach max number per message
                    lastOffset = currentOffset;
                    continue;
                }else{
                    //seperate unit beacuse:
                    //address not continueous or
                    //max package length reached!
                    unit.setStartAddress(startOffset);
                    unit.setValueCount(lastOffset - startOffset + 1);
                    ret.append(unit);
                    startOffset = currentOffset;
                    lastOffset = startOffset;
                    continue;
                }
            }
        }
        //finish last unit
        unit.setStartAddress(startOffset);
        unit.setValueCount(lastOffset - startOffset + 1);
        ret.append(unit);
        return ret;
    }
    case QModbusDataUnit::InputRegisters:
    case QModbusDataUnit::HoldingRegisters:{
        int currentOffset;
        bool isDWord = false;
        for (int i = (startIndex+1); i<list.size(); ++i){
            if( _dataQualifier(dataType, list.at(i)) ){
                //condition 1: must qualified
                currentOffset = _addressOffset( list.at(i)->address );
                if( //condition 2: address continueous
                    (((!isDWord) && currentOffset<=(lastOffset +1)) || (isDWord && currentOffset<=(lastOffset +2)))
                        &&
                    //condition 3: not reach max number per message
                    maxNumberPerMessage >= (lastOffset - startOffset + 1) ){

                    lastOffset = currentOffset;

                    //feature for registers: 32bit length data could combine with two continueous 16bit registers!
                    //update last tagAddress's condition
                    isDWord = _isDWord( list.at(i)->address );
                    continue;
                }else{
                    //seperate unit beacuse:
                    //address not continueous or
                    //max package length reached!
                    unit.setStartAddress(startOffset);
                    if(isDWord){
                        unit.setValueCount(lastOffset - startOffset + 2);
                    }else{
                        unit.setValueCount(lastOffset - startOffset + 1);
                    }
                    ret.append(unit);
                    startOffset = currentOffset;
                    lastOffset = startOffset;

                    //feature for registers: 32bit length data could combine with two continueous 16bit registers!
                    //update last tagAddress's condition
                    isDWord = _isDWord( list.at(i)->address );
                    continue;
                }
            }
        }
        //finish last unit
        unit.setStartAddress(startOffset);
        if(isDWord){
            unit.setValueCount(lastOffset - startOffset + 2);
        }else{
            unit.setValueCount(lastOffset - startOffset + 1);
        }
        ret.append(unit);
        return ret;
    }
    default:
        return ret;
    }
}

void ModbusMasterProtocolDriver::_readValues(const QList<TagAddress *> &list, const QModbusDataUnit& unit){
    int startAddress = unit.startAddress();
    for(int index=0; index<unit.valueCount(); index++){
        int lastSpan = list.size() /2;
        int pos = list.size() / 2;
        while(1){
            TagAddress * t = list.at(pos);
            if( _addressOffset(t->address) == (startAddress+index) ){
                //found!
                _readValue(t, unit, index);
                //look forward for same address
                for(int i=1; (pos+i)<list.size();i++){
                    t = list.at(pos+i);
                    if( _addressOffset(t->address) == (startAddress+index) ){
                        _readValue(t, unit, index);
                        continue;
                    }
                    break;
                }
                //look backward for same address
                for(int i=1; (pos-i)>=0  ;i++){
                    t = list.at(pos+i);
                    if( _addressOffset(t->address) == (startAddress+index) ){
                        _readValue(t, unit, index);
                        continue;
                    }
                    break;
                }
                break;
            }else if( _addressOffset(t->address) > (startAddress+index) ){
                if(lastSpan == 0) break;
                lastSpan /= 2;
                if(lastSpan == 0) pos -= 1;
                else pos -= lastSpan;
            }else if( _addressOffset(t->address) < (startAddress+index)){
                if(lastSpan == 0) break;
                lastSpan /= 2;
                if(lastSpan == 0) pos += 1;
                else pos += lastSpan;
            }
        }
    }
}

void ModbusMasterProtocolDriver::_writeValues(const QList<TagAddress *>& list, QModbusDataUnit& unit){
    int startAddress = unit.startAddress();
    for(uint index=0; index<unit.valueCount(); index++){
        int lastSpan = list.size() /2;
        int pos = list.size() / 2;
        while(1){
            TagAddress * t = list.at(pos);
            if( _addressOffset(t->address) == (startAddress+index) ){
                //found!
                _writeValue(t, unit, index);
                //look forward for same address
                for(int i=1; (pos+i)<list.size();i++){
                    t = list.at(pos+i);
                    if( _addressOffset(t->address) == (startAddress+index) ){
                        _writeValue(t, unit, index);
                        continue;
                    }
                    break;
                }
                //look backward for same address
                for(int i=1; (pos-i)>=0  ;i++){
                    t = list.at(pos+i);
                    if( _addressOffset(t->address) == (startAddress+index) ){
                        _writeValue(t, unit, index);
                        continue;
                    }
                    break;
                }
                break;
            }else if( _addressOffset(t->address) > (startAddress+index) ){
                if(lastSpan == 0) break;
                lastSpan /= 2;
                if(lastSpan == 0) pos -= 1;
                else pos -= lastSpan;
            }else if( _addressOffset(t->address) < (startAddress+index)){
                if(lastSpan == 0) break;
                lastSpan /= 2;
                if(lastSpan == 0) pos += 1;
                else pos += lastSpan;
            }
        }
    }
}

void ModbusMasterProtocolDriver::_readValue(TagAddress *t, const QModbusDataUnit& unit, uint index){
    if(index>=unit.valueCount()) return;

    quint16 valueSmallAddr = unit.value(index);
    quint16 valueBigAddr;
    if((index+1)>=unit.valueCount())
        valueBigAddr = 0;
    else
        valueBigAddr = unit.value(index+1);

    switch (t->tagInfo->type()) {
    case iTagInfo::TYPE_INT32:
    case iTagInfo::TYPE_UINT32:
    {
        if(_parameters[DWordMapping] == BigEnd)
            t->tagInfo->updatevalue( (quint32)((valueSmallAddr&0xFFFF)<<16) + (quint32)(valueBigAddr&0xFFFF) );
        else
            t->tagInfo->updatevalue( (quint32)((valueBigAddr&0xFFFF)<<16) + (quint32)(valueSmallAddr&0xFFFF) );
        break;
    }
    case iTagInfo::TYPE_FLOAT:
    {
        if(_parameters[DWordMapping] == BigEnd){
            quint32 uint32Value = (quint32)((valueSmallAddr&0xFFFF)<<16) + (quint32)(valueBigAddr&0xFFFF);
            float* floatValue = (float*)&uint32Value;
            t->tagInfo->updatevalue( *floatValue );
        }else{
            quint32 uint32Value = (quint32)((valueBigAddr&0xFFFF)<<16) + (quint32)(valueSmallAddr&0xFFFF);
            float* floatValue = (float*)&uint32Value;
            t->tagInfo->updatevalue( *floatValue );
        }
        break;
    }
    default:
        t->tagInfo->updatevalue( valueSmallAddr );
    }
}

void ModbusMasterProtocolDriver::_writeValue(TagAddress *t, QModbusDataUnit& unit, uint index){
    if(index>=unit.valueCount()) return;
    if(!t->needToWrite)          return;

    QVariant value;
    if(t->RWStrategy == iTagInfo::RWS_READ_WRITE)
        //because in R&W Strategy, read value is always scaled.
        //If scaled value is written, some data tremblling will occured.
        value = t->tagInfo->unscaledValue();
    else
        value = t->tagInfo->value();

    if((index+1)>=unit.valueCount()){
        unit.setValue(index, (quint16)(value.toUInt()));
        return;
    }



    switch (t->tagInfo->type()) {
//    case iTagInfo::TYPE_INT32:
//    case iTagInfo::TYPE_UINT32:
//    {
//        quint32 data = value.toUInt();
//        if(_parameters[DWordMapping] == BigEnd){
//            unit.setValue(index,   (quint16)((data&0xFF00)>>16));
//            unit.setValue(index+1, (quint16)(data&0x00FF));
//        }else{
//            unit.setValue(index,   (quint16)(data&0x00FF));
//            unit.setValue(index+1, (quint16)((data&0xFF00)>>16));
//        }
//        break;
//    }
    case iTagInfo::TYPE_FLOAT:
    case iTagInfo::TYPE_DOUBLE:
    {
        float data = value.toFloat();
        quint32 *pValue = (quint32*)&data;
        if(_parameters[DWordMapping] == BigEnd){
            unit.setValue(index,   (quint16)((*pValue&0xFF00)>>16));
            unit.setValue(index+1, (quint16)(*pValue&0x00FF));
        }else{
            unit.setValue(index,   (quint16)(*pValue&0x00FF));
            unit.setValue(index+1, (quint16)((*pValue&0xFF00)>>16));
        }
        break;
    }
    default:
    {
        unit.setValue(index, (quint16)(value.toUInt()));
        break;
    }
    }
}

bool  ModbusMasterProtocolDriver::_isDWord(const QString& addr)const{
    if(addr.endsWith("+")){
        return true;
    }else{
        return false;
    }
}
