#include "carreau.h"
/*constructeur paramétre */
carreau::carreau(int c)
{
    int FLOAT_MIN = 0;
    int FLOAT_MAX = 1;
    //on va générer un carreau aléatoire avec une valeur entre 2 et 4
    float alea = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX/(FLOAT_MAX - FLOAT_MIN)));
    if (alea>0.8){
        this->value="4";
        this->color=(enum couleur)4;
    }
    else{
        this->value="2";
        this->color=(enum couleur)2;
    }

}
/*constructeur non paramétré */
carreau::carreau()
{
    this->value=" ";
    this->color=(enum couleur)0;
}
/*constructeur de recopie */
carreau::carreau(const carreau& c)
{
   this->value=c.value;
   this->color=c.color;
}
/*opérateur d'affectation */
carreau& carreau::operator=(const carreau& c)
{
    this->value=c.value;
    this->color=c.color;
    return *this;
}
void carreau::setColor(int color)
{
    this->color=(enum couleur)color;
}
void carreau::setValue(QString chaine)
{
    this->value=chaine;
}
couleur carreau::getColor()
{
    return this->color;
}
QString carreau::getValue()
{
    return this->value;
}
