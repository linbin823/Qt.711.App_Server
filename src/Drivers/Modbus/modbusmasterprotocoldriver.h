#ifndef MODBUSMASTERPROTOCOLDRIVER_H
#define MODBUSMASTERPROTOCOLDRIVER_H
#include "iglobal.h"
#include <QObject>
#include <QMap>
#include <QTimer>
#include <QModbusDataUnit>
#include <QSerialPort>
#include <QMutex>

QT_BEGIN_NAMESPACE
class QTimer;
class QVariant;
class QHostAddress;
class QModbusClient;
class ModbusMasterProtocolDriverUI;
QT_END_NAMESPACE

class ModbusMasterProtocolDriver : public iDriver
{
    Q_OBJECT

    Q_PLUGIN_METADATA(IID "com.csic711.appServer.drivers.modbusMaster" FILE "modbusMaster.json")
    Q_INTERFACES(iDriver)

    friend class ModbusMasterParametersModel;
    friend class ModbusMasterParametersDelegate;
public:
    enum enumConnectionType {
        Serial,
        Tcp
    };
    static QString enumConnectionTypeString(int type){
        switch(type){
        case Serial:
            return tr("串口");
        case Tcp:
            return tr("以太网");
        default:
            return QString();
        }
    }
    enum enumDataAddressing{
        ZeroBased,
        OneBased
    };
    static QString enumDataAddressingString(int type){
        switch(type){
        case ZeroBased:
            return tr("从0开始");
        case OneBased:
            return tr("从1开始");
        default:
            return QString();
        }
    }
    enum enumDWordMapping{
        BigEnd,
        SmallEnd
    };
    static QString enumDWordMappingString(int type){
        switch(type){
        case BigEnd:
            return tr("大端");
        case SmallEnd:
            return tr("小端");
        default:
            return QString();
        }
    }
    enum enumParameters{
        ConnectionType,
        SlaveStationID,
        ScheduleIntervMS,
        SerialPortNameParameter,
        SerialParityParameter,
        SerialBaudRateParameter,
        SerialDataBitsParameter,
        SerialStopBitsParameter,
        NetworkPortParameter,
        NetworkAddressParameter,
        ResponseTimeOutMS,
        NumberOfRetries,
        SerialInterFrameDelayMS,
        DataAddressing,
        DWordMapping,
        MaxReadInputPerMessage,
        MaxWriteCoilPerMessage,
        MaxReadRegistersPerMessage,
        MaxWriteRegistersPerMessage,
        MaxReadWriteRegistersPerMessage
    };
    static QString enumParametersString(int type){
        switch(type){
        case ConnectionType:
            return tr("通信类型");
        case SlaveStationID:
            return tr("从站ID");
        case ScheduleIntervMS:
            return tr("轮询时间");
        case SerialPortNameParameter:
            return tr("串口名称");
        case SerialParityParameter:
            return tr("串口校验");
        case SerialBaudRateParameter:
            return tr("串口波特率");
        case SerialDataBitsParameter:
            return tr("串口数据位");
        case SerialStopBitsParameter:
            return tr("串口停止位");
        case NetworkPortParameter:
            return tr("服务器端口");
        case NetworkAddressParameter:
            return tr("服务器IP地址");
        case ResponseTimeOutMS:
            return tr("超时时间(ms)");
        case NumberOfRetries:
            return tr("重试次数");
        case SerialInterFrameDelayMS:
            return tr("串口数据帧延时(ms)");
        case DataAddressing:
            return tr("地址格式");
        case DWordMapping:
            return tr("双字(32bits)拼字模式");
        case MaxReadInputPerMessage:
            return tr("单个数据包最大读取bit数(<=2000)");
        case MaxWriteCoilPerMessage:
            return tr("单个数据包最大写入bit数(<=1968)");
        case MaxReadRegistersPerMessage:
            return tr("单个数据包最大读取寄存器数(<=125)");
        case MaxWriteRegistersPerMessage:
            return tr("单个数据包最大写入寄存器数(<=123)");
        case MaxReadWriteRegistersPerMessage:
            return tr("单个数据包最大读写寄存器数(<=121)");
        default:
            return QString();
        }
    }
    static QString enumSerialParityString(int type){
        switch(type){
        case QSerialPort::NoParity:
            return tr("无校验");
        case QSerialPort::OddParity:
            return tr("奇校验");
        case QSerialPort::EvenParity:
            return tr("偶校验");
        case QSerialPort::SpaceParity:
            return tr("0校验");
        case QSerialPort::MarkParity:
            return tr("1校验");
        default:
            return tr("Unknow Parity");
        }
    }
    static QString enumSerialBaudString(int type){
        switch(type){
        case QSerialPort::Baud1200:
            return tr("1200bps");
        case QSerialPort::Baud2400:
            return tr("2400bps");
        case QSerialPort::Baud4800:
            return tr("4.8kbps");
        case QSerialPort::Baud9600:
            return tr("9.6kbps");
        case QSerialPort::Baud19200:
            return tr("19.2kbps");
        case QSerialPort::Baud38400:
            return tr("38.4kbps");
        case QSerialPort::Baud57600:
            return tr("57.6kbps");
        case QSerialPort::Baud115200:
            return tr("115.2kbps");
        default:
            return tr("Unkonw Baud");
        }
    }
    static QString enumSerialDataBitString(int type){
        switch(type){
        case QSerialPort::Data5:
            return tr("5bits");
        case QSerialPort::Data6:
            return tr("6bits");
        case QSerialPort::Data7:
            return tr("7bits");
        case QSerialPort::Data8:
            return tr("8bits");
        default:
            return tr("Unkonw Data Bit");
        }
    }
    static QString enumSerialStopBitString(int type){
        switch(type){
        case QSerialPort::OneStop:
            return tr("1bit");
        case QSerialPort::OneAndHalfStop:
            return tr("1.5bit");
        case QSerialPort::TwoStop:
            return tr("2bits");
        default:
            return tr("Unkonw Stop Bit");
        }
    }
public:
    ModbusMasterProtocolDriver(QObject *parent = 0);
    ~ModbusMasterProtocolDriver();

public slots:
    DriverInfo driverInfo()const override;
    void save(iLoadSaveProcessor* processor) override;
    void load(iLoadSaveProcessor* processor) override;
    int start() override;
    int stop() override;
    int restart() override;
    inline int state() override{return _state;}
    QList<int> availableRWStrategy(void)const override;
    QList<int> availableRWStrategy(const QString& addr)const override;
    bool isAddressCorrect(const QString& addr)const override;
    QString addressErrorString(const QString& addr)const override;
    int setRelatedTagAddresses(const QList<TagAddress *>& relatedTagAddresses) override;
    void showUI(bool show=true, QWidget* parent=0) override;

private:
    QModbusClient* _pModbusDevice;
    //all parameters.
    QMap<int,QVariant> _parameters;

    int _state;
    ModbusMasterProtocolDriverUI * _pUI;
    QTimer* _scheduleTimer;

    QMutex _mutex;
    /*!
     * \brief compareTagAddress
     * For sorting
     * instead of operator<() to compare the TagInfo*
     * \param t1
     * \param t2
     * \return
     */
    static bool compareTagAddress(const TagAddress* t1, const TagAddress* t2);

    QList<TagAddress*> _coils,
                     _discreteInputs,
                     _inputRegisters,
                     _holdingRegisters;
    QList<QModbusDataUnit>  _coilsDataUnit,
                            _discreteInputsDataUnit,
                            _inputRegistersDataUnit,
                            _holdingRegistersDataUnit;
private slots:
    void _initParameters();
    void _setState(enum_states state);
    void _scheduleProcess();
    /*!
     * \brief _readyRead
     * aft reply was received, process the reply data.
     */
    void _readyRead();
    /*!
     * \brief _addressArea
     * get area part of a address
     * \param addr
     * \return
     */
    int  _addressArea(const QString& addr)const;
    /*!
     * \brief _addressOffset
     * get offset part of a address
     * \param addr
     * \return
     */
    int  _addressOffset(const QString& addr)const;
    /*!
     * \brief _dataQualifier
     * each data type has a acceptable RWStrategy
     * return true if a TagAddress meets the requirement.
     * \param dataType
     * \param t
     * \return
     */
    bool _dataQualifier(int dataType, const TagAddress * t)const;
    /*!
     * \brief _prepareDataUnit
     * generate DataUnit from TagAddress
     * \param dataType
     * \param list
     * \return
     */
    QList<QModbusDataUnit> _prepareDataUnit(int dataType, const QList<TagAddress *>& list) const;
    /*!
     * \brief _readValues
     * read data from DataUnit unit to QList<TagAddress *> list
     * \param unit
     * \param list
     */
    void _readValues(const QList<TagAddress *>& list, const QModbusDataUnit& unit);
    /*!
     * \brief _writeValues
     * write data from QList<TagAddress *> list to DataUnit unit
     * \param unit
     * \param list
     */
    void _writeValues(const QList<TagAddress *>& list, QModbusDataUnit &unit);
    /*!
     * \brief _readValue
     * read value from QModbusDataUnit unit to TagAddress t
     * \param t
     * \param unit
     * \param index
     */
    void _readValue(TagAddress *t, const QModbusDataUnit& unit, uint index);
    /*!
     * \brief _writeValue
     * write value to QModbusDataUnit unit from TagAddress t
     * \param t
     * \param unit
     * \param index
     */
    void _writeValue(TagAddress *t, QModbusDataUnit& unit, uint index);
    /*!
     * \brief _isDWord(Double Word)
     * \param addr
     * \return if t is 32bit, then return true
     */
    bool _isDWord(const QString& addr)const;
};
#endif // MODBUSMASTERPROTOCOLDRIVER_H
