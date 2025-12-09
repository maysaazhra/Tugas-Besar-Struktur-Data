#include "Account.h"

void createAccountList(AccountList &A) {
    A.first = NULL;
}
void registerAccount(AccountList &A, string username, string password, string role) {
    adrAccount nodeBantu = A.first;

    // cek apakah username sudah ada
    while (nodeBantu != NULL) {
        if (nodeBantu->username == username) {
            cout << "\nUsername sudah digunakan. Silakan pilih yang lain.\n";
            return;
        }
        nodeBantu = nodeBantu->next;
    }

    // jika belum ada, buat akun baru
    adrAccount node = new Account;
    node->username = username;
    node->password = password;
    node->role = role;
    createPlaylist(node->playlist); // playlist kosong di awal
    node->next = A.first;
    A.first = node;

    if (node->role != "admin") {
        cout << "\nRegistrasi berhasil! Silakan login.\n";
    }
}


adrAccount login(AccountList A, string username, string password) {
    adrAccount node = A.first;

    while (node != NULL) {
        if (node->username == username && node->password == password) {
            cout << "\nLogin berhasil. Selamat datang, " << username << "!\n";
            return node;
        }
        node = node->next;
    }

    cout << "\nUsername atau password salah!\n";
    return NULL;
}


