#ifndef IALARMTAGINFO_H
#define IALARMTAGINFO_H

#include <QObject>
#include <QDateTime>
#include <QVariant>
#include "../RTData/itaginfo.h"
#include "iloadsave.h"
/*!
 * \brief The iAlarmTagInfo class
 * 接口类。一个报警点。
 * 报警状态：屏蔽、抑制、正常、发生未确认、发生已确认、正常未确认
 * 时刻记录：最后发生时刻、最后消失时刻
 * 被监控变量：指向一个iTagInfo
 * 报警方法：常数型、变量型、表达式（JS）型
 * 其他报警信息：报警级别、报警区域、报警描述、报警备注
 */

class iAlarmTagInfo: public QObject, public iLoadSave
{
    Q_OBJECT
    Q_PROPERTY(QString   name                   READ name                   NOTIFY nameChanged)
    Q_PROPERTY(int       state                  READ state                  NOTIFY stateChanged)
    Q_PROPERTY(QString   level                  READ level                  NOTIFY levelChanged)
    Q_PROPERTY(QString   zone                   READ zone                   NOTIFY zoneChanged)
    Q_PROPERTY(QString   description            READ description            NOTIFY descriptionChanged)
    Q_PROPERTY(QString   extraInfo              READ extraInfo              NOTIFY extraInfoChanged)
    Q_PROPERTY(int       method                 READ method                 NOTIFY methodChanged)
    Q_PROPERTY(QDateTime lastAlarmOccurredTime  READ lastAlarmOccurredTime  NOTIFY lastAlarmOccurredTimeChanged)
    Q_PROPERTY(QDateTime lastAlarmDisappearTime READ lastAlarmDisappearTime NOTIFY lastAlarmDisappearTimeChanged)
    Q_PROPERTY(QDateTime lastAcknowledgeTime    READ lastAcknowledgeTime    NOTIFY lastAcknowledgeTimeChanged)
    Q_PROPERTY(bool      needAck                READ needAck                NOTIFY needAckChanged)
public:
    explicit iAlarmTagInfo(QObject *parent = 0):QObject(parent){}
    virtual ~iAlarmTagInfo(){}

    enum __method{
        METHOD_CONST,
        METHOD_VARIABLE,
        METHOD_SCRIPT
    };
    static QString enumMethodString(int alaMethod){
        switch (alaMethod) {
        case METHOD_CONST:
            return tr("常数");
            break;
        case METHOD_VARIABLE:
            return tr("变量");
            break;
        case METHOD_SCRIPT:
            return tr("JS脚本");
            break;
        default:
            return tr("未知报警方法");
            break;
        }
    }
    static int enumMethodValue(const QString& string){
        if(string == enumMethodString(METHOD_CONST)){
            return METHOD_CONST;
        }else if(string == enumMethodString(METHOD_VARIABLE)){
            return METHOD_VARIABLE;
        }else if(string == enumMethodString(METHOD_SCRIPT)){
            return METHOD_SCRIPT;
        }else return 0;
    }
    static QStringList enumMethodStrings(){
        QStringList ret;
        ret<<enumMethodString(METHOD_CONST)<<enumMethodString(METHOD_VARIABLE);
        ret<<enumMethodString(METHOD_SCRIPT);
        return ret;
    }

    enum __state{
        STATE_DISABLE = 0x01,
        STATE_INHIBIT,
        STATE_NORMAL,
        STATE_DELAYING,
        STATE_ALARM
    };
    static QString enumStateString(int alaState){
        switch (alaState) {
        case STATE_DISABLE:
            return tr("禁用");
        case STATE_INHIBIT:
            return tr("抑制");
        case STATE_NORMAL:
            return tr("无报警");
        case STATE_DELAYING:
            return tr("触发延时中");
        case STATE_ALARM:
            return tr("报警触发");
        default:
            return tr("未知状态");
        }
    }
    static int enumStateValue(const QString& string){
        if(string == enumStateString(STATE_DISABLE)){
            return STATE_DISABLE;
        }else if(string == enumStateString(STATE_INHIBIT)){
            return STATE_INHIBIT;
        }else if(string == enumStateString(STATE_NORMAL)){
            return STATE_NORMAL;
        }else if(string == enumStateString(STATE_DELAYING)){
            return STATE_DELAYING;
        }else if(string == enumStateString(STATE_ALARM)){
            return STATE_ALARM;
        }else return 0;
    }
    static QStringList enumStateStrings(){
        QStringList ret;
        ret<<enumStateString(STATE_DISABLE)<<enumStateString(STATE_INHIBIT);
        ret<<enumStateString(STATE_NORMAL)<<enumStateString(STATE_DELAYING);
        ret<<enumStateString(STATE_ALARM);
        return ret;
    }

    virtual QString name(void) const=0;
    virtual int state(void) const=0;
    virtual int method(void) const=0;
    /*!
     * \brief needAck
     * \return
     */
    virtual bool needAck(void) const=0;

    virtual QString level(void)  const=0;
    virtual QString zone(void)   const=0;
    virtual QString description(void) const=0;
    virtual QString extraInfo(void) const=0;
    virtual QDateTime lastAlarmOccurredTime(void) const=0;
    virtual QDateTime lastAlarmDisappearTime(void) const=0;
    virtual QDateTime lastAcknowledgeTime(void) const=0;

    inline bool isEnable(){ return state()==STATE_DISABLE? false:true; }
    inline bool isInhibit(){ return state()==STATE_INHIBIT? true:false; }
    inline bool isNormal(){ return state()==STATE_NORMAL? true:false; }
    inline bool isAlarm(){ return state()==STATE_ALARM? true:false; }

public slots:

    /*!
     * \brief acknowledge
     * 确认报警。
     */
    virtual void acknowledge(void)=0;

    /*!
     * \brief acknowledge
     * 禁用报警
     */
    virtual void disable(void)=0;

    /*!
     * \brief acknowledge
     * 启用报警
     */
    virtual void enable(void)=0;

    /*!
     * \brief alarmCondition
     * 根据设置,检查状态报警
     * 不带任何条件，判断是否有报警
     * \return
     * true 有报警
     * false 正常
     */
    virtual bool alarmCondition(void)=0;


    /*!
     * \brief alarmJudge
     * 连接监测对象TagInfo的valueChanged信号。判断报警
     */
    virtual void alarmJudge(void)=0;

    /*!
     * \brief inhibitJudge
     * 连接抑制条件对象TagInfo的valueChanged信号。判断抑制
     */
    virtual void inhibitJudge(void)=0;


signals:
    void stateChanged(void);
    void nameChanged(void);
    void levelChanged(void);
    void zoneChanged(void);
    void descriptionChanged(void);
    void extraInfoChanged(void);
    void methodChanged(void);
    void lastAlarmOccurredTimeChanged(void);
    void lastAlarmDisappearTimeChanged(void);
    void lastAcknowledgeTimeChanged(void);
    void needAckChanged(void);
};

#endif // IALARMTAGINFO_H
