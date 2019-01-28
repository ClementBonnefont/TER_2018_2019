#include "Model/couleur.h"


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

    if(this->r == 255 && this->g == 255 && this->b == 255){
        return true;
    }
    if(this->r == 223 && this->g == 223 && this->b == 223){
        return true;
    }
    if(this->r == 255 && this->g == 175 && this->b == 175){
        return true;
    }
    if(this->r == 69 && this->g == 239 && this->b == 69){
        return true;
    }
    if(this->r == 128 && this->g == 144 && this->b == 255){
        return true;
    }
    if(this->r == 213 && this->g == 212 && this->b == 45){
        return true;
    }
    if(this->r == 255 && this->g == 127 && this->b == 238){
        return true;
    }
    if(this->r == 255 && this->g == 154 && this->b == 88){
        return true;
    }
    if(this->r == 223 && this->g == 175 && this->b == 255){
        return true;
    }
    if(this->r == 179 && this->g == 213 && this->b == 232){
        return true;
    }
    if(this->r == 255 && this->g == 186 && this->b == 165){
        return true;
    }
    if(this->r == 178 && this->g == 255 && this->b == 68){
        return true;
    }
    if(this->r == 158 && this->g == 232 && this->b == 255){
        return true;
    }
    if(this->r == 255 && this->g == 255 && this->b == 128){
        return true;
    }
    if(this->r == 248 && this->g == 200 && this->b == 216){
        return true;
    }
    if(this->r == 255 && this->g == 212 && this->b == 165){
        return true;
    }
    if(this->r == 196 && this->g == 175 && this->b == 237){
        return true;
    }

        return false;
}
bool Couleur::isNoir(){
    if(this->r == 0 && this->g == 0 && this->b == 0){
        return true;
    }
    if(this->r == 223 && this->g == 11 && this->b == 11){
        return true;
    }
    if(this->r == 12 && this->g == 144 && this->b == 11){
        return true;
    }
    if(this->r == 6 && this->g == 12 && this->b == 255){
        return true;
    }
    if(this->r == 255 && this->g == 255 && this->b == 11){
        return true;
    }
    if(this->r == 255 && this->g == 23 && this->b == 223){
        return true;
    }
    if(this->r == 255 && this->g == 101 && this->b == 11){
        return true;
    }
    if(this->r == 128 && this->g == 51 && this->b == 207){
        return true;
    }
    if(this->r == 41 && this->g == 93 && this->b == 122){
        return true;
    }
    if(this->r == 177 && this->g == 45 && this->b == 11){
        return true;
    }
    if(this->r == 79 && this->g == 130 && this->b == 11){
        return true;
    }
    if(this->r == 11 && this->g == 108 && this->b == 221){
        return true;
    }
    if(this->r == 191 && this->g == 191 && this->b == 11){
        return true;
    }
    if(this->r == 226 && this->g == 35 && this->b == 96){
        return true;
    }
    if(this->r == 173 && this->g == 90 && this->b == 11){
        return true;
    }
    if(this->r == 68 && this->g == 35 && this->b == 137){
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

