#include "./Account/Account.h"
#include "./Library/Library.h"
#include "./Library/Searching.h"
#include "./Playlist/Playlist.h"
#include "./Player/Player.h"

// Untuk mengarahkan ke menu admin
void menuAdmin(libraryList &L, Playlist &P, lAddress &currentLagu) {
    int pilihan;
    
    do {
        cout << "\n=== MENU ADMIN ===\n";
        cout << "1. Tambah Lagu\n";
        cout << "2. Lihat Library Lagu\n";
        cout << "3. Update Lagu\n";
        cout << "4. Hapus Lagu\n";
        cout << "0. Logout\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                dataLagu data;
                cout << "\n=== Input Data Lagu ===\n";

                cin.ignore();
                cout << "Masukkan Judul  : ";
                getline(cin, data.judulLagu);

                cout << "Masukkan Artis  : ";
                getline(cin, data.namaArtis);
                
                cout << "Masukkan Genre  : ";
                getline(cin, data.genreLagu);
                
                cout << "Masukkan Album  : ";
                getline(cin, data.albumLagu);
                
                tambahLagu(L, data.judulLagu, data.namaArtis, data.genreLagu, data.albumLagu);
                break;
            }
            case 2:
                tampilkanLibraryLagu(L, currentLagu);
                break;
            case 3: {
                tampilkanLibraryLagu(L, currentLagu);
                int id;
                cout << "Masukkan ID lagu yang ingin diupdate: ";
                cin >> id;

                editLagu(L, id);
                break;
            }
            case 4: {
                tampilkanLibraryLagu(L, currentLagu);
                int id;
                cout << "Masukkan ID lagu yang ingin dihapus: ";
                cin >> id;

                hapusPlaylist(P, id);
                hapusLagu(L, id);
                break;
            }
            case 0:
                cout << "Logout...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);
}

// untuk mengelola playlist
void menuPlaylist(libraryList &L, Playlist &P, lAddress &currentLagu) {
    int pilihan;
   
    do {
        tampilkanPlaylist(P, currentLagu);
        cout << "\n=== KELOLA PLAYLIST ===\n";
        cout << "1. Tambah Lagu ke Playlist\n";
        cout << "2. Hapus Lagu dari Playlist\n";
        cout << "3. Play\n";
        cout << "4. Stop\n";
        cout << "5. Next Lagu\n";
        cout << "6. Prev Lagu\n";
        cout << "0. Kembali ke Menu User\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                tampilkanLibraryLagu(L, currentLagu);
                int id;
                cout << "Masukkan ID lagu yang ingin ditambah: ";
                cin >> id;

                lAddress lagu = cariLaguById(L, id);
                if (lagu != Nil) {
                    tambahPlaylist(P, lagu);
                } else {
                    cout << "Lagu tidak ditemukan.\n";
                }
                break;
            }

            case 2: {
                tampilkanPlaylist(P, currentLagu);
                if (P.first != Nil) {
                    int id;
                    cout << "Masukkan ID lagu yang ingin dihapus: ";
                    cin >> id;
                    hapusPlaylist(P, id);
                }
                break;
            }

            case 3: {
                tampilkanPlaylist(P, currentLagu);
                int id;
                if (P.first == Nil) {
                    cout << "Playlist kosong, tidak ada lagu yang bisa diputar.\n";
                    return;
                }
                cout << "Masukkan ID lagu yang ingin diputar: ";
                cin >> id;
                lAddress lagu = cariLaguById(L, id);
                if (lagu != Nil) {
                    playLagu(lagu);
                    currentLagu = lagu;
                } else {
                    cout << "Lagu tidak ditemukan.\n";
                }
                break;
            }

            case 4: 
                stopLagu(currentLagu);
                break;

            case 5:
                nextPlaylist(P.first, currentLagu);
                break;

            case 6:
                prevPlaylist(P.first, currentLagu);
                break;

            default:
                break;
        }
    } while (pilihan != 0);
}

// untuk mengelola menu user
void menuUser(libraryList &L, Playlist &P, searchTree &T, lAddress &currentLagu) {
    int pilihan;

    do {
        tampilkanLibraryLagu(L, currentLagu);
        cout << "\n=== MENU USER ===\n";
        cout << "1. Cari Lagu\n";
        cout << "2. Lihat Playlist\n";
        cout << "3. Play\n";
        cout << "4. Stop\n";
        cout << "5. Next Lagu\n";
        cout << "6. Prev Lagu\n";
        cout << "0. Logout\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string judul;
                cout << "\n=== Pencarian Lagu Berdasarkan Judul ===\n";
                cout << "Masukkan judul lagu: ";
                cin.ignore();
                getline(cin, judul);

                sAddress hasil = searchByJudul(T, judul);
                if (hasil != Nil) {
                    cout << "\nLagu ditemukan!\n";
                    cout << "Judul : " << hasil->lagu->info.judulLagu << endl;
                    cout << "Artis : " << hasil->lagu->info.namaArtis << endl;
                    cout << "Genre : " << hasil->lagu->info.genreLagu << endl;
                    cout << "Album : " << hasil->lagu->info.albumLagu << endl;
                } else {
                    cout << "\nLagu dengan judul \"" << judul << "\" tidak ditemukan.\n";
                }
                break;
            }
            
            case 2:
                menuPlaylist(L,P,currentLagu);
                break;

            case 3: {
                tampilkanLibraryLagu(L, currentLagu);
                int id;
                cout << "Masukkan ID lagu yang ingin diputar: ";
                cin >> id;

                lAddress lagu = cariLaguById(L, id);
                if (lagu != Nil) {
                    playLagu(lagu);
                    currentLagu = lagu;
                } else {
                    cout << "Lagu tidak ditemukan.\n";
                }
                break;
            }

            case 4:
                stopLagu(currentLagu);
                break;

            case 5: {
                if (currentLagu == Nil) {
                    lAddress HasilAcak = laguAcak(L);
                    playLagu(HasilAcak);
                    currentLagu = HasilAcak;
                    break;
                }

                lAddress hasilSimiliar = laguSimiliar(L, currentLagu->info.namaArtis, currentLagu->info.genreLagu, currentLagu);
                if (hasilSimiliar != Nil) {
                    currentLagu = hasilSimiliar;
                } else {
                    cout << "Lagu tidak ada yg sama.\n";
                    lAddress HasilAcak = laguAcak(L);
                    currentLagu = HasilAcak;
                }
                break;
            }

            case 6: {
                if (currentLagu == Nil) {
                    lAddress HasilAcak = laguAcak(L);
                    playLagu(HasilAcak);
                    currentLagu = HasilAcak;
                    break;
                }

                lAddress hasilSimiliar = laguSimiliar(L, currentLagu->info.namaArtis, currentLagu->info.genreLagu, currentLagu);
                if (hasilSimiliar != Nil) {
                    currentLagu = hasilSimiliar;
                } else {
                    cout << "Lagu tidak ada yg sama.\n";
                    lAddress HasilAcak = laguAcak(L);
                    currentLagu = HasilAcak;
                }
                break;
            }

            case 0:
                cout << "Logout...\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);
}


int main() {
    int role;
    string username, password;
    
    AccountList akun;
    createAccountList(akun);

    libraryList L;
    createLibraryList(L);

    Playlist P;
    createPlaylist(P);

    searchTree T;
    createSearchTree(T);

    adrAccount currentUser = NULL;
    lAddress currentLagu = Nil;

    // Menambahkan lagu dummy ke library
    tambahLaguDummy(L, "Hati yang Kau Sakiti", "Rossa", "Pop", "Rossa Collection");
    tambahLaguDummy(L, "Weekend", "Coldplay", "Alternative Rock", "X&Y");
    tambahLaguDummy(L, "Perfect", "Ed Sheeran", "Pop", "Divide");
    tambahLaguDummy(L, "Lathi", "Weird Genius", "EDM", "Lathi");
    tambahLaguDummy(L, "Yellow", "Coldplay", "Alternative Rock", "Parachutes");
    // tambahLaguDummy(L, "Paradise", "Coldplay", "Alternative Rock", "Mylo Xyloto");
    // tambahLaguDummy(L, "Shape of You", "Ed Sheeran", "Pop", "Divide");
    // tambahLaguDummy(L, "Someone Like You", "Adele", "Pop", "21");
    // tambahLaguDummy(L, "Believer", "Imagine Dragons", "Rock", "Evolve");
    // tambahLaguDummy(L, "Monokrom", "Tulus", "Pop", "Monokrom");
    
    // Menambahkan lagu ke tree
    tambahLaguTree(T, L);

    // Akun admin default
    registerAccount(akun, "admin", "1234", "admin");
   
    do {
        cout << "\n=== APLIKASI PEMUTAR MUSIK ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> role;

        switch (role) {
            case 1:
                cout << "Masukkan username: ";
                cin >> username;
                cout << "Masukkan password: ";
                cin >> password;
                registerAccount(akun, username, password, "user");
                break;

            case 2:
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;
                currentUser = login(akun, username, password);

                if (currentUser != NULL) {
                    if (currentUser->role == "admin") {
                        menuAdmin(L, P, currentLagu);
                    } else {
                        menuUser(L, P, T, currentLagu);
                    }
                }
                break;

            case 0:
                cout << "Terima kasih telah menggunakan aplikasi!\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (role != 0);

    return 0;
}
