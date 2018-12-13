#include "carton.h"

Carton::Carton(string chemin, string nom, string date, int nbL, int nbC)
{
    this->chemin = "C:/Users/ville/Documents/UPSSITECH/2A/TER/carton20x240.bmp";
    this->nom = nom;
    this->date = date;
    this->nbLigne = nbL;
    this->nbColonne = nbC;
}

Carton::~Carton()
{
    //delete this->matrice;
}

void Carton::charger()
{
    const char * c = this->chemin.c_str();
    QImage image(c);
    this->nbLigne = image.height();
    this->nbColonne = image.width();
    QList<int> col;

    for(int i = 0; i < this->nbLigne; i++) {
        for(int j = 0; j < this->nbColonne; j++) {
            col.append(1);
        }
        this->matrice.append(col);
        col.clear();
    }
}

// NUL //
void Carton::editCarton(int ligne, string date, string chemin, string nom)
{
    this->chemin = chemin;
    this->nbLigne = ligne;
    this->date = date;
    this->nom = nom;

}

void Carton::affichageCarton()
{

    cout << "Nom du carton : "<<this->nom << endl;
    cout << "Nombre de ligne : "<<this->nbLigne << endl;
    cout << "Nombre de colonne : "<<this->nbColonne << endl;
    cout << "Donnée : " << endl;
    cout << "[" << endl;
    for (int i = 0; i< this->matrice.size() ; i++ ){
        for (int j = 0; j< this->matrice.value(i).size() ; j++ ){
            cout << this->matrice.value(i).value(j) << endl;
        }
        cout << endl;
    }
    cout << "]" << endl;
}

// NUL //
void Carton::saveCarton(string chemin)
{
    this->chemin = chemin;
}


QList<int> Carton::getLigne(int indexLigne) {
    return this->matrice.value(indexLigne);
}

bool Carton::finCarton(int indexLigne) {
    return (indexLigne == nbLigne-1);
}
