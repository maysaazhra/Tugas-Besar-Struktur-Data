#ifndef SEARCHING_H
#define SEARCHING_H
#define Nil NULL

#include "Library.h"
#include <iostream>
#include <string>
using namespace std;

typedef struct searchNode *sAddress;

struct searchNode {
    lAddress lagu;
    sAddress left;
    sAddress right;
};

typedef sAddress searchTree;    


void createSearchTree(searchTree &T);
sAddress alokasiSearch(lAddress laguBaru);
void insertTree(searchTree &T, sAddress laguBaru);
sAddress searchByJudul(searchTree T, string judul);
void tambahLaguTree(searchTree &T, libraryList L);
string toLower(string s);

#endif