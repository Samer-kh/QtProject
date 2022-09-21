import QtQuick 2.0

Item {
    width: 470
    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 470
        height: 480
        color: "#ffffff"

        Image {
            id: grille4
            x: 63
            y: 42
            width: 120
            height: 120
            source: "images/Grille4X4.png"
        }

        Image {
            id: grille5
            x: 299
            y: 42
            width: 120
            height: 120
            source: "images/Grille5X5.jpeg"
        }

        Image {
            id: grille6
            x: 63
            y: 208
            width: 120
            height: 120
            source: "images/Grille6X6.jpeg"
        }

        Image {
            id: grille8
            x: 299
            y: 208
            width: 120
            height: 120
            source: "images/Grille8X8.jpg"

        }
        Image {
            id: trophee
            x: 88
            y: 388
            width: 75
            height: 55
            source: "images/trophee.png"

        }



        Image {
            id: medaille
            x: 306
            y: 388
            width: 46
            height: 50
            source: "images/medaille.png"

        }

        Text {
            id: text1
            x: 106
            y: 174
            width: 57
            height: 19
            text: qsTr("4X4")
            font.pixelSize: 15
            font.styleName: "Gras"
            font.family: "Verdana"
            font.bold: true
        }

        Text {
            id: text2
            x: 349
            y: 177
            text: qsTr("5X5")
            font.pixelSize: 15
            font.styleName: "Gras"
            font.family: "Verdana"
            font.bold: true
        }

        Text {
            id: text3
            x: 115
            y: 342
            text: qsTr("6X6")
            font.pixelSize: 15
            font.styleName: "Gras"
            font.family: "Verdana"
            font.bold: true
        }

        Text {
            id: text4
            x: 354
            y: 342
            text: qsTr("8X8")
            font.pixelSize: 15
            font.styleName: "Gras"
            font.family: "Verdana"
            font.bold: true
        }

    }

}


