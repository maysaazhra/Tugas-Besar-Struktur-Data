#include "Player.h"

void playLagu(lAddress lagu) {
    cout << "\nSedang memutar lagu: " 
         << lagu->info.judulLagu 
         << " - " << lagu->info.namaArtis << endl;
}

void stopLagu(lAddress &currentLagu) {
    currentLagu = Nil;
    cout << "\nLagu dihentikan.\n";
}

lAddress nextLibrary(lAddress &list, lAddress &currentLagu) { 
    if (list == Nil) {
        return Nil;
    }

    if (currentLagu == Nil) {
        currentLagu = list->prev;
        return currentLagu;
    }

    if (currentLagu->prev == Nil) {
        cout << "Sudah di lagu terakhir.\n";
        return currentLagu;
    }

    currentLagu = currentLagu->prev;
    return currentLagu;
}

lAddress prevLibrary(lAddress &list, lAddress &currentLagu) { 
    if (list == Nil) {
        return Nil;
    }

    if (currentLagu == Nil) {
        currentLagu = list->next;
        return currentLagu;
    }

    if (currentLagu->next == Nil) {
        cout << "Sudah di lagu pertama.\n";
        return currentLagu;
    }

    currentLagu = currentLagu->next;
    return currentLagu;
}


pAddress nextPlaylist(pAddress &list, lAddress &currentLagu) {
    if (list == Nil) {
        return Nil;
    }

    if (currentLagu == Nil) {
        currentLagu = list->lagu;
        return list;
    }

    pAddress node = list;
    while (node != Nil && node->lagu != currentLagu) {
        node = node->next;
    }

    if (node == Nil) {
        return Nil;
    }

    if (node->next != Nil) {
        currentLagu = node->next->lagu;
        return node->next;
    }

    cout << "Sudah di lagu terakhir.\n";
    return node;
}

pAddress prevPlaylist(pAddress &list, lAddress &currentLagu) {
    if (list == Nil) {
        return Nil;
    }

    if (currentLagu == Nil) {
        pAddress node = list;
        while (node->next != Nil) {
            node = node->next;
        }
        currentLagu = node->lagu;
        return node;
    }

    pAddress node = list;
    while (node != Nil && node->lagu != currentLagu) {
        node = node->next;
    }

    if (node == Nil) {
        return Nil;
    }

    if (node->prev != Nil) {
        currentLagu = node->prev->lagu;
        return node->prev;
    }

    cout << "Sudah di lagu pertama.\n";
    return node;
}

