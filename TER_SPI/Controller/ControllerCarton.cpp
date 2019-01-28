#include "ControllerCarton.h"

ControllerCarton::ControllerCarton(string chemin, string nom, string date, int nbL): carton(chemin, nom, date, nbL){
}
ControllerCarton::ControllerCarton(ControllerCarton& c){
    this->carton = c.carton;
}
QList<Couleur> ControllerCarton::getLigne(int ligne){
    return this->carton.getLigne(ligne);
}
void ControllerCarton::charger(string chemin){

    this->carton.charger(chemin);
}
void ControllerCarton::editCarton(int ligne, int colonne, Couleur couleur){
    this->carton.editCarton(ligne, colonne, couleur);
}
void ControllerCarton::saveCarton(){
    //si le carton n'a pas de chemin, il doit faire un appel a save carton as
    this->carton.saveCarton();
}
void ControllerCarton::saveCartonAs(string chemin, string nom){
    this->carton.saveCartonAs(chemin, nom);
}
bool ControllerCarton::finCarton(int ligne){
    return this->carton.finCarton(ligne);
}
QList<int> ControllerCarton::getLigneNoirBlanc(int ligne){
    return this->carton.getLigneNoirBlanc(ligne);
}
QList<QList<int>> ControllerCarton::getMatriceNoirBlanc(){
    return this->carton.getMatriceNoirBlanc();
}
QList<QList<Couleur>> ControllerCarton::getMatrice(){
    return this->carton.getMatrice();
}

Carton ControllerCarton::getCarton(){
    return this->carton;
}

int ControllerCarton::getNbColonneConnue(){
    return this->carton.getNbColonneConnue();
}
int ControllerCarton::getNbLigne(){
   return this->carton.getNbLigne();
}
