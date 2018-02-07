#include "modbusmasterclient.h"
class ServerInfo: public QObject
{
    Q_OBJECT
public:
    explicit ServerInfo(QObject* parent = 0);

    QHostAddress ip;
    int state;
    int port, retryCount;
    QString lastError;
    modbus_t* pModbus;
    QTimer retryDelay;

public slots:
    void connect();

};

ServerInfo::ServerInfo(QObject* parent): QObject(parent)
{
    state= iDriver::STAT_STOP;
    port = 502;
    retryCount = 3;
    pModbus = nullptr;
    retryDelay.setSingleShot(true);
    retryDelay.stop();
    connect(&retryDelay, &QTimer::timeout, this, &ServerInfo::connect);
}

ModbusMasterOrClient::ModbusMasterOrClient(QObject *parent): iDriver(parent), _modbus(nullptr)
{
    _setState(STAT_STOP);
    QMap<QString, QVariant> generalPara, dataPara, serialPara, ethernetPara, advancedPara;

    generalPara.insert(tr("Communication Method"), QVariant::fromValue(METHOD_SERIAL));
    generalPara.insert(tr("Protocol"), QVariant::fromValue(PROTOCOL_RTU));
    generalPara.insert(tr("Station Number"),QVariant::fromValue(1));
    generalPara.insert(tr("Schedule Interv ms"),QVariant::fromValue(1000));
    _parameters.insert(tr("General Parameters"),QVariant(generalPara));

    dataPara.insert(tr("Data Addressing"), QVariant::fromValue(ADDRESSING_ZEROBASED));
    dataPara.insert(tr("32bit Word Mapping"), QVariant::fromValue(WORDMAP_BIGENDIAN));
    dataPara.insert(tr("Max Read Coil/Input per Message"), QVariant::fromValue(128));   //1~MODBUS_MAX_READ_BITS
    dataPara.insert(tr("Max Write Coil/Output per Message"), QVariant::fromValue(100)); //1~MODBUS_MAX_WRITE_BITS
    dataPara.insert(tr("Max Read Holding/Input Registers per Message"), QVariant::fromValue(16));  //1-MODBUS_MAX_READ_REGISTERS
    dataPara.insert(tr("Max Write Holding/Output Registers per Message"), QVariant::fromValue(8)); //1-MODBUS_MAX_WR_WRITE_REGISTERS
    _parameters.insert(tr("Data Parameters"),QVariant(dataPara));

    serialPara.insert(tr("Port Name"), QVariant(""));
    serialPara.insert(tr("Baud"), QVariant::fromValue(9600));
    serialPara.insert(tr("Parity"), QVariant::fromValue(PARITY_NONE));
    serialPara.insert(tr("Data Bits"), QVariant::fromValue(8));
    serialPara.insert(tr("Stop Bits"), QVariant::fromValue(1));
    _parameters.insert(tr("Serial Parameters"),QVariant(serialPara));

    ethernetPara.insert(tr("Open New Socket When Reconnect"), QVariant(true));
    _parameters.insert(tr("Ethernet Parameters"),QVariant(ethernetPara));

    advancedPara.insert(tr("Retries"), QVariant::fromValue(10));
    advancedPara.insert(tr("TimeOut ms"), QVariant::fromValue(500));
    _parameters.insert(tr("Advanced Parameters"),QVariant(advancedPara));

    _pWatchDogTimer = new QTimer(this);
    _pWatchDogTimer->setSingleShot(true);
    _pScheduleTimer = new QTimer(this);
}
ModbusMasterOrClient::~ModbusMasterOrClient(){
    stop();
}

void ModbusMasterOrClient::save(iLoadSaveProcessor* processor){

}

void ModbusMasterOrClient::load(iLoadSaveProcessor* processor){

}

int ModbusMasterOrClient::start(){


    if(generalParaValue(tr("Communication Method")).toInt()==METHOD_SERIAL){
        char parity;
        int val = serialParaValue("Parity").toInt();
        if(val == PARITY_EVEN)
            parity = 'E';
        else if(val == PARITY_ODD)
            parity = 'O';
        else parity = 'N';

        _pModbus = modbus_new_rtu(
            serialParaValue("Port Name").toByteArray().data(),
            serialParaValue("Baud").toInt(),
            parity,
            serialParaValue("Data Bits").toInt(),
            serialParaValue("Stop Bits").toInt()   );
        if( modbus_connect(_pModbus)==-1 ){
            emit msgEventString( tr("Connection failed: %s\n").arg(modbus_strerror(errno)) );
            modbus_free(_pModbus);
            _pModbus = nullptr;
            return -1;
        }
        _retryCount = advancedParaValue( tr("Retries") ).toInt();
        connect();
        return 0;

    }else{
        foreach(ServerInfo info, _servers){
            if(!info.ip.isNull()){
                info._pModbus = modbus_new_tcp(info.ip.toString().toLatin1().data(),info.port);
            }
        }
    }



}

int ModbusMasterOrClient::stop(){
    if(_pModbus != nullptr){
        modbus_close(_pModbus);
        modbus_free(_pModbus);
        _pModbus = nullptr;
    }
    foreach(ServerInfo info, _servers){
        if(info._pModbus != nullptr){
            modbus_close(info._pModbus);
            modbus_free(info._pModbus);
            info._pModbus = nullptr;
        }
    }
    _setState(STAT_STOP);
}

int ModbusMasterOrClient::restart(){
    stop();
    return start();
}

bool ModbusMasterOrClient::isAddressCorrect(const QString& addr){

}

QString ModbusMasterOrClient::addressErrorString(const QString& addr){

}

int ModbusMasterOrClient::setRelatedTags(const QList<iTagInfo *>& relatedTags){

}

void ModbusMasterOrClient::tagWriteOnce(iTagInfo*one){

}

void ModbusMasterOrClient::showUI(bool show, QWidget* parent){

}

QVariant& ModbusMasterOrClient::generalParaValue(const QString& paraName){
    return _parameters[tr("General Parameters")].toMap()[paraName];
}
QVariant& ModbusMasterOrClient::dataParaValue(const QString& paraName){
    return _parameters[tr("Data Parameters")].toMap()[paraName];
}
QVariant& ModbusMasterOrClient::serialParaValue(const QString& paraName){
    return _parameters[tr("Serial Parameters")].toMap()[paraName];
}
QVariant& ModbusMasterOrClient::ethernetParaValue(const QString& paraName){
    return _parameters[tr("Ethernet Parameters")].toMap()[paraName];
}
QVariant& ModbusMasterOrClient::advancedParaValue(const QString& paraName){
    return _parameters[tr("Advanced Parameters")].toMap()[paraName];
}

bool ModbusMasterOrClient::compareTagInfo(const iTagInfo *t1, const iTagInfo *t2){
    return t1->address() < t2->address();
}

void ModbusMasterOrClient::_setState(enum_states state){
    if(state != _state){
        _state = state;
        emit stateChanged(state);
    }
}

void ModbusMasterOrClient::_scheduleProcess(){

}
