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
    void populateAllCombobox();
    QSerialPort::BaudRate getMBaudRate(const QString mbaudrate);
    QSerialPort::DataBits getMDataBits(const QString mdatabits);
    QSerialPort::Parity getMDataParity(const QString mdataparity);
    QSerialPort::StopBits getMStopBits(const QString mstopbits);
    QSerialPort::FlowControl getMFlowControl(const QString mflowctrol);

private slots:
    void runConfigTest();
    void runSaveConfig();
    void restoreDefaultConfig();


private:
    Ui::SerialPortSettings * ui;
    QString portname;


};

#endif // SERIALPORTSETTINGS_H
