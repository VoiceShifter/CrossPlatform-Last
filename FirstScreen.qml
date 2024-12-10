import QtQuick

Item{
    id: _MainScreen
    Rectangle
    {
        id: _Background
        z: -1
        anchors.fill: parent
        //color: "transperent"
        Text {
            id: _Text

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 50
            text: qsTr("FirstScreen")
        }
        Rectangle
        {
            id: _Button01
            border.color: "black"
            border.width: 1
            anchors.top: parent.top
            anchors.left: parent.left
            width: 40
            height: 40
            radius: 60
        }
        Rectangle
        {

            id: _Button02
            border.color: "black"
            border.width: 1
            anchors.top: parent.top
            anchors.right: parent.right
            width: 40
            height: 40
            radius: 60
            MouseArea
            {
                anchors.fill: parent
                onClicked:
                {
                    _Stack.push("SecondScreen.qml")
                    console.log("From first to second")
                }
            }
        }
        Rectangle
        {
            id: _Picture
            width: parent.width
            height: parent.height - parent.height/5
            color: "black"
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
