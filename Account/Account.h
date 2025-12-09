#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "../Playlist/Playlist.h"
#include <iostream>
using namespace std;

struct Account {
    string username;
    string password;
    string role;
    Playlist playlist;
    Account* next; 
};

typedef Account* adrAccount;

struct AccountList {
    adrAccount first;
};

void createAccountList(AccountList &A);
void registerAccount(AccountList &A, string username, string password, string role);
adrAccount login(AccountList A, string username, string password);

#endif