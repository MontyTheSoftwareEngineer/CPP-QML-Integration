import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import Monty 1.0

Window {
    width: 1024
    height: 680
    visible: true
    title: qsTr("Hello World")

    SomeClass {
        id: myClass
    }

    Connections {
        target: myClass
        onSomeVarChanged: myLabel.text = myClass.getSomeVar()
    }

    Button {
        id: myButton
        anchors.centerIn: parent
        text: "Click Me"
        onClicked: myClass.setSomeVar("ABC")
    }

    Text {
        id: myLabel
        anchors {
            top: parent.top
            horizontalCenter: parent.horizontalCenter
            topMargin: 20
        }
        font.pixelSize: 24
        text: myClass.getSomeVar()
    }
}
