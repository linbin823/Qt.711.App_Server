#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "multicastprotocoldriverui.h"
#include "ui_multicastprotocoldriverui.h"
#include <QNetworkInterface>
#include <QHostAddress>
#include <QNetworkAddressEntry>

MulticastProtocolDriverUI::MulticastProtocolDriverUI(MulticastProtocolDriver *driver, QWidget *parent) :
    QWidget(parent),_pDriver(driver),
    ui(new Ui::MulticastProtocolDriverUI)
{
    ui->setupUi(this);
    setLayout( ui->gridLayout );
//    setWindowFlag( Qt::WindowStaysOnTopHint );
    setWindowTitle(tr("711组播协议驱动设置"));
    _acceptedDataN = _receivedDataN = 0;

    connect(_pDriver,&MulticastProtocolDriver::msgEventString,
            ui->lbLastError,&QLabel::setText);
    connect(_pDriver,&MulticastProtocolDriver::stateChanged,
            this,&MulticastProtocolDriverUI::updateState);
    connect(_pDriver,&MulticastProtocolDriver::dataAccepted,
            this,&MulticastProtocolDriverUI::updateAcceptedDataN);
    connect(_pDriver,&MulticastProtocolDriver::dataReceived,
            this,&MulticastProtocolDriverUI::updateReceivedDataN);
    connect(this,&MulticastProtocolDriverUI::start,
            _pDriver,&MulticastProtocolDriver::start);
    //init state
    int state = _pDriver->state();
    updateState(state);

    ui->leMulticastAddress->setText(  _pDriver->multicastAddress() );
    ui->lePort->setText( QString::number( _pDriver->multicastPort() ) );
    QList<QNetworkInterface> ifaces = QNetworkInterface::allInterfaces();
    QNetworkInterface currentInterface = _pDriver->networkInterface();
    foreach(QNetworkInterface iface, ifaces){
        if(iface.flags().testFlag(QNetworkInterface::CanMulticast)){
            ui->cbInterface->addItem(QString("%1  %2")
                                     .arg(iface.name())
                                     .arg(iface.hardwareAddress() ),
                                     QVariant::fromValue(iface));
        }
        if(currentInterface.name() == iface.name() ){
            ui->cbInterface->setCurrentIndex( ui->cbInterface->count()-1 );
        }
    }
}

MulticastProtocolDriverUI::~MulticastProtocolDriverUI()
{
    delete ui;
}

void MulticastProtocolDriverUI::on_pbStart_clicked()
{

    int ret = -1;
    QHostAddress addr = QHostAddress ( ui->leMulticastAddress->text() );
    if(addr.isNull()){
        ui->lbLastError->setText("IP地址错误");
    }
    if(!addr.isMulticast()){
        ui->lbLastError->setText("IP地址不是组播地址");
    }
    bool ok;
    int port = ui->lePort->text().toInt(&ok);
    if(!ok || port ==0){
        ui->lbLastError->setText("端口错误");
    }
    ret = _pDriver->setMulticastAddress(addr, port);
    if(ret!=0) return;

    ret=_pDriver->setNetworkInterface( qvariant_cast<QNetworkInterface>(ui->cbInterface->currentData() ) );
    if(ret!=0) return;

    _acceptedDataN = _receivedDataN = 0;
    ui->lbReceiveDataN->setText( QString::number(0) );
    ui->lbAcceptDataN->setText( QString::number(0) );

    //to avoid create object in this ui thread
    emit start();
}

void MulticastProtocolDriverUI::on_pbStop_clicked()
{
    _pDriver->stop();
}

void MulticastProtocolDriverUI::updateState(int state){
    ui->lbState->setText( _pDriver->enumStatesString( _pDriver->state() ));
    if(state == MulticastProtocolDriver::STAT_RUN){
        ui->pbStart->setEnabled(false);
        ui->pbStop->setEnabled(true);
    }else{
        ui->pbStart->setEnabled(true);
        ui->pbStop->setEnabled(false);
    }
}

void MulticastProtocolDriverUI::updateReceivedDataN(){
    _receivedDataN++;
    ui->lbReceiveDataN->setText( QString::number( _receivedDataN ) );
}

void MulticastProtocolDriverUI::updateAcceptedDataN(){
    _acceptedDataN++;
    ui->lbAcceptDataN->setText( QString::number( _acceptedDataN ) );
}


void MulticastProtocolDriverUI::on_pbClose_clicked()
{
    this->hide();
}
