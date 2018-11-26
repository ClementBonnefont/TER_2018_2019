#include "carton.h"

Carton::Carton(string chemin, string nom, string date, int nbL)
{
    this->chemin = chemin;
    this->nom = nom;
    this->date = date;
    this->nbLigne = nbL;
}
Carton::Carton(Carton& copy){
    this->chemin = copy.chemin;
    this->nom = copy.nom;
    this->date = copy.date;
    this->nbLigne = copy.nbLigne;
    QList<Couleur> ligne;
    for(int i = 0; i < nbLigne; i++) {
        for(int j = 0; j < 24; j++) {
            ligne.append(Couleur(copy.matrice[i][j].getR(),copy.matrice[i][j].getG(),copy.matrice[i][j].getB()));
        }
        matrice.append(ligne);
        ligne.clear();
    }
}



void Carton::charger()
{
    const char * c = this->chemin.c_str();
    QImage image(c);
    this->nbLigne = image.width();
    QList<Couleur> ligne;

    for(int i = 0; i < nbLigne; i++) {
        for(int j = 0; j < 24; j++) {
            if (j< image.height()){
                ligne.append(Couleur(qRed(image.pixel(i,j)), qGreen(image.pixel(i,j)), qBlue(image.pixel(i,j))));

            }else{
                ligne.append(Couleur(0, 0, 0));
            }

        }
        matrice.append(ligne);
        ligne.clear();
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
    cout << "Chemin : "<<this->chemin << endl;
    cout << "Donnée : " << endl;
    cout << "[" << endl;
    for (int i(0); i< this->matrice.size() ; i++ ){

        for (int j(0); j< this->matrice[i].size() ; j++ ){
            cout << this->matrice[i][j];
        }
        cout<< endl;
    }
    cout << "]" << endl;
}

Carton Carton::operator=(Carton copy){
    this->chemin = copy.chemin;
    this->nom = copy.nom;
    this->date = copy.date;
    this->nbLigne = copy.nbLigne;
    QList<Couleur> ligne;
    for(int i = 0; i < nbLigne; i++) {
        for(int j = 0; j < 24; j++) {
            ligne.append(Couleur(copy.matrice[i][j].getR(),copy.matrice[i][j].getG(),copy.matrice[i][j].getB()));
        }
        matrice.append(ligne);
        ligne.clear();
    }
    return *this;
}
void Carton::saveCartonAs(string chemin, string nom)
{
    Carton copi(*this);
    copi.chemin = chemin;
    copi.nom = nom;
    *this = copi;
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

    image.save(QString::fromStdString(this->nom + ".bmp"));

}


QList<Couleur> Carton::getLigne(int indexLigne) {
    return this->matrice[indexLigne];
}

bool Carton::finCarton(int indexLigne) {
    return (indexLigne == nbLigne-1);
}


QList<int> Carton::getLigneNoirBlanc(int indexLigne){
    QList<int> ligneNoirBlanc = QList<int>();
    foreach(Couleur item, this->matrice[indexLigne] )
    {
        if (item.isBlanc()){
            ligneNoirBlanc.append(0);
        }else if (item.isNoir()){
            ligneNoirBlanc.append(1);
        }
    }
    return ligneNoirBlanc;
}

 QList<QList<int>> Carton::getMatriceNoirBlanc(){
    QList<QList<int>> matriceNoirBlanc;
    for(int i(0); i<this->nbLigne; i++)
    {
        matriceNoirBlanc.append(this->getLigneNoirBlanc(i));
    }
    return matriceNoirBlanc;
}

 void Carton::afficheMatriceNoirBlanc(){
     QList<QList<int>> m = this->getMatriceNoirBlanc();
     for(int i(0); i<m.size();i++){
         for(int j(0); j<m[i].size();j++){
             cout << m[i][j] <<" ";
         }
         cout <<endl;
     }

     cout <<endl;
 }

 QList<QList<Couleur>> Carton::getMatrice(){
     return this->matrice;
 }
