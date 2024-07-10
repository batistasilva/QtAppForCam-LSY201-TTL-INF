#ifndef SERIALPORTSETTINGS_H
#define SERIALPORTSETTINGS_H
#include <QString>
#include <QDialog>
#include <QSerialPortInfo>
#include <QSerialPort>
#include "mngsportsetting.h"


namespace Ui {
class SerialPortSettings;
}

class SerialPortSettings : public QDialog
{
    Q_OBJECT

public:
    explicit SerialPortSettings(QWidget *parent = nullptr);
    ~SerialPortSettings();
    void loadAppSettings();
    void populateSerialPort();
    void populateBaudRate();
    void populateDataBits();
    void populateParity();
    void populateStopBits();
    void populateFlowControl();

private:
    Ui::SerialPortSettings * ui;
    QString portname;
    int baudrate;
    int databits;
    int parity;
    int stopbits;
    int flowcontrol;

};

#endif // SERIALPORTSETTINGS_H
