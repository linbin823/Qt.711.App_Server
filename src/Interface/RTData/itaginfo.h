#ifndef ITAGINFO_H
#define ITAGINFO_H
#include <QObject>
#include <QDateTime>
#include <QVariant>
#include <QTimer>
#include "iloadsave.h"
class TagAddress;

class iTagInfo : public QObject, public iLoadSave
{
    Q_OBJECT
    Q_PROPERTY(QString   name           READ name           NOTIFY nameChanged)
    Q_PROPERTY(QString   description    READ description    NOTIFY descriptionChanged)
    Q_PROPERTY(QString   extraInfo      READ extraInfo      NOTIFY extraInfoChanged)
    Q_PROPERTY(int       type           READ type           NOTIFY typeChanged)
    Q_PROPERTY(QVariant  value          READ value          WRITE  setvalue       NOTIFY valueChanged)
    Q_PROPERTY(QString   unit           READ unit           NOTIFY unitChanged)
    Q_PROPERTY(int       projectID      READ projectID      NOTIFY projectIDChanged)
    Q_PROPERTY(QString   projectName    READ projectName    NOTIFY projectNameChanged)
    Q_PROPERTY(int       stationID      READ stationID      NOTIFY stationIDChanged)
    Q_PROPERTY(QString   stationName    READ stationName    NOTIFY stationNameChanged)
    Q_PROPERTY(int       moduleID       READ moduleID       NOTIFY moduleIDChanged)
    Q_PROPERTY(int       pointID        READ pointID        NOTIFY pointIDChanged)
    Q_PROPERTY(QString   systemName     READ systemName     NOTIFY systemNameChanged)
    Q_PROPERTY(QDateTime lastUpdateTime READ lastUpdateTime NOTIFY lastUpdateTimeChanged)
//    Q_PROPERTY(int       quilityCode    READ quilityCode    NOTIFY quilityCodeChanged)
    Q_PROPERTY(float     scaleRatio     READ scaleRatio     NOTIFY scaleRatioChanged)
    Q_PROPERTY(float     scaleOffset    READ scaleOffset    NOTIFY scaleOffsetChanged)

public:
    explicit iTagInfo(QObject *parent = 0):QObject(parent){}
    virtual ~iTagInfo(){}
    enum __enumRWStrategyCode{
        RWS_DISABLE,
        RWS_READ_ONLY,
        RWS_WRITE_ONLY,
        RWS_READ_WRITE
    };
    static QString enumRWStrategyString(int RWCode){
        switch(RWCode){
        case RWS_DISABLE:
            return tr("禁用");
        case RWS_READ_ONLY:
            return tr("只读");
        case RWS_WRITE_ONLY:
            return tr("只写");
        case RWS_READ_WRITE:
            return tr("读写");
        default:
            return QString();
        }
    }
    static int enumRWStrategyValue(const QString& string){
        if(string == enumRWStrategyString(RWS_DISABLE)){
            return RWS_DISABLE;
        }else if(string == enumRWStrategyString(RWS_READ_ONLY)){
            return RWS_READ_ONLY;
        }else if(string == enumRWStrategyString(RWS_WRITE_ONLY)){
            return RWS_WRITE_ONLY;
        }else if(string == enumRWStrategyString(RWS_READ_WRITE)){
            return RWS_READ_WRITE;
        }else return 0;
    }
    static QStringList enumRWStrategyStrings(){
        QStringList ret;
        ret<<enumRWStrategyString(RWS_DISABLE)<<enumRWStrategyString(RWS_READ_ONLY);
        ret<<enumRWStrategyString(RWS_WRITE_ONLY)<<enumRWStrategyString(RWS_READ_WRITE);
        return ret;
    }

    enum __enumTypeCode{
        TYPE_DEFAULT=0x00,
        TYPE_BOOL,
        TYPE_INT16,
        TYPE_INT32,
        TYPE_INT64,
        TYPE_UINT16,
        TYPE_UINT32,
        TYPE_UINT64,
        TYPE_FLOAT,
        TYPE_DOUBLE,
        TYPE_STRING,
        TYPE_DATETIME,
        TYPE_TIME,
        TYPE_DATE
    };
    static QString enumTypeString(int typeCode) {
        switch(typeCode){
        case TYPE_DEFAULT:
            return tr("默认");
        case TYPE_BOOL:
            return tr("BOOL");
        case TYPE_INT16:
            return tr("INT16");
        case TYPE_INT32:
            return tr("INT32");
        case TYPE_INT64:
            return tr("INT64");
        case TYPE_UINT16:
            return tr("UINT16");
        case TYPE_UINT32:
            return tr("UINT32");
        case TYPE_UINT64:
            return tr("UINT64");
        case TYPE_FLOAT:
            return tr("FLOAT");
        case TYPE_DOUBLE:
            return tr("DOUBLE");
        case TYPE_STRING:
            return tr("STRING");
        case TYPE_DATETIME:
            return tr("DATETIME");
        case TYPE_TIME:
            return tr("TIME");
        case TYPE_DATE:
            return tr("DATE");
        default:
            return QString();
        }
    }
    static int enumTypeValue(const QString& string){
        if(string == enumTypeString(TYPE_DEFAULT)){
            return TYPE_DEFAULT;
        }else if(string == enumTypeString(TYPE_BOOL)){
            return TYPE_BOOL;
        }else if(string == enumTypeString(TYPE_INT16)){
            return TYPE_INT16;
        }else if(string == enumTypeString(TYPE_INT32)){
            return TYPE_INT32;
        }else if(string == enumTypeString(TYPE_INT64)){
            return TYPE_INT64;
        }else if(string == enumTypeString(TYPE_UINT16)){
            return TYPE_UINT16;
        }else if(string == enumTypeString(TYPE_UINT32)){
            return TYPE_UINT32;
        }else if(string == enumTypeString(TYPE_UINT64)){
            return TYPE_UINT64;
        }else if(string == enumTypeString(TYPE_FLOAT)){
            return TYPE_FLOAT;
        }else if(string == enumTypeString(TYPE_DOUBLE)){
            return TYPE_DOUBLE;
        }else if(string == enumTypeString(TYPE_STRING)){
            return TYPE_STRING;
        }else if(string == enumTypeString(TYPE_DATETIME)){
            return TYPE_DATETIME;
        }else if(string == enumTypeString(TYPE_TIME)){
            return TYPE_TIME;
        }else if(string == enumTypeString(TYPE_DATE)){
            return TYPE_DATE;
        }else return 0;
    }
    static QStringList enumTypeStrings(){
        QStringList ret;
        ret<<enumTypeString(TYPE_DEFAULT)<<enumTypeString(TYPE_BOOL);
        ret<<enumTypeString(TYPE_INT16)<<enumTypeString(TYPE_INT32)<<enumTypeString(TYPE_INT64);
        ret<<enumTypeString(TYPE_UINT16)<<enumTypeString(TYPE_UINT32)<<enumTypeString(TYPE_UINT64);
        ret<<enumTypeString(TYPE_FLOAT)<<enumTypeString(TYPE_DOUBLE);
        ret<<enumTypeString(TYPE_STRING)<<enumTypeString(TYPE_DATETIME);
        ret<<enumTypeString(TYPE_TIME)<<enumTypeString(TYPE_DATE);
        return ret;
    }

    virtual QString     extraInfo()     const=0;
    virtual QString     description()   const=0;
    virtual int         type()          const=0;
    /*!
     * \brief 读测点值
     * 输入参数：无
     * 返回数值：
     * QVariant value
     * 失败返回 null
     * 功能描述：
     * 1、执行的时候，value要进行工程量变换。。。
     */
    virtual QVariant    value()         const=0;
    virtual QString     name()          const=0;
    virtual QString     unit()          const=0;
    virtual int         projectID()     const=0;
    virtual QString     projectName()   const=0;
    virtual int         stationID()     const=0;
    virtual QString     stationName()   const=0;
    virtual int         moduleID()      const=0;
    virtual int         pointID()       const=0;
    virtual QString     systemName()    const=0;
    virtual QDateTime   lastUpdateTime()const=0;
//    virtual QString     pollGroupName() const=0;
    virtual float       scaleRatio()    const=0;
    virtual float       scaleOffset()   const=0;

    /*!
     * \brief unscaledValue
     * get unscaled value
     * for drivers who need
     * \return
     */
    virtual QVariant    unscaledValue() const=0;
    /*!
     * \brief allAddresses
     * get all address structure related to this tagInfo
     * \return
     */
    virtual QList<TagAddress*> allAddresses() const=0;
    /*!
     * \brief 写测点值
     * 输入参数：
     * 1、QVariant value
     * 2、QDateTime time
     * 返回数值：
     * 0：成功
     * 其他：失败
     * 功能描述：
     * 1、专门给数据驱动模块用的方法
     * 2、执行的时候，value 不需要 执行阶码缩放、工程量变换。。。
     * 3、最后更新时间按照传入参数执行更新。
     */
    virtual int updatevalue(const QVariant &value, const QDateTime &time = QDateTime::currentDateTime() )=0;
    /*!
     * \brief 写测点值
     * 输入参数：QVariant value
     * 返回数值：
     * 0：成功
     * 其他：失败
     * 功能描述：
     * 1、专门给上位软件模块用的方法
     * 2、执行的时候，value要进行工程量变换。。。
     * 3、最后更新时间:without changing updateTime.
     */
    virtual int setvalue(const QVariant &value)=0;
    /*!
     * \brief set Tag's Read Write Strategy. Options include disabel/Read only/Write only/readWrite
     * \param RWS is read write strategy
     */
    virtual void setRWStrategy(int RWS, const QString& driverName)=0;
    virtual int RWStrategy(const QString& driverName) const=0;

    /*!
     * \brief address
     * \param driverName
     * \return address belongs to a driver
     */
    virtual QString address(const QString& driverName) const=0;
    virtual void setAddress(const QString& address, const QString& driverName)=0;

    /*!
     * \brief isAddressCorrect
     * \param driverName
     * \return whether the address is correct
     */
    virtual bool isAddressCorrect(const QString& driverName)const=0;
    /*!
     * \brief addressErrorString
     * \param driverName
     * \return the address error string.
     * if correct, return QString()
     */
    virtual QString addressErrorString(const QString& driverName)const=0;
    /*!
     * \brief allAvailableRWStrategy
     * get all available RWStrategy for this driver.
     * \return
     */
    virtual QList<int> allAvailableRWStrategy(const QString& driverName)const=0;
    /*!
     * \brief availableRWStrategy
     * always update available RWSStrategy after change address.
     * \param driverName
     * \return
     */
    virtual QList<int> availableRWStrategy(const QString& driverName)const=0;

    /*!
     * \brief needRead
     * for drivers
     * tag need to be read from controller
     * tag can't accept multi sources read(by drivers read and update)
     * solution: accept the first source update.
     * \return
     */
//    virtual bool needRead()const =0;

public slots:
    /*!
     * \brief pollValue
     * pollValue only used by pollGroup
     * periodically poll value.
     * poll include:
     *  set needRead. One Tag has only one "needRead"
     *  set needWrite. Each tagAddress has one "needWrite"
     *  That means, one tag can write to several controllers(with different drivers)
     *  but only one drive can read and update the tag's value
     */
//    virtual void pollValue() =0;

signals:
    void nameChanged();
    void descriptionChanged();
    void extraInfoChanged();
    void typeChanged();
    void valueChanged();
    void unitChanged();
    void projectIDChanged();
    void projectNameChanged();
    void stationIDChanged();
    void stationNameChanged();
    void moduleIDChanged();
    void pointIDChanged();
    void systemNameChanged();
    void lastUpdateTimeChanged();
//    void pollGroupNameChanged();
    void scaleRatioChanged();
    void scaleOffsetChanged();
    void addressChanged();
    void RWStrategyChanged();
};

class TagAddress: public iLoadSave
{
public:
    bool    needToWrite;
    QString address;
    QString driverName;
    iTagInfo* tagInfo;
    int     RWStrategy;
    void save(iLoadSaveProcessor *processor){
//        processor->writeValue("needToWrite",needToWrite);
        processor->writeValue("address",address);
        processor->writeValue("driverName",driverName);
        processor->writeValue("RWStrategy",RWStrategy);
    }
    void load(iLoadSaveProcessor *processor){
//        processor->readValue("needToWrite",needToWrite);
        processor->readValue("address",address);
        processor->readValue("driverName",driverName);
        processor->readValue("RWStrategy",RWStrategy);
    }
};

#endif // ITAGINFO_H
