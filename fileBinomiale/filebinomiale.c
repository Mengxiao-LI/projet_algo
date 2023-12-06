
#include <stdio.h>
#include <string.h>
#include "filebinomiale.h"

//primitive tournois
int Degre(Tournoi t) {
    int degre = 0;
    ArbreBinomialeNode* current = t.racine->child;

    while (current != NULL) {
        degre++;
        current = current->frere;
    }
    return degre;
}

bool EstVide_T(Tournoi t) {
    return t.racine == NULL;
}
Tournoi Union2Tid(Tournoi t1, Tournoi t2) {
    if (t1.racine == NULL) return t2;
    if (t2.racine == NULL) return t1;
    Tournoi newTournoi;

    // comparer les valeurs des tournois,la plus petite valeur est la racine
    if (t1.racine->data < t2.racine->data) {
        // inserer la racine de t2 a la droite de t1
        t2.racine->parent = t1.racine;
        ArbreBinomialeNode *current = t1.racine->child;
        if (current == NULL) {
            t1.racine->child = t2.racine;
        } else {
            while (current->frere != NULL) {
                current = current->frere;
            }
            current->frere = t2.racine;
        }
        newTournoi.racine = t1.racine;
    } else {
        // inserer la racine de t1 a la droite de t2
        t1.racine->parent = t2.racine;
        ArbreBinomialeNode *current = t2.racine->child;
        if (current == NULL) {
            t2.racine->child = t1.racine;
        } else {
            while (current->frere != NULL) {
                current = current->frere;
            }
            current->frere = t1.racine;
        }
        newTournoi.racine = t2.racine;
    }

    return newTournoi;
}

FileBinomiale File(Tournoi T) {
    // creer un nouveau file binomiale vide
    FileBinomiale newFb;
    newFb.size = 1; // cette file n'a que un seul tournois
    newFb.file = malloc(sizeof(Tournoi*) * newFb.size);

    newFb.file[0] = &T;

    return newFb;
}


//primitive file binomiale
bool EstVide_FB(FileBinomiale F) {
    return F.file == NULL;
}

Tournoi* MinDeg(FileBinomiale fb) {
    //fb null
    if (fb.size == 0) {
        return NULL;
    }
    Tournoi* minTournoi = NULL;
    int minDeg = INT_MAX;
    for (int i = 0; i < fb.size; i++) {
        int currentDeg = Degre(*(fb.file[i]));

        if (currentDeg < minDeg) {
            minDeg = currentDeg;
            minTournoi = fb.file[i];
        }
    }
    return minTournoi;
}

FileBinomiale Reste(FileBinomiale fb) {
    // fb NULL
    if (fb.size == 0) {
        return fb;
    }
    // find the minimum tournois
    Tournoi* minTournoi = MinDeg(fb);
    // creer un nouveau fb vide
    FileBinomiale newFb;
    newFb.size = fb.size - 1;
    newFb.file = malloc(sizeof(Tournoi*) * newFb.size);
    // copy tous les tournois sauf le minimum
    for (int i = 0, j = 0; i < fb.size; i++) {
        if (fb.file[i] != minTournoi) {
            newFb.file[j++] = fb.file[i];
        }
    }
    return newFb;
}

FileBinomiale AjoutMin(Tournoi T, FileBinomiale F) {
    // creer un nouveau fb vide
    FileBinomiale newFb;
    newFb.size = F.size + 1;
    newFb.file = malloc(sizeof(Tournoi*) * newFb.size);
    // considerer le tournois parametre est le plus petit
    newFb.file[0] = &T;
    // then copy tous les autres trournois
    for (int i = 0; i < F.size; i++) {
        newFb.file[i + 1] = F.file[i];
    }
    return newFb;
}

FileBinomiale UnionFile(FileBinomiale F1, FileBinomiale F2) {
    Tournoi T = {NULL}; // Null
    return UFret(F1, F2, T);
}

FileBinomiale UFret(FileBinomiale F1, FileBinomiale F2, Tournoi T) {
    if (EstVide_T(T)) {//T Null
        if (EstVide_FB(F1)) return F2;
        if (EstVide_FB(F2)) return F1;
        Tournoi* T1 = MinDeg(F1);
        Tournoi* T2 = MinDeg(F2);
        if (Degre(*T1) < Degre(*T2)) {
            return AjoutMin(*T1, UnionFile(Reste(F1), F2));
        } else if (Degre(*T2) < Degre(*T1)) {
            return AjoutMin(*T2, UnionFile(Reste(F2), F1));
        } else {
            return UFret(Reste(F1), Reste(F2), Union2Tid(*T1, *T2));
        }
    } else { //T non null
        if (EstVide_FB(F1)) return UnionFile(File(T), F2);
        if (EstVide_FB(F2)) return UnionFile(File(T), F1);
        Tournoi *T1 = MinDeg(F1);
        Tournoi *T2 = MinDeg(F2);
        if (Degre(T) < Degre(*T1) && Degre(T) < Degre(*T2)) {
            return AjoutMin(T, UnionFile(F1, F2));
        } else if (Degre(T) == Degre(*T1) && Degre(T) == Degre(*T2)) {
            return AjoutMin(T, UFret(Reste(F1), Reste(F2), Union2Tid(*T1, *T2)));
        } else if (Degre(T) == Degre(*T1)) {
            return UFret(Reste(F1), F2, Union2Tid(*T1, T));
        } else { // Degre(T) == Degre(T2)
            return UFret(Reste(F2), F1, Union2Tid(*T2, T));
        }
    }
}


FileBinomiale ajout_FB(Tournoi T, FileBinomiale FBn) {
    // Créer une file binomiale FB1 contenant uniquement T
    FileBinomiale FB1 = File(T);
    // faire l’union de FB1 et FBn
    return UnionFile(FB1, FBn);
}

//FileBinomiale Construction_FB

FileBinomiale SupprMin_FB(FileBinomiale fb) {
    return Reste(fb);
}


