#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    for(const QSerialPortInfo &info : QSerialPortInfo::availablePorts())
       {
           ui->portaserial->addItem(info.portName());
           for(int i=0; i<info.standardBaudRates().size(); i++){
               ui->voltagem->addItem(QString::number(info.standardBaudRates().at(i)));

           }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_abrir_clicked()
{
    //botao de abrir o serial
    serial->setPortName(ui->portaserial->currentText());
    serial->open(QSerialPort::ReadWrite);
    serial->setBaudRate(9600);
    serial->setParity(QSerialPort::NoParity);
    serial->setDataBits(QSerialPort::Data8);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    connect(serial, SIGNAL(readyRead()),this, SLOT(lerSerial()));
}

void MainWindow::on_fechar_clicked()
{
    //botao de fechar serial
    if(serial->isOpen()){
        serial->flush();
        serial->close();
    }
}

void MainWindow::lerSerial()
{
    serialReading = QString::fromStdString(serial->readAll().data());
    nmea = serialReading.split('\n').at(0);
    ui->textBrowser->append(nmea);
    if(nmea.split(',').at(0)=="$GPRMC"){
        dataS = nmea.split(',').at(9);
        dataS = dataS.left(2)+"/"+dataS.mid(2,2)+"/"+dataS.right(2);
        ui->showData->setText(dataS);

        horaS = nmea.split(',').at(1);
        horaS = horaS.left(2)+":"+horaS.mid(2,2)+":"+horaS.mid(4,2);
        ui->showHora->setText(horaS);

        statusGPS  = nmea.split(',').at(2);
        if(statusGPS == "A"){
            ui->showStatus->setText("Ativo");
        }else{
            ui->showStatus->setText("Aguardando Satélites");
        }

        latS = nmea.split(',').at(3)+" "+nmea.split(',').at(4);
        latitude = latS.left(2).toInt()+(latS.mid(2,8).toDouble()/60);
        if(nmea.split(',').at(4) == "S"){
            latitude = (latS.left(2).toInt()+(latS.mid(2,8).toDouble()/60))*-1;
        }
        ui->showLat->setText(QString::number(latitude,'f',6));

        longS = nmea.split(',').at(5)+" "+nmea.split(',').at(6);
        longitude = longS.left(3).toInt()+(longS.mid(3,8).toDouble()/60);
        if(nmea.split(',').at(6) == "W"){
            longitude = (longS.left(3).toInt()+(longS.mid(3,8).toDouble()/60))*-1;
        }
        ui->showLong->setText(QString::number(longitude,'f',6));

        velocidadeS = nmea.split(',').at(7);
        velocidadeS = QString::number(velocidadeS.toDouble()*1.852,'f',3);
        ui->showSpeed->setText(velocidadeS);

        directionS = nmea.split(',').at(8);
        ui->showDirection->setText(directionS);

    }
    if(nmea.split(',').at(0) == "$GPGSA"){
        pdop = nmea.split(',').at(15);
        ui->showPDOP->setText(pdop);
    }
    if(nmea.split(',').at(0) == "$GPGSV"){
        satellites = nmea.split(',').at(4);
        ui->showSatellites->setText(satellites);
        snr = nmea.split(',').at(7);
        ui->showSNR->setText(snr);
    }
}


