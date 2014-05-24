#include "myvideooutput.h"

#include <QPainter>
#include <QVideoRendererControl>
#include <myvideosurface.h>

#include <iostream>

MyVideoOutput::MyVideoOutput(QQuickItem *parent)
  :  QQuickPaintedItem(parent)
  , m_camera(0)
  , m_myVideoSurface(0)
{
}

MyVideoOutput::~MyVideoOutput()
{
    freeResources();
}

void MyVideoOutput::freeResources()
{
    if (m_myVideoSurface)
        m_myVideoSurface->stop();

    if (m_camera) {
        m_camera->stop();
        delete m_camera;
        m_camera = 0;
    }
}


void MyVideoOutput::paint(QPainter *painter) {
    painter->fillRect(0,0,100,200,QColor(255,0,0));
    m_imageRect.moveCenter(boundingRect().center().toPoint());
    painter->drawImage(m_imageRect.topLeft(), m_targetImage);
}

bool MyVideoOutput::updateItem(const QVideoFrame &frame)
{
    m_frame = frame;


    if (m_frame.map(QAbstractVideoBuffer::ReadOnly)) {
        if (m_frame.pixelFormat() == QVideoFrame::Format_UYVY) {
            m_yuv2Rgb.convert(m_frame.bits(), m_frame.width(), m_frame.height());
            std::cout << m_yuv2Rgb.width() << std::endl;

            m_targetImage = QImage(m_yuv2Rgb.bits(), m_yuv2Rgb.width(),
                                   m_yuv2Rgb.height(), m_yuv2Rgb.width() * 4,
                                   QImage::Format_RGB32);
        } else if (m_frame.pixelFormat() == QVideoFrame::Format_RGB32) {
            m_targetImage = QImage(m_frame.bits(), m_frame.width(),
                                   m_frame.height(), m_frame.bytesPerLine(),
                                   QImage::Format_RGB32);
        } else {

            m_targetImage = QImage();
        }

        update();

        m_imageRect = m_targetImage.rect();

        // TODO use image

        m_frame.unmap();
    }

    return true;
}

void MyVideoOutput::start()
{
    freeResources();

    m_camera = new QCamera(QCamera::availableDevices()[0]);
    m_camera->load();

    m_myVideoSurface = new MyVideoSurface(this, this);

    QMediaService *mediaService = m_camera->service();
    QVideoRendererControl *rendererControl = mediaService->requestControl<QVideoRendererControl *>();
    rendererControl->setSurface(m_myVideoSurface);

    m_camera->start();
}
