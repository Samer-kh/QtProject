import QtQuick 2.0

Item {
    width: 249
    height: 251
    anchors.fill: parent
    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 251
        height: 252
        anchors.fill: parent
        color: "#716d6d"

        Grid{
            id: grid
            anchors.fill: parent
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
            flow: Grid.LeftToRight
            layoutDirection: Qt.LeftToRight
            spacing: 15
            rows: 4
            columns: 4

            Carreau {
                id: carreau
                anchors.fill: parent
            }

            Carreau {
                id: carreau1
                anchors.fill: parent
            }

            Carreau {
                id: carreau2
                anchors.fill: parent
            }

            Carreau {
                id: carreau3
                anchors.fill: parent
            }

            Carreau {
                id: carreau4
                anchors.fill: parent
            }

            Carreau {
                id: carreau5
                anchors.fill: parent
            }

            Carreau {
                id: carreau6
                anchors.fill: parent
            }

            Carreau {
                id: carreau7
                anchors.fill: parent
            }

            Carreau {
                id: carreau8
                anchors.fill: parent
            }

            Carreau {
                id: carreau9
                anchors.fill: parent
            }

            Carreau {
                id: carreau10
                anchors.fill: parent
            }

            Carreau {
                id: carreau11
                anchors.fill: parent
            }

            Carreau {
                id: carreau12
                anchors.fill: parent
            }

            Carreau {
                id: carreau13
                anchors.fill: parent
            }

            Carreau {
                id: carreau14
                anchors.fill: parent
            }

            Carreau {
                id: carreau15
                anchors.fill: parent
            }
        }
    }

}
