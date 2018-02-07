#ifndef IRTDATA_H
#define IRTDATA_H
#include <QObject>
#include "itaginfo.h"
#include "iloadsave.h"

class iRTData: public QObject, public iLoadSave
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> tagList       READ tagList       NOTIFY tagListChanged)

public:
    explicit iRTData(QObject *parent = 0) : QObject(parent){}
    virtual ~iRTData(){}

public slots:
    /*!
     * \brief tagList
     * get all tags, for QML
     * \return
     */
    virtual QList<QObject*> tagList(void)const=0;
    /*!
     * \brief allTags
     * get all tags, for drivers and data proxy
     * \return
     */
    virtual QList<iTagInfo*> allTags(void)const=0;
    /*!
     * \brief allAddresses
     * for driverManager.
     * can get all TagAddress.
     * \return
     */
    virtual QList<TagAddress*> allAddresses(void)const=0;
    /*!
     * \brief names
     * 获取所有的点名称
     * \return
     */
    virtual QStringList names(void)const=0;
    /*!
     * \brief tagInfo
     * QML使用，获取TagInfo
     * 输入参数：
     * 1、name
     * 返回数值：返回QObject
     * 功能描述：
     * 1、查找TagInfo
     * 2、找不到返回nullptr
     * \param name
     * \return
     */
    virtual QObject* tagInfo(const QString& name)const=0;
    /*!
     * \brief contains
     * 测试tagInfoName 是否存在
     * \param tagInfoName
     * \return true=does contains
     */
    virtual bool contains(const QString& tagInfoName , iTagInfo* ignore = nullptr)const=0;
    /*!
     * \brief showUI
     * 显示管理页面
     * \param show
     * \param parent
     */
    virtual void showUI(bool show=true, QWidget* parent=0)=0;

    virtual bool insertTagInfo(int pos, const QString& tagName=QString())=0;
    virtual bool removeTagInfo(const QString& tagName)=0;
    virtual bool removeTagInfo(int pos)=0;

    /*!
     * \brief attachPollGroup
     * connect signals of PollGroup with slots of iTagInfo
     * should call it after any changes made to RollGroups or iTagInfos
     */
//    virtual void attachPollGroup(const QString& pollGroupName, iTagInfo* t=0)const=0;

signals:
    void tagListChanged(const QList<iTagInfo*> tags);

};


#endif // IRTDATA_H
