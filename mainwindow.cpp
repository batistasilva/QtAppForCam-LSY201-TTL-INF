#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // QObject::connect(
    //     ui->myActionSettings,          //Extance to Second Window
    //     SIGNAL(triggered(bool)),       //Signal to emit in Second Window
    //     this,                          //Extance to Main Window
    //     SLOT(runSerialPortSettings()));//Slot to Execute an Action in Main Window
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::runSerialPortSettings()
{
    SerialPortSettings msportset;
    //
    msportset.exec();
    msportset.show();

    qDebug() << "runSerialPortSettings() "<< "\n";
}

void MainWindow::runMngSerialCamData()
{
    qDebug() << "runMngSerialCamData() "<< "\n";
    MSerialPort mseport;
    //
    mseport.exec();
    mseport.show();
}
