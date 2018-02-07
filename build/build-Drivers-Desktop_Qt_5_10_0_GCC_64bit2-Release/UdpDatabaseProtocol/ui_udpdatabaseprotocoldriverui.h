/********************************************************************************
** Form generated from reading UI file 'udpdatabaseprotocoldriverui.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDPDATABASEPROTOCOLDRIVERUI_H
#define UI_UDPDATABASEPROTOCOLDRIVERUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UdpDatabaseProtocolDriverUI
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pbClose;
    QLabel *lbState;
    QLabel *lbReceiveDataN;
    QLabel *lbAcceptData;
    QLabel *lbReceiveData;
    QLabel *lbAcceptDataN;
    QSpacerItem *verticalSpacer;
    QPushButton *pbStart;
    QPushButton *pbStop;
    QLabel *lbLastError;
    QComboBox *cbInterface;
    QLabel *lbHostPort;
    QLabel *lbPort;
    QLabel *lbInterface;
    QLineEdit *leLocalPort;
    QLabel *lbStationID;
    QLineEdit *leStationID;
    QLineEdit *leHostPort;
    QLabel *lbHostIP;
    QLineEdit *leHostIP;

    void setupUi(QWidget *UdpDatabaseProtocolDriverUI)
    {
        if (UdpDatabaseProtocolDriverUI->objectName().isEmpty())
            UdpDatabaseProtocolDriverUI->setObjectName(QLatin1String("UdpDatabaseProtocolDriverUI"));
        UdpDatabaseProtocolDriverUI->resize(400, 300);
        gridLayoutWidget = new QWidget(UdpDatabaseProtocolDriverUI);
        gridLayoutWidget->setObjectName(QLatin1String("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 0, 381, 307));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QLatin1String("gridLayout"));
        gridLayout->setContentsMargins(10, 10, 10, 10);
        pbClose = new QPushButton(gridLayoutWidget);
        pbClose->setObjectName(QLatin1String("pbClose"));

        gridLayout->addWidget(pbClose, 9, 4, 1, 1);

        lbState = new QLabel(gridLayoutWidget);
        lbState->setObjectName(QLatin1String("lbState"));

        gridLayout->addWidget(lbState, 4, 2, 1, 3);

        lbReceiveDataN = new QLabel(gridLayoutWidget);
        lbReceiveDataN->setObjectName(QLatin1String("lbReceiveDataN"));

        gridLayout->addWidget(lbReceiveDataN, 6, 2, 1, 1);

        lbAcceptData = new QLabel(gridLayoutWidget);
        lbAcceptData->setObjectName(QLatin1String("lbAcceptData"));

        gridLayout->addWidget(lbAcceptData, 6, 3, 1, 1);

        lbReceiveData = new QLabel(gridLayoutWidget);
        lbReceiveData->setObjectName(QLatin1String("lbReceiveData"));

        gridLayout->addWidget(lbReceiveData, 6, 0, 1, 1);

        lbAcceptDataN = new QLabel(gridLayoutWidget);
        lbAcceptDataN->setObjectName(QLatin1String("lbAcceptDataN"));

        gridLayout->addWidget(lbAcceptDataN, 6, 4, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 2, 1, 1);

        pbStart = new QPushButton(gridLayoutWidget);
        pbStart->setObjectName(QLatin1String("pbStart"));

        gridLayout->addWidget(pbStart, 4, 0, 1, 1);

        pbStop = new QPushButton(gridLayoutWidget);
        pbStop->setObjectName(QLatin1String("pbStop"));

        gridLayout->addWidget(pbStop, 5, 0, 1, 1);

        lbLastError = new QLabel(gridLayoutWidget);
        lbLastError->setObjectName(QLatin1String("lbLastError"));

        gridLayout->addWidget(lbLastError, 5, 2, 1, 3);

        cbInterface = new QComboBox(gridLayoutWidget);
        cbInterface->setObjectName(QLatin1String("cbInterface"));

        gridLayout->addWidget(cbInterface, 0, 2, 1, 3);

        lbHostPort = new QLabel(gridLayoutWidget);
        lbHostPort->setObjectName(QLatin1String("lbHostPort"));

        gridLayout->addWidget(lbHostPort, 1, 0, 1, 1);

        lbPort = new QLabel(gridLayoutWidget);
        lbPort->setObjectName(QLatin1String("lbPort"));

        gridLayout->addWidget(lbPort, 2, 0, 1, 1);

        lbInterface = new QLabel(gridLayoutWidget);
        lbInterface->setObjectName(QLatin1String("lbInterface"));

        gridLayout->addWidget(lbInterface, 0, 0, 1, 1);

        leLocalPort = new QLineEdit(gridLayoutWidget);
        leLocalPort->setObjectName(QLatin1String("leLocalPort"));

        gridLayout->addWidget(leLocalPort, 2, 2, 1, 1);

        lbStationID = new QLabel(gridLayoutWidget);
        lbStationID->setObjectName(QLatin1String("lbStationID"));

        gridLayout->addWidget(lbStationID, 2, 3, 1, 1);

        leStationID = new QLineEdit(gridLayoutWidget);
        leStationID->setObjectName(QLatin1String("leStationID"));

        gridLayout->addWidget(leStationID, 2, 4, 1, 1);

        leHostPort = new QLineEdit(gridLayoutWidget);
        leHostPort->setObjectName(QLatin1String("leHostPort"));
        leHostPort->setEnabled(true);

        gridLayout->addWidget(leHostPort, 1, 2, 1, 1);

        lbHostIP = new QLabel(gridLayoutWidget);
        lbHostIP->setObjectName(QLatin1String("lbHostIP"));

        gridLayout->addWidget(lbHostIP, 1, 3, 1, 1);

        leHostIP = new QLineEdit(gridLayoutWidget);
        leHostIP->setObjectName(QLatin1String("leHostIP"));
        leHostIP->setEnabled(true);

        gridLayout->addWidget(leHostIP, 1, 4, 1, 1);


        retranslateUi(UdpDatabaseProtocolDriverUI);

        QMetaObject::connectSlotsByName(UdpDatabaseProtocolDriverUI);
    } // setupUi

    void retranslateUi(QWidget *UdpDatabaseProtocolDriverUI)
    {
        UdpDatabaseProtocolDriverUI->setWindowTitle(QApplication::translate("UdpDatabaseProtocolDriverUI", "Form", nullptr));
        pbClose->setText(QApplication::translate("UdpDatabaseProtocolDriverUI", "\345\205\263\351\227\255", nullptr));
        lbState->setText(QApplication::translate("UdpDatabaseProtocolDriverUI", "\347\212\266\346\200\201", nullptr));
        lbReceiveDataN->setText(QApplication::translate("UdpDatabaseProtocolDriverUI", "0", nullptr));
        lbAcceptData->setText(QApplication::translate("UdpDatabaseProtocolDriverUI", "\346\234\211\346\225\210\346\225\260\346\215\256\357\274\232\n"
"(\346\265\213\347\202\271\346\225\260)", nullptr));
        lbReceiveData->setText(QApplication::translate("UdpDatabaseProtocolDriverUI", "\346\216\245\345\217\227\346\225\260\346\215\256\357\274\232\n"
"(UDP\345\214\205\346\225\260)", nullptr));
        lbAcceptDataN->setText(QApplication::translate("UdpDatabaseProtocolDriverUI", "0", nullptr));
        pbStart->setText(QApplication::translate("UdpDatabaseProtocolDriverUI", "\345\220\257\345\212\250", nullptr));
        pbStop->setText(QApplication::translate("UdpDatabaseProtocolDriverUI", "\345\201\234\346\255\242", nullptr));
        lbLastError->setText(QApplication::translate("UdpDatabaseProtocolDriverUI", "\346\234\200\345\220\216\351\224\231\350\257\257\357\274\232\346\227\240", nullptr));
        lbHostPort->setText(QApplication::translate("UdpDatabaseProtocolDriverUI", "HostPort", nullptr));
        lbPort->setText(QApplication::translate("UdpDatabaseProtocolDriverUI", "LocalPort", nullptr));
        lbInterface->setText(QApplication::translate("UdpDatabaseProtocolDriverUI", "\351\200\211\346\213\251\347\273\204\346\222\255\347\275\221\345\215\241", nullptr));
        lbStationID->setText(QApplication::translate("UdpDatabaseProtocolDriverUI", "StationID", nullptr));
        lbHostIP->setText(QApplication::translate("UdpDatabaseProtocolDriverUI", "HostIP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UdpDatabaseProtocolDriverUI: public Ui_UdpDatabaseProtocolDriverUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDPDATABASEPROTOCOLDRIVERUI_H
