import QtQuick 2.2
import QtQuick.Controls 1.1
import QtMultimedia 5.2
import Chilitags 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    ChilitagsCamera {
        id: chilitagsCamera
        x: 10
        y: 20
        width: 1600
        height: 1200
        Component.onCompleted: {
            chilitagsCamera.start();
        }
    }

    ConfigFinder {
        id: configFinder
        tags: chilitagsCamera.tags
    }

    Text {
        //text: qsTr(configFinder.config.toString())
        text: qsTr("kikoo");
        anchors.centerIn: parent
    }
}
