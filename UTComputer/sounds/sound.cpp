#include "sound.h"

Sound::Sound(){

}


void Sound::play(){
    QSound::play(":/sounds/que_trepasse.wav");
}
