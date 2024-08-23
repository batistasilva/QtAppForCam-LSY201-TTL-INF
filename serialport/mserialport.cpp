#include "mserialport.h"
#include "ui_mserialport.h"


MSerialPort::MSerialPort(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MSerialPort)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);


    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
    //c
    // connect(ui->pbStopSaveToVideo, &QPushButton::clicked, [&]() {
    //     started = false;
    //     video.release();
    // });


    // QObject::connect(&timer, &QTimer::timeout, [&]() {

    //     // if(!qimg_to_pix.isNull()){
    //     //     frame = to_cvmat(qimg_to_pix);

    //     //     if (started) {
    //     //         video.write(frame);
    //     //     }

    //     //     QImage qimg(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_BGR888);

    //     //     ui->qlabelPic->setPixmap(QPixmap::fromImage(qimg));
    //     //     //ui->qlabelPic->show();
    //     // }
    // });


}

MSerialPort::~MSerialPort()
{
    delete ui;
}

void MSerialPort::openSerialPort()
{
    serial->setPortName("/dev/ttyACM0");
    serial->setBaudRate(QSerialPort::Baud19200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (serial->open(QIODevice::ReadWrite))
    {
        //Connected
        qDebug() << "Connected....";
    }
    else
    {
        //Open error
        qDebug() << "Open Error....";
    }
}

void MSerialPort::writeData(const QByteArray &data)
{
    serial->write(data, data.length());
}

/**
 * @brief MSerialPort::readData
 * read data from port..
 */
void MSerialPort::readData()
{
    //VideoUtil vutil;

    QByteArray data = serial->readAll();
    //
    QString qstr_data = QString(data);
    qDebug() << qstr_data;

    //Get a new image from hex
    //QImage new_img = vutil.cleanDataGotFromPort(qstr_data);

    //QMutexLocker locker(&mutex);

    //from_hex_image_list.push_back(new_img);

    //QMutexLocker unlock(&mutex);

    ui->pTEditCommand->insertPlainText(qstr_data);

    qDebug() << qstr_data;
}

/***
 * Send Command to Serial Port
 **/
void MSerialPort::sendCommand()
{
    //QByteArray data;

    QString strData = ui->leCommand->text();

    data = strData.toLatin1();

    if(serial->isReadable()){
        serial->write(data);
        qDebug() << "Sending Command...." << strData;
        ui->pTEditCommand->insertPlainText(strData);
    }else{
        qDebug() << "Port is not Opened to Write....";
    }
}

/**
 * @brief MSerialPort::getOnePic
 * Get one pic to Serial Port opened
 */
void MSerialPort::saveToImage()
{
    //QByteArray data;
    QString str_data_ui = getDataToUiPlainText();

    //Get QByteArray with data
    data = getDataToPic(str_data_ui);

    //qDebug() << data;

    QPixmap mpixmap(320,240);
    //QPixmap::scaled(const QSize &size, Qt::AspectRatioMode aspectRatioMode = Qt::IgnoreAspectRatio, Qt::TransformationMode transformMode = Qt::FastTransformation);

   // mpixmap.fill(QColor("white"));

    mpixmap.loadFromData(data);
    ui->qlabelPic->setPixmap(mpixmap);
    //  ui->mylabel->setText("Hello World");
    ui->qlabelPic->show();

    //Cleaning the QByteArray data
    data.clear();


    // string strStdData = strData.toStdString();
    // cout << strStdData << endl;

    // for (char a : strStdData) {
    //     cout << "-->>" << "Char: [";
    //     cout << a;
    //     cout << " ]";
    //     //
    //     cout << " Dec: [";
    //     cout << dec << (int) a;
    //     cout << "] " << " \t";
    //     //
    //     cout << "Hex: [";
    //     cout << hex << (int) a;
    //     cout << "]  " << "\n";
    // }

    // for (QChar a : strData) {
    //     //qDebug() << "Chars: -->> " << a;

    //     if (a == 10 || a == 13 ) {
    //         qDebug() << "Has Special Chars" << a;
    //         qDebug() << "Has Special Chars" << a.toLatin1();
    //     }
    //     // myImgStr.append(a);

    // }
    //qDebug() << "Getting one Pic...." << strData;
}
/**
 * @brief MSerialPort::saveToVideo
 * Get data serial image to save frame
 * to a video.
 */
void MSerialPort::saveToVideo()
{
    VideoUtil vutil;
    QVector<QImage> qimage_list;

    // QMutexLocker locker(&mutex);

    if(from_hex_image_list.size() > 0){
        qDebug() << "List from port size...." << from_hex_image_list.length();
        qimage_list = from_hex_image_list;
        from_hex_image_list.clear();
        qDebug() << "List from port after...." << from_hex_image_list.length();
        qDebug() << "My new list size...." << qimage_list.length();
    }
    // QMutexLocker unlock(&mutex);

    vutil.addFrameToVideo(qimage_list);

    //make video without worrying


}

void MSerialPort::stopSaveToVideo()
{
    // started = false;
    // video.release();
}

/**
 * @brief MSerialPort::runConnect
 * Make connect to serial port
 */
void MSerialPort::runConnect()
{
    qDebug() << "Connecting to Serial Port....";
    openSerialPort();
    if(serial->isOpen()){
        ui->lineEditStatus->setText("The Port is Opened...");
    }else{
        ui->lineEditStatus->setText("The Port is Closed...");
    }
}

void MSerialPort::runCleanArea()
{
   ui->pTEditCommand->clear();
}


void MSerialPort::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        closeSerialPort();
    }
}

void MSerialPort::showStatusMessage(const QString &message)
{
    qDebug() << message;
}

void MSerialPort::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();


    showStatusMessage(tr("Disconnected"));
}

QByteArray MSerialPort::getDataToPic(QString &data_str)
{
    QString dataToPic;
    //QByteArray data;
    bool startRead =false;


    for (char a: data_str.toStdString()) {
        if(a == 64)
            startRead = true;
        if(a == 35)
            startRead = false;

        if(a == 10 || a == 13 || a == 64 || a == 35){
            qDebug() << "Ignore char a --->> " << a;
        }else{

            if(startRead == true) dataToPic.append(a);
        }

        qDebug() << "Char --->> " << a;

    }

    qDebug() << "Data to Pic --->> " << dataToPic;

    data = QByteArray::fromHex(dataToPic.toLatin1());

    return data;
}

QImage MSerialPort::getQImageFromPixmap()
{
    QPixmap mpixmap(320,240);
    QByteArray data_img;

    //QPixmap::scaled(const QSize &size, Qt::AspectRatioMode aspectRatioMode = Qt::IgnoreAspectRatio, Qt::TransformationMode transformMode = Qt::FastTransformation);
    // mpixmap.fill(QColor("white"));
    QString str_data = getDataToUiPlainText();

    data_img = getDataToPic(str_data);

    mpixmap.loadFromData(data_img);

    return mpixmap.toImage();
}

QString MSerialPort::getDataToUiPlainText()
{
    QString strData = ui->pTEditCommand->toPlainText();
    return strData;
}
