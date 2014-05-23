#ifndef MYVIDEOOUTPUT_H
#define MYVIDEOOUTPUT_H

#include <QQuickPaintedItem>

class MyVideoOutput : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)

public:
    explicit MyVideoOutput(QQuickItem *parent = 0);

    QString name() const {return m_name;}
    void setName(const QString &name) {m_name = name;}

    void paint(QPainter *painter) {}

signals:

public slots:

private:
    QString m_name;

};

#endif // MYVIDEOOUTPUT_H
