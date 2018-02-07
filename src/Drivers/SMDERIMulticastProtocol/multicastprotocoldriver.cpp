#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QDateTime>
#include <QHostAddress>
#include "multicastprotocoldriverui.h"
#include "multicastprotocoldriver.h"
#include "loadsaveprocessorxml.h"

MulticastProtocolDriver::MulticastProtocolDriver(QObject *parent) : iDriver(parent),
    _multicastAddress( QHostAddress("225.11.1.2")),
    _port(41002),
    _pUdpSocket(nullptr),
    _pUI(nullptr),
    _pWatchDogTimer(new QTimer(this) )
{
    //default
    if(QNetworkInterface::allInterfaces().size() == 0){
        emit msgEventString(tr("电脑上找不到网卡") );
    }
    else{
        _networkInterface = QNetworkInterface::allInterfaces().at(0);
    }
    _pWatchDogTimer->setSingleShot(true);
    _pWatchDogTimer->setInterval(10 * 1000);
    connect(_pWatchDogTimer,SIGNAL(timeout()),this,SLOT(_watchDogTimeOver()));

    _setState(STAT_STOP);
}
MulticastProtocolDriver::~MulticastProtocolDriver(){
    stop();
    if(_pUdpSocket!=nullptr){
        _pUdpSocket->deleteLater();
    }
    if(_pUI != nullptr){
        _pUI->deleteLater();
    }
}

DriverInfo MulticastProtocolDriver::driverInfo()const{
    DriverInfo info;
    info.driverType = "Multicast Protocol";
    info.driverManufacturer = "CSIC711";
    info.description = "Multicast Protocol for data acquisition\nDate:2017.9";
    info.majorVersion = QString::number(0);
    info.minorVersion = QString::number(0);
    info.microVersion = QString::number(1);
    return info;
}

void MulticastProtocolDriver::save(iLoadSaveProcessor* processor){
    processor->writeValue("multicastAddress",_multicastAddress);
    processor->writeValue("port",_port);
    QString networkInterfaceName = _networkInterface.name();
    processor->writeValue("networkInterface", networkInterfaceName );
}

void MulticastProtocolDriver::load(iLoadSaveProcessor* processor){
    processor->readValue("multicastAddress",_multicastAddress);
    processor->readValue("port",_port);
    QList<QNetworkInterface> allInterfaces = QNetworkInterface::allInterfaces();
    if(allInterfaces.size() == 0){
        emit msgEventString(tr("电脑上找不到网卡") );
        return;
    }
    QString networkInterfaceName;
    processor->readValue("networkInterface", networkInterfaceName );
    bool foundInterface = false;
    foreach (QNetworkInterface iface, allInterfaces) {
        if(iface.name() == networkInterfaceName){
            foundInterface = true;
            _networkInterface = iface;
            break;
        }
    }
    if(!foundInterface){
        emit msgEventString(tr("电脑上找不到名为“%1”的网卡").arg(networkInterfaceName) );
        _networkInterface = allInterfaces.at(0);
    }
    if(state() == STAT_RUN){
        restart();
    }
}

void MulticastProtocolDriver::_watchDogTimeOver(){
    emit msgEventString(tr("超时错误，长时间未收到数据") );
    _setState(STAT_ERR);
}

int MulticastProtocolDriver::start(){
    bool ret;
    if(_pUdpSocket != nullptr){
        _pUdpSocket->close();
        _pUdpSocket->deleteLater();
    }
    if( _multicastAddress.isMulticast() ){
        _pUdpSocket = new QUdpSocket(this);
        ret = _pUdpSocket->bind(QHostAddress::AnyIPv4, _port, QUdpSocket::ShareAddress);
        if(!ret){
            _setState( STAT_STOP );
            emit msgEventString(tr("启动失败！网络监听失败，检查网络状态！错误描述：%1").arg(_pUdpSocket->errorString() ) );
            return -1;
        }
    }
    if(_networkInterface.flags().testFlag(QNetworkInterface::CanMulticast) ){
        ret = _pUdpSocket->joinMulticastGroup(_multicastAddress, _networkInterface);
        if(ret){
            //_pUdpSocket->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption,1024*1024*8);
            connect(_pUdpSocket, SIGNAL(readyRead()), this, SLOT(_processPendingDatagrams()));
            _setState(STAT_RUN);
            emit msgEventString(tr("启动成功！") );
            return 0;
        }
        else{
            emit msgEventString(tr("启动失败！加入组播组失败，检查组播地址和网络状态！") );
            return -1;
        }
    }
    emit msgEventString(tr("启动失败！地址不是组播地址或网卡没有组播功能！") );
    return -1;
}

int MulticastProtocolDriver::stop(){
    if(_pUdpSocket != nullptr){
        _pUdpSocket->close();
        _setState(STAT_STOP);
        emit msgEventString(tr("停止成功！") );
    }
    return 0;
}

int MulticastProtocolDriver::restart(){
    stop();
    return start();
}

QList<int> MulticastProtocolDriver::availableRWStrategy(void)const{
    QList<int> ret;
    ret<<iTagInfo::RWS_DISABLE<<iTagInfo::RWS_READ_ONLY;
    return ret;
}

QList<int> MulticastProtocolDriver::availableRWStrategy(const QString& addr)const{
    QList<int> ret;
    ret<<iTagInfo::RWS_DISABLE;
    if(isAddressCorrect(addr))
        ret<<iTagInfo::RWS_READ_ONLY;
    return ret;
}

bool MulticastProtocolDriver::isAddressCorrect(const QString& addr)const{
    bool ret;
    addr.toInt(&ret,10);
    return ret;
}

QString MulticastProtocolDriver::addressErrorString(const QString& addr) const{
    if(isAddressCorrect(addr)){
        return QString();
    }
    return tr("地址必须是十进制数字！");
}

int MulticastProtocolDriver::setMulticastAddress(const QHostAddress& addr, int port){
    if( addr.isMulticast() ){
        if(addr != _multicastAddress ){
            _multicastAddress = addr;
            _port = port;
        }
        return 0;
    }
    emit msgEventString(tr("地址设置失败。地址不是组播地址！") );
    return -1;
}

int MulticastProtocolDriver::setNetworkInterface(const QNetworkInterface& networkInterface){
    if(networkInterface.isValid()){
        if(networkInterface.flags().testFlag(QNetworkInterface::CanMulticast) ){
            _networkInterface = networkInterface;
            return 0;
        }
    }
    emit msgEventString(tr("设置失败。没有组播功能或无效地址！") );
    return -1;
}

QString MulticastProtocolDriver::multicastAddress(void)const{
    return _multicastAddress.toString();
}

int MulticastProtocolDriver::multicastPort(void)const{
    return _port;
}

QNetworkInterface& MulticastProtocolDriver::networkInterface(void){
    return _networkInterface;
}

int MulticastProtocolDriver::setRelatedTagAddresses(const QList<TagAddress *>& relatedTagAddresses){
    int count =0;
    _relatedTags.clear();
    foreach (TagAddress* it, relatedTagAddresses) {
        if(it->RWStrategy == iTagInfo::RWS_READ_ONLY){
            _relatedTags<<it;
            count++;
        }
    }
    qSort(_relatedTags.begin(), _relatedTags.end(), compareTagAddress);
    return count;
}

void MulticastProtocolDriver::showUI(bool show, QWidget *parent){
    if(_pUI == nullptr){
        _pUI = new MulticastProtocolDriverUI(this, parent);
    }
    if(show){
        _pUI->show();
    }else{
        _pUI->hide();
    }
}

void MulticastProtocolDriver::_processPendingDatagrams()
{
    while (_pUdpSocket->hasPendingDatagrams()) {
        emit dataReceived();//accept per UDP package
        QByteArray datagram;
        datagram.resize(_pUdpSocket->pendingDatagramSize());
        int count = _pUdpSocket->readDatagram(datagram.data(), datagram.size());

///extension alarming system protocol
//        int group,offset,num;

//        group	= (datagram[16]&0xff) + ((datagram[15]&0xff) << 8);
//        offset	= (datagram[18]&0xff) + ((datagram[17]&0xff) << 8);
//        num		= (datagram[19]&0xff);

//        if(num > 80)//data num is not right
//            return;

//        if((offset+num)>513)//data length is not right
//            return;

//        int year= (datagram[8]&0xff) + ( (datagram[9]&0xff)<<8 );
//        int month = (datagram[10]&0xff);
//        int day = (datagram[11]&0xff);
//        int hour =(datagram[12]&0xff);
//        int min = (datagram[13]&0xff);
//        int sec = (datagram[14]&0xff);
//        QDateTime updateDateTime;
//        updateDateTime.setDate( QDate(year,month,day) );
//        updateDateTime.setTime( QTime(hour,min,sec) );

//        int tagID;

//        for(int i=0; i<num; i++){
//            tagID = offset + i;
//            foreach(TagInfo*t, *_pAllTags){
//                if(t->tagID() == tagID){
//                    int value = datagram[20 + i*6] + (datagram[20 + i*6 + 1] << 8);
//                    t->updatevalue(QString::number(value), updateDateTime);
//                }
//            }
//        }


///real time database receiving protocol
        if ((datagram[0] == (char)0x53)
                && (count >= 16)
                && (datagram[count - 1] == (char)0x0D)
                && ( ((datagram[7]&0xFF)<<8) + (datagram[6]&0xFF) + 7  == count)){
            //以太网帧校验
            char check = 0;
            for (int i = 8; i < count - 2; i++)
                check = (char)(check + datagram[i]);
            if (check != datagram[count - 2])
            {
                return;
            }

            quint32 ip_i = (quint32)((datagram[1]&0xFF)<<24) +
                    (quint32)((datagram[2]&0xFF)<<16) +
                    (quint32)((datagram[3]&0xFF)<<8) +
                    (quint32)(datagram[4]&0xFF);
            QHostAddress ip;
            ip.setAddress(ip_i);//数据来源 IP 地址


            int dt = datagram[5];//数据类型
            int p = 8;
            QDateTime updateDateTime;

            switch (dt)
            {
                //case 0x64://网络确认请求
                //    if (OnComm != null)
                //        OnComm(DateTime.Now, host.ToString(), 0);
                //    break;
                //case 0x65://网络确认响应
                    ////if (OnComm != null)
                    ////    OnComm(DateTime.Now, host.ToString(), 1);
                    //break;
                //case 0x12://网络校时
                //    if (_getTime(updateDateTime, datagram[p] + datagram[p + 1]<<8, datagram[p + 2], datagram[p + 3], datagram[p + 4], datagram[p + 5], datagram[p + 6]))
                //    {
                //        if (OnTime != null)
                //            OnTime(time);
                //    }
                //    break;

                case 0x11://广播数据,老的程序是11H
                    if (_getTime(updateDateTime, datagram[p] + datagram[p + 1] * 100, datagram[p + 2], datagram[p + 3], datagram[p + 4], datagram[p + 5], datagram[p + 6]))
                    {
                        p = p + 7;
                        while ((p + 12) < count)
                        {
                            //unwrap
                            //project id, bit28 -- bit16, together 13 bits. using byte 0(lower 5 bits ) and byte 1(hole bits)
                            int projectID = (((quint8)datagram[p]) << 8) + (quint8)datagram[p + 1];
                            //station id, bit15 -- bit9, together 7 bits(0~127). using byte 2(higher 7 bits)
                            int stationID = ((quint8)datagram[p + 2]) >> 1;
                            //module id, bit8 -- bit5, together 4 bits(according to manual 0~15). using byte2(lower 1bit) and byte 3(higher 3bits)
                            int moduleID  = (((quint8)datagram[p + 2] & 0x01 )<<3 ) + (( (quint8)datagram[p + 3]) >>5 );
                            //point id, bit4 -- bit0, together 5 bits(according to manual 0~31). using byte3(lower 5bits)
                            int pointID   = ((quint8)datagram[p + 3] & 0x1F ) + 1;
                            int value =     ((quint8)datagram[p + 6] << 8) + (quint8)datagram[p + 5];
                            int alarmType = ((quint8)datagram[p + 8] << 8) + (quint8)datagram[p + 7];
                            int limitValue =((quint8)datagram[p + 10] << 8) +(quint8)datagram[p + 9];
                            Q_UNUSED(alarmType)
                            Q_UNUSED(limitValue)
                            int address = (projectID << 16) + (stationID << 9) + (moduleID << 5) + pointID;
                            QString addressStr = QString::number(address, 10);
                            //qDebug()<<Q_FUNC_INFO<<address<<stationID<<moduleID<<pointID<<value;
                            //if(stationID == 2 && moduleID == 5 && pointID ==1){
                            //    qDebug()<<Q_FUNC_INFO<<stationID<<moduleID<<pointID<<"ss";
                            //}

                            TagAddress* t;
                            int lastSpan = _relatedTags.size() /2;
                            int pos = _relatedTags.size() / 2;
                            while(1){
                                t = _relatedTags.at(pos);
                                if( t->address == addressStr ){
                                    //found!
                                    emit dataAccepted();//emit per accepted tag
                                    t->tagInfo->updatevalue(QString::number(value), updateDateTime);
                                    //look forward for same address
                                    for(int i=1; (pos+i)<_relatedTags.size()  ;i++){
                                        t = _relatedTags.at(pos+i);
                                        if( t->address == addressStr){
                                            t->tagInfo->updatevalue(QString::number(value), updateDateTime);
                                            continue;
                                        }
                                        break;
                                    }
                                    //look backward for same address
                                    for(int i=1; (pos-i)>=0  ;i++){
                                        t = _relatedTags.at(pos-i);
                                        if( t->address == addressStr){
                                            t->tagInfo->updatevalue(QString::number(value), updateDateTime);
                                            continue;
                                        }
                                        break;
                                    }
                                    break;
                                }else if( t->address > addressStr ){
                                    if(lastSpan == 0) break;
                                    lastSpan /= 2;
                                    if(lastSpan == 0) pos -= 1;
                                    else pos -= lastSpan;
                                }else if( t->address < addressStr){
                                    if(lastSpan == 0) break;
                                    lastSpan /= 2;
                                    if(lastSpan == 0) pos += 1;
                                    else pos += lastSpan;
                                }
                            }
                            p = p + 12;
                         }
                    }
                    break;

//                case 0x13://车令
//                    if (_getTime(updateDateTime, datagram[p] + datagram[p + 1]<<8, datagram[p + 2], datagram[p + 3], datagram[p + 4], datagram[p + 5], datagram[p + 6]))
//                    {
//                        UInt16 shij = (UInt16)((datagram[p + 10] << 8) + datagram[p + 9]);
//                        Int16 jiasbwz = (Int16)((datagram[p + 12] << 8) + datagram[p + 11]);
//                        Int16 jisbwz = (Int16)((datagram[p + 14] << 8) + datagram[p + 13]);
//                        Int16 luoj = (Int16)((datagram[p + 16] << 8) + datagram[p + 15]);
//                        Int16 zhouxzs = (Int16)((datagram[p + 18] << 8) + datagram[p + 17]);
//                        unsigned char jiasbwzJm = datagram[p + 19];
//                        unsigned char jisbwzJm = datagram[p + 20];
//                        unsigned char luojJm = datagram[p + 21];
//                        unsigned char zhouxzsJm = datagram[p + 22];

//                        RecvCmdBlock cmdBlock = new RecvCmdBlock(time, shij, jiasbwz, jisbwz, luoj, zhouxzs, jiasbwzJm, jisbwzJm, luojJm, zhouxzsJm);
//                        //车令测试，测试完成后删除
//                        if (OnCmd != null)
//                            OnCmd(cmdBlock);
//                    }
//                    break;

//                case 0x20://cep
//                    if (_getTime(updateDateTime, datagram[p] + datagram[p + 1]<<8, datagram[p + 2], datagram[p + 3], datagram[p + 4], datagram[p + 5], datagram[p + 6]))
//                    {
//                        p = p + 7;
//                        while ((p + 16) < count)
//                        {
//                            //时戳
//                            DateTime time1 = DBManager.GetTime((datagram[p + 0] << 24) + (datagram[p + 1] << 16) + (datagram[p + 2] << 8) + datagram[p + 3]);
//                            UInt16 msec = (UInt16)((datagram[p + 4] << 24) + (datagram[p + 5] << 16) + (datagram[p + 6] << 8) + datagram[p + 7]);
//                            int cepno = (int)((datagram[p + 8] << 24) + (datagram[p + 9] << 16) + (datagram[p + 10] << 8) + datagram[p + 11]);
//                            //int cepno = 0xABCD;
//                            Int16 cepvalue = (Int16)((datagram[p + 13] << 8) + datagram[p + 12]);
//                            Int16 cepalarmflag = (Int16)((datagram[p + 15] << 8) + datagram[p + 14]);
//                            RecvCepBlock cepBlock = new RecvCepBlock(time1, msec, cepvalue, cepno,cepalarmflag);
//                            if (OnCep != null)
//                                OnCep(cepBlock);//存cep数据库

//                            RecvDataBlock recvBlock1 = new RecvDataBlock(time1);
//                            recvBlock1.Add(new DataValue(cepno, cepvalue, cepalarmflag,0));
//                            if (OnRecv != null)
//                                OnRecv(recvBlock1);//存data数据库
//                            p = p + 16;
//                        }
//                     }
//                    break;
            }
        }
    }
}

void MulticastProtocolDriver::_setState(enum_states state){
    if(state != _state){
        _state = state;
        emit stateChanged(state);
    }
}

bool MulticastProtocolDriver::_getTime(QDateTime& t, int year, int month, int day, int hour, int minute, int second, int millisecond){
    if(!QDate::isValid(year,month,day))
        return false;
    if(!QTime::isValid(hour,minute,second,millisecond))
        return false;
    t.setDate( QDate(year,month,day) );
    t.setTime( QTime(hour,minute,second,millisecond) );
    return true;
}

bool MulticastProtocolDriver::compareTagAddress(const TagAddress *t1, const TagAddress *t2){
    return t1->address < t2->address;
}
