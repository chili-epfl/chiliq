import QtQuick 2.2
import QtQuick.Controls 1.1
import QtMultimedia 5.2
import MyVideoOutput 1.0

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

    //Camera {
    //    id: camera
    //}

    //VideoOutput {
    //    source: camera
    //}

    MyVideoOutput {
        id: myVideoOutput
        Component.onCompleted: {
            myVideoOutput.start();
        }
    }

    Text {
        text: qsTr("kikoo")
        anchors.centerIn: parent
    }
}
