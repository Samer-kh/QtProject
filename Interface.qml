import QtQuick 2.0

Item {
    width: 450
    height: 800


    anchors.fill: parent

    Flow {
        id: flow1
        x: 0
        y: 0
        width: 450
        height: 620
        anchors.fill: parent
        anchors.rightMargin: 0
        anchors.bottomMargin: 21
        anchors.leftMargin: 0
        anchors.topMargin: -8

        Rectangle {
            id: rectangle
            width: 450
            height: 623
            color: "#f4f5e3"
            anchors.fill: parent
            anchors.bottomMargin: -20

            Rectangle {
                id: rectangle2
                x: 18
                y: 30
                width: 143
                height: 125
                color: "#e6cc82"

                Text {
                    id: nomJeu
                    x: 24
                    y: 35
                    width: 95
                    height: 47
                    text: qsTr("2048")
                    font.pixelSize: 39
                    horizontalAlignment: Text.AlignHCenter
                    font.weight: Font.Bold
                }
            }

            Rectangle {
                id: rectangle3
                x: 195
                y: 30
                width: 104
                height: 67
                color: "#3f3939"

                Text{
                    id: textEdit1
                    x: 12
                    y: 8
                    width: 80
                    height: 20
                    color: "#fdfbfb"
                    text: qsTr("Score :")
                    font.pixelSize: 20
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                }

                TextEdit {
                    id: text1
                    x: 9
                    y: 34
                    width: 78
                    height: 26
                    color: "#fdfbfb"
                    text: ng.score
                    font.family: police
                    font.pixelSize: 19
                    horizontalAlignment: Text.AlignHCenter
                }
            }

            Rectangle {
                id: rectangle4
                x: 316
                y: 30
                width: 104
                height: 67
                color: "#3f3939"
                Text {
                    id: textEdit2
                    x: 12
                    y: 8
                    width: 80
                    height: 20
                    color: "#fdfbfb"
                    text: qsTr("Best :")
                    font.pixelSize: 20
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                }

                TextEdit {
                    id: text2
                    x: 2
                    y: 36
                    width: 90
                    height: 26
                    color: "#fdfbfb"
                    text: ng.best_score
                    font.family: police
                    font.pixelSize: 19
                    horizontalAlignment: Text.AlignHCenter
                }
            }

            Rectangle {
                id: rectNewGame
                x: 195
                y: 113
                width: 103
                height: 42
                color: "#b34455"

                Text {
                    id: newGame
                    x: 8
                    y: 8
                    width: 80
                    height: 36
                    color: "#fcfcfc"
                    text: qsTr("New")
                    font.family: police
                    font.pixelSize: 22
                    horizontalAlignment: Text.AlignHCenter
                    font.weight: Font.Bold
                }
                MouseArea{
                    x:0
                    y:0
                    width: 103
                    height: 42
                    onClicked:{
                        console.log("new game")

                        ng.new_game()

                    }

                }
            }

            Rectangle {
                id: rectangle6
                x: 317
                y: 113
                width: 103
                height: 42
                color: "#b34455"
                Text {
                    id: textEdit4
                    x: 12
                    y: 8
                    width: 80
                    height: 36
                    color: "#fcfcfc"
                    text: qsTr("Undo")
                    font.family: police
                    font.pixelSize: 22
                    horizontalAlignment: Text.AlignHCenter
                    font.weight: Font.Bold
                }

                MouseArea {
                    id: mouseArea1
                    x: 3
                    y: 0
                    width: 100
                    height: 41
                    onClicked: {
                        console.log("hello from top")
                        ng.restorePrec()
                    }
                }
            }


        }

        Text {
            id: textWelcome
            x: 53
            y: 220
            width: 350
            height: 30
            text: qsTr("Join the numbers and get the 2048 tile")
            font.pixelSize: 21
            horizontalAlignment: Text.AlignHCenter
            font.styleName: "Gras Italique"
            font.bold: true
        }

        TextEdit {
            id: textWelcome1
            x: 53
            y: 246
            width: 350
            height: 30
            color: "#b34455"
            text: ng.phraseend
            font.pixelSize: 21
            horizontalAlignment: Text.AlignHCenter
            font.styleName: "Gras Italique"
            font.bold: true

        }


    }

}
