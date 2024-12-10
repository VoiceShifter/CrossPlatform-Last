#ifndef FILEDOWNLOADER_H
#define FILEDOWNLOADER_H

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class FileDownloader : public QObject
{
    Q_OBJECT
public:
    explicit FileDownloader(QObject *parent = nullptr);
    Q_INVOKABLE void _BindConnect(QString imageUrl);
    QByteArray downloadedData() const;
    QNetworkAccessManager fNetworkManager;
    QByteArray fDownloadedData;
    Q_INVOKABLE QByteArray getData();
signals:
    void _Downloaded();
private slots:
    void FileDownloaded(QNetworkReply* pReply);

};

#endif // FILEDOWNLOADER_H
