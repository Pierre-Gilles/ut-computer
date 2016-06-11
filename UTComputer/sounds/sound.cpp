#include "sound.h"

Sound::Sound(){

}


void Sound::play(){
    vector<string> listOfSounds;
    listOfSounds.push_back(":/sounds/que_trepasse.wav");
    QSound::play(":/sounds/que_trepasse.wav");
}
