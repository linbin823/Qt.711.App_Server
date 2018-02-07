#ifndef UdpDatabaseProtocolDriverUI_H
#define UdpDatabaseProtocolDriverUI_H

#include <QWidget>
#include "udpdatabaseprotocoldriver.h"

namespace Ui {
class UdpDatabaseProtocolDriverUI;
}

class UdpDatabaseProtocolDriverUI : public QWidget
{
    Q_OBJECT

public:
    explicit UdpDatabaseProtocolDriverUI(UdpDatabaseProtocolDriver* driver,
                                        QWidget *parent = 0);
    ~UdpDatabaseProtocolDriverUI();

private slots:
    void on_pbStart_clicked();
    void on_pbStop_clicked();
    void updateState(int state);
    void updateReceivedDataN();
    void updateAcceptedDataN();
    void on_pbClose_clicked();
signals:
    //to avoid create object in this ui thread
    void start();
private:

    Ui::UdpDatabaseProtocolDriverUI *ui;
    UdpDatabaseProtocolDriver* _pDriver;
    long _receivedDataN, _acceptedDataN;
};

#endif // UdpDatabaseProtocolDriverUI_H
