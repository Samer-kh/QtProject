#ifndef GRILLE_H
#define GRILLE_H
#include <iostream>
#include<QObject>
using namespace std;

//La classe Grille représente le tableau
class Grille: public QObject
{
    Q_OBJECT
public:
    explicit Grille(int lignes,int colonnes, QObject* parent=0);
    Grille(const Grille& g);
    ~Grille();
    //Getters et setters
    void set(int x,int y,int valeur);
    int get(int x,int y);
    int get_nb_lignes();
    int get_nb_colonnes();
    int get_nb_cases();

    Q_INVOKABLE void reset(int nb_l, int nb_c);
    Q_INVOKABLE void set_grille(int lignes,int colonnes);
    Q_PROPERTY(int nb_cases READ get_nb_cases NOTIFY changed)

    Q_PROPERTY(int nb_lignes READ get_nb_lignes NOTIFY changed)
    Q_PROPERTY(int nb_colonnes READ get_nb_colonnes NOTIFY changed)

signals:
    void changed();
private:
    int nb_lignes,nb_colonnes;
    int **T;
    //Factorisation du code
    void alloc(int l,int c);
    void free();

};

#endif // GRILLE_H
