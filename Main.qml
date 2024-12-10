import QtQuick
import QtQuick.Controls 2.15
import com.Downloader
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Downloader
    {
        id: _Downloader
        Component.onCompleted:
        {
            console.log("Binding")
            _Downloader._BindConnect("https://www.tlock.ru/photo_bank/46959_01.jpg")
        }
    }

    StackView
    {
        id: _Stack
        initialItem: "FirstScreen.qml"
        anchors.fill: parent
    }

}
