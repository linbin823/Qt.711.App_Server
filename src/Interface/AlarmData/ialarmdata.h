#ifndef IALARMDATA_H
#define IALARMDATA_H
#include <QObject>
#include <QColor>
#include "../RTData/irtdata.h"
#include "ialarmtaginfo.h"
#include "iloadsave.h"

QT_BEGIN_NAMESPACE
class AlarmLevel;
class AlarmZone;
class iGlobal;
QT_END_NAMESPACE
/*!
 * \brief The iAlarmData class
 * 报警等级管理。这个除了等级名称，还要带各种状态下的颜色管理。含QHarsh<QString alarmLevelName, AlarmLevel*>
 * 报警点QHarsh<QString alarmName, iAlarmTagInfo*>
 * 每个报警点，发现状态改变后，直接通知WebServer，进行报警推送等活动。
 * 还要考虑和DB的接口
 */
class iAlarmData: public QObject, public iLoadSave
{
    Q_OBJECT
public:

    explicit iAlarmData(QObject *parent = 0):QObject(parent){}
    virtual ~iAlarmData(){}

    /*!
     * \brief global
     * 返回全局管理类
     */
    virtual iGlobal* global()const=0;
    /*!
     * \brief setGlobal
     * 必须设置全局管理类，采能开始工作
     * \param newGlobal
     */
    virtual void setGlobal( iGlobal* Global)=0;
    /*!
     * \brief contains
     * 是否包含alarmLevelName
     * \param alarmLevelName
     * \return true=does contains
     */
    virtual bool contains(const QString& alarmLevelName)const=0;
    /*!
     * \brief alarmTagInfo
     * 获取报警点信息
     * \param alarmName
     * \return 报警点信息
     */
    virtual iAlarmTagInfo* alarmTagInfo(const QString& alarmName)const=0;
    /*!
     * \brief alarmNames
     * 获取所有的报警点名称
     * \return
     */
    virtual QStringList alarmNames(void)const=0;
    /*!
     * \brief ackAll
     * 确认所有报警。
     * 停止闪烁
     */
    virtual void ackAll(void)=0;
    /*!
     * \brief resetAll
     * 复位所有报警。
     * 所有报警复位到正常状态，然后重新产生报警。
     */
    virtual void resetAll(void)=0;
    /*!
     * \brief exists
     * 测试alarmTagInfoName 是否存在
     * \param alarmTagInfoName
     * \return
     */
    virtual bool exists(const QString& alarmName)const=0;
    /*!
     * 显示管理页面
     */
    virtual void showUI(bool show=true, QWidget* parent=0)=0;

signals:
    /*!
     * \brief alarmStateChanged
     * For Upper Interface, such as webServer
     * \param info
     */
    void alarmStateChanged(iAlarmTagInfo* info);

};
#endif // IALARMDATA_H
