#include "serialportsettings.h"
#include "settings/ui_serialportsettings.h"

SerialPortSettings::SerialPortSettings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SerialPortSettings)
{
    ui->setupUi(this);
    populateAllCombobox();
    //
    loadAppSettings();
}

SerialPortSettings::~SerialPortSettings()
{
    delete ui;
}

void SerialPortSettings::loadAppSettings()
{
    // MngSPortSetting app_setting;
    // General settings
    const MngSPortSetting settings;

    QString cPortName = settings.getSerialPort();
    qDebug() << "Port Name: "<< cPortName << "\n";
    ui->cbBoxSPortName->setCurrentIndex(ui->cbBoxSPortName->findText(cPortName));

    QString cBaudRate = settings.getBaudRate();
    qDebug() << "BaudRate : "<< cBaudRate << "\n";
    ui->cbBoxSBaudRate->setCurrentIndex(ui->cbBoxSBaudRate->findText(cBaudRate));

    QString cDataBits = settings.getDataBits();
    qDebug() << "DataBits : "<< cDataBits << "\n";
    ui->cbBoxSPDataBits->setCurrentIndex(ui->cbBoxSPDataBits->findText(cDataBits));

    QString cParity = settings.getParity();
    qDebug() << "Parity : "<< cParity << "\n";
    ui->cbBoxSPParity->setCurrentIndex(ui->cbBoxSPParity->findText(cParity));

    QString cStopBits = settings.getStopBits();
    qDebug() << "StopBits : "<< cStopBits << "\n";
    ui->cbBoxSPStopBits->setCurrentIndex(ui->cbBoxSPStopBits->findText(cStopBits));

    QString cFlowControl = settings.getFlowControl();
    qDebug() << "FlowControl : "<< cFlowControl << "\n";
    ui->cbBoxSPFlowControl->setCurrentIndex(ui->cbBoxSPFlowControl->findText(cFlowControl));

}

/**
 * @brief SerialPortSettings::populateSerialPort
 * Populate the Combobox with the serial port
 * available on the System.
 */
void SerialPortSettings::populateSerialPort()
{
    // Default settings
    MngSPortSetting app_settings;
    // populateAllCombobox();

    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    ui->cbBoxSPortName->clear();
    int i=0;
    for (const QSerialPortInfo &portInfo : serialPortInfos) {
        QString item = portInfo.systemLocation();
        ui->cbBoxSPortName->addItem(item, i);
        ui->cbBoxSPortName->setStyleSheet("QComboBox {padding-left: 30px;}");
        i++;
    }
    //If an active serial port is not found, enter to add the default port
    if(i == 0){
        QString cPortName = app_settings.getSerialPort();
        qDebug() << "Port Name: "<< cPortName << "\n";

        ui->cbBoxSPortName->addItem(cPortName, 1);
        ui->cbBoxSPortName->setStyleSheet("QComboBox {padding-left: 30px;}");
    }

}

/**
 * @brief SerialPortSettings::populateBaudRate
 * This enum describes the baud rate which the communication device operates with.
 * Note: Only the most common standard baud rates are listed in this enum.
 * Constant	Value	Description
 * QSerialPort::Baud1200	1200	1200 baud.
 * QSerialPort::Baud2400	2400	2400 baud.
 * QSerialPort::Baud4800	4800	4800 baud.
 * QSerialPort::Baud9600	9600	9600 baud.
 * QSerialPort::Baud19200	19200	19200 baud.
 * QSerialPort::Baud38400	38400	38400 baud.
 * QSerialPort::Baud57600	57600	57600 baud.
 * QSerialPort::Baud115200	115200	115200 baud.
 */
void SerialPortSettings::populateBaudRate()
{
    QList<QString> br_list = {"Baud1200",
                                     "Baud2400",
                                     "Baud4800",
                                     "Baud9600",
                                     "Baud19200",
                                     "Baud38400",
                                     "Baud57600",
                                     "Baud115200"};
    ui->cbBoxSBaudRate->clear();

    for(int i=0; i<br_list.length(); i++) {
        QString item = br_list.at(i);
        ui->cbBoxSBaudRate->addItem(item, i);
        ui->cbBoxSBaudRate->setStyleSheet("QComboBox {padding-left: 50px;}");
    }

}
/**
 * @brief SerialPortSettings::populateDataBits
 *
 * QSerialPort::Data5	5	The number of data bits in each character is 5.
 * It is used for Baudot code. It generally only makes sense with older equipment
 * such as teleprinters.
 * QSerialPort::Data6	6	The number of data bits in each character is 6.
 * It is rarely used.
 * QSerialPort::Data7	7	The number of data bits in each character is 7.
 * It is used for true ASCII. It generally only makes sense with older equipment
 * such as teleprinters.
 * QSerialPort::Data8	8	The number of data bits in each character is 8.
 * It is used for most kinds of data, as this size matches the size of a byte.
 * It is almost universally used in newer applications.
 */
void SerialPortSettings::populateDataBits()
{
    QList<QString> dbt_list = {"Data5",
                                      "Data6",
                                      "Data7",
                                      "Data8"};
    ui->cbBoxSPDataBits->clear();

    for(int i=0; i < dbt_list.length(); i++) {
        QString item = dbt_list.at(i);
        // qDebug() << item << "\n";
        ui->cbBoxSPDataBits->addItem(item);
        ui->cbBoxSPDataBits->setStyleSheet("QComboBox {padding-left: 50px;}");
    }
}

/**
 * @brief SerialPortSettings::populateParity
 * This enum describes the parity scheme used.
 * Constant	Value	Description
 * QSerialPort::NoParity	0	No parity bit it sent. This is the most common
 * parity setting. Error detection is handled by the communication protocol.
 * QSerialPort::EvenParity	2	The number of 1 bits in each character, including
 * the parity bit, is always even.
 * QSerialPort::OddParity	3	The number of 1 bits in each character, including
 * the parity bit, is always odd. It ensures that at least one state transition
 * occurs in each character.
 * QSerialPort::SpaceParity	4	Space parity. The parity bit is sent in the space
 * signal condition. It does not provide error detection information.
 * QSerialPort::MarkParity	5	Mark parity. The parity bit is always set to the
 * mark signal condition (logical 1). It does not provide error detection
 * information.
 */
void SerialPortSettings::populateParity()
{
    QList<QString> pry_list = {"NoParity",
                                      "EvenParity",
                                      "OddParity",
                                      "SpaceParity",
                                      "MarkParity"};
    ui->cbBoxSPParity->clear();

    for(int i=0; i < pry_list.length(); i++) {
        QString item = pry_list.at(i);
        // qDebug() << item << "\n";
        ui->cbBoxSPParity->addItem(item);
        ui->cbBoxSPParity->setStyleSheet("QComboBox {padding-left: 50px;}");
    }
}

/**
 * @brief SerialPortSettings::populateStopBits
 * This enum describes the number of stop bits used.
 * Constant	Value	Description
 * QSerialPort::OneStop	1	1 stop bit.
 * QSerialPort::OneAndHalfStop	3	1.5 stop bits. This is only for the Windows
 * platform.
 * QSerialPort::TwoStop	2	2 stop bits.
 *
 */
void SerialPortSettings::populateStopBits()
{
    QList<QString> stpb_list = {"OneStop","OneAndHalfStop","TwoStop"};

    ui->cbBoxSPStopBits->clear();

    for(int i=0; i < stpb_list.length(); i++) {
        QString item = stpb_list.at(i);
        // qDebug() << item << "\n";
        ui->cbBoxSPStopBits->addItem(item);
        ui->cbBoxSPStopBits->setStyleSheet("QComboBox {padding-left: 50px;}");
    }
}

/**
 * @brief SerialPortSettings::populateFlowControl
 * This enum describes the flow control used.
 * Constant	Value	Description
 * QSerialPort::NoFlowControl	0	No flow control.
 * QSerialPort::HardwareControl	1	Hardware flow control (RTS/CTS).
 * QSerialPort::SoftwareControl	2	Software flow control (XON/XOFF).
 *
 */
void SerialPortSettings::populateFlowControl()
{
    QList<QString> flowc_list = {"NoFlowControl............"
                                        ,"HardwareControl(RTS/CTS)."
                                        , "SoftwareControl(XON/XOFF)"};
    ui->cbBoxSPFlowControl->clear();

    for(int i=0; i < flowc_list.length(); i++) {
        QString item = flowc_list.at(i);
        // qDebug() << item << "\n";
        ui->cbBoxSPFlowControl->addItem(item);
        ui->cbBoxSPFlowControl->setStyleSheet("QComboBox {padding-left: 30px;}");
    }
}

void SerialPortSettings::populateAllCombobox()
{
    populateSerialPort();
    populateBaudRate();
    populateDataBits();
    populateParity();
    populateStopBits();
    populateFlowControl();
}

/**
 *
    Note: Only the most common standard baud rates are listed in this enum.
    Constant	Value	Description
    QSerialPort::Baud1200	1200	1200 baud.
    QSerialPort::Baud2400	2400	2400 baud.
    QSerialPort::Baud4800	4800	4800 baud.
    QSerialPort::Baud9600	9600	9600 baud.
    QSerialPort::Baud19200	19200	19200 baud.
    QSerialPort::Baud38400	38400	38400 baud.
    QSerialPort::Baud57600	57600	57600 baud.
    QSerialPort::Baud115200	115200	115200 baud.
 * @brief SerialPortSettings::getMBaudRate
 * @param mbaudrate
 * @return
 */
QSerialPort::BaudRate SerialPortSettings::getMBaudRate(const QString mbaudrate)
{
    if(mbaudrate == "Baud1200") return QSerialPort::Baud1200;
    if(mbaudrate == "Baud2400") return QSerialPort::Baud2400;
    if(mbaudrate == "Baud4800") return QSerialPort::Baud4800;
    if(mbaudrate == "Baud9600") return QSerialPort::Baud9600;
    if(mbaudrate == "Baud19200") return QSerialPort::Baud19200;
    if(mbaudrate == "Baud38400") return QSerialPort::Baud38400;
    if(mbaudrate == "Baud57600") return QSerialPort::Baud57600;
    if(mbaudrate == "Baud115200") return QSerialPort::Baud115200;
}

QSerialPort::DataBits SerialPortSettings::getMDataBits(const QString mdatabits)
{
    if(mdatabits == "Data5") return QSerialPort::Data5;
    if(mdatabits == "Data6") return QSerialPort::Data6;
    if(mdatabits == "Data7") return QSerialPort::Data7;
    if(mdatabits == "Data8") return QSerialPort::Data8;
}

QSerialPort::Parity SerialPortSettings::getMDataParity(const QString mdataparity)
{
    if(mdataparity == "NoParity") return QSerialPort::NoParity;
    if(mdataparity == "EvenParity") return QSerialPort::EvenParity;
    if(mdataparity == "OddParity") return QSerialPort::OddParity;
    if(mdataparity == "SpaceParity") return QSerialPort::SpaceParity;
    if(mdataparity == "MarkParity") return QSerialPort::MarkParity;
}

QSerialPort::StopBits SerialPortSettings::getMStopBits(const QString mstopbits)
{
    if(mstopbits == "OneStop") return QSerialPort::OneStop;
    if(mstopbits == "OneAndHalfStop") return QSerialPort::OneAndHalfStop;
    if(mstopbits == "TwoStop") return QSerialPort::TwoStop;
}

QSerialPort::FlowControl SerialPortSettings::getMFlowControl(const QString mflowctrol)
{
    if(mflowctrol.contains("NoFlowControl")) return QSerialPort::NoFlowControl;
    if(mflowctrol.contains("HardwareControl")) return QSerialPort::HardwareControl;
    if(mflowctrol.contains("SoftwareControl")) return QSerialPort::SoftwareControl;
}

void SerialPortSettings::runConfigTest()
{
    qDebug() << "Run Config Test()" << "\n";

    QSerialPort serial;

    QString curretPorName = ui->cbBoxSPortName->currentText();
    qDebug() << "Port Name: " << curretPorName;
    serial.setPortName(curretPorName);

    QString cBaudRate = ui->cbBoxSBaudRate->currentText();
    qDebug() << "BaudRate: " << cBaudRate;
    serial.setBaudRate(getMBaudRate(cBaudRate));

    QString cDataBits = ui->cbBoxSPDataBits->currentText();
    qDebug() << "DataBits: " << cDataBits;
    serial.setDataBits(getMDataBits(cDataBits));

    QString cParity = ui->cbBoxSPParity->currentText();
    qDebug() << "Parity: " << cParity;
    serial.setParity(getMDataParity(cParity));

    QString cStopBits = ui->cbBoxSPStopBits->currentText();
    qDebug() << "StopBits: " << cStopBits;
    serial.setStopBits(getMStopBits(cStopBits));

    QString cFlowControl = ui->cbBoxSPFlowControl->currentText();
    qDebug() << "FlowControl: " << cFlowControl;
    serial.setFlowControl(getMFlowControl(cFlowControl));


    if (!serial.open(QIODevice::ReadWrite)) {
        qDebug() << tr("Can't open %1, error code %2").arg(ui->cbBoxSPortName->currentText()).arg(serial.error());
        ui->toolBSPSettingSave->setEnabled(false);
        return;
    }else{
        ui->toolBSPSettingSave->setEnabled(true);
        qDebug() << "Serial Port Opened Successfully..." << "\n";
    }


    serial.close();

}

void SerialPortSettings::runSaveConfig()
{
    qDebug() << "Run Save Config()" << "\n";

    MngSPortSetting app_setting;

    app_setting.setSerialPort(ui->cbBoxSPortName->currentText());
    app_setting.setBaudRate(ui->cbBoxSBaudRate->currentText());
    app_setting.setDataBits(ui->cbBoxSPDataBits->currentText());
    app_setting.setParity(ui->cbBoxSPParity->currentText());
    app_setting.setStopBits(ui->cbBoxSPStopBits->currentText());
    app_setting.setFlowControl(ui->cbBoxSPFlowControl->currentText());

}

void SerialPortSettings::restoreDefaultConfig()
{
    // Default settings
    MngSPortSetting app_settings;
   // populateAllCombobox();

    QString cPortName = app_settings.getSerialPort();
    qDebug() << "Port Name: "<< cPortName << "\n";

    QString cBaudRate = app_settings.getBaudRate();
    qDebug() << "BaudRate : "<< cBaudRate << "\n";

    QString cDataBits = app_settings.getDataBits();
    qDebug() << "DataBits : "<< cDataBits << "\n";

    QString cParity = app_settings.getParity();
    qDebug() << "Parity : "<< cParity << "\n";

    QString cStopBits = app_settings.getStopBits();
    qDebug() << "StopBits : "<< cStopBits << "\n";

    QString cFlowControl = app_settings.getFlowControl();
    qDebug() << "FlowControl : "<< cFlowControl << "\n";

    qDebug() << "Port Name: "<< cPortName << "\n";
    ui->cbBoxSPortName->setCurrentIndex(ui->cbBoxSPortName->findText(cPortName));

    qDebug() << "BaudRate : "<< cBaudRate << "\n";
    ui->cbBoxSBaudRate->setCurrentIndex(ui->cbBoxSBaudRate->findText(cBaudRate));

    qDebug() << "DataBits : "<< cDataBits << "\n";
    ui->cbBoxSPDataBits->setCurrentIndex(ui->cbBoxSPDataBits->findText(cDataBits));

    qDebug() << "Parity : "<< cParity << "\n";
    ui->cbBoxSPParity->setCurrentIndex(ui->cbBoxSPParity->findText(cParity));

    qDebug() << "StopBits : "<< cStopBits << "\n";
    ui->cbBoxSPStopBits->setCurrentIndex(ui->cbBoxSPStopBits->findText(cStopBits));

    qDebug() << "FlowControl : "<< cFlowControl << "\n";
    ui->cbBoxSPFlowControl->setCurrentIndex(ui->cbBoxSPFlowControl->findText(cFlowControl));

    app_settings.setSerialPort(cPortName);
    app_settings.setBaudRate(cBaudRate);
    app_settings.setDataBits(cDataBits);
    app_settings.setParity(cParity);
    app_settings.setStopBits(cStopBits);
    app_settings.setFlowControl(cFlowControl);

    qDebug() << "Restore Default Config()" << "\n";

}


