#ifndef CARREAU_H
#define CARREAU_H
#include "couleur.h"
#include <QObject>
/*class reponsable des petits carreaux dans le frid des nombreus*/
class carreau: QObject
{
    Q_OBJECT
public:
    explicit carreau();
    explicit carreau(int);
    void setColor(int);
    void setValue(QString);
    carreau(const carreau& c);
    carreau& operator=(const carreau& c);
    couleur getColor();
    QString getValue();
private:
    QString value; //la valeur qu'il contient
    couleur color;//son couleur
};

#endif // CARREAU_H
