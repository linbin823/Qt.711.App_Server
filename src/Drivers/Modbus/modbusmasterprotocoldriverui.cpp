#include "modbusmasterprotocoldriverui.h"
#include "ui_modbusmasterprotocoldriverui.h"
#include "modbusmasterparametersmodel.h"

ModbusMasterProtocolDriverUI::ModbusMasterProtocolDriverUI(ModbusMasterProtocolDriver* driver, QWidget *parent) :
    _pDriver(driver),
    QWidget(parent),
    ui(new Ui::ModbusMasterProtocolDriverUI)
{
    ui->setupUi(this);
    setLayout( ui->gridLayout );
    ui->paraTab->setLayout( ui->gridLayout_2 );
    ui->aboutTab->setLayout( ui->gridLayout_3 );
    ui->lbManufacturer->setText( driver->driverInfo().driverManufacturer );
    ui->lbName->setText( driver->driverInfo().driverType );
    ui->lbVersion->setText( driver->driverInfo().majorVersion+"."+
                            driver->driverInfo().minorVersion+"."+
                            driver->driverInfo().microVersion);
    ui->tbDescription->setEnabled( false );
    ui->tbDescription->setText( driver->driverInfo().description );
//    setWindowFlag( Qt::WindowStaysOnTopHint );
    setWindowTitle(tr("Modbus Master/Client 协议驱动设置"));

    ModbusMasterParametersModel * _pModle = new ModbusMasterParametersModel(_pDriver, this);
    ModbusMasterParametersDelegate*_pDelegate = new ModbusMasterParametersDelegate(_pDriver,this);
    ui->tv_parameters->setModel( _pModle );
    ui->tv_parameters->setItemDelegateForColumn(1, _pDelegate);

    connect(_pDriver,&ModbusMasterProtocolDriver::msgEventString,
            ui->lbLastError,&QLabel::setText);
    connect(_pDriver,&ModbusMasterProtocolDriver::stateChanged,
            this,&ModbusMasterProtocolDriverUI::_updateState);

    _updateState(_pDriver->state());
}

ModbusMasterProtocolDriverUI::~ModbusMasterProtocolDriverUI()
{
    delete ui;
}

void ModbusMasterProtocolDriverUI::_updateState(int state){
    ui->lbState->setText( _pDriver->enumStatesString( state ));
    if(state == iDriver::STAT_RUN){
        ui->pbStart->setEnabled(false);
        ui->pbStop->setEnabled(true);
    }else{
        ui->pbStart->setEnabled(true);
        ui->pbStop->setEnabled(false);
    }
}

void ModbusMasterProtocolDriverUI::on_pbStart_clicked()
{
    QMetaObject::invokeMethod(_pDriver,"start");
}

void ModbusMasterProtocolDriverUI::on_pbStop_clicked()
{
    QMetaObject::invokeMethod(_pDriver,"stop");
}

void ModbusMasterProtocolDriverUI::on_pbClose_clicked()
{
    this->hide();
}
