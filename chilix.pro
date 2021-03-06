TEMPLATE = app

QT += qml quick widgets multimedia

HEADERS += \
    myvideosurface.h \
    frameobserver.h \
    chilitagscamera.h \
    configfinder.h

SOURCES += main.cpp \
    myvideosurface.cpp \
    chilitagscamera.cpp \
    configfinder.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

QMAKE_CXXFLAGS += -std=c++11

LIBS += -lopencv_core -lopencv_imgproc
LIBS += -lchilitags

OTHER_FILES += \
    android/AndroidManifest.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
    LIBS += -L$$PWD/android/libs/armeabi-v7a
    ANDROID_EXTRA_LIBS = \
        $$PWD/android/libs/armeabi-v7a/libopencv_core.so \
        $$PWD/android/libs/armeabi-v7a/libopencv_imgproc.so \
        $$PWD/android/libs/armeabi-v7a/libopencv_video.so \
        $$PWD/android/libs/armeabi-v7a/libopencv_highgui.so \
        $$PWD/android/libs/armeabi-v7a/libopencv_flann.so \
        $$PWD/android/libs/armeabi-v7a/libopencv_features2d.so \
        $$PWD/android/libs/armeabi-v7a/libopencv_calib3d.so \
        $$PWD/android/libs/armeabi-v7a/libchilitags.so
}
