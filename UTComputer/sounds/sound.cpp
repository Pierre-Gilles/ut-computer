#include "sound.h"

using namespace std;

Sound::Sound(){
    listOfSounds.push_back(":/sounds/attention.wav");
    listOfSounds.push_back(":/sounds/binz.wav");
    listOfSounds.push_back(":/sounds/boule_merdasse.wav");
    listOfSounds.push_back(":/sounds/c_est_cela_oui.wav");
    listOfSounds.push_back(":/sounds/Les_cons_tontons_flingeurs.wav");
    listOfSounds.push_back(":/sounds/monumentale_erreur.wav");
    listOfSounds.push_back(":/sounds/mortecouille.wav");
    listOfSounds.push_back(":/sounds/pas_jour_faire_chier_kamelott.wav");
    listOfSounds.push_back(":/sounds/que_trepasse.wav");
    listOfSounds.push_back(":/sounds/wou_pinaise.wav");
    listOfSounds.push_back(":/sounds/you_shall_not_pass.wav");
    srand(time(NULL));
}


void Sound::play(){

    // if all sounds have been played, clear listOfSounds_AlreadyPlayed
    if (listOfSounds_AlreadyPlayed.size() == listOfSounds.size())
        listOfSounds_AlreadyPlayed.clear();

    //generate random int between 0 and listOfSounds.size() while we don't found a sound not played yet
    int random = rand() % listOfSounds.size();
    vector<string>::iterator it = find (listOfSounds_AlreadyPlayed.begin(), listOfSounds_AlreadyPlayed.end(), listOfSounds.at(random));
    while (it != listOfSounds_AlreadyPlayed.end()) {
        random = rand() % listOfSounds.size();
        it = find (listOfSounds_AlreadyPlayed.begin(), listOfSounds_AlreadyPlayed.end(), listOfSounds.at(random));
    }

    // here we've found a sound not played yet
    QString s = QString::fromStdString(listOfSounds.at(random));
    listOfSounds_AlreadyPlayed.push_back(listOfSounds.at(random));
    QSound::play(s);
}
