#ifndef IDRIVER_H
#define IDRIVER_H
#include <QObject>
#include "../RTData/itaginfo.h"
#include "iloadsave.h"

class DriverInfo;

class iDriver : public QObject, public iLoadSave
{
    Q_OBJECT
    Q_PROPERTY(int state  READ state  NOTIFY stateChanged)

public:
    /*!
     * 构造函数
     * 功能描述：
     * 1、初始化参数
     * 2、进入停止状态
     */
    explicit iDriver(QObject *parent = 0):QObject(parent){}
    virtual ~iDriver(){}

    enum enum_states{
        STAT_RUN,
        STAT_STOP,
        STAT_ERR,
        STAT_CONNECTING,
        STAT_CONNECTED,
        STAT_WAIT_FOR_RECONNECT
    };
    static QString enumStatesString(int states) {
        switch(states){
        case STAT_RUN:
            return tr("运行");
        case STAT_STOP:
            return tr("停止");
        case STAT_ERR:
            return tr("故障");
        case STAT_CONNECTING:
            return tr("连接中");
        case STAT_CONNECTED:
            return tr("已连接");
        case STAT_WAIT_FOR_RECONNECT:
            return tr("等待重连接");
        default:
            return QString::null;
        }
    }

public slots:
    /*!
     * \brief getDriverInfo
     * get driverType driverType
     * \return DriverType
     */
    virtual DriverInfo driverInfo()const=0;
    /*!
     * \brief start
     * 启动驱动
     * 返回数值：0：成功    其他：失败
     * \return
     */
    virtual int start()=0;
    virtual int stop()=0;
    virtual int restart()=0;
    virtual int state()=0;

    /*!
     * \brief isAddressCorrect
     * 判断测点地址是否正确
     * \param addr 测点地址
     * \return true=correct
     */
    virtual bool isAddressCorrect(const QString& addr)const=0;
    /*!
     * \brief availableRWStrategy
     * get all available RWStrategy for this driver.
     * \return
     */
    virtual QList<int> availableRWStrategy(void)const=0;
    /*!
     * \brief availableRWStrategy
     * get available RWStrategy related to a certain address
     * \param addr
     * \return
     */
    virtual QList<int> availableRWStrategy(const QString& addr)const=0;
    /*!
     * \brief addressErrorString
     * 测点地址错误提示
     * \param addr 测点地址
     * \return return QString() means no error
     * else shows the reason of the invalid address.
     */
    virtual QString addressErrorString(const QString& addr)const=0;

    /*!
     * \brief setRelatedTagAddresses
     * 设置驱动相关的测点
     * \return 返回数值：Int 输入的测点数
     */
    virtual int setRelatedTagAddresses(const QList<TagAddress *>& relatedTagAddresses)=0;
    /*!
     * 显示管理页面
     */
    virtual void showUI(bool show=true, QWidget* parent=0)=0;

signals:
    void stateChanged(int);
    void msgEventString(const QString& msg);

};

class DriverInfo : public iLoadSave{
public:
    QString driverType;
    QString driverManufacturer;
    QString description;
    QString majorVersion;
    QString minorVersion;
    QString microVersion;
    void save(iLoadSaveProcessor *processor){
        processor->writeValue("driverType", driverType);
        processor->writeValue("driverManufacturer", driverManufacturer);
        processor->writeValue("majorVersion", majorVersion);
        processor->writeValue("minorVersion", minorVersion);
        processor->writeValue("microVersion", microVersion);
    }
    void load(iLoadSaveProcessor *processor){
        processor->readValue("driverType", driverType);
        processor->readValue("driverManufacturer", driverManufacturer);
        processor->readValue("majorVersion", majorVersion);
        processor->readValue("minorVersion", minorVersion);
        processor->readValue("microVersion", microVersion);
    }

    bool operator==(const DriverInfo& other){
        if(driverType != other.driverType) return false;
        if(majorVersion.toInt() != other.majorVersion.toInt()) return false;
        if(minorVersion.toInt() != other.minorVersion.toInt()) return false;
        if(microVersion.toInt() != other.microVersion.toInt()) return false;
        return true;
    }
};

Q_DECLARE_INTERFACE(iDriver, "iDriver_iid")

#endif // IDRIVER_H
