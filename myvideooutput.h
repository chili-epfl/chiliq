#ifndef MYVIDEOOUTPUT_H
#define MYVIDEOOUTPUT_H

#include <QQuickPaintedItem>
#include <QCamera>

class MyVideoOutput : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)

public:
    explicit MyVideoOutput(QQuickItem *parent = 0);
    ~MyVideoOutput();

    QString name() const {return m_name;}
    void setName(const QString &name) {m_name = name;}

    void paint(QPainter *painter);

signals:

public slots:
    void start();

private:
    void freeResources();

    QString m_name;
    QCamera *m_camera;

};

#endif // MYVIDEOOUTPUT_H
