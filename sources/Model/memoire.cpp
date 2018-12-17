#include "memoire.h"


/*
 * string repertoireDeSauvegarde;
    Carton cartonEnCours;
    int ligneEnCours;
    int EtatPresent;
 *
 * */
inline char separator()
{
#ifdef _WIN32
    return '\\';
#else
    return '/';
#endif
}
string Memoire::REPERTOIRE_DE_SAUVEGARDE = "C:\\Users\\clement\\Desktop\\TER\\";

bool Memoire::CHARGE_MEMOIRE(){
    QFile file(QString::fromStdString(REPERTOIRE_DE_SAUVEGARDE + separator() +"Sauvegarde.txt"));
    if (!file.exists()){
        return false;
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        // Impossible de créer ou ouvrir le fichier!
        return false;

    QTextStream in(&file);
    InterfaceDonnees::MEMO_ETAT_PRESENT = 2;
    InterfaceDonnees::LIGNES_EN_COURS = in.readLine().toInt();
    string chemin =  in.readLine().toStdString();
    InterfaceDonnees::CARTON_EN_COURS.charger(chemin);
    file.remove();
    return true;

}
bool Memoire::SAVE_MEMOIRE(){
    QFile file(QString::fromStdString(REPERTOIRE_DE_SAUVEGARDE + separator() +"Sauvegarde.txt"));
    if (!file.open(QIODevice::Text | QIODevice::WriteOnly)){
        // Impossible de créer ou ouvrir le fichier!
        return false;
    }

    QTextStream t(&file);

    t << InterfaceDonnees::LIGNES_EN_COURS << endl;
    t << InterfaceDonnees::CARTON_EN_COURS << endl;
    file.close();
    return true;
}
