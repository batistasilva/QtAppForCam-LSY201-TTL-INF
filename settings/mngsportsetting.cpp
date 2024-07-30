#include "mngsportsetting.h"

MngSPortSetting::MngSPortSetting(QObject *parent)
    : QObject(parent)
#ifndef WITH_PORTABLE_MODE
    , m_settings(new QSettings(this))
#else
    , m_settings(QFile::exists(AppSettings::portableConfigName()) ? new QSettings(AppSettings::portableConfigName(), QSettings::IniFormat, this) : new QSettings(this))
#endif
{
        // m_setting_file = QApplication::applicationDirPath() + "/sport-settings.ini";
}

void MngSPortSetting::loadSettings()
{
}


/**
 * @brief MngSPortSetting::setSerialPort
 * @param m_port Example: (Com1, Com2, or /dev/ttyS1, /dev/ttyACM0
 * Setting the preferred serial port for the configuration file.
 */
void MngSPortSetting::setSerialPort(QString m_port)
{
    m_settings->setValue("Serial Port", m_port);
}

/**
 * @brief MngSPortSetting::getSerialPort
 * @return QString
 */
QString MngSPortSetting::getSerialPort() const
{
  return m_settings->value("Serial Port", defaultSerialPort()).toString();
}

QString MngSPortSetting::defaultSerialPort()
{
#ifdef Q_OS_LINUX
    return "/dev/ttyACM0";
#endif
    return "com1";
}

/**
 * @brief MngSPortSetting::setBaudRate
 * @param m_baudrate
 */
void MngSPortSetting::setBaudRate(QString m_baudrate)
{
    m_settings->setValue("BaudRate", m_baudrate);
}

/**
 * @brief MngSPortSetting::getBaudRate
 * @return QString
 */
QString MngSPortSetting::getBaudRate() const
{
    return m_settings->value("BaudRate", defaultBaudRate()).toString();
}

/**
 * @brief MngSPortSetting::defaultBaudRate
 * @return QString
 */
QString MngSPortSetting::defaultBaudRate()
{
    return "9600";
}

/**
 * @brief MngSPortSetting::setDataBits
 * @param m_databits
 */
void MngSPortSetting::setDataBits(QString m_databits)
{
   m_settings->setValue("DataBits", m_databits);
}

/**
 * @brief MngSPortSetting::getDataBits
 * @return QString
 */
QString MngSPortSetting::getDataBits() const
{
    return m_settings->value("DataBits", defaulDataBits()).toString();
}

/**
 * @brief MngSPortSetting::defaulDataBits
 * @return QString
 */
QString MngSPortSetting::defaulDataBits()
{
    return "8";
}

/**
 * @brief MngSPortSetting::setParity
 * @param m_parity
 */
void MngSPortSetting::setParity(QString m_parity)
{
    m_settings->setValue("Parity", m_parity);
}

/**
 * @brief MngSPortSetting::getParity
 * @return QString
 */
QString MngSPortSetting::getParity() const
{
    return m_settings->value("Parity", defaulParity()).toString();
}

/**
 * @brief MngSPortSetting::defaulParity
 * @return
 */
QString MngSPortSetting::defaulParity()
{
    return "0";
}

/**
 * @brief MngSPortSetting::setStopBits
 * @param m_stopbits
 */
void MngSPortSetting::setStopBits(QString m_stopbits)
{
   m_settings->setValue("StopBits", m_stopbits);
}

/**
 * @brief MngSPortSetting::getStopBits
 * @return QString
 */
QString MngSPortSetting::getStopBits() const
{
    return m_settings->value("StopBits", defaulStopBits()).toString();
}

/**
 * @brief MngSPortSetting::defaulStopBits
 * @return QString
 */
QString MngSPortSetting::defaulStopBits()
{
    return "1";
}

/**
 * @brief MngSPortSetting::setFlowControl
 * @param m_flowcontrol
 */
void MngSPortSetting::setFlowControl(QString m_flowcontrol)
{
   m_settings->setValue("FlowControl", m_flowcontrol);
}

/**
 * @brief MngSPortSetting::getFlowControl
 * @return QString
 */
QString MngSPortSetting::getFlowControl() const
{
    return m_settings->value("FlowControl", defaulFlowControl()).toString();
}

/**
 * @brief MngSPortSetting::defaulFlowControl
 * @return QString
 */
QString MngSPortSetting::defaulFlowControl()
{
    return "0";
}
