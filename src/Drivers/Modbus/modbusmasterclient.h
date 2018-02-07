#ifndef MODBUSRTUMASTER_H
#define MODBUSRTUMASTER_H

#include "Interface/iglobal.h"
#include <QMap>
#include <QTimer>
#include <QVariant>
#include <QHostAddress>

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

class ModbusMasterOrClient: iDriver
{
    Q_OBJECT
public:
    explicit ModbusMasterOrClient(QObject *parent = 0);
    ~ModbusMasterOrClient();

public slots:
    /*!
     * 保存功能
     */
    void save(iLoadSaveProcessor* processor) override;

    /*!
     * 读取功能
     */
    void load(iLoadSaveProcessor* processor) override;
    /*!
     * 启动驱动
     * 返回数值：0：成功    其他：失败
     * 功能描述：
     * 1、初始化UdpSocket
     * 2、监听AnyIPv4，加入组播组
     */
    int start() override;
    int stop() override;
    int restart() override;
    inline int state() override{return _state;}

    /*!
     * \brief isAddressCorrect
     * 判断测点地址是否正确
     * \param addr 测点地址
     * \return true=correct
     */
    bool isAddressCorrect(const QString& addr)override;

    /*!
     * \brief addressErrorString
     * 测点地址错误提示
     * \param addr 测点地址
     * \return return QString() means no error
     * else shows the reason of the invalid address.
     */
    QString addressErrorString(const QString& addr)override;

    /*!
     * 设置驱动相关的测点
     * 返回数值：Int 输入的测点数
     * 功能描述：
     * 写入驱动自带的_relatedTagList
     */
    int setRelatedTags(const QList<iTagInfo *>& relatedTags) override;

    /*!
     * 测点请求往设备写值一次（download）
     * 槽函数，TagInfo发出SIGNAL，本SLOT负责执行。在setRelatedTags时connect。
     * 往PLC写一次。
     */
    void tagWriteOnce(iTagInfo*one) override;
    /*!
     * 显示管理页面
     */
    void showUI(bool show=true, QWidget* parent=0) override;

public slots:

private:
    //all parameters. tree structure
    QMap<QString, QVariant> _parameters;
    //all modbus tcp servers on the net
    QList<ServerInfo> _TCPServers;
    //only one serial master on serial comm
    ServerInfo _SerialMaster;

    int _state;

    QTimer _scheduleTimer;

    /*!
     * For sorting
     * instead of operator<() to compare the TagInfo*
     */
    static bool compareTagInfo(const iTagInfo* t1, const iTagInfo* t2);
    QList<iTagInfo*> _relatedTags;

private slots:
    void _setState(enum_states state);
    void _scheduleProcess();
};

#endif // MODBUSRTUMASTER_H
