#include "videoutil.h"

using namespace std;

QString strHexPic;

cv::Mat to_cvmat(QImage img)
{
    img = img.convertToFormat(QImage::Format_RGB888, Qt::ColorOnly).rgbSwapped();
    return cv::Mat(img.height(), img.width(), CV_8UC3, img.bits(), img.bytesPerLine()).clone();
}

VideoUtil::VideoUtil() {


}

/**
 * @brief VideoUtil::addNewImgToVideo
 * Create a new Video and add images from
 * disk to new video in a folder.
 */
void VideoUtil::addNewImgToVideo(){

    QSize size(320, 240);
    QVector<QImage> img_list;
    cv::Mat frame;
    cv::VideoWriter video;

    img_list = loadImagesToList();

    int fps = 5;
    int codec = cv::VideoWriter::fourcc('m', 'p', '4', 'v');

    //Save to video
    // video.open("out.mp4", cv::CAP_FFMPEG, codec, fps, cv::Size(size.width(), size.height()));
    video.open("my-video-out.mp4"
               ,codec
               ,fps
               ,cv::Size(size.width() ,size.height())
               , 1);

    foreach (auto img, img_list) {

        if(!img.isNull()){
            frame = to_cvmat(img);
            video.write(frame);
            cv::waitKey(1000/fps);
        }
    }

    video.release();

}

/**
 * @brief VideoUtil::addFrameToVideo
 * Create a new Video or add frame to
 * existent video in a folder.
 */
void VideoUtil::addFrameToVideo(QVector<QImage> &img_list)
{
    QSize size(320, 240);

    cv::Mat frame;
    cv::VideoWriter video;

    int fps = 5;
    int codec = cv::VideoWriter::fourcc('m', 'p', '4', 'v');

    video.open("my-video-out.mp4"
               ,codec
               ,fps
               ,cv::Size(size.width() ,size.height())
               , 1);

    foreach (auto img, img_list) {
        qDebug() <<"Img..." << "\n";

        if(!img.isNull()){
            frame = to_cvmat(img);
            video.write(frame);
            cv::waitKey(1000/fps);
        }
    }

    video.release();
}

/**
 * @brief VideoUtil::readFileName
 * Read an image filename to generate
 * a video.
 * @return
 */
QList<QString> VideoUtil::readFileName()
{
    QList<QString> file_list;
    QString str_path = "/home/system/WorkSpace/QtProjects/QtVideo/Images/";
    QString file_type;

    QDir dir(str_path);

    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir.setSorting(QDir::Size | QDir::Reversed);

    QFileInfoList list = dir.entryInfoList();
    qDebug() << "     Bytes Filename";
    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list.at(i);

        file_type = fileInfo.suffix();
        if(file_type == "png")
            file_list.push_back(str_path + fileInfo.fileName());

        qDebug()<<"File Name: " << fileInfo.fileName() <<"Size: " << fileInfo.size() << "Type: " << file_type;
        qDebug() << "\n";
    }

    foreach (auto str, file_list) {
        qDebug()<<"File Name: " << str;
    }

    return file_list;
}

/**
 * @brief VideoUtil::readHexFile
 * Read an Image Hex file to make one
 * jpg Pic
 * @return QString
 */
QString VideoUtil::readHexFile()
{
    QString myImgStr;

    QFile file("/home/system/WorkSpace/QtProjects/QtImage/QtAppWithImg/myHexPic.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        //QStringList fields = line.split(",");
        qDebug() << line;
        myImgStr +=line;
    }

    strHexPic = myImgStr;

    file.close();

    return myImgStr;
}



QVector<QImage> VideoUtil::loadImagesToList()
{
    QList<QString> file_list;
    QVector<QImage>  img_list;

    file_list = readFileName();
    QImage img_read;
    // reader.format() == "png"

    foreach(auto img_file, file_list){
        img_read.load(img_file);
        img_list.push_back(img_read);
    }

    return img_list;
}

/**
 * @brief VideoUtil::cleanDataGotFromPort
 * @param data_str
 * @return  QImage
 */
QImage VideoUtil::cleanDataGotFromPort(QString &data_str)
{
    QString dataToPic;

    bool startRead =false;


    for (auto a: data_str.toStdString()) {
        if(a == 64)
            startRead = true;//Start == @
        if(a == 35)
            startRead = false;//End == #

        if(a == 10 || a == 13 || a == 64 || a == 35){
            qDebug() << "Ignore char a --->> " << a;
        }else{

            if(startRead == true) dataToPic.append(a);
        }

        qDebug() << "Char --->> " << a;

    }

    qDebug() << "Data to Pic --->> " << dataToPic;

    QByteArray data = QByteArray::fromHex(dataToPic.toLatin1());

    QImage qimg = QImage::fromData(data);

    return qimg;
}
