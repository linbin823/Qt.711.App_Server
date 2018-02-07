#ifndef MODBUSMASTERPROTOCOLDRIVERUI_H
#define MODBUSMASTERPROTOCOLDRIVERUI_H

#include <QWidget>
#include "modbusmasterprotocoldriver.h"
#include "modbusmasterparametersdelegate.h"

namespace Ui {
class ModbusMasterProtocolDriverUI;
}

class ModbusMasterProtocolDriverUI : public QWidget
{
    Q_OBJECT

public:
    explicit ModbusMasterProtocolDriverUI(ModbusMasterProtocolDriver* driver, QWidget *parent = 0);
    ~ModbusMasterProtocolDriverUI();

private:
    Ui::ModbusMasterProtocolDriverUI *ui;
    ModbusMasterProtocolDriver* _pDriver;

private slots:
    void _updateState(int state);
    void on_pbStart_clicked();
    void on_pbStop_clicked();
    void on_pbClose_clicked();
};

#endif // MODBUSMASTERPROTOCOLDRIVERUI_H
