#include "grille.h"
#include <iostream>
#include<QObject>
using namespace std;

Grille::Grille(int lignes,int colonne,QObject* parent):QObject(parent)
{
    nb_lignes=lignes;
    nb_colonnes=colonne;
    alloc(lignes,colonne);
}
Grille::Grille(const Grille &g)
{
  nb_lignes=g.nb_lignes;
  nb_colonnes=g.nb_colonnes;
  alloc(nb_lignes,nb_colonnes);
  for(int i=0;i<nb_lignes;i++){
      for(int j=0;j<nb_colonnes;j++)
          T[i][j]=g.T[i][j];
  }
}
Grille::~Grille(){
    free();
}
int Grille::get_nb_lignes()
{
    return nb_lignes;
}
int Grille::get_nb_colonnes()
{
    return nb_colonnes;
}
int Grille::get_nb_cases()
{
    return nb_colonnes*nb_lignes;
}
void Grille::set_grille(int lignes, int colonnes){
    nb_lignes=lignes;
    nb_colonnes=colonnes;
    emit changed();
    cout <<"ok";
}
//Allouer l'espace mémoire pour le tableau
void Grille::alloc(int l,int c){
    T=new int*[l];
    for (int i=0;i<l;i++){
        T[i]=new int[c];
    }
}
void Grille::reset(int nb_lignes, int nb_colonnes)
{
      emit changed ();
}
//Libérer l'espace mémoire du tableau constituant la grille
void Grille::free()
{
    for (int i=0; i < nb_lignes; i++)
    {
        delete [] T[i];
    }
    delete [] T;
}
