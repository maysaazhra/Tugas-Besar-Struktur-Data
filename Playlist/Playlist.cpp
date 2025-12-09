#include "Playlist.h"

void createPlaylist(Playlist &P) {
    P.first = Nil;
    P.last = Nil;
}

void tambahPlaylist(Playlist &P, lAddress lagu) {
    pAddress nodeBantu = P.first;
    while (nodeBantu != Nil) {
        if (nodeBantu->lagu->info.idLagu == lagu->info.idLagu) {
            cout << "Lagu sudah ada di playlist!\n";
            return;
        }
        nodeBantu = nodeBantu->next;
    }

    pAddress node = new playlistNode;
    node->lagu = lagu;
    node->next = Nil;
    node->prev = Nil;

    if (P.first == Nil) {
        P.first = P.last = node;
    } else {
        P.last->next = node;
        node->prev = P.last;
        P.last = node;
    }

    cout << "Lagu berhasil ditambahkan ke playlist!\n";
}


void hapusPlaylist(Playlist &P, int id) {
    if (P.first == Nil) {
        cout << "Playlist kosong. Tidak ada yang dihapus.\n";
        return;
    }

    pAddress node = P.first;

    while (node != Nil) {
        if (node->lagu->info.idLagu == id) {

            // CASE 1: hanya satu node
            if (node == P.first && node == P.last) {
                P.first = P.last = Nil;
            }
            // CASE 2: hapus node pertama
            else if (node == P.first) {
                P.first = node->next;
                P.first->prev = Nil;
            }
            // CASE 3: hapus node terakhir
            else if (node == P.last) {
                P.last = node->prev;
                P.last->next = Nil;
            }
            // CASE 4: hapus node tengah
            else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }

            delete node;
            cout << "Lagu berhasil dihapus dari playlist!\n";
            return;
        }

        node = node->next;
    }

    cout << "Lagu tidak ada di playlist.\n";
}

void removeFromPlaylist(Playlist &P, int id) {
    if (P.first == NULL) {
        cout << "Playlist kosong, tidak ada lagu yang bisa dihapus.\n";
        return;
    }

    pAddress node = P.first;

    while (node != NULL) {
        // cek apakah lagu yang ditunjuk masih valid dan memiliki id yang sesuai
        if (node->lagu != NULL && node->lagu->info.idLagu == id) {
            
            // CASE 1: node tunggal (hanya satu di playlist)
            if (node == P.first && node == P.last) {
                P.first = P.last = NULL;
            }
            // CASE 2: hapus node pertama
            else if (node == P.first) {
                P.first = node->next;
                if (P.first) P.first->prev = NULL;
            }
            // CASE 3: hapus node terakhir
            else if (node == P.last) {
                P.last = node->prev;
                if (P.last) P.last->next = NULL;
            }
            // CASE 4: hapus node di tengah
            else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }

            delete node;
            cout << "Lagu dengan ID " << id << " berhasil dihapus dari playlist.\n";
            return;
        }

        node = node->next;
    }

    cout << "Lagu dengan ID " << id << " tidak ditemukan di playlist.\n";
}



void tampilkanPlaylist(Playlist P, lAddress currentLagu) {
    if (P.first == Nil) {
        cout << "\n=== PLAYLIST KOSONG ===\n";
        return;
    }

    cout << "\n=== DAFTAR PLAYLIST ===\n";
    cout << "ID | Judul | Artis\n";
    cout << "-------------------------------------------------\n";

    pAddress node = P.first;

    while (node != Nil) {
        bool isPutar = (node->lagu == currentLagu);

        cout << node->lagu->info.idLagu << " | "
             << node->lagu->info.judulLagu << " | "
             << node->lagu->info.namaArtis;
        if (isPutar){
            cout << "   <-- [Sedang diputar]";
        }
        cout << endl;
        node = node->next;
    }

    cout << "=================================================\n";
}


// void tampilkanPlaylist(Playlist P) {
//      if (P.first == Nil) {
//         cout << "\n=== PLAYLIST KOSONG ===\n";
//         return;
//     }

//     cout << "\n=== DAFTAR PLAYLIST ===\n";
//     cout << "ID | Judul | Artis\n";
//     cout << "---------------------------------\n";

//     pAddress node = P.first;

//     while (node != Nil) {
//         cout << node->lagu->info.idLagu << " | "
//              << node->lagu->info.judulLagu << " | "
//              << node->lagu->info.namaArtis << endl;

//         node = node->next;
//     }

//     cout << "=================================\n";
// }

