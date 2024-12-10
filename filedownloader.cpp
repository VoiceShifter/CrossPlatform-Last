#include "filedownloader.h"
# include <thread>
FileDownloader::FileDownloader(QObject *parent)
    : QObject{parent}
{}

void FileDownloader::_BindConnect(QString imageUrl)
{
    connect(
        &fNetworkManager, SIGNAL (finished(QNetworkReply*)),
        this, SLOT (FileDownloaded(QNetworkReply*))
        );
    std::thread SomeThread([&]{
    QNetworkRequest request(imageUrl);
    fNetworkManager.get(request);
    });
    SomeThread.detach();
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
    pReply->deleteLater();
    emit _Downloaded();
}
