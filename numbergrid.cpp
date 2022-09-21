#include "numbergrid.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

/*constructeur  */
NumberGrid::NumberGrid()
{
 grid = new carreau*[ligne];
 for (int i=0;i<ligne;i++)
    {
     grid[i]=new carreau[colonne];

    }
 for(int i=0;i<ligne;i++)
 {
     for (int j=0;j<colonne;j++)
     {
         grid[i][j].setValue(" ");
     }
 }
 scoretab=new int[undotimes];
 for(int p=0;p<undotimes;p++)
 {
     scoretab[p]=0;
 }
 etatprec=new carreau**[undotimes];
 for (int i=0;i<undotimes;i++)
 {
     etatprec[i]=new carreau*[ligne];
     for (int j=0;j<ligne;j++)
     {
         etatprec[i][j]=new carreau[colonne];
     }
 }
 for (int i=0;i<undotimes;i++)
 {
     for (int k=0;k<ligne;k++)
     {
         for (int j=0;j<colonne;j++)
         {
             etatprec[i][k][j].setValue(" ");
         }
     }
 }
setPhraseend(QString::fromStdString("Currently Playing"));
cout<<phraseend.toStdString()<<endl;
}


/*constructeur paramétré */


NumberGrid::NumberGrid(int lig,int col)
{this->ligne=lig;
 this->colonne=col;
 grid = new carreau*[lig];
 for (int i=0;i<lig;i++)
    {
     grid[i]=new carreau[colonne];
    }
 for(int i=0;i<ligne;i++)
 {
     for (int j=0;j<colonne;j++)
     {
         grid[i][j].setValue(" ");
     }
 }
 scoretab=new int[undotimes];
 for(int p=0;p<undotimes;p++)
 {
     scoretab[p]=0;
 }
 etatprec=new carreau**[undotimes];
 for (int i=0;i<undotimes;i++)
 {
     etatprec[i]=new carreau*[ligne];
     for (int j=0;j<ligne;j++)
     {
         etatprec[i][j]=new carreau[colonne];
     }
 }
 for (int i=0;i<undotimes;i++)
 {
     for (int k=0;k<ligne;k++)
     {
         for (int j=0;j<colonne;j++)
         {
             etatprec[i][k][j].setValue(" ");
         }
     }
 }
 setPhraseend(QString::fromStdString("Currently Playing"));
 cout<<phraseend.toStdString()<<endl;
}

/*destructeur  */


NumberGrid::~NumberGrid()
{
    for(int i=0 ; i<ligne ;i++)
    {
        delete[] grid[i];
    }
    delete[] grid;

    for (int j=0;j<undotimes;j++)
    {
        for (int i=0;i<ligne;i++)
        {
                delete[] etatprec[j][i];
        }
    }
    for (int i=0;i<undotimes;i++)
    {
        delete[] etatprec[i];
    }
    delete[] etatprec;
    delete[] scoretab;
}


/*constructeur de recopie */


NumberGrid::NumberGrid(const NumberGrid& c)
{   this->undotimes=c.undotimes;
    this->undocount=c.undocount;
    this->compteur=c.compteur;
    this->ended=c.ended;
    this->ligne=c.ligne;
    this->colonne=c.colonne;
    this->grid=new carreau*[this->ligne];
    for (int i=0;i<this->ligne;i++)
       {
        this->grid[i]=new carreau[colonne];
       }
    for (int i=0;i<this->ligne;i++)
    {
        for (int j=0;j<this->colonne;j++)
        {
            this->grid[i][j]=c.grid[i][j];
        }
    }

    etatprec=new carreau**[undotimes];
    for (int i=0;i<undotimes;i++)
    {
        etatprec[i]=new carreau*[ligne];
        for (int j=0;j<ligne;j++)
        {
            etatprec[i][j]=new carreau[colonne];
        }
    }
    scoretab= new int[undotimes];
    for (int p=0 ; p<undotimes;p++)
    {
        scoretab[p]=c.scoretab[p];
    }
    for (int i=0;i<undotimes;i++)
    {
        for (int k=0;k<ligne;k++)
        {
            for (int j=0;j<colonne;j++)
            {
                etatprec[i][k][j]=c.etatprec[i][k][j];
            }
        }
    }
}


/*operateur d'affectation*/


NumberGrid& NumberGrid::operator=(const NumberGrid& c)
{   this->undocount=c.undocount;
    this->undotimes=c.undotimes;
    this->compteur=c.compteur;
    this->ended=c.ended;
    this->ligne=c.ligne;
    this->colonne=c.colonne;
    this->grid=new carreau*[this->ligne];
    for (int i=0;i<this->ligne;i++)
       {
        this->grid[i]=new carreau[colonne];
       }
    for (int i=0;i<this->ligne;i++)
    {
        for (int j=0;j<this->colonne;j++)
        {
            this->grid[i][j]=c.grid[i][j];
        }
    }
    scoretab=new int[undotimes];
    for (int p=0;p<undotimes;p++)
    {
        scoretab[p]=c.scoretab[p];
    }
    etatprec=new carreau**[undotimes];
    for (int i=0;i<undotimes;i++)
    {
        etatprec[i]=new carreau*[ligne];
        for (int j=0;j<ligne;j++)
        {
            etatprec[i][j]=new carreau[colonne];
        }
    }
    for (int i=0;i<undotimes;i++)
    {
        for (int k=0;k<ligne;k++)
        {
            for (int j=0;j<colonne;j++)
            {
                this->etatprec[i][k][j]=c.etatprec[i][k][j];
            }
        }
    }
    return *this;
}


/*responsable à la désallocation de la grille  */

void NumberGrid::free(){
    for (int i=0; i<ligne; i++) {
        delete [] grid[i];
    }
    delete [] grid;

    for (int j=0;j<undotimes;j++)
    {
        for (int i=0;i<ligne;i++)
        {
                delete[] etatprec[j][i];
        }
    }
    for (int i=0;i<undotimes;i++)
    {
        delete[] etatprec[i];
    }
    delete[] etatprec;
    delete[] scoretab;

}


/*responsable de l'allocation de la grille  */


void NumberGrid::alloc(int l, int c){
    ligne = l;
    colonne = c;
    grid = new carreau*[ligne];

    for(int i=0; i<ligne; i++)
    {
        grid[i] = new carreau[colonne];
    }
    scoretab=new int[undotimes];
    for(int p=0;p<undotimes;p++)
    {
        scoretab[p]=0;
    }
    etatprec=new carreau**[undotimes];
    for (int i=0;i<undotimes;i++)
    {
        etatprec[i]=new carreau*[ligne];
        for (int j=0;j<ligne;j++)
        {
            etatprec[i][j]=new carreau[colonne];
        }
    }

}
void NumberGrid::set_grille(int lignes, int colonnes){
    free();
    alloc(lignes,colonnes);
    emit changed();

}

/*responsable de l'enregistrement de la grille dans les taets précédent en cas ou l'utilisateur click undo  */


void NumberGrid::addGridToPrec()
{
    for(int i=0;i<ligne;i++)
    {
        for (int j=0;j<colonne;j++)
        {
            etatprec[undocount][i][j]=grid[i][j];
        }
    }
    addscore(getScore().toInt());
    undocount++;
}

/*restore la grille précédente  */


void NumberGrid::affichPrec(int i)
{

        for (int j=0;j<ligne;j++)
        {
            for (int k=0;k<colonne;k++)
            {
                cout<<etatprec[i][j][k].getValue().toInt();
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<endl;

}

/*responsble de l'initialisation de la grille  */


void NumberGrid::initGrid()
{   srand(time(NULL));
   //choix de deux position aléatoires
    bool ok = false;
    int pos1_i=rand()%ligne;
    int pos1_j=rand()%ligne;
    int pos2_i,pos2_j;
    while (!ok)
    {
        pos2_i= rand()%ligne;
        pos2_j= rand()%ligne;

        if (pos1_i!=pos2_i || pos2_j!=pos1_j)
        {
         ok = true;
        }
    }
    grid[pos1_i][pos1_j]=*(new carreau(0));
    grid[pos2_i][pos2_j]=*(new carreau(0));
   compteur=0;
   //affich();
   //affichPrec()
   emit changed();
   setPhraseend(QString::fromStdString("currently playing "));
   emit pch();
   cout<<phraseend.toStdString()<<endl;
   for (int h=0;h<4;h++)
   {
       endTab[h]=false;
   }

}

/*ajour de nouveaux cases à chaque fois l'utilisateur fais une mvmnt  */


void NumberGrid::initialise()
{
    cout<<"initilase"<<endl;

    int ligne=this->getLigne();
    int colonne =this->getColonne();

    int lin=rand()%ligne;
    int col=rand()%colonne;
    while(this->getGrid()[lin][col].getValue()!=" ")
    {
        lin=rand()%ligne;
        col=rand()%colonne;
    }
    this->getGrid()[lin][col]=*(new carreau(0));
}
void NumberGrid::setGrid(carreau** c)
{
    this->grid=c;
}

carreau** NumberGrid::getGrid()
{
    return this->grid;
}
int NumberGrid::getColonne(){
    return this->colonne;
}
int NumberGrid::getLigne()
{
    return this->ligne;
}
int NumberGrid::get_nb_cases(){
    return ligne*colonne;
}
QString NumberGrid::getScore()
{
    return QString::number(score);

}
QString NumberGrid::getBestScore(){
    fstream fichier;
    string ligne;
    switch(getLigne()){
    case 4:{
        fichier.open("bestScore4x4", ios::in);
        fichier >>ligne;
        cout<<ligne;

        int best_actuel;
        // convertir en un int

        best_actuel= atoi(ligne.c_str());
        cout<<"dans score"<<best_actuel<<"okay"<<endl;
        cout<<"score actuel"<<score<<endl;
        if(score>best_actuel){

              best_score=score;

              cout<<"changed"<<endl;
        }
        cout <<"apres best "<<best_score<<endl;
    }
    case 5:{
        fichier.open("bestScore5x5", ios::in);
        fichier >>ligne;
        cout<<ligne;

        int best_actuel;
        // convertir en un int

        best_actuel= atoi(ligne.c_str());
        cout<<"dans score"<<best_actuel<<"okay"<<endl;
        cout<<"score actuel"<<score<<endl;
        if(score>best_actuel){

              best_score=score;

              cout<<"changed"<<endl;
        }
    }
    case 6:{
        fichier.open("bestScore6x6", ios::in);
        fichier >>ligne;
        cout<<ligne;

        int best_actuel;
        // convertir en un int

        best_actuel= atoi(ligne.c_str());
        cout<<"dans score"<<best_actuel<<"okay"<<endl;
        cout<<"score actuel"<<score<<endl;
        if(score>best_actuel){

              best_score=score;

              cout<<"changed"<<endl;
        }
    }
    case 8:{
        fichier.open("bestScore8x8", ios::in);
        fichier >>ligne;
        cout<<ligne;

        int best_actuel;
        // convertir en un int

        best_actuel= atoi(ligne.c_str());
        cout<<"dans score"<<best_actuel<<"okay"<<endl;
        cout<<"score actuel"<<score<<endl;
        if(score>best_actuel){

              best_score=score;

              cout<<"changed"<<endl;
        }
    }

    }


    return QString::number(best_score);
}

/*recherche de la premier case vide à partir d'une case et dans une direction bien determiné */

int* firstEmpty(NumberGrid g,direction d , int n, int m )
{   int* tab = new int[3];
    tab[0]=0;

    switch(d)
    {
        case 1:
         for (int i=n;i>-1;i--)
         {

             if (g.getGrid()[i][m].getValue()==" ")
             {
                 tab[0]=1;
                 tab[1]=i;
                 tab[2]=m;

             }

         }
         return tab;
        case 2:
        for (int i=n;i<g.getLigne();i++)
        {
            if (g.getGrid()[i][m].getValue()==" ")
            {
                tab[0]=1;
                tab[1]=i;
                tab[2]=m;

            }

        }
        return tab;
        case 3:
        for (int i=m;i<g.getColonne();i++)
        {
            if (g.getGrid()[n][i].getValue()==" ")
            {
                tab[0]=1;
                tab[1]=n;
                tab[2]=i;

            }

        }
        return tab;
        case 4:
        for (int i=m;i>-1;i--)
        {
            if (g.getGrid()[n][i].getValue()==" ")
            {
                tab[0]=1;
                tab[1]=n;
                tab[2]=i;

            }

        }
        return tab;
    }
}

/*verifier si deux cases sont sommables  */

bool summable(carreau a , carreau b)
{
    return a.getValue()==b.getValue();
}

/*initialisation du matrice des booleans pour la verification de changements de chaque case  */

bool** initverif(int ligne,int colonne)
{
    bool** verif;
    verif = new bool*[ligne];
    for (int i=0;i<ligne;i++)
       {
        verif[i]=new bool[colonne];

       }
    for(int i=0;i<ligne;i++)
    {
        for (int j=0;j<colonne;j++)
        {
            verif[i][j]=false;
        }
    }
   return verif;
}

/*verifier si le nombre d'ete prec est maximisé */

bool NumberGrid::undounder()
{
    if(undocount<undotimes)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*initialisation du cube contenant tous les grids précedents  */

void NumberGrid::initialiseUndo()
{   carreau*** etatprecc;
    etatprecc=new carreau**[undotimes];
    for (int i=0;i<undotimes;i++)
    {
        etatprecc[i]=new carreau*[ligne];
        for (int j=0;j<ligne;j++)
        {
            etatprecc[i][j]=new carreau[colonne];
        }
    }
    for (int i=0;i<undotimes;i++)
    {
        for (int k=0;k<ligne;k++)
        {
            for (int j=0;j<colonne;j++)
            {
                etatprecc[i][k][j]=this->etatprec[i][k][j];
            }
        }
    }
    //    for (int j=0;j<undotimes;j++)
    //    {
    //    for (int i=0;i<ligne;i++)
    //    {
    //        delete[] etatprec[j][i];
    //    }
    //    }
    //    for (int i=0;i<undotimes;i++)
    //    {
    //        delete[] etatprec[i];
    //    }
//    delete[] etatprec;
    etatprec=new carreau**[undotimes*2];
    for (int i=0;i<undotimes;i++)
    {
        etatprec[i]=new carreau*[ligne];
        for (int j=0;j<ligne;j++)
        {
            etatprec[i][j]=new carreau[colonne];
        }
    }
    for (int i=0;i<undotimes;i++)
    {
        for (int k=0;k<ligne;k++)
        {
            for (int j=0;j<colonne;j++)
            {
                etatprec[i][k][j]=etatprecc[i][k][j];
            }
        }
    }
    int* abs=new int[undotimes];
    for (int p=0;p<undotimes;p++)
    {
        abs[p]=scoretab[p];
    }
    scoretab=new int[undotimes*2];
    for (int p=0;p<undotimes;p++)
    {
        scoretab[p]=abs[p];
    }
    this->undotimes=undotimes*2;
}
void NumberGrid::addscore(int a)
{
  scoretab[undocount]=a;
}

/*verifier si une seul case est vide dans la grid  */

bool oneempty(carreau** grid,int ligne,int colonne)
{
    for (int i=0;i<ligne;i++)
    {
        for (int j=0;j<colonne;j++)
        {
            if(grid[i][j].getValue()==" ")
            {
                return true;
            }
        }
    }
    return false;
}


/*responsable de la sommation du grid dans une direction  */


void NumberGrid::sumGrid(direction d)
{   bool** gridverif=initverif(ligne,colonne);

    if(undounder()){
    addGridToPrec();

    affichPrec(undocount-1);
    cout<<undocount<<endl;
    }
    else
    {
        initialiseUndo();
        addGridToPrec();


    }
    switch(d)
    {
    int* coord;
    case 1:
        for (int i=0;i<ligne;i++)
        {
            for (int j=0;j<colonne;j++)
            {

                if(grid[i][j].getValue()!=" ")
                {
                    coord= firstEmpty(*this,d,i,j);
                    if(coord[0]==0)
                    {
                        if(i!=0)
                        {
                            if(summable(grid[i][j],grid[i-1][j])&&(gridverif[i-1][j]==false))
                            {
                                grid[i-1][j].setValue(QString::number(grid[i-1][j].getValue().toInt()*2));
                                score=score+grid[i-1][j].getValue().toInt();
                                emit modifScore();
                                grid[i][j]=*(new carreau());
                                gridverif[i-1][j]=true;
                            }
                        }
                        else
                        {
                            cout<<"pas de place vide"<<endl;
                        }
                    }
                    else
                    {
                        if(coord[1]==0)
                        {


                            grid[coord[1]][coord[2]]=grid[i][j];
                            grid[i][j]= *(new carreau());



                        }
                        else
                        {
                            if(summable(grid[coord[1]-1][coord[2]],grid[i][j])&&gridverif[coord[1]-1][coord[2]]==false)
                            {
                                grid[coord[1]-1][coord[2]].setValue(QString::number(grid[coord[1]-1][coord[2]].getValue().toInt()*2));
                                score=score+grid[coord[1]-1][coord[2]].getValue().toInt();
                                emit modifScore();
                                grid[i][j]=*(new carreau());
                                gridverif[coord[1]-1][coord[2]]=true;
                            }
                            else
                            {

                                grid[coord[1]][coord[2]]=grid[i][j];
                                grid[i][j]= *(new carreau());


                            }
                        }
                    }
                }
            }

        }
       delete[] coord;

    case 2:
        for (int i=ligne-1;i>-1;i--)
        {
            for (int j=0;j<colonne;j++)
            {
                if(grid[i][j].getValue()!=" ")
                {coord= firstEmpty(*this,d,i,j);
                    if(coord[0]==0)
                    {
                        if(i!=(ligne-1))
                        {
                            if(summable(grid[i+1][j],grid[i][j])&&gridverif[i+1][j]==false)
                            {
                                grid[i+1][j].setValue(QString::number(grid[i+1][j].getValue().toInt()*2));
                                score=score+grid[i+1][j].getValue().toInt();
                                emit modifScore();
                                grid[i][j]=*(new carreau());
                                gridverif[i+1][j]=true;
                            }
                        }
                        else
                        {
                            cout<<"pas de place vide"<<endl;
                        }
                    }
                    else
                    {
                        if(coord[1]==ligne-1)
                        {


                            grid[coord[1]][coord[2]]=grid[i][j];
                            grid[i][j]= *(new carreau());

                        }
                        else
                        {
                            if(summable(grid[coord[1]+1][coord[2]],grid[i][j])&&gridverif[coord[1]+1][coord[2]]==false)
                        {
                            grid[coord[1]+1][coord[2]].setValue(QString::number(grid[coord[1]+1][coord[2]].getValue().toInt()*2));
                            score=score+grid[coord[1]+1][coord[2]].getValue().toInt();
                            emit modifScore();
                            grid[i][j]=*(new carreau());
                            gridverif[coord[1]+1][coord[2]]=true;
                        }
                        else
                        {

                                grid[coord[1]][coord[2]]=grid[i][j];
                                grid[i][j]= *(new carreau());


                        }
                        }
                    }
                }}

        }
       delete[] coord;
        break;
    case 3:
        for (int j=colonne-1;j>-1;j--)
        {
            for (int i=0;i<ligne;i++)
            {
                if(grid[i][j].getValue()!=" ")
                {coord= firstEmpty(*this,d,i,j);
                    if(coord[0]==0)
                    {
                        if(j!=colonne-1)
                        {
                            if(summable(grid[i][j+1],grid[i][j])&&gridverif[i][j+1]==false)
                            {
                                grid[i][j+1].setValue(QString::number(grid[i][j+1].getValue().toInt()*2));
                                score=score+grid[i][j+1].getValue().toInt();
                                emit modifScore();
                                grid[i][j]=*(new carreau());
                                gridverif[i][j+1]=true;
                            }
                        }
                        else
                        {
                            cout<<"pas de place vide"<<endl;
                        }
                    }
                    else
                    {
                        if(coord[2]==colonne-1)
                        {

                            grid[coord[1]][coord[2]]=grid[i][j];
                            grid[i][j]= *(new carreau());


                        }
                        else
                        {
                            if(summable(grid[coord[1]][coord[2]+1],grid[i][j])&&gridverif[coord[1]][coord[2]+1]==false)
                            {
                                grid[coord[1]][coord[2]+1].setValue(QString::number(grid[coord[1]][coord[2]+1].getValue().toInt()*2));
                                score=score+grid[coord[1]][coord[2]+1].getValue().toInt();
                                emit modifScore();
                                grid[i][j]=*(new carreau());
                                gridverif[coord[1]][coord[2]+1]=true;
                            }
                            else
                            {

                                grid[coord[1]][coord[2]]=grid[i][j];
                                grid[i][j]= *(new carreau());


                            }
                        }}
                }}
}

       delete[] coord;
        break;
    case 4:
        for (int j=0;j<colonne;j++)
        {
            for (int i=0;i<ligne;i++)
            {
                if(grid[i][j].getValue()!=" ")
                {coord= firstEmpty(*this,d,i,j);
                    if(coord[0]==0)
                    {
                        if(j!=0)
                        {
                            if(summable(grid[i][j-1],grid[i][j])&&gridverif[i][j-1]==false)
                            {
                                grid[i][j-1].setValue(QString::number(grid[i][j-1].getValue().toInt()*2));
                                score=score+grid[i][j-1].getValue().toInt();
                                emit modifScore();
                                grid[i][j]=*(new carreau());
                                gridverif[i][j-1]=true;
                            }
                        }
                        else
                        {
                            cout<<"pas de place vide"<<endl;
                        }
                    }
                    else
                    {
                        if(coord[2]==0)
                        {

                            grid[coord[1]][coord[2]]=grid[i][j];
                            grid[i][j]= *(new carreau());


                        }
                        else {
                            if(summable(grid[coord[1]][coord[2]-1],grid[i][j])&&gridverif[coord[1]][coord[2]-1]==false)
                        {
                            grid[coord[1]][coord[2]-1].setValue(QString::number(grid[coord[1]][coord[2]-1].getValue().toInt()*2));
                            score=score+grid[coord[1]][coord[2]-1].getValue().toInt();
                            emit modifScore();
                            grid[i][j]=*(new carreau());

                        }
                            else{

                                grid[coord[1]][coord[2]]=grid[i][j];
                                grid[i][j]= *(new carreau());


                            }
                    }}
                }}

        }
       delete[] coord;
       break;
    }
    delete[] gridverif;
    if(oneempty(this->grid,this->ligne,this->colonne)){
    initialise();
    }
    emit changed();



    verifLoss(d,etatprec[undocount-1]);
    verifTot();
    emit pch();
    for (int h=0;h<4;h++)
    {
       cout<<endTab[h]<<endl;
    }
    if(verifWin()){
        cout<<"won won"<<endl;
        setPhraseend(QString::fromStdString("you have won !!!"));
        emit pch();
        blocked=true;
    }
cout<<phraseend.toStdString()<<endl;
cout<<getPhraseend().toStdString()<<endl;
}
bool NumberGrid::getEnded()
{
    return this->ended;
}

/*verifie si l'utilisateur à gagné */

void NumberGrid::endGame()
{   bool ok =false;
    for(int i=0;i<ligne;i++)
    {
        for(int j=0;j<colonne;j++)
        {
            if(grid[i][j].getValue().toInt()==2048)
            {
                ok=true;
                this->ended=true;
            }
        }

    }
    if(!ok)
    {
    this->ended=false;
    }
}

/*préparer la grid pour l'affichage  */

QString NumberGrid::flatenGrid()
{   if(compteur==ligne*colonne)
    {
        compteur=0;
    }
    int k=0;
    int* tab = new int[ligne*colonne];
    for (int i=0;i<ligne;i++)
    {
        for(int j=0;j<colonne;j++)
        {
            tab[k]=grid[i][j].getValue().toInt();
            k++;
        }
    }

    if(tab[compteur]==0)
    {
        compteur++;
        delete[]tab;
        QString s=" ";
        return s;
    }
    else
    {valeur=QString::number(tab[compteur]);
        delete[]tab;
        compteur++;
    return valeur;
    }



}

/*affichage dans le console  */


void NumberGrid::affich()
{
    for (int i=0;i<ligne;i++)
    {
        for(int j=0;j<colonne;j++)
        {
            cout<<grid[i][j].getValue().toInt();
        }
        cout<<endl;
    }
}

/*méthode de sommation selon la direction  */


void NumberGrid::sumGridUp()
{ if(!blocked){
    this->sumGrid((enum direction)(1));
    emit changed();
    }
}
void NumberGrid::sumGridDown()
{   if(!blocked){
    this->sumGrid((enum direction)(2));
    emit changed();
    }
}
void NumberGrid::sumGridRight()
{   if(!blocked){
    this->sumGrid((enum direction)(3));
    emit changed();
}}
void NumberGrid::sumGridLeft()
{   if(!blocked){
    this->sumGrid((enum direction)(4));
    emit changed();
}}
void NumberGrid::setScore(int a)
{
    score=a;
}

/*affecter l'etat précedente de la grille  */

void NumberGrid::restorePrec()
{
if((undocount!=0))
{
for(int i=0;i<ligne;i++)
{
    for(int j=0;j<colonne;j++)
    {
        grid[i][j].setValue(etatprec[undocount-1][i][j].getValue());
    }

}
        setScore(scoretab[undocount-1]);
        undocount=undocount-1;
        cout<<undocount<<endl;
        emit changed();
        emit modifScore();
        blocked=false;
        setPhraseend(QString::fromStdString("currently playing"));
        emit pch();
}
}

/*initialisé une nouvelle partie  */


void NumberGrid::new_game(){
    set_grille(ligne,colonne);
    initGrid();
    cout<<"new game"<<endl;
}

/*verifier si l'utilisateur à gagné  */


bool NumberGrid::verifWin()
{
    for(int i=0;i<ligne;i++)
    {
        for(int j=0;j<colonne;j++)
        {
            if(grid[i][j].getValue().toInt()==2048)
            {

                setPhraseend(QString::fromStdString("you have won !!!"));
                emit pch();
                emit changed();
                cout<<"looool"<<endl;
                return true;
            }
        }
    }
    return false;
}

/*verifier si deux etats de la grille sont somblales  */

bool semblable(carreau** grid1,carreau** grid2,int ligne,int colonne )
{
    for (int i=0;i<ligne;i++)
    {
        for (int j=0;j<colonne;j++)
        {
            if (grid1[i][j].getValue()!=grid2[i][j].getValue())
            {
                return false;
            }
        }
    }
    return true;
}

/*verifier si l'utilisateur à perdu  */


bool NumberGrid::verifLoss(direction d,carreau** grid)
{
    if (undocount!=0){
        if (semblable(this->grid,grid,this->ligne,this->colonne)){
            switch(d)
            {
            case 1 : endTab[0]=true;
            case 2 : endTab[1]=true;
            case 3 : endTab[2]=true;
            case 4 : endTab[3]=true;
            }
            return true;
        }
        else{
            for (int h=0;h<4;h++)
            {
                endTab[h]=false;
            }
            setPhraseend(QString::fromStdString("currently playing"));
            emit pch();
           return false ;
        }
    }
    else{
        return false;
    }
}
bool NumberGrid::verifTot()
{
    for (int i=0 ; i<4;i++)
    {
        if (endTab[i]==false)
        {
            return false;
        }
    }
    setPhraseend(QString::fromStdString("you have lost !!!"));
    emit pch();
    return true;
}
QString NumberGrid::getPhraseend()
{
    return phraseend;
}
void NumberGrid::setPhraseend(QString p)
{
    phraseend=p;

}
