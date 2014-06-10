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
        onInputUpdate: {
            if (isPresent("tag_64")) console.log("64:" + transform("tag_64"));
            console.log(tagIds());
        }
    }

    Text {
        text: qsTr("kikoo")
        anchors.centerIn: parent
    }
}
