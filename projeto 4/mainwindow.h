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
    QString serialReading;

private slots:
    void on_ligar_clicked();
    void on_pushButton_clicked();
    void on_abrirserial_clicked();
    void on_fecharserial_clicked();

    void on_antihorario_clicked();

    void on_horario_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
};

#endif // MAINWINDOW_H
