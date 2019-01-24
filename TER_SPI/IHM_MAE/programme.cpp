#include "programme.h"

Programme::Programme()
{
    // Constructeur
}

void Programme::debutTissage() {
    InterfaceDonnees::DEBUT = true;
}

void Programme::finTissage() {
    InterfaceDonnees::FIN = true;
}

void Programme::pauseTissage() {
    InterfaceDonnees::PAUSE = true;
}

void Programme::repriseTissage() {
    InterfaceDonnees::REPRISE = true;
}

void Programme::urgenceTissage() {
    InterfaceDonnees::URGENCE = true;
}

void Programme::retourTissage() {
    InterfaceDonnees::REDEMARRAGE = true;
}

void Programme::setTor(bool val) {
    InterfaceSimu::valTOR = val;
}

void Programme::setCadre(int i) {
    InterfaceSimu::valEA[i] = true;
}

void Programme::setSens(bool val) {
    InterfaceDonnees::SENS_NORMAL = val;
}
