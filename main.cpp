#include <QApplication>
#include <QQmlApplicationEngine>

#include "chilitagscamera.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<ChilitagsCamera>("Chilitags", 1, 0, "ChilitagsCamera");


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
