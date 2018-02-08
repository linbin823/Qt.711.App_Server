#include "modbusmasterparametersmodel.h"
#include "modbusmasterprotocoldriver.h"

ModbusMasterParametersModel::ModbusMasterParametersModel(ModbusMasterProtocolDriver *driver, QObject *parent) :
      _pDriver(driver),
      QAbstractListModel(parent)
{
}

QVariant ModbusMasterParametersModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::TextAlignmentRole){
        return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
    }else if(role == Qt::DisplayRole ){
        if(orientation == Qt::Horizontal){
            switch(section){
            case 0:
                return QVariant("名称");
            case 1:
                return QVariant("参数");
            default:
                return QVariant();
            }
        }else{
            return QVariant::fromValue(section+1);
        }
    }
    return QVariant();
}

int ModbusMasterParametersModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;
    return _pDriver->_parameters.size();
}

int ModbusMasterParametersModel::columnCount(const QModelIndex &parent) const{
    Q_UNUSED(parent)
    return 2;
}

QVariant ModbusMasterParametersModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    //parameter's key
    int paraName =_pDriver->_parameters.keys().at(index.row());
    QVariant paraValue = _pDriver->_parameters[paraName];
    if(role == Qt::TextAlignmentRole){
        return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
    }else if(role == Qt::DisplayRole || role ==Qt::EditRole ){
        switch( index.column() ){
        case 0:
            return ModbusMasterProtocolDriver::enumParametersString( ModbusMasterProtocolDriver::enumParameters(paraName) );
        case 1:
            switch(paraName){
            case ModbusMasterProtocolDriver::ConnectionType:
                return ModbusMasterProtocolDriver::enumConnectionTypeString( paraValue.toInt() );
            case ModbusMasterProtocolDriver::SlaveStationID:
                return paraValue.toInt();
            case ModbusMasterProtocolDriver::ScheduleIntervMS:
                return paraValue.toInt();
            case ModbusMasterProtocolDriver::SerialPortNameParameter:
                return paraValue.toString();
            case ModbusMasterProtocolDriver::SerialParityParameter:
                return ModbusMasterProtocolDriver::enumSerialParityString( paraValue.toInt() );
            case ModbusMasterProtocolDriver::SerialBaudRateParameter:
                return ModbusMasterProtocolDriver::enumSerialBaudString( paraValue.toInt() );
            case ModbusMasterProtocolDriver::SerialDataBitsParameter:
                return ModbusMasterProtocolDriver::enumSerialDataBitString( paraValue.toInt() );
            case ModbusMasterProtocolDriver::SerialStopBitsParameter:
                return ModbusMasterProtocolDriver::enumSerialStopBitString( paraValue.toInt() );
            case ModbusMasterProtocolDriver::NetworkPortParameter:
                return paraValue.toInt();
            case ModbusMasterProtocolDriver::NetworkAddressParameter:
                return paraValue.toString();
            case ModbusMasterProtocolDriver::ResponseTimeOutMS:
                return paraValue.toInt();
            case ModbusMasterProtocolDriver::NumberOfRetries:
                return paraValue.toInt();
            case ModbusMasterProtocolDriver::SerialInterFrameDelayMS:
                return paraValue.toInt();
            case ModbusMasterProtocolDriver::DataAddressing:
                return ModbusMasterProtocolDriver::enumDataAddressingString( paraValue.toInt() );
            case ModbusMasterProtocolDriver::DWordMapping:
                return ModbusMasterProtocolDriver::enumDWordMappingString( paraValue.toInt() );
            case ModbusMasterProtocolDriver::MaxReadInputPerMessage:
                return paraValue.toInt();
            case ModbusMasterProtocolDriver::MaxWriteCoilPerMessage:
                return paraValue.toInt();
            case ModbusMasterProtocolDriver::MaxReadRegistersPerMessage:
                return paraValue.toInt();
            case ModbusMasterProtocolDriver::MaxWriteRegistersPerMessage:
                return paraValue.toInt();
            case ModbusMasterProtocolDriver::MaxReadWriteRegistersPerMessage:
                return paraValue.toInt();
            default:
                break;
            }
        default:
            break;
        }
    }else if(role == Qt::UserRole){
        if( index.column() == 0){
            return paraName;
        }else if( index.column() == 1){
            return paraValue;
        }
    }
    return QVariant();
}

bool ModbusMasterParametersModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    //only second colunm can be edit
    if(index.column() != 1) return false;
    //only accept EditRole
    if(role != Qt::EditRole) return false;

    if (data(index, role) != value) {
        QModelIndex paraNameIndex = createIndex(index.row(),0);
        int paraName = paraNameIndex.data( Qt::UserRole ).toInt();

        _pDriver->_parameters.insert(paraName, value);
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags ModbusMasterParametersModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    if(index.column()==1){
        return Qt::ItemIsEditable | Qt::ItemIsEnabled;
    }else{
        return Qt::ItemIsEnabled;
    }
}
