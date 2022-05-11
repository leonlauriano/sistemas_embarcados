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
        ui->comboBox->addItem(info.portName());

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ligar_clicked()
{
    //botao de ligar
    serial->write("ligar\r\n");
}

void MainWindow::on_pushButton_clicked()
{
    //botao de desligar
    serial->write("desligar\r\n");
}

void MainWindow::on_abrirserial_clicked()
{
    //botao de abrir o serial
    serial->setPortName(ui->comboBox->currentText());
    serial->open(QSerialPort::ReadWrite);
    serial->setBaudRate(9600);
    serial->setParity(QSerialPort::NoParity);
    serial->setDataBits(QSerialPort::Data8);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

}

void MainWindow::on_fecharserial_clicked()
{
    //botao de fechar serial
    if(serial->isOpen()){
        serial->flush();
        serial->close();
    }
}

void MainWindow::on_antihorario_clicked()
{
    //botao pra girar sentido anti horario
    serial->write("antihorario\r\n");
}

void MainWindow::on_horario_clicked()
{
    //botao pra girar sentido horario
    serial->write("horario\r\n");
}
