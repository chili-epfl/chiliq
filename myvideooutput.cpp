#include "myvideooutput.h"
#include <iostream>

#include <QPainter>

#include <QVideoRendererControl>

MyVideoOutput::MyVideoOutput(QQuickItem *parent)
  :  QQuickPaintedItem(parent)
  , m_camera(0)
{
}

MyVideoOutput::~MyVideoOutput()
{
    freeResources();
}

void MyVideoOutput::freeResources()
{
    //if (m_myVideoSurface)
    //    m_myVideoSurface->stop();

    if (m_camera) {
        m_camera->stop();
        delete m_camera;
        m_camera = 0;
    }
}


void MyVideoOutput::paint(QPainter *painter) {
    painter->fillRect(0,0,100,200,QColor(255,0,0));
}

void MyVideoOutput::start()
{
    std::cout << "jkik" << std::endl;

    freeResources();

    m_camera = new QCamera(QCamera::availableDevices()[0]);
    m_camera->load();

    m_camera->start();
}
