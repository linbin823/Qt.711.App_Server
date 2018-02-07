#ifndef MulticastProtocolDriverUI_H
#define MulticastProtocolDriverUI_H

#include <QWidget>
#include "multicastprotocoldriver.h"

namespace Ui {
class MulticastProtocolDriverUI;
}

class MulticastProtocolDriverUI : public QWidget
{
    Q_OBJECT

public:
    explicit MulticastProtocolDriverUI(MulticastProtocolDriver* driver,
                                        QWidget *parent = 0);
    ~MulticastProtocolDriverUI();

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

    Ui::MulticastProtocolDriverUI *ui;
    MulticastProtocolDriver* _pDriver;
    long _receivedDataN, _acceptedDataN;
};

#endif // MulticastProtocolDriverUI_H
