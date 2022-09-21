#ifndef ETATJEU_H
#define ETATJEU_H
#include "grille.h"
//Cette classe représente un état de jeu ainsi que ses informations relatives
class EtatJeu
{
public:
    EtatJeu(int lignes,int colonnes);

private:
    Grille* etat; // Pointeur vers la grille représentante de cet état
    EtatJeu* etat_prec; //Pointeur vers l'état précédent
    Grille* getEtat();
    EtatJeu* getEtatPrec();
    int score;
    bool gagne;
};

#endif // ETATJEU_H
