#include "serialportsettings.h"
#include "settings/ui_serialportsettings.h"

SerialPortSettings::SerialPortSettings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SerialPortSettings)
{
    ui->setupUi(this);

}

SerialPortSettings::~SerialPortSettings()
{
    delete ui;
}

void SerialPortSettings::loadAppSettings()
{
    // MngSPortSetting app_setting;
    // portname = app_setting.getSerialPort();
    // baudrate = app_setting.getBaudRate().toInt();
    // databits = app_setting.getDataBits().toInt();
    // parity   = app_setting.getParity().toInt();
    // stopbits = app_setting.getStopBits().toInt();
    // flowcontrol = app_setting.getFlowControl().toInt();

}

/**
 * @brief SerialPortSettings::populateSerialPort
 * Populate the Combobox with the serial port
 * available on the System.
 */
void SerialPortSettings::populateSerialPort()
{
    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &portInfo : serialPortInfos) {
        ui->cbBoxSPortName->addItem(portInfo.systemLocation());
        ui->cbBoxSPortName->setStyleSheet("QComboBox {padding-left: 30px;}");

        // qDebug() << "\n"
        //          << "Port:" << portInfo.portName() << "\n"
        //          << "Location:" << portInfo.systemLocation() << "\n"
        //          << "Description:" << portInfo.description() << "\n"
        //          << "Manufacturer:" << portInfo.manufacturer() << "\n"
        //          << "Serial number:" << portInfo.serialNumber() << "\n"
        //          << "Vendor Identifier:"
        //          << (portInfo.hasVendorIdentifier()
        //                  ? QByteArray::number(portInfo.vendorIdentifier(), 16)
        //                  : QByteArray()) << "\n"
        //          << "Product Identifier:"
        //          << (portInfo.hasProductIdentifier()
        //                  ? QByteArray::number(portInfo.productIdentifier(), 16)
        //                  : QByteArray());
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
    QList<QList<QString>> br_list = {{"Baud1200","1200"},{"Baud2400","2400"}, {"Baud4800","4800"}, {"Baud9600","9600"}, {"Baud19200","19200"}, {"Baud38400","38400"}, {"Baud57600","57600"}, {"Baud115200","115200"}};

    for(int i=0; i<br_list.length(); i++) {
        ui->cbBoxSBaudRate->addItem(br_list.at(i).at(0));
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
    QList<QList<QString>> dbt_list = {{"Data5","5"},{"Data6","6"}, {"Data7","7"}, {"Data8","8"}};

    for(int i=0; i < dbt_list.length(); i++) {
        QString item = dbt_list.at(i).at(0);
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
    QList<QList<QString>> pry_list = {
        {"NoParity","0"},
        {"EvenParity","2"},
        {"OddParity","3"},
        {"SpaceParity","4"},
        {"MarkParity","5"}};

    for(int i=0; i < pry_list.length(); i++) {
        QString item = pry_list.at(i).at(0);
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
    QList<QList<QString>> stpb_list = {
                                      {"OneStop","1"},
                                      {"OneAndHalfStop","3"},
                                      {"TwoStop","2"}};

    for(int i=0; i < stpb_list.length(); i++) {
        QString item = stpb_list.at(i).at(0);
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
    QList<QList<QString>> flowc_list = {
                                       {"NoFlowControl............","0"},
                                       {"HardwareControl(RTS/CTS).","1"},
                                       {"SoftwareControl(XON/XOFF)","2"}};

    for(int i=0; i < flowc_list.length(); i++) {
        QString item = flowc_list.at(i).at(0);
        // qDebug() << item << "\n";
        ui->cbBoxSPFlowControl->addItem(item);
        ui->cbBoxSPFlowControl->setStyleSheet("QComboBox {padding-left: 30px;}");
    }
}

QSerialPort::DataBits SerialPortSettings::getMDataBits(const qint8 mdatabits)
{
    if(mdatabits == 5) return QSerialPort::Data5;
    if(mdatabits == 6) return QSerialPort::Data6;
    if(mdatabits == 7) return QSerialPort::Data7;
    if(mdatabits == 8) return QSerialPort::Data8;
}

QSerialPort::Parity SerialPortSettings::getMDataParity(const qint8 mdataparity)
{
    if(mdataparity == 0) return QSerialPort::NoParity;
    if(mdataparity == 2) return QSerialPort::EvenParity;
    if(mdataparity == 3) return QSerialPort::OddParity;
    if(mdataparity == 4) return QSerialPort::SpaceParity;
    if(mdataparity == 5) return QSerialPort::MarkParity;
}

QSerialPort::StopBits SerialPortSettings::getMStopBits(const qint8 mstopbits)
{
    if(mstopbits == 1) return QSerialPort::OneStop;
    if(mstopbits == 3) return QSerialPort::OneAndHalfStop;
    if(mstopbits == 2) return QSerialPort::TwoStop;
}

QSerialPort::FlowControl SerialPortSettings::getMFlowControl(const qint8 mflowctrol)
{
    if(mflowctrol == 0) return QSerialPort::NoFlowControl;
    if(mflowctrol == 1) return QSerialPort::HardwareControl;
    if(mflowctrol == 2) return QSerialPort::SoftwareControl;
}

void SerialPortSettings::runConfigTest()
{
    qDebug() << "Run Config Test()" << "\n";
    QSerialPort serial;

    // serial.setPortName(currentPortName);
    // serial.setBaudRate(serial.Baud19200);
    serial.setPortName(ui->cbBoxSPortName->currentText());
    serial.setBaudRate(ui->cbBoxSBaudRate->currentText().toInt());

    databits = ui->cbBoxSPDataBits->currentText().toInt();
    serial.setDataBits(getMDataBits(databits));

    parity = ui->cbBoxSPParity->currentText().toInt();
    serial.setParity(getMDataParity(parity));

    stopbits = ui->cbBoxSPStopBits->currentText().toInt();
    serial.setStopBits(getMStopBits(stopbits));

    flowcontrol = ui->cbBoxSPFlowControl->currentText().toInt();
    serial.setFlowControl(getMFlowControl(flowcontrol));


    if (!serial.open(QIODevice::ReadWrite)) {
        qDebug() << tr("Can't open %1, error code %2").arg(ui->cbBoxSPortName->currentText()).arg(serial.error());
        return;
    }else{
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


