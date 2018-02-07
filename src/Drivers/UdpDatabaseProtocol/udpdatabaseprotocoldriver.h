#ifndef UDPDATABASEPROTOCOLDRIVER_H
#define UDPDATABASEPROTOCOLDRIVER_H

#include <QObject>
#include <QTimer>
#include <QtNetwork>
#include <QtNetwork/QUdpSocket>
#include "iglobal.h"

class QUdpSocket;
class QHostAddress;
class UdpDatabaseProtocolDriverUI;

class UdpDatabaseProtocolDriver : public iDriver
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.csic711.appServer.drivers.udpdatabaseProtocol" FILE "udpdatabaseProtocol.json")
    Q_INTERFACES(iDriver)
public:
    /*!
     * 构造函数
     * 功能描述：
     * 1、初始化参数
     * 2、进入停止状态
     */
    explicit UdpDatabaseProtocolDriver(QObject *parent = 0);
    ~UdpDatabaseProtocolDriver();

public slots:
    DriverInfo driverInfo()const override;
    void save(iLoadSaveProcessor* processor) override;
    void load(iLoadSaveProcessor* processor) override;
    int start() override;
    int stop() override;
    int restart() override;
    int state() override{ return _state; }
    QList<int> availableRWStrategy(void)const override;
    QList<int> availableRWStrategy(const QString& addr)const override;
    bool isAddressCorrect(const QString& addr)const override;
    QString addressErrorString(const QString& addr)const override;
    int setRelatedTagAddresses(const QList<TagAddress *>& relatedTagAddresses) override;
    void showUI(bool show=true, QWidget* parent=0) override;


public slots:
    /*!
     * 设置组播的Address和Port
     * 返回数值：0：成功   -1：失败
     * 功能描述：
     * 1、如果是组播的地址则成功，否则失败
     */
    int setUdpDatabaseAddress(const QHostAddress& hostaddr, qint16 hostport,qint16 localport);

    /*!
     * 设置组播的网卡接口
     * 返回数值：0：成功   -1：失败
     * 功能描述：
     * 1、如果是组播的网卡接口则成功，否则失败
     */
    int setNetworkInterface(const QNetworkInterface& networkInterface);
    /*!
     * 设置站号-csic711定制
     * 返回数值：0：成功   -1：失败
     * 功能描述：
     * 站号范围：1-255
     */
    int setSMDERIMStation(qint16 station);

    QString udpdatabaseAddress(void)const;
    int     udpdatabasePort(void)const;
    QNetworkInterface& networkInterface(void);

signals:
    void msgEventString(const QString& msg);
    //accept per udp package
    void dataReceived();
    //emit per accepted tag
    void dataAccepted();

private slots:
    void _processPendingDatagrams();
    void _setState(enum_states state);
    void _watchDogTimeOver();
    bool _getTime(QDateTime& t, int year, int month, int day, int hour, int minute, int second, int millisecond = 0);
    void _scheduleProcess();

private:

    /*!
     * For sorting
     * instead of operator<() to compare the TagInfo*
     */
    static bool compareTagAddress(const TagAddress* t1, const TagAddress* t2);
    QUdpSocket * _pUdpSocket;
    QHostAddress _udpdatabaseAddress;
    QHostAddress _hostAddress;
    QNetworkInterface _networkInterface;
    UdpDatabaseProtocolDriverUI * _pUI;
    int _port;
    quint16 _hostPort;
    char _stationID;
    enum_states _state;

    QTimer *_pWatchDogTimer;
    QList<TagAddress*> _relatedTags;

    QTimer* _scheduleTimer;//UDP发送定时器
};

#endif // UDPDATABASEPROTOCOLDRIVER_H
