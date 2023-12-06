
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
    // 创建一个新的二项队列
    FileBinomiale newFb;
    newFb.size = F.size + 1;
    newFb.file = malloc(sizeof(Tournoi*) * newFb.size);
    // 将新的二项树作为最小阶二项树添加到队列
    newFb.file[0] = &T;
    // 复制原始队列中的所有二项树
    for (int i = 0; i < F.size; i++) {
        newFb.file[i + 1] = F.file[i];
    }
    return newFb;
}



