#include "mainwindow.h"
//#include "settings/serialportsettings.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    a.setApplicationName("QtAppForCam-LSY201-TTL-INF");
    a.setOrganizationName("QtAppForCam-LSY201");//For create folder to settings

    //SerialPortSettings se_settings;
    //se_settings.show();

    w.show();

    return a.exec();
}
