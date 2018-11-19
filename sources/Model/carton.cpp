#include "carton.h"

Carton::Carton(string chemin, string nom, string date, int nbL, int nbC)
{
    this->chemin = chemin;
    this->nom = nom;
    this->date = date;
    this->nbLigne = nbL;
    this->nbColonne = nbC;
}


void Carton::charger()
{
    const char * c = this->chemin.c_str();
    QImage image(c);
    this->nbLigne = image.width();
    this->nbColonne = image.height();
    QList<Couleur> ligne;

    for(int i = 0; i < nbLigne; i++) {
        for(int j = 0; j < nbColonne; j++) {
            ligne.append(Couleur(qRed(image.pixel(i,j)), qGreen(image.pixel(i,j)), qBlue(image.pixel(i,j))));
            matrice.append(ligne);
            ligne.clear();
        }
    }
}

void Carton::editCarton(int ligne, int colonne, Couleur couleur)
{
    this->matrice[ligne][colonne] = couleur;
}

void Carton::affichageCarton()
{

    cout << "Nom du carton : "<<this->nom << endl;
    cout << "Nombre de ligne : "<<this->nbLigne << endl;
    cout << "Nombre de colonne : "<<this->nbColonne << endl;
    cout << "Donnée : " << endl;
    cout << "[" << endl;
    for (int i(0); i< this->matrice.size() ; i++ ){
        for (int j(0); j< this->matrice[i].size() ; j++ ){
            cout << this->matrice[i][j] << endl;
        }
        cout << endl;
    }
    cout << "]" << endl;
}


void Carton::saveCartonAs(string chemin, string nom)
{
    this->chemin = chemin;
    this->nom = nom;
    this->saveCarton();
}

//sauvegarde le carton en fonction du bon format
void Carton::saveCarton()
{
    QImage image(this->nbLigne, this->nbColonne, QImage::Format_RGB32);
    QRgb value;

    for(int i = 0; i < image.width(); i++) {
        for(int j = 0; j < image.height(); j++) {
            value = qRgb(this->matrice[i][j].getR(), this->matrice[i][j].getG(), this->matrice[i][j].getB());
            image.setPixel(i, j, value);
        }
    }
    QString repertoire = QString::fromStdString(this->chemin);
    image.setText(QString::fromStdString(this->nom), repertoire);
    image.save(image.text(QString::fromStdString(this->nom)));

}


QList<Couleur> Carton::getLigne(int indexLigne) {return this->matrice[indexLigne];}

bool Carton::finCarton(int indexLigne) {
    return (indexLigne == nbLigne-1);
}
