import QtQuick 2.15

Rectangle {

    id: tile
    color: couleur_list[choose_color(couleur)][choose_indice()]
    radius: 3

    property variant couleur_list:
        [ ["#929292","#7b68ee","#00ffff","#7fffd4","#8a2be2","#5f9ea0","#6495ed","#008b8b","#00ced1","#add8e6","#e6e6fa","#4b0082"],
          ["#929292","#9acd32","#006400","#bdb76b","#556b2f","#8fbc8f","#2f4f4f","#228b22","#008000","#adff2f","#f0fff0","#20b2aa"],
          ["#929292","#faebd7","#ffe4c4","#e9967a","#ff1493","#ff00ff","#ff69b4","#cd5c5c","#f08080","#ffb6c1","#ff00ff","#c71585"]
    ]





    function choose_color(couleur ) {
        if (couleur==="vert"){
            return 1
        }
        else if (couleur==="bleu"){
            return 0
        }
        else if (couleur==="rose"){
            return 2
        }
    }
    function choose_indice(){

           switch(tile_value.text){

            case qsTr("2"):
                return 1
            case qsTr("4"):
                return 2
            case qsTr("8"):
                return 3
            case qsTr("16"):
                return 4
            case qsTr("32"):
                return 5
            case qsTr("64"):
                return 6
            case qsTr("128"):
                return 7
            case qsTr("256"):
                return 8
            case qsTr("512"):
                return 9
            case qsTr("1024"):
                return 10
             case qsTr("2048"):
                 return 11
             default:
                 return 0

            }
        }


    TextEdit {
        id: tile_value
        text: ng.valeur
        readOnly: true

        font.pixelSize: 25
        font.family: police
        anchors.fill: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        font.styleName:police

    }








}
