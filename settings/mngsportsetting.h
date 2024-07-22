#ifndef MNGSPORTSETTING_H
#define MNGSPORTSETTING_H

#include <QSettings>
#include <QApplication>
#include <QObject>

class QSettings;

class MngSPortSetting : public QObject
{
    Q_OBJECT
public:
    explicit MngSPortSetting(QObject *parent = nullptr);
    void loadSettings();


    //For Serial Port
    void setSerialPort(QString m_port);
    QString getSerialPort() const;
    static QString defaultSerialPort();

    //Baud Rate
    QString  getBaudRate() const;
    void setBaudRate(QString m_baudrate);
    static QString defaultBaudRate();

    //Data Bits
    QString  getDataBits() const;
    void setDataBits(QString m_databits);
    static QString defaulDataBits();

    //Parity
    QString  getParity() const;
    void setParity(QString m_parity);
    static QString defaulParity();

    //Stop Bits
    QString  getStopBits() const;
    void setStopBits(QString m_stopbits);
    static QString defaulStopBits();

    //FlowControl
    QString  getFlowControl() const;
    void setFlowControl(QString m_flowcontrol);
    static QString defaulFlowControl();

signals:

private:
    QSettings * m_settings;
    QString m_setting_file;
};

#endif // MNGSPORTSETTING_H
