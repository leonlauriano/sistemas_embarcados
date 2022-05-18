#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString serialReading, nmea, dataS, horaS, statusGPS, latS, longS, velocidadeS, directionS, pdop, satellites, snr;
    double latitude, longitude;

private slots:
    void on_abrir_clicked();

    void on_fechar_clicked();

    void lerSerial();


private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
};

#endif // MAINWINDOW_H
