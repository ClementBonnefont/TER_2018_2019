#include "Couleur.h"


Couleur::Couleur(int r, int g, int b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}


void Couleur::setBlancNoir(){
    if(this->isNoir()){
        this->r = 255;
        this->g = 255;
        this->b = 255;
    }else if(this->isBlanc()){
        this->r = 0;
        this->g = 0;
        this->b = 0;
    }
}
bool Couleur::isBlanc(){
    if(this->r != 0 && this->g != 0 && this->b != 0){
        return true;
    }
        return false;
}
bool Couleur::isNoir(){
    if(this->r == 0 && this->g == 0 && this->b == 0){
        return true;
    }
        return false;
}
void Couleur::setR(int r){
    this->r = r;
}
void Couleur::setB(int b){
    this->b = b;
}
void Couleur::setG(int g){
    this->g = g;
}

int Couleur::getR(){
    return this->r;
}
int Couleur::getB(){
    return this->b;
}
int Couleur::getG(){
    return this->g;
}

void Couleur::editCouleur(int r, int g, int b){
    this->r = r;
    this->g = g;
    this->b = b;
}
void Couleur::affichageCouleur(){
    cout << "RGB : (" <<this->r <<", "<<this->g<<", "<<this->b<<")";
}

ostream& operator<<(ostream& out,Couleur& c){
   out << "(" <<c.r <<", "<<c.g<<", "<<c.b<<")";
    return out;
}

QTextStream& operator <<(QTextStream& out, Couleur& c){
    out << "(" <<c.r <<", "<<c.g<<", "<<c.b<<")";
     return out;
}

