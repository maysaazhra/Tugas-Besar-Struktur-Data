#include "Library.h"
#include <cstdlib>

bool isEmpty(libraryList list){
    return list.first == Nil;
};

void createLibraryList(libraryList &list){
    list.first = Nil;
    list.last = Nil;
    list.nextID = 1;
};

lAddress alokasiLibrary(int id, string judul, string artis, string genre, string album){
    lAddress nodeBaru = new libraryNode;
    nodeBaru->info.idLagu = id;
    nodeBaru->info.judulLagu = judul;
    nodeBaru->info.namaArtis = artis;
    nodeBaru->info.genreLagu = genre;
    nodeBaru->info.albumLagu = album;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasiLibrary(lAddress &node) {
    node->next = Nil;
    delete node;
}

// insert first(dll)
void tambahLagu(libraryList &list, string judul, string artis, string genre, string album){
    int idBaru = list.nextID;  // ambil ID
    list.nextID++;            // increment ID untuk lagu berikutnya

    lAddress nodeBaru = alokasiLibrary(idBaru, judul, artis, genre, album);

    // insert first
    if(isEmpty(list)){
        list.first = list.last = nodeBaru;
    } else {
        nodeBaru->next = list.first;
        list.first->prev = nodeBaru;
        list.first = nodeBaru;
    }

    cout << "Lagu berhasil ditambahkan!\n";
}

void tambahLaguDummy(libraryList &list, string judul, string artis, string genre, string album){
    int idBaru = list.nextID;  // ambil ID
    list.nextID++;            // increment ID untuk lagu berikutnya

    lAddress nodeBaru = alokasiLibrary(idBaru, judul, artis, genre, album);

    // insert first
    if(isEmpty(list)){
        list.first = list.last = nodeBaru;
    } else {
        nodeBaru->next = list.first;
        list.first->prev = nodeBaru;
        list.first = nodeBaru;
    }
}

void tampilkanLibraryLagu(libraryList list, lAddress currentLagu) {
    if (list.first == Nil) {
        cout << "\n=== LIBRARY LAGU KOSONG ===\n";
        cout << "Belum ada lagu dalam library.\n";
        return;
    }

    cout << "\n=== LIBRARY LAGU ===\n";
    cout << "ID | Judul | Artis | Genre | Album\n";
    cout << "-------------------------------------------------------------\n";

    lAddress nodeBantu = list.last;

    while (nodeBantu != Nil) {
        bool isPutar = (nodeBantu == currentLagu);

        cout << nodeBantu->info.idLagu << " | "
             << nodeBantu->info.judulLagu << " | "
             << nodeBantu->info.namaArtis << " | "
             << nodeBantu->info.genreLagu << " | "
             << nodeBantu->info.albumLagu;
        if (isPutar){
            cout << "   <-- [Sedang diputar]";
        }
        cout << endl;
        nodeBantu = nodeBantu->prev;
    }

    cout << "=============================================================\n";
}


void editLagu(libraryList &list, int id) {
    string judul, artis, genre, album;

    if (list.first == Nil) {
        cout << "Library lagu masih kosong!\n";
        return;
    }

    lAddress nodeBantu = list.first;

    while (nodeBantu != Nil) {
        if (nodeBantu->info.idLagu == id) {
            cout << "\n=== DATA LAGU SAAT INI ===\n";
            cout << "Judul : " << nodeBantu->info.judulLagu << endl;
            cout << "Artis : " << nodeBantu->info.namaArtis << endl;
            cout << "Genre : " << nodeBantu->info.genreLagu << endl;
            cout << "Album : " << nodeBantu->info.albumLagu << endl;

            cin.ignore();
            cout << "\n=== MASUKKAN DATA BARU (Enter untuk skip) ===\n";

            cout << "Masukkan Judul baru : ";
            getline(cin, judul);

            cout << "Masukkan Artis baru : ";
            getline(cin, artis);

            cout << "Masukkan Genre baru : ";
            getline(cin, genre);

            cout << "Masukkan Album baru : ";
            getline(cin, album);

            if (!judul.empty()){
                nodeBantu->info.judulLagu = judul;
            }
            if (!artis.empty()) {
                nodeBantu->info.namaArtis = artis;
            }
            if (!genre.empty()) {
                nodeBantu->info.genreLagu = genre;
            }
            if (!album.empty()) {
                nodeBantu->info.albumLagu = album;
            }

            cout << "\nLagu berhasil diupdate!\n";
            return;
        }

        nodeBantu = nodeBantu->next;
    }

    cout << "Lagu dengan ID " << id << " tidak ditemukan!\n";
}


void hapusLagu(libraryList &list, int id) {
    if (list.first == Nil) {
        cout << "Library lagu masih kosong!\n";
        return;
    }

    lAddress nodeBantu = list.first;

    while (nodeBantu != Nil) {
        if (nodeBantu->info.idLagu == id) {
            // CASE 1: hapus node pertama
            if (list.first == list.last) {
                list.first = Nil;
                list.last = Nil;
            }
            // CASE 2: hapus node terakhir
            else if (nodeBantu == list.first) {
                list.first = nodeBantu->next;
                list.first->prev = Nil;
            }
            // CASE 2: hapus node terakhir
            else if (nodeBantu == list.last) {
                list.last = nodeBantu->prev;
                list.last->next = Nil;
            }
            // CASE 3: hapus node di tengah
            else {
                nodeBantu->prev->next = nodeBantu->next;
                nodeBantu->next->prev = nodeBantu->prev;
            }
            
            dealokasiLibrary(nodeBantu);
            cout << "Lagu berhasil dihapus!\n";
            return;
        }
        nodeBantu = nodeBantu->next;
    }

    cout << "Lagu dengan ID " << id << " tidak ditemukan!\n";
}


lAddress cariLaguById(libraryList list, int id) {
    lAddress nodeBantu = list.first;

    while (nodeBantu != Nil) {
        if (nodeBantu->info.idLagu == id) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->next;
    }

    return Nil;
}

lAddress laguSimiliar(libraryList list, string artis, string genre, lAddress current) {
    if (list.first == Nil || current == Nil) {
        return Nil;
    }

    lAddress nodeBantu = current->next;

    while (nodeBantu != Nil) {
        if (nodeBantu->info.namaArtis == artis || nodeBantu->info.genreLagu == genre) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->next;
    }

    nodeBantu = list.first;
    while (nodeBantu != current) {
        if (nodeBantu->info.namaArtis == artis || nodeBantu->info.genreLagu == genre) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->next;
    }

    return Nil;
}

lAddress laguAcak(libraryList list) {
    if (list.first == Nil) {
        return Nil;
    }

    int count = 0;
    lAddress node = list.first;
    while (node != Nil) {
        count++;
        node = node->next;
    }

    int acak = rand() % count;

    node = list.first;
    while (acak--) {
        node = node->next;
    }

    return node;
}

