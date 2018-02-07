#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QDateTime>
#include <QHostAddress>
#include "udpdatabaseprotocoldriverui.h"
#include "udpdatabaseprotocoldriver.h"
#include "loadsaveprocessorxml.h"

UdpDatabaseProtocolDriver::UdpDatabaseProtocolDriver(QObject *parent) : iDriver(parent),
    _udpdatabaseAddress( QHostAddress("127.0.0.1")),
    _stationID(0xFA),
    _port(5656),
    _pUdpSocket(nullptr),
    _pUI(nullptr),
    _pWatchDogTimer(nullptr),
    _scheduleTimer(nullptr)
{
    //default
    if(QNetworkInterface::allInterfaces().size() == 0){
        emit msgEventString(tr("电脑上找不到网卡") );
    }
    else{
        _networkInterface = QNetworkInterface::allInterfaces().at(0);
    }


    _setState(STAT_STOP);
}
UdpDatabaseProtocolDriver::~UdpDatabaseProtocolDriver(){
    stop();
    if(_pUdpSocket!=nullptr){
        _pUdpSocket->deleteLater();
    }
    if(_pUI != nullptr){
        _pUI->deleteLater();
    }
}

DriverInfo UdpDatabaseProtocolDriver::driverInfo()const{
    DriverInfo info;
    info.driverType = "UdpDatabase Protocol";
    info.driverManufacturer = "CSIC711";
    info.description = "UdpDatabase Protocol for data acquisition\nDate:2017.9";
    info.majorVersion = QString::number(0);
    info.minorVersion = QString::number(0);
    info.microVersion = QString::number(1);
    return info;
}

void UdpDatabaseProtocolDriver::save(iLoadSaveProcessor* processor){
    processor->writeValue("udpdatabaseAddress",_udpdatabaseAddress);
    processor->writeValue("port",_port);
    QString networkInterfaceName = _networkInterface.name();
    processor->writeValue("networkInterface", networkInterfaceName );
}

void UdpDatabaseProtocolDriver::load(iLoadSaveProcessor* processor){
    processor->readValue("udpdatabaseAddress",_udpdatabaseAddress);
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

void UdpDatabaseProtocolDriver::_watchDogTimeOver(){
    emit msgEventString(tr("超时错误，长时间未收到数据") );
    _setState(STAT_ERR);
}

int UdpDatabaseProtocolDriver::start(){
    if(_state!=iDriver::STAT_STOP) return-1;
    if(_pUdpSocket != nullptr){
        _pUdpSocket->close();
        _pUdpSocket->deleteLater();
    }
    else{
        _pUdpSocket = new QUdpSocket(this);
        bool ret = _pUdpSocket->bind(_port, QUdpSocket::ShareAddress);
        if(!ret){
            _setState( STAT_STOP );
            emit msgEventString(tr("启动失败！网络监听失败，检查网络状态！错误描述：%1").arg(_pUdpSocket->errorString() ) );
            return -1;
        }
        else{
            connect(_pUdpSocket, SIGNAL(readyRead()), this, SLOT(_processPendingDatagrams()));
        }
    }
    if(_pWatchDogTimer!=nullptr){
        _pWatchDogTimer->stop();
        _pWatchDogTimer->deleteLater();
    }else{
        _pWatchDogTimer = new QTimer(this);
        _pWatchDogTimer->setSingleShot(true);
        _pWatchDogTimer->setInterval(100 * 1000);
        connect(_pWatchDogTimer,SIGNAL(timeout()),this,SLOT(_watchDogTimeOver()));
        _pWatchDogTimer->start();
    }
    if(_scheduleTimer!=nullptr){
        _scheduleTimer->stop();
        _scheduleTimer->deleteLater();
    }else{
        _scheduleTimer = new QTimer(this);
        _scheduleTimer->setSingleShot(false);
        _scheduleTimer->setInterval(500);
        connect(_scheduleTimer,&QTimer::timeout,this,&UdpDatabaseProtocolDriver::_scheduleProcess);
        _scheduleTimer->start();
    }

    _setState(STAT_RUN);
    emit msgEventString(tr("启动成功！") );
    return 0;

//    if(_pUdpSocket != nullptr){
//        _pUdpSocket->close();
//        _pUdpSocket->deleteLater();
//    }
//    else{

//        _pUdpSocket = new QUdpSocket(this);
//        ret = _pUdpSocket->bind(_port, QUdpSocket::ShareAddress);
//        if(!ret){
//            _setState( STAT_STOP );
//            emit msgEventString(tr("启动失败！网络监听失败，检查网络状态！错误描述：%1").arg(_pUdpSocket->errorString() ) );
//            return -1;
//        }
//        else{
//            connect(_pUdpSocket, SIGNAL(readyRead()), this, SLOT(_processPendingDatagrams()));
//            _setState(STAT_RUN);
//            emit msgEventString(tr("启动成功！") );
//            return 0;
//        }
//    }
}

int UdpDatabaseProtocolDriver::stop(){
    if(_scheduleTimer!=nullptr){
        _scheduleTimer->stop();
        _scheduleTimer->deleteLater();
        _scheduleTimer=nullptr;
    }
    if(_pWatchDogTimer!=nullptr){
        _pWatchDogTimer->stop();
        _pWatchDogTimer->deleteLater();
        _pWatchDogTimer=nullptr;
    }
    if(_pUdpSocket != nullptr){
        _pUdpSocket->close();
        _pUdpSocket->deleteLater();
        _pUdpSocket=nullptr;
        _setState(STAT_STOP);
        emit msgEventString(tr("停止成功！") );
    }
    return 0;
}

int UdpDatabaseProtocolDriver::restart(){
    stop();
    return start();
}

QList<int> UdpDatabaseProtocolDriver::availableRWStrategy(void)const{
    QList<int> ret;
    ret<<iTagInfo::RWS_DISABLE<<iTagInfo::RWS_WRITE_ONLY;
    return ret;
}

QList<int> UdpDatabaseProtocolDriver::availableRWStrategy(const QString& addr)const{
    QList<int> ret;
    ret<<iTagInfo::RWS_DISABLE;
    if(isAddressCorrect(addr))
        ret<<iTagInfo::RWS_WRITE_ONLY;
    return ret;
}

bool UdpDatabaseProtocolDriver::isAddressCorrect(const QString& addr)const{
    bool ret;
    addr.toUInt(&ret,16);
    return ret;
}

QString UdpDatabaseProtocolDriver::addressErrorString(const QString& addr) const{
    if(isAddressCorrect(addr)){
        return QString();
    }
    return tr("地址必须是十进制数字！");
}

int UdpDatabaseProtocolDriver::setUdpDatabaseAddress(const QHostAddress& hostaddr, qint16 hostport,qint16 localport){
    //if( addr.isUdpDatabase() ){
     //   if(addr != _udpdatabaseAddress ){
            //_udpdatabaseAddress = addr;
            _hostAddress = hostaddr;
            _hostPort = hostport;
            _port = localport;
    //    }
        return 0;
    //}
}
int UdpDatabaseProtocolDriver::setSMDERIMStation(qint16 station){
   if(station < 0 || station >255){
       emit msgEventString(tr("输入错误：StationID超出范围！") );
       return -1;
   }
    else{
       _stationID = station;
       return 0;
   }
}

int UdpDatabaseProtocolDriver::setNetworkInterface(const QNetworkInterface& networkInterface){
    if(networkInterface.isValid()){
        //if(networkInterface.flags().testFlag(QNetworkInterface::CanUdpDatabase) ){
            _networkInterface = networkInterface;
            return 0;
        //}
    }
    emit msgEventString(tr("设置失败。没有组播功能或无效地址！") );
    return -1;
}

QString UdpDatabaseProtocolDriver::udpdatabaseAddress(void)const{
    return _udpdatabaseAddress.toString();
}

int UdpDatabaseProtocolDriver::udpdatabasePort(void)const{
    return _port;
}

QNetworkInterface& UdpDatabaseProtocolDriver::networkInterface(void){
    return _networkInterface;
}

int UdpDatabaseProtocolDriver::setRelatedTagAddresses(const QList<TagAddress *>& relatedTagAddresses){
    int count =0;
    _relatedTags.clear();
    foreach (TagAddress* it, relatedTagAddresses) {
        if(it->RWStrategy == iTagInfo::RWS_WRITE_ONLY){
            _relatedTags<<it;
            count++;
        }
    }
    qSort(_relatedTags.begin(), _relatedTags.end(), compareTagAddress);
    return count;
}

void UdpDatabaseProtocolDriver::showUI(bool show, QWidget *parent){
    if(_pUI == nullptr){
        _pUI = new UdpDatabaseProtocolDriverUI(this, parent);
    }
    if(show){
        _pUI->show();
    }else{
        _pUI->hide();
    }
}
void UdpDatabaseProtocolDriver::_scheduleProcess()
{
    QByteArray datagram;
    int i = 0;
    qint16 dmh = 0;
    qint32 temp;
    char*temp1;
    if(_state != STAT_RUN) return;
    datagram.clear();

    datagram[0] = 0x53;
    datagram[1] = 0x03;
    datagram[2] = _stationID;
    datagram[3] = 0x00;
    datagram[4] = 0x00;
    i = 5;
    if(_relatedTags.size()!=0 && !_hostAddress.isNull() ){
        //prepare data
        foreach(TagAddress* t, _relatedTags){
            if(t->RWStrategy == iTagInfo::RWS_DISABLE)   continue;
            if(t->RWStrategy == iTagInfo::RWS_READ_ONLY) continue;
            if(t->RWStrategy == iTagInfo::RWS_READ_WRITE) continue;

            temp = t->address.toUInt(nullptr,16);
            temp1 = (char*)&temp;
            datagram.append(*(temp1+3));
            datagram.append(*(temp1+2));
            datagram.append(*(temp1+1));
            datagram.append(*(temp1+0));
            switch (t->tagInfo->type()) {
            case iTagInfo::TYPE_INT32:
                datagram.append(char(0x04));
                datagram.append(char(0x00));
                //datagram.append(0x00);//quality byte:0-ok,1-error;
                temp  =t->tagInfo->value().toUInt();
                temp1  =(char*)&temp;
                datagram.append(*(temp1+3));
                datagram.append(*(temp1+2));
                datagram.append(*(temp1+1));
                datagram.append(*(temp1+0));
                break;
            case iTagInfo::TYPE_INT16:
                datagram.append(char(0x02));
                datagram.append(char(0x00));
                //datagram.append(0x00);//quality byte:0-ok,1-error;
                temp  =t->tagInfo->value().toUInt();
                temp1  =(char*)&temp;
                datagram.append(*(temp1+1));
                datagram.append(*(temp1+0));
                break;
            default:
                break;
            }
        }
        qint16 len = datagram.size() - 3;
        datagram[3] = (len & 0xff00)>>8;
        datagram[4] = len & 0xff;
        for(int i=1;i<len;i++) {
            dmh += datagram[i];
        }

        datagram.append(dmh & 0xff).append((dmh & 0xff00)>>8);
        datagram.append(char(0x0D));
        //write data
        _pUdpSocket->writeDatagram(datagram.data(),datagram.size(),_hostAddress,_hostPort);
    }
}

void UdpDatabaseProtocolDriver::_processPendingDatagrams()
{
    while (_pUdpSocket->hasPendingDatagrams()) {
        emit dataReceived();//accept per UDP package
        QByteArray datagram;
        datagram.resize(_pUdpSocket->pendingDatagramSize());
        int count = _pUdpSocket->readDatagram(datagram.data(),datagram.size(),&_hostAddress,&_hostPort);//,&_hostAddress,&_hostPort

        if ((datagram[0] == 0x53)
                && (count >= 7)
                && (datagram[count - 1] == 0x0D)){
            switch (datagram[1]) {
            case 1:
                _pUdpSocket->writeDatagram(datagram.data(),datagram.size(),_hostAddress,_hostPort);
                _pWatchDogTimer->start();

                break;
            default:
                break;
            }
        }

    }
}

void UdpDatabaseProtocolDriver::_setState(enum_states state){
    if(state != _state){
        _state = state;
        emit stateChanged(state);
    }
}

bool UdpDatabaseProtocolDriver::_getTime(QDateTime& t, int year, int month, int day, int hour, int minute, int second, int millisecond){
    if(!QDate::isValid(year,month,day))
        return false;
    if(!QTime::isValid(hour,minute,second,millisecond))
        return false;
    t.setDate( QDate(year,month,day) );
    t.setTime( QTime(hour,minute,second,millisecond) );
    return true;
}

bool UdpDatabaseProtocolDriver::compareTagAddress(const TagAddress *t1, const TagAddress *t2){
    return t1->address < t2->address;
}
