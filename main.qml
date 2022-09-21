import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQml.Models 2.15

Window {
    width: 450
    height: 480
    maximumHeight: height
    maximumWidth: width

    minimumHeight: height
    minimumWidth: width
    visible: true


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

                MouseArea {
                    id: mouseAreaGrid4
                    x: 0
                    y: 0
                    width: 120
                    height: 120
                    onClicked:{

                        ng.set_grille(4,4)
                        ng.initGrid()

                    }




                }
            }

            Image {
                id: grille5
                x: 299
                y: 42
                width: 120
                height: 120
                source: "images/Grille5X5.jpeg"

                MouseArea {
                    id: mouseAreaGrid5
                    x: 0
                    y: 0
                    width: 120
                    height: 120
                    onClicked:{
                        ng.set_grille(5,5)
                        ng.initGrid()

}
                }
            }

            Image {
                id: grille6
                x: 63
                y: 208
                width: 120
                height: 120
                source: "images/Grille6X6.jpeg"

                MouseArea {
                    id: mouseAreaGrid6
                    x: 0
                    y: 0
                    width: 120
                    height: 120
                    onClicked:{
                        ng.set_grille(6,6)
                        ng.initGrid()

                    }

                }
            }

            Image {
                id: grille8
                x: 299
                y: 208
                width: 120
                height: 120
                source: "images/Grille8X8.jpg"

                MouseArea {
                    id: mouseAreaGrid8
                    x: 0
                    y: 0
                    width: 120
                    height: 120
                    onClicked:{
                        ng.set_grille(8,8)
                        ng.initGrid()

                    }
                }

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

    Image {
        id: button
        x: 190
        y: 387
        width: 80
        height: 63
        source: "images/button"
        MouseArea{
            x: 0
            y: 0
            width: 80
            height: 63
            onClicked: rpmodel.append({})

                ListModel {
                    id: rpmodel
                }

                Instantiator { // from QtQml 2.0
                    model: rpmodel
                    delegate: Window {
                        width: 480
                        height: 650
                        maximumHeight: height
                        maximumWidth: width

                        minimumHeight: height
                        minimumWidth: width


                        visible: true
                        property alias police : comboPolice.currentText
                        property alias couleur : comboCouleur.currentText

                        Interface{
                            id:inter2
                        }
                        Rectangle{
                            ComboBox{
                                id:comboPolice
                                x: 195
                                y: 165
                                width: 85
                                height: 42
                                font.styleName: police

                                model: ListModel{
                                    ListElement{text:"Helvetica"}
                                    ListElement{text:"Times New Roman"}

                                    ListElement{text:"Georgia"}
                                    ListElement{text:"Courier New"}
                                    ListElement{text:"Papyrus"}

                                }

                            }
                            ComboBox{
                                id:comboCouleur
                                x: 318
                                y: 165
                                width: 85
                                height: 42
                                font.styleName: police

                                model: ListModel{
                                    ListElement{text:"rose"}
                                    ListElement{text:"bleu"}
                                    ListElement{text:"vert"}

                                }

                            }
                        }



                        Item{
                            Loader{
                                id: loadBoard
                                source:"Board.qml"
                                x:60
                                y:270
                                function reload(nb_rows, nb_cols) {
                                    source = "";
                                    grille.reset(nb_rows, nb_cols, win_value);
                                    source = "Board.qml";
                                }
                            }
                        }

                        onClosing: rpmodel.remove(index)
                    }
                }
        }

    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:1}
}
##^##*/

