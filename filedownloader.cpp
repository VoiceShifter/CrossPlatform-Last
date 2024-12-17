#include "filedownloader.h"
# include <thread>
# include <QFile>
FileDownloader::FileDownloader(QObject *parent)
    : QObject{parent}
{}

void FileDownloader::_BindConnect(QString imageUrl)
{
    connect(
        &fNetworkManager, SIGNAL (finished(QNetworkReply*)),
        this, SLOT (FileDownloaded(QNetworkReply*))
        );
    QNetworkRequest request(imageUrl);
    fNetworkManager.get(request);
}


QByteArray FileDownloader::getData()
{
    return fDownloadedData;
}

void FileDownloader::FileDownloaded(QNetworkReply *pReply)
{
    fDownloadedData = pReply->readAll();
    //emit a signal
    qDebug() << "FileDownloaded";
    QFile Save("./pic.jpg");
    Save.open(QIODevice::WriteOnly);
    Save.write(fDownloadedData);
    Save.close();
    pReply->deleteLater();
    emit _Downloaded();
}
