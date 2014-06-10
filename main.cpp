#include <QApplication>
#include <QQmlApplicationEngine>

#include "myvideooutput.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<MyVideoOutput>("MyVideoOutput", 1, 0, "MyVideoOutput");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
