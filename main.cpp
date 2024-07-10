#include "mainwindow.h"

#include <QApplication>
#include "settings/serialportsettings.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    SerialPortSettings se_setting;
    se_setting.populateSerialPort();
    se_setting.populateBaudRate();
    se_setting.populateDataBits();
    se_setting.populateParity();
    se_setting.populateStopBits();
    se_setting.populateFlowControl();

    se_setting.show();
    return a.exec();
}
