#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "settings/serialportsettings.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class SerialPortSettings;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void runSerialPortSettings();
    void runMainSendToFirst();
  //  void receiveDataFromFirst();
    void receiveRequestFromFirst();

private:
    Ui::MainWindow *ui;
    SerialPortSettings *msportset;
};
#endif // MAINWINDOW_H
