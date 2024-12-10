#include <QGuiApplication>
#include <QQmlApplicationEngine>
# include "filedownloader.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/Downloader/Main.qml"));
    qmlRegisterType<FileDownloader>("com.Downloader", 1, 0, "Downloader");
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
