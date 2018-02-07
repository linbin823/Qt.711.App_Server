#ifndef MULTICASTPROTOCOLDRIVER_H
#define MULTICASTPROTOCOLDRIVER_H

#include <QObject>
#include <QTimer>
#include <QtNetwork>
#include "iglobal.h"

class QUdpSocket;
class QHostAddress;
class MulticastProtocolDriverUI;

class MulticastProtocolDriver : public iDriver
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.csic711.appServer.drivers.multicastProtocol" FILE "multicastProtocol.json")
    Q_INTERFACES(iDriver)
public:
    /*!
     * 构造函数
     * 功能描述：
     * 1、初始化参数
     * 2、进入停止状态
     */
    explicit MulticastProtocolDriver(QObject *parent = 0);
    ~MulticastProtocolDriver();

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
    int setMulticastAddress(const QHostAddress& addr, int port);

    /*!
     * 设置组播的网卡接口
     * 返回数值：0：成功   -1：失败
     * 功能描述：
     * 1、如果是组播的网卡接口则成功，否则失败
     */
    int setNetworkInterface(const QNetworkInterface& networkInterface);

    QString multicastAddress(void)const;
    int     multicastPort(void)const;
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

private:

    /*!
     * For sorting
     * instead of operator<() to compare the TagInfo*
     */
    static bool compareTagAddress(const TagAddress* t1, const TagAddress* t2);
    QUdpSocket * _pUdpSocket;
    QHostAddress _multicastAddress;
    QHostAddress _hostAddress;
    QNetworkInterface _networkInterface;
    MulticastProtocolDriverUI * _pUI;
    int _port;
    enum_states _state;

    QTimer *_pWatchDogTimer;
    QList<TagAddress*> _relatedTags;
};

#endif // MULTICASTPROTOCOLDRIVER_H
