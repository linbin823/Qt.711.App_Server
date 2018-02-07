/********************************************************************************
** Form generated from reading UI file 'multicastprotocoldriverui.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTICASTPROTOCOLDRIVERUI_H
#define UI_MULTICASTPROTOCOLDRIVERUI_H

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

class Ui_MulticastProtocolDriverUI
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
    QLineEdit *leMulticastAddress;
    QLabel *lbLastError;
    QComboBox *cbInterface;
    QLabel *lbMulticastAddress;
    QLineEdit *lePort;
    QLabel *lbPort;
    QLabel *lbInterface;

    void setupUi(QWidget *MulticastProtocolDriverUI)
    {
        if (MulticastProtocolDriverUI->objectName().isEmpty())
            MulticastProtocolDriverUI->setObjectName(QLatin1String("MulticastProtocolDriverUI"));
        MulticastProtocolDriverUI->resize(400, 300);
        gridLayoutWidget = new QWidget(MulticastProtocolDriverUI);
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

        leMulticastAddress = new QLineEdit(gridLayoutWidget);
        leMulticastAddress->setObjectName(QLatin1String("leMulticastAddress"));

        gridLayout->addWidget(leMulticastAddress, 1, 2, 1, 3);

        lbLastError = new QLabel(gridLayoutWidget);
        lbLastError->setObjectName(QLatin1String("lbLastError"));

        gridLayout->addWidget(lbLastError, 5, 2, 1, 3);

        cbInterface = new QComboBox(gridLayoutWidget);
        cbInterface->setObjectName(QLatin1String("cbInterface"));

        gridLayout->addWidget(cbInterface, 0, 2, 1, 3);

        lbMulticastAddress = new QLabel(gridLayoutWidget);
        lbMulticastAddress->setObjectName(QLatin1String("lbMulticastAddress"));

        gridLayout->addWidget(lbMulticastAddress, 1, 0, 1, 1);

        lePort = new QLineEdit(gridLayoutWidget);
        lePort->setObjectName(QLatin1String("lePort"));

        gridLayout->addWidget(lePort, 2, 2, 1, 3);

        lbPort = new QLabel(gridLayoutWidget);
        lbPort->setObjectName(QLatin1String("lbPort"));

        gridLayout->addWidget(lbPort, 2, 0, 1, 1);

        lbInterface = new QLabel(gridLayoutWidget);
        lbInterface->setObjectName(QLatin1String("lbInterface"));

        gridLayout->addWidget(lbInterface, 0, 0, 1, 1);


        retranslateUi(MulticastProtocolDriverUI);

        QMetaObject::connectSlotsByName(MulticastProtocolDriverUI);
    } // setupUi

    void retranslateUi(QWidget *MulticastProtocolDriverUI)
    {
        MulticastProtocolDriverUI->setWindowTitle(QApplication::translate("MulticastProtocolDriverUI", "Form", nullptr));
        pbClose->setText(QApplication::translate("MulticastProtocolDriverUI", "\345\205\263\351\227\255", nullptr));
        lbState->setText(QApplication::translate("MulticastProtocolDriverUI", "\347\212\266\346\200\201", nullptr));
        lbReceiveDataN->setText(QApplication::translate("MulticastProtocolDriverUI", "0", nullptr));
        lbAcceptData->setText(QApplication::translate("MulticastProtocolDriverUI", "\346\234\211\346\225\210\346\225\260\346\215\256\357\274\232\n"
"(\346\265\213\347\202\271\346\225\260)", nullptr));
        lbReceiveData->setText(QApplication::translate("MulticastProtocolDriverUI", "\346\216\245\345\217\227\346\225\260\346\215\256\357\274\232\n"
"(UDP\345\214\205\346\225\260)", nullptr));
        lbAcceptDataN->setText(QApplication::translate("MulticastProtocolDriverUI", "0", nullptr));
        pbStart->setText(QApplication::translate("MulticastProtocolDriverUI", "\345\220\257\345\212\250", nullptr));
        pbStop->setText(QApplication::translate("MulticastProtocolDriverUI", "\345\201\234\346\255\242", nullptr));
        lbLastError->setText(QApplication::translate("MulticastProtocolDriverUI", "\346\234\200\345\220\216\351\224\231\350\257\257\357\274\232\346\227\240", nullptr));
        lbMulticastAddress->setText(QApplication::translate("MulticastProtocolDriverUI", "\347\273\204\346\222\255\345\234\260\345\235\200", nullptr));
        lbPort->setText(QApplication::translate("MulticastProtocolDriverUI", "\347\273\204\346\222\255\347\253\257\345\217\243", nullptr));
        lbInterface->setText(QApplication::translate("MulticastProtocolDriverUI", "\351\200\211\346\213\251\347\273\204\346\222\255\347\275\221\345\215\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MulticastProtocolDriverUI: public Ui_MulticastProtocolDriverUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTICASTPROTOCOLDRIVERUI_H
