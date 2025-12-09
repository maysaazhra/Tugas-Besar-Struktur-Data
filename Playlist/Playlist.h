#ifndef PLAYLIST_H
#define PLAYLIST_H
#define Nil NULL

#include "../Library/Library.h"
#include <iostream>
#include <string>
using namespace std;

typedef struct playlistNode *pAddress;

struct playlistNode {
    lAddress lagu;
    pAddress next;
    pAddress prev;
};

struct Playlist {
    pAddress first;
    pAddress last;
};

void createPlaylist(Playlist &P);
void tambahPlaylist(Playlist &P, lAddress lagu);
void hapusPlaylist(Playlist &P, int id);
void removeFromPlaylist(Playlist &P, int id);
void tampilkanPlaylist(Playlist P, lAddress currentLagu);


#endif