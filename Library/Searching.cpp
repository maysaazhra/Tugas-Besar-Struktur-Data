#include "Searching.h"
#include <cctype>

void createSearchTree(searchTree &tree) {
    tree = Nil;
}

sAddress alokasiSearch(lAddress laguBaru) {
    sAddress P = new searchNode;
    P->lagu = laguBaru;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void insertTree(searchTree &tree, sAddress nodeBaru) {
    if (tree == Nil) {
        tree = nodeBaru;
        return;
    } else if (nodeBaru->lagu->info.judulLagu < tree->lagu->info.judulLagu) {
        insertTree(tree->left, nodeBaru);
    } else {
        insertTree(tree->right, nodeBaru);
    }
}

sAddress searchByJudul(searchTree tree, string judul) {
    string key = toLower(judul);
    sAddress nodeBantu = tree;

    while (nodeBantu != Nil) {
         string nodeJudul = toLower(nodeBantu->lagu->info.judulLagu);

        if (key == nodeJudul) {
            return nodeBantu;
        }

        if (judul < nodeBantu->lagu->info.judulLagu){
            nodeBantu = nodeBantu->left;
        } else {
            nodeBantu = nodeBantu->right;
        }
    }

    return Nil;
}

void tambahLaguTree(searchTree &tree, libraryList L) {
    lAddress nodeBantu = L.first;

    while (nodeBantu != Nil) {
        insertTree(tree, alokasiSearch(nodeBantu));
        nodeBantu = nodeBantu->next;
    }
}


string toLower(string s) {
    for (char &c : s) {
        c = tolower(c);
    }
    return s;
}
