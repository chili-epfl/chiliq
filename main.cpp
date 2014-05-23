#include <QApplication>
#include <QQmlApplicationEngine>

#include <iostream>

//#include <chilitags.hpp>
#include "myvideooutput.h"

int main(int argc, char *argv[])
{
    //chilitags::Chilitags chilitags;
    //auto test = chilitags.encode(0);
    //std::cout << test << "\n";

    QApplication app(argc, argv);

    qmlRegisterType<MyVideoOutput>("MyVideoOutput", 1, 0, "MyVideoOutput");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
