#ifndef MYVIDEOOUTPUT_H
#define MYVIDEOOUTPUT_H

#include <QQuickPaintedItem>
#include <QCamera>
class MyVideoSurface;
#include "frameobserver.h"

#include <chilitags/chilitags.hpp>

class ChilitagsCamera : public QQuickPaintedItem, public FrameObserver
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QSize frameSize READ frameSize NOTIFY frameSizeChanged)

public:
    explicit ChilitagsCamera(QQuickItem *parent = 0);
    ~ChilitagsCamera();

    QString name() const {return m_name;}
    void setName(const QString &name) {m_name = name;}

    QSize frameSize() const {return m_frameSize;}

    void paint(QPainter *painter);

    virtual bool updateItem(const QVideoFrame &frame);

signals:
    void frameSizeChanged();

public slots:
    void start();

private:
    void freeResources();

    QString m_name;

    QCamera *m_camera;
    MyVideoSurface *m_myVideoSurface;

    cv::Mat m_gray, m_rgb;
    chilitags::Chilitags m_chilitags;

    QVideoFrame m_frame;
    QImage m_targetImage;
    QRect m_imageRect;
    QSize m_frameSize;
};

#endif // MYVIDEOOUTPUT_H
