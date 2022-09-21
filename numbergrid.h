#ifndef NUMBERGRID_H
#define NUMBERGRID_H
#include <QObject>
#include "carreau.h"
#include "direction.h"
#include <QObject>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*class reponsable à la gestion du frid du nombreux et tout les opérations de l'utilisateur */

class NumberGrid: public QObject
{
    Q_OBJECT
public:
    //tous les méthodes sont expliqué dans le .cpp
   explicit NumberGrid();
    explicit NumberGrid(int lig,int col);
    explicit NumberGrid(int lig,int col,bool ok);
    ~NumberGrid();
    NumberGrid(const NumberGrid& n);
    NumberGrid& operator=(const NumberGrid& c);
    Q_INVOKABLE void initGrid();
    Q_INVOKABLE void sumGrid(direction d);
    Q_INVOKABLE void sumGridUp();
    Q_INVOKABLE void sumGridDown();
    Q_INVOKABLE void sumGridRight();
    Q_INVOKABLE void sumGridLeft();
    Q_INVOKABLE void restorePrec();
    void initGridAfterSum(direction d);
    bool verifWin();
    bool verifLoss(direction d,carreau** grid);
    carreau** getGrid();
    int getLigne();
    int getColonne();
    int get_nb_cases();
    QString getScore();
    void endGame();
    bool getEnded();
    void affich();
    void setGrid(carreau** c);
    void initialise();
    bool undounder();
    void initialiseUndo();
    void addGridToPrec();
    void affichPrec(int);
    void addscore(int);
    void setScore(int);
    QString getBestScore();
    bool verifTot();
    void setPhraseend(QString p);
    QString getPhraseend();
    Q_INVOKABLE void new_game();
    Q_INVOKABLE QString flatenGrid();
    Q_INVOKABLE void set_grille(int lignes,int colonnes);

    Q_PROPERTY(int ligne READ getLigne NOTIFY changed());
    Q_PROPERTY(int colonne READ getColonne NOTIFY changed());
    Q_PROPERTY(int nb_cases READ get_nb_cases NOTIFY changed)

    Q_PROPERTY(carreau** grid READ getGrid NOTIFY changed());
    Q_PROPERTY(bool ended READ getEnded NOTIFY changed());
    Q_PROPERTY(bool ended READ getEnded NOTIFY changed());
    Q_PROPERTY(QString valeur READ flatenGrid NOTIFY changed());
    Q_PROPERTY(QString score READ getScore NOTIFY modifScore());
    Q_PROPERTY(QString best_score READ getBestScore NOTIFY modifScore());

    Q_PROPERTY(QString phraseend READ getPhraseend NOTIFY pch());

signals:
    void changed(); // signal pour les valeurs du grille
    void modifScore(); // signal pour le score
    void pch();//signal sur l'etaat de la partie
private:
   int ligne=4;
   int* scoretab; // tableau des scores
   int colonne=4;
   bool ended;// la partie est terminé ou non
   int compteur=0;
   int score=0;
   int best_score=0;
   int undocount=0; //nomre d"etat précedentes stockés
   int undotimes=1000; //nombre des etats precedentes à stocker
   QString valeur;
   carreau*** etatprec; //cube des etats précédentes de la grille
   carreau** grid; // la grille
   void alloc (int l,int c); //allouer la grille
   void free();//désallocation de la grille
   bool endTab[4]={false,false,false,false}; // tableau pour verifier si la grille reste la meme dans tous les directions de sommation
   QString phraseend;
   bool blocked=false;
};

#endif // NUMBERGRID_H
