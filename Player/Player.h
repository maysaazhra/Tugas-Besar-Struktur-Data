#ifndef PLAYER_H
#define PLAYER_H
#define Nil NULL

#include "../Library/Library.h"
#include "../Playlist/Playlist.h"
#include <iostream>
#include <string>
using namespace std;

void playLagu(lAddress lagu);
void stopLagu(lAddress &currentLagu);

// next prev library
lAddress nextLibrary(lAddress &list, lAddress &currentLagu);
lAddress prevLibrary(lAddress &list, lAddress &currentLagu);

// next prev playlist
pAddress nextPlaylist(pAddress &list, lAddress &currentLagu);
pAddress prevPlaylist(pAddress &list, lAddress &currentLagu);

#endif