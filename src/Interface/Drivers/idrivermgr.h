#ifndef IDRIVERMGR_H
#define IDRIVERMGR_H

#include <QObject>
#include "iloadsave.h"
#include "idriver.h"

class iDriverMgr : public QObject, public iLoadSave
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> driverList  READ driverList NOTIFY driverListChanged)

public:
    explicit iDriverMgr(QObject *parent = nullptr):QObject(parent){}
    virtual ~iDriverMgr(){}

public slots:
    /*!
     * \brief startAll
     * start all drivers
     */
    virtual void startAll(void)=0;
    /*!
     * \brief stopAll
     * stop all drivers
     */
    virtual void stopAll(void)=0;
    /*!
     * \brief driverList
     *  For QML usage
     * \return all drivers
     */
    virtual QList<QObject*> driverList(void)=0;
    /*!
     * \brief allDrivers
     *  For C++ usage
     * \return all drivers
     */
    virtual QList<iDriver*> allDrivers(void)=0;
    /*!
     * \brief names
     * \return all drivers' names
     */
    virtual QStringList driverNames(void)=0;
    virtual QStringList driverNameRelateToType(const QString& driverType)=0;
    /*!
     * \brief setDriverName
     * \param pos
     * \param driverName
     */
    virtual void setDriverName(int pos, const QString& driverName)=0;
    /*!
     * \brief driver
     * return a certain driver
     * \param name
     * \return
     */
    virtual QObject* driver(const QString& driverName)=0;

    /*!
     * \brief contains
     * \param driverName
     * \return true = found name
     */
    virtual bool contains(const QString& driverName)const=0;
    /*!
     * \brief 设置测点
     * 当测点表有更新，更新地址列表
     * must connect RTData's signal to this slots
     * \return 返回数值：Int 输入的测点数
     */
    virtual int setRelatedTags(const QList<iTagInfo *>& relatedTags)const=0;
    /*!
     * \brief showUI
     * \param show: true = show, false = hide
     * \param parent widget
     */
    virtual void showUI(bool show=true, QWidget* parent=0)=0;
    /*!
     * \brief insertDriver
     * insert a certain type driver into certain pos, driverName assigned
     * \param pos
     * \param info
     * \param driverName
     * \return
     */
    virtual bool insertDriver(int pos, const DriverInfo& info, const QString& driverName=QString())=0;
    virtual bool removeDriver(const QString& driverName)=0;
    virtual bool removeDriver(int pos)=0;
signals:
    void driverListChanged();

};

#endif // IDRIVERMGR_H
