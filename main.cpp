#include <QApplication>
#include <QQmlApplicationEngine>

#include <iostream>

#include <chilitags.hpp>

int main(int argc, char *argv[])
{
    chilitags::Chilitags chilitags;
    auto test = chilitags.encode(0);
    std::cout << test << "\n";

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
