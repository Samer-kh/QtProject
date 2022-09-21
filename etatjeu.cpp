#include "etatjeu.h"

EtatJeu::EtatJeu(int lignes,int colonnes)
{
   etat=new Grille(lignes,colonnes);
   etat_prec=0;
}

Grille* EtatJeu::getEtat()
{
    return etat;
}

EtatJeu* EtatJeu::getEtatPrec()
{
    return etat_prec;
}
