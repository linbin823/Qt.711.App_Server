/********************************************************************************
** Form generated from reading UI file 'modbusmasterprotocoldriverui.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODBUSMASTERPROTOCOLDRIVERUI_H
#define UI_MODBUSMASTERPROTOCOLDRIVERUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModbusMasterProtocolDriverUI
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pbClose;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *paraTab;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *lbLastError;
    QLabel *lbState;
    QTableView *tv_parameters;
    QPushButton *pbStart;
    QPushButton *pbStop;
    QLabel *lbInterface;
    QWidget *aboutTab;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLabel *label_5;
    QTextBrowser *tbDescription;
    QLabel *label_3;
    QLabel *lbName;
    QLabel *lbVersion;
    QLabel *label_2;
    QLabel *lbManufacturer;

    void setupUi(QWidget *ModbusMasterProtocolDriverUI)
    {
        if (ModbusMasterProtocolDriverUI->objectName().isEmpty())
            ModbusMasterProtocolDriverUI->setObjectName(QLatin1String("ModbusMasterProtocolDriverUI"));
        ModbusMasterProtocolDriverUI->resize(400, 300);
        gridLayoutWidget = new QWidget(ModbusMasterProtocolDriverUI);
        gridLayoutWidget->setObjectName(QLatin1String("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 381, 281));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QLatin1String("gridLayout"));
        gridLayout->setContentsMargins(10, 10, 10, 10);
        pbClose = new QPushButton(gridLayoutWidget);
        pbClose->setObjectName(QLatin1String("pbClose"));

        gridLayout->addWidget(pbClose, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        tabWidget = new QTabWidget(gridLayoutWidget);
        tabWidget->setObjectName(QLatin1String("tabWidget"));
        paraTab = new QWidget();
        paraTab->setObjectName(QLatin1String("paraTab"));
        gridLayoutWidget_2 = new QWidget(paraTab);
        gridLayoutWidget_2->setObjectName(QLatin1String("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 9, 331, 193));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QLatin1String("gridLayout_2"));
        gridLayout_2->setContentsMargins(10, 10, 10, 10);
        lbLastError = new QLabel(gridLayoutWidget_2);
        lbLastError->setObjectName(QLatin1String("lbLastError"));

        gridLayout_2->addWidget(lbLastError, 3, 2, 1, 2);

        lbState = new QLabel(gridLayoutWidget_2);
        lbState->setObjectName(QLatin1String("lbState"));

        gridLayout_2->addWidget(lbState, 2, 2, 1, 2);

        tv_parameters = new QTableView(gridLayoutWidget_2);
        tv_parameters->setObjectName(QLatin1String("tv_parameters"));

        gridLayout_2->addWidget(tv_parameters, 1, 0, 1, 4);

        pbStart = new QPushButton(gridLayoutWidget_2);
        pbStart->setObjectName(QLatin1String("pbStart"));

        gridLayout_2->addWidget(pbStart, 2, 0, 1, 1);

        pbStop = new QPushButton(gridLayoutWidget_2);
        pbStop->setObjectName(QLatin1String("pbStop"));

        gridLayout_2->addWidget(pbStop, 3, 0, 1, 1);

        lbInterface = new QLabel(gridLayoutWidget_2);
        lbInterface->setObjectName(QLatin1String("lbInterface"));

        gridLayout_2->addWidget(lbInterface, 0, 0, 1, 4);

        tabWidget->addTab(paraTab, QString());
        aboutTab = new QWidget();
        aboutTab->setObjectName(QLatin1String("aboutTab"));
        aboutTab->setMaximumSize(QSize(16777211, 16777215));
        gridLayoutWidget_3 = new QWidget(aboutTab);
        gridLayoutWidget_3->setObjectName(QLatin1String("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 10, 331, 206));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QLatin1String("gridLayout_3"));
        gridLayout_3->setContentsMargins(10, 10, 10, 10);
        label = new QLabel(gridLayoutWidget_3);
        label->setObjectName(QLatin1String("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_3);
        label_5->setObjectName(QLatin1String("label_5"));

        gridLayout_3->addWidget(label_5, 3, 0, 1, 1);

        tbDescription = new QTextBrowser(gridLayoutWidget_3);
        tbDescription->setObjectName(QLatin1String("tbDescription"));

        gridLayout_3->addWidget(tbDescription, 4, 0, 1, 2);

        label_3 = new QLabel(gridLayoutWidget_3);
        label_3->setObjectName(QLatin1String("label_3"));

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);

        lbName = new QLabel(gridLayoutWidget_3);
        lbName->setObjectName(QLatin1String("lbName"));

        gridLayout_3->addWidget(lbName, 0, 1, 1, 1);

        lbVersion = new QLabel(gridLayoutWidget_3);
        lbVersion->setObjectName(QLatin1String("lbVersion"));

        gridLayout_3->addWidget(lbVersion, 2, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_3);
        label_2->setObjectName(QLatin1String("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        lbManufacturer = new QLabel(gridLayoutWidget_3);
        lbManufacturer->setObjectName(QLatin1String("lbManufacturer"));

        gridLayout_3->addWidget(lbManufacturer, 1, 1, 1, 1);

        tabWidget->addTab(aboutTab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 2);


        retranslateUi(ModbusMasterProtocolDriverUI);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ModbusMasterProtocolDriverUI);
    } // setupUi

    void retranslateUi(QWidget *ModbusMasterProtocolDriverUI)
    {
        ModbusMasterProtocolDriverUI->setWindowTitle(QApplication::translate("ModbusMasterProtocolDriverUI", "Form", nullptr));
        pbClose->setText(QApplication::translate("ModbusMasterProtocolDriverUI", "\345\205\263\351\227\255", nullptr));
        lbLastError->setText(QApplication::translate("ModbusMasterProtocolDriverUI", "\346\234\200\345\220\216\351\224\231\350\257\257\357\274\232\346\227\240", nullptr));
        lbState->setText(QApplication::translate("ModbusMasterProtocolDriverUI", "\347\212\266\346\200\201", nullptr));
        pbStart->setText(QApplication::translate("ModbusMasterProtocolDriverUI", "\345\220\257\345\212\250", nullptr));
        pbStop->setText(QApplication::translate("ModbusMasterProtocolDriverUI", "\345\201\234\346\255\242", nullptr));
        lbInterface->setText(QApplication::translate("ModbusMasterProtocolDriverUI", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(paraTab), QApplication::translate("ModbusMasterProtocolDriverUI", "Tab 1", nullptr));
        label->setText(QApplication::translate("ModbusMasterProtocolDriverUI", "\351\251\261\345\212\250\345\220\215\347\247\260", nullptr));
        label_5->setText(QApplication::translate("ModbusMasterProtocolDriverUI", "\346\217\217\350\277\260", nullptr));
        label_3->setText(QApplication::translate("ModbusMasterProtocolDriverUI", "\347\211\210\346\234\254\345\217\267", nullptr));
        lbName->setText(QApplication::translate("ModbusMasterProtocolDriverUI", "TextLabel", nullptr));
        lbVersion->setText(QApplication::translate("ModbusMasterProtocolDriverUI", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("ModbusMasterProtocolDriverUI", "\345\216\202\345\225\206\345\220\215\347\247\260", nullptr));
        lbManufacturer->setText(QApplication::translate("ModbusMasterProtocolDriverUI", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(aboutTab), QApplication::translate("ModbusMasterProtocolDriverUI", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModbusMasterProtocolDriverUI: public Ui_ModbusMasterProtocolDriverUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODBUSMASTERPROTOCOLDRIVERUI_H
