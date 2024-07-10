#ifndef VIDEOUTIL_H
#define VIDEOUTIL_H

#include <QtCore/QCoreApplication>
#include <QTextStream>
#include <QDataStream>
#include <QThread>
#include <QMutex>
#include <QBitArray>
#include <QFile>
#include <QList>
#include <QDir>
#include <QString>
#include <QDateTime>
#include <QObject>
#include <QImageReader>
#include <QVector>
#include "showmsg.h"
#include "globals.h"

//
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

class VideoUtil: public QThread
{
public:
    VideoUtil();

    void addNewImgToVideo();
    void addFrameToVideo(QVector<QImage> &img_list);
    QString  readHexFile();
    QVector<QImage>  loadImagesToList();
    QImage cleanDataGotFromPort(QString &data_str);
    QList<QString> readFileName();



private:
    //static QVector<QImage> from_hex_image_list;
    // QPixmap pixmap;

};

#endif // VIDEOUTIL_H
