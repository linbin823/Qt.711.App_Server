#ifndef MODBUSMASTERPARAMETERSMODEL_H
#define MODBUSMASTERPARAMETERSMODEL_H
#include <QAbstractListModel>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include "modbusmasterprotocoldriver.h"

class ModbusMasterParametersModel : public QAbstractListModel
{
    Q_OBJECT
    friend class ModbusMasterProtocolDriver;

public:
    explicit ModbusMasterParametersModel(ModbusMasterProtocolDriver* driver, QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // editorable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

private:
    ModbusMasterProtocolDriver *_pDriver;
};


#endif // MODBUSMASTERPARAMETERSMODEL_H
