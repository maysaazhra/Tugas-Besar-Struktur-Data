#ifndef LIBRARY_H
#define LIBRARY_H
#define Nil NULL

#include <iostream>
#include <string>
using namespace std;

struct Lagu {
    int idLagu;
    string judulLagu, namaArtis, genreLagu, albumLagu;
};

typedef Lagu dataLagu;
typedef struct libraryNode *lAddress;

struct libraryNode {
    dataLagu info;
    lAddress next;
    lAddress prev;
};

struct libraryList {
    lAddress first;
    lAddress last;
    int nextID;
};

bool isEmpty(libraryList list);
void createLibraryList(libraryList &list);
lAddress alokasiLibrary(int idBaru, string judul, string artis, string genre, string album);
void dealokasiLibrary(lAddress &nodeHapus);

void tambahLagu(libraryList &list, string judul, string artis, string genre, string album);
void tambahLaguDummy(libraryList &list, string judul, string artis, string genre, string album);
void tampilkanLibraryLagu(libraryList list, lAddress currentLagu);
void editLagu(libraryList &list, int id);
void hapusLagu(libraryList &list, int id);

lAddress cariLaguById(libraryList list, int id);
lAddress laguSimiliar(libraryList list, string artis, string genre, lAddress current);
lAddress laguAcak(libraryList list);



#endif