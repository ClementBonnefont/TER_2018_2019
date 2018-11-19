#include "carton.h"

Carton::Carton()
{
    QImage image("C:/Users/ville/Documents/UPSSITECH/2A/TER/carton20x240.bmp");
    nbLigne = image.width();
    nbColonne = image.height();
    QList<int> col;

    for(int i = 0; i < nbLigne; i++) {
        for(int j = 0; j < nbColonne; j++)
            col.append(255 - image.pixelIndex(i,j));
            matMotif.append(col);
            col.clear();
    }
}

QList<int> Carton::getLigne(int indexLigne) {return matMotif[indexLigne];}

bool Carton::finCarton(int indexLigne) {
    return (indexLigne == nbLigne-1);
}
