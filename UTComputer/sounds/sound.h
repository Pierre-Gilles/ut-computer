#ifndef SOUND_H
#define SOUND_H

#include <QSound>
#include <QMediaPlayer>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

class Sound {
    vector<string> listOfSounds;
    vector<string> listOfSounds_AlreadyPlayed;
public:
    Sound();
    void play();
};

#endif // SOUND_H
