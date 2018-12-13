#include "memoire.h"



Memoire::Memoire(Carton carton, int ligne, string repertoireDeSauvegarde){
    this->cartonEnCours = carton;
    this->ligneEnCours = ligne;
    this->repertoireDeSauvegarde = repertoireDeSauvegarde;
}
void Memoire::startMemorisation(){
    this->start();
}
void Memoire::stopMemorisation(){
    this->quit();
}
void Memoire::setCartonEnCours(Carton carton){
    this->cartonEnCours = carton;
}

void Memoire::setLigneEnCours(int ligne){
    this->ligneEnCours = ligne;
}

//a finir

void Memoire::run()
{
    if(this->repertoireDeSauvegarde == ""){
        QDir dir;
        QString rep = dir.absolutePath();
        this->repertoireDeSauvegarde = rep.toStdString();
    }
    this->cartonEnCours.saveCartonAs(this->repertoireDeSauvegarde);

}
