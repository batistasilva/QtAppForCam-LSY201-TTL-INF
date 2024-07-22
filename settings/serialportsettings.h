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
    QSerialPort::DataBits getMDataBits(const qint8 mdatabits);
    QSerialPort::Parity getMDataParity(const qint8 mdataparity);
    QSerialPort::StopBits getMStopBits(const qint8 mstopbits);
    QSerialPort::FlowControl getMFlowControl(const qint8 mflowctrol);

private slots:
    void runConfigTest();
    void runSaveConfig();

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
