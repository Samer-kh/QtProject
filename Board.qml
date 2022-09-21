import QtQuick 2.15



Rectangle {

    id: board
    property int gridSpacing: 8



    width: adjusted_size(350, gridSpacing, ng.colonne)
    height: adjusted_size(350, gridSpacing, ng.ligne)
    color: "#b2aaaa"
    radius: 7



    function adjusted_size(size, spacing, nb_rows) {
        return nb_rows * Math.round((size-spacing)/nb_rows )+spacing
    }


    Grid {
        id: grid
        rows: ng.ligne
        columns: ng.colonne
        spacing: gridSpacing


        width: board.width - (1+columns)*spacing
        height: board.height - (1+rows)*spacing
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: spacing
        anchors.topMargin: spacing
        Component.onCompleted: forceActiveFocus()


        Keys.onPressed: {
          switch (event.key) {
            case Qt.Key_Up:
              ng.sumGridUp();
              break;
            case Qt.Key_Down:
              ng.sumGridDown();
              break;
            case Qt.Key_Right:
              ng.sumGridRight();
              break;
            case Qt.Key_Left:
              ng.sumGridLeft();
              break;
          }
        }
        Repeater {
                id: tiles

                model: ng.nb_cases
                delegate: Carreau{
                    focus:true
                    width: Math.round(grid.width / grid.columns)
                    height: Math.round(grid.height / grid.rows)


                }




            }
}
}











