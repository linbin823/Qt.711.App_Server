#ifndef MODBUSMASTERPARAMETERSDELEGATE_H
#define MODBUSMASTERPARAMETERSDELEGATE_H

#include "modbusmasterprotocoldriver.h"
#include <QItemDelegate>
#include <QComboBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QSerialPortInfo>

class ModbusMasterParametersDelegate: public QItemDelegate{
    Q_OBJECT
public:
    ModbusMasterParametersDelegate(ModbusMasterProtocolDriver* driver, QObject* parent =0):
        _pDriver(driver),QItemDelegate(parent){

    }
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const{
        Q_UNUSED(option)
        QModelIndex paraNameIndex = index.sibling(index.row(),0);
        int paraName = paraNameIndex.data( Qt::UserRole ).toInt();
        QComboBox* comboboxEdit;
        QSpinBox* spinboxEdit;
        QLineEdit* lineEdit;
        QList<QSerialPortInfo> all = QSerialPortInfo::availablePorts();
        switch(paraName){
        case ModbusMasterProtocolDriver::ConnectionType:
            comboboxEdit = new QComboBox(parent);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumConnectionTypeString(ModbusMasterProtocolDriver::Serial),
                                 ModbusMasterProtocolDriver::Serial);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumConnectionTypeString(ModbusMasterProtocolDriver::Tcp),
                                 ModbusMasterProtocolDriver::Tcp);
            if(_pDriver->_parameters[paraName].toInt() ==  ModbusMasterProtocolDriver::Serial)
                comboboxEdit->setCurrentIndex(0);
            else
                comboboxEdit->setCurrentIndex(1);
            return comboboxEdit;
        case ModbusMasterProtocolDriver::SlaveStationID:
            spinboxEdit = new QSpinBox(parent);
            spinboxEdit->setMaximum(255);
            spinboxEdit->setMinimum(0);
            spinboxEdit->setValue(_pDriver->_parameters[paraName].toInt() );
            return spinboxEdit;
        case ModbusMasterProtocolDriver::ScheduleIntervMS:
            spinboxEdit = new QSpinBox(parent);
            spinboxEdit->setMaximum(10*1000);
            spinboxEdit->setMinimum(200);
            spinboxEdit->setValue(_pDriver->_parameters[paraName].toInt() );
            return spinboxEdit;
        case ModbusMasterProtocolDriver::SerialPortNameParameter:
            comboboxEdit = new QComboBox(parent);
            foreach(QSerialPortInfo info , all){
                comboboxEdit->addItem( info.portName(), info.portName() );
                if( info.portName() == _pDriver->_parameters[paraName].toString() )
                    comboboxEdit->setCurrentText( info.portName() );
            }
            return comboboxEdit;
        case ModbusMasterProtocolDriver::SerialParityParameter:
            comboboxEdit = new QComboBox(parent);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumSerialParityString(QSerialPort::NoParity),
                                 QSerialPort::NoParity);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumSerialParityString(QSerialPort::OddParity),
                                 QSerialPort::OddParity);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumSerialParityString(QSerialPort::EvenParity),
                                 QSerialPort::EvenParity);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumSerialParityString(QSerialPort::SpaceParity),
                                 QSerialPort::SpaceParity);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumSerialParityString(QSerialPort::MarkParity),
                                 QSerialPort::MarkParity);
            if(_pDriver->_parameters[paraName].toInt() == QSerialPort::NoParity)
                comboboxEdit->setCurrentIndex(0);
            else if(_pDriver->_parameters[paraName].toInt() == QSerialPort::OddParity)
                comboboxEdit->setCurrentIndex(1);
            else
                comboboxEdit->setCurrentIndex(2);
            return comboboxEdit;
        case ModbusMasterProtocolDriver::SerialBaudRateParameter:
            comboboxEdit = new QComboBox(parent);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumSerialBaudString(QSerialPort::Baud1200),
                                 QSerialPort::Baud1200);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumSerialBaudString(QSerialPort::Baud2400),
                                 QSerialPort::Baud2400);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumSerialBaudString(QSerialPort::Baud4800),
                                 QSerialPort::Baud4800);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumSerialBaudString(QSerialPort::Baud9600),
                                 QSerialPort::Baud9600);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumSerialBaudString(QSerialPort::Baud19200),
                                 QSerialPort::Baud19200);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumSerialBaudString(QSerialPort::Baud38400),
                                 QSerialPort::Baud38400);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumSerialBaudString(QSerialPort::Baud57600),
                                 QSerialPort::Baud57600);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumSerialBaudString(QSerialPort::Baud115200),
                                 QSerialPort::Baud115200);
            if(_pDriver->_parameters[paraName].toInt() == QSerialPort::Baud1200)
                comboboxEdit->setCurrentIndex(0);
            else if(_pDriver->_parameters[paraName].toInt() == QSerialPort::Baud2400)
                comboboxEdit->setCurrentIndex(1);
            else if(_pDriver->_parameters[paraName].toInt() == QSerialPort::Baud4800)
                comboboxEdit->setCurrentIndex(2);
            else if(_pDriver->_parameters[paraName].toInt() == QSerialPort::Baud9600)
                comboboxEdit->setCurrentIndex(3);
            else if(_pDriver->_parameters[paraName].toInt() == QSerialPort::Baud19200)
                comboboxEdit->setCurrentIndex(4);
            else if(_pDriver->_parameters[paraName].toInt() == QSerialPort::Baud38400)
                comboboxEdit->setCurrentIndex(5);
            else if(_pDriver->_parameters[paraName].toInt() == QSerialPort::Baud57600)
                comboboxEdit->setCurrentIndex(6);
            else if(_pDriver->_parameters[paraName].toInt() == QSerialPort::Baud115200)
                comboboxEdit->setCurrentIndex(7);
            else
                comboboxEdit->setCurrentIndex(3);
            return comboboxEdit;
        case ModbusMasterProtocolDriver::SerialDataBitsParameter:
            comboboxEdit = new QComboBox(parent);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumSerialDataBitString(QSerialPort::Data5),
                                   QSerialPort::Data5);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumSerialDataBitString(QSerialPort::Data6),
                                   QSerialPort::Data6);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumSerialDataBitString(QSerialPort::Data7),
                                   QSerialPort::Data7);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumSerialDataBitString(QSerialPort::Data8),
                                   QSerialPort::Data8);
            if(_pDriver->_parameters[paraName].toInt() == QSerialPort::Data5)
                comboboxEdit->setCurrentIndex(0);
            else if(_pDriver->_parameters[paraName].toInt() == QSerialPort::Data6)
                comboboxEdit->setCurrentIndex(1);
            else if(_pDriver->_parameters[paraName].toInt() == QSerialPort::Data7)
                comboboxEdit->setCurrentIndex(2);
            else if(_pDriver->_parameters[paraName].toInt() == QSerialPort::Data8)
                comboboxEdit->setCurrentIndex(3);
            else
                comboboxEdit->setCurrentIndex(3);
            return comboboxEdit;
        case ModbusMasterProtocolDriver::SerialStopBitsParameter:
            comboboxEdit = new QComboBox(parent);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumSerialStopBitString(QSerialPort::OneStop),
                                   QSerialPort::OneStop);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumSerialStopBitString(QSerialPort::OneAndHalfStop),
                                   QSerialPort::OneAndHalfStop);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumSerialStopBitString(QSerialPort::TwoStop),
                                   QSerialPort::TwoStop);
            if(_pDriver->_parameters[paraName].toInt() == QSerialPort::OneStop)
                comboboxEdit->setCurrentIndex(0);
            else if(_pDriver->_parameters[paraName].toInt() == QSerialPort::OneAndHalfStop)
                comboboxEdit->setCurrentIndex(1);
            else if(_pDriver->_parameters[paraName].toInt() == QSerialPort::TwoStop)
                comboboxEdit->setCurrentIndex(2);
            else
                comboboxEdit->setCurrentIndex(0);
            return comboboxEdit;
        case ModbusMasterProtocolDriver::NetworkPortParameter:
            spinboxEdit = new QSpinBox(parent);
            spinboxEdit->setMaximum(65536);
            spinboxEdit->setMinimum(100);
            spinboxEdit->setValue(_pDriver->_parameters[paraName].toInt() );
            return spinboxEdit;
        case ModbusMasterProtocolDriver::NetworkAddressParameter:
            lineEdit = new QLineEdit(parent);
            lineEdit->setReadOnly(false);
            lineEdit->setText(_pDriver->_parameters[paraName].toString() );
            return lineEdit;
        case ModbusMasterProtocolDriver::ResponseTimeOutMS:
            spinboxEdit = new QSpinBox(parent);
            spinboxEdit->setMaximum(50*1000);
            spinboxEdit->setMinimum(1000);
            spinboxEdit->setValue(_pDriver->_parameters[paraName].toInt() );
            return spinboxEdit;
        case ModbusMasterProtocolDriver::NumberOfRetries:
            spinboxEdit = new QSpinBox(parent);
            spinboxEdit->setValue(_pDriver->_parameters[paraName].toInt() );
            return spinboxEdit;
        case ModbusMasterProtocolDriver::SerialInterFrameDelayMS:
            spinboxEdit = new QSpinBox(parent);
            spinboxEdit->setMaximum(10*1000);
            spinboxEdit->setMinimum(10);
            spinboxEdit->setValue(_pDriver->_parameters[paraName].toInt() );
            return spinboxEdit;
        case ModbusMasterProtocolDriver::DataAddressing:
            comboboxEdit = new QComboBox(parent);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumDataAddressingString(ModbusMasterProtocolDriver::ZeroBased),
                                   ModbusMasterProtocolDriver::ZeroBased);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumDataAddressingString(ModbusMasterProtocolDriver::OneBased),
                                   ModbusMasterProtocolDriver::OneBased);
            if(_pDriver->_parameters[paraName].toInt() == ModbusMasterProtocolDriver::ZeroBased)
                comboboxEdit->setCurrentIndex(0);
            else if(_pDriver->_parameters[paraName].toInt() == ModbusMasterProtocolDriver::OneBased)
                comboboxEdit->setCurrentIndex(1);
            else
                comboboxEdit->setCurrentIndex(0);
            return comboboxEdit;
        case ModbusMasterProtocolDriver::DWordMapping:
            comboboxEdit = new QComboBox(parent);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumDWordMappingString(ModbusMasterProtocolDriver::BigEnd),
                                   ModbusMasterProtocolDriver::BigEnd);
            comboboxEdit->addItem( ModbusMasterProtocolDriver::enumDWordMappingString(ModbusMasterProtocolDriver::SmallEnd),
                                   ModbusMasterProtocolDriver::SmallEnd);
            if(_pDriver->_parameters[paraName].toInt() == ModbusMasterProtocolDriver::BigEnd)
                comboboxEdit->setCurrentIndex(0);
            else if(_pDriver->_parameters[paraName].toInt() == ModbusMasterProtocolDriver::SmallEnd)
                comboboxEdit->setCurrentIndex(1);
            else
                comboboxEdit->setCurrentIndex(0);
            return comboboxEdit;
        case ModbusMasterProtocolDriver::MaxReadInputPerMessage:
            spinboxEdit = new QSpinBox(parent);
            spinboxEdit->setMaximum(2000);
            spinboxEdit->setMinimum(1);
            spinboxEdit->setValue(_pDriver->_parameters[paraName].toInt() );
            return spinboxEdit;
        case ModbusMasterProtocolDriver::MaxWriteCoilPerMessage:
            spinboxEdit = new QSpinBox(parent);
            spinboxEdit->setMaximum(1968);
            spinboxEdit->setMinimum(1);
            spinboxEdit->setValue(_pDriver->_parameters[paraName].toInt() );
            return spinboxEdit;
        case ModbusMasterProtocolDriver::MaxReadRegistersPerMessage:
            spinboxEdit = new QSpinBox(parent);
            spinboxEdit->setMaximum(125);
            spinboxEdit->setMinimum(1);
            spinboxEdit->setValue(_pDriver->_parameters[paraName].toInt() );
            return spinboxEdit;
        case ModbusMasterProtocolDriver::MaxWriteRegistersPerMessage:
            spinboxEdit = new QSpinBox(parent);
            spinboxEdit->setMaximum(123);
            spinboxEdit->setMinimum(1);
            spinboxEdit->setValue(_pDriver->_parameters[paraName].toInt() );
            return spinboxEdit;
        case ModbusMasterProtocolDriver::MaxReadWriteRegistersPerMessage:
            spinboxEdit = new QSpinBox(parent);
            spinboxEdit->setMaximum(121);
            spinboxEdit->setMinimum(1);
            spinboxEdit->setValue(_pDriver->_parameters[paraName].toInt() );
            return spinboxEdit;
        default:
            break;
        }
        return nullptr;
    }
    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const{
        QComboBox* comboboxEdit;
        QSpinBox* spinboxEdit;
        QLineEdit* lineEdit;
        QVariant data;
        QModelIndex paraNameIndex = index.sibling(index.row(),0);
        int paraName = paraNameIndex.data( Qt::UserRole ).toInt();
        switch(paraName){
        case ModbusMasterProtocolDriver::ConnectionType:
        case ModbusMasterProtocolDriver::SerialPortNameParameter:
        case ModbusMasterProtocolDriver::SerialParityParameter:
        case ModbusMasterProtocolDriver::SerialBaudRateParameter:
        case ModbusMasterProtocolDriver::SerialDataBitsParameter:
        case ModbusMasterProtocolDriver::SerialStopBitsParameter:
        case ModbusMasterProtocolDriver::DataAddressing:
        case ModbusMasterProtocolDriver::DWordMapping:
            comboboxEdit = static_cast<QComboBox*>(editor);
            if(!comboboxEdit) return;
            data = comboboxEdit->currentData(Qt::UserRole);
            break;
        case ModbusMasterProtocolDriver::SlaveStationID:
        case ModbusMasterProtocolDriver::ScheduleIntervMS:
        case ModbusMasterProtocolDriver::NetworkPortParameter:
        case ModbusMasterProtocolDriver::ResponseTimeOutMS:
        case ModbusMasterProtocolDriver::NumberOfRetries:
        case ModbusMasterProtocolDriver::SerialInterFrameDelayMS:
        case ModbusMasterProtocolDriver::MaxReadInputPerMessage:
        case ModbusMasterProtocolDriver::MaxWriteCoilPerMessage:
        case ModbusMasterProtocolDriver::MaxReadRegistersPerMessage:
        case ModbusMasterProtocolDriver::MaxWriteRegistersPerMessage:
        case ModbusMasterProtocolDriver::MaxReadWriteRegistersPerMessage:
            spinboxEdit = static_cast<QSpinBox*>(editor);
            if(!spinboxEdit) return;
            data = spinboxEdit->value();
            break;
        case ModbusMasterProtocolDriver::NetworkAddressParameter:
            lineEdit = static_cast<QLineEdit*>(editor);
            if(!lineEdit) return;
            data = QVariant( lineEdit->text() );
            break;
        default:
            data = QVariant();
        }
        model->setData(index, data, Qt::EditRole);
    }
private:
    ModbusMasterProtocolDriver *_pDriver;
};

#endif // MODBUSMASTERPARAMETERSDELEGATE_H
