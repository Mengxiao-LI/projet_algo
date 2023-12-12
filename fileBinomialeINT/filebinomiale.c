#include <stdio.h>
#include "filebinomiale.h"
#include "../echauffement/echauffement.h"

//primitive tournois
int Degre(Tournoi t) {

    if (t.racine == NULL) {
        // 如果 t.racine 是 NULL，则返回0或适当的错误值
        fprintf(stderr, "erreur degre racine Null.\n");
        return 0;
    }else if (t.racine->child == NULL) {
        return 0;
    }

    int degre = 0;
    ArbreBinomialeNode* current = t.racine->child;
    while (current != NULL) {
        degre++;
        //修改
        if(current->frere = NULL)
        return degre;
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

        // 检查 T1 和 T2 是否为 NULL
        if (T1 == NULL)  {fprintf(stderr, "test1 F2:erreur UFret racine Null.\n");return F2;}
        if (T2 == NULL)  {fprintf(stderr, "test1 F1:erreur UFret racine Null.\n");return F1;}

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

        // 检查 T1 和 T2 是否为 NULL
        if (T1 == NULL) {fprintf(stderr, "test2 F2 erreur UFret racine Null.\n");return F2;}
        if (T2 == NULL) {fprintf(stderr, "test2 F1 erreur UFret racine Null.\n");return F1;}

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


FileBinomiale Ajout_FB(Tournoi T, FileBinomiale FBn) {
    // Créer une file binomiale FB1 contenant uniquement T
    FileBinomiale FB1 = File(T);
    // faire l’union de FB1 et FBn
    return UnionFile(FB1, FBn);
}

FileBinomiale Construction_FB(Tournoi *tournois, int size) {
    FileBinomiale FBn;
    FBn.size = 0;
    for (int i = 0; i < size; i++) {
        FBn = Ajout_FB(tournois[i], FBn); // ajout successivement Tournoi
    }
    return FBn;
}

FileBinomiale SupprMin_FB(FileBinomiale FBn) {
    if (FBn.size == 0) {
        return FBn;
    }

    Tournoi * minTournoi = MinDeg(FBn); // 找到最小根节点的二项树
    FileBinomiale resteFBn = Reste(FBn); // 移除最小根节点的二项树

    // retirer la racine de minTournoi
    int count = 0;
    ArbreBinomialeNode* current = minTournoi->racine->child;
    while (current != NULL) {
        count++;
        current = current->frere;
    }

    Tournoi **subTournois = malloc(sizeof(Tournoi*) * count);
    current = minTournoi->racine->child;
    for (int i = 0; i < count; i++) {
        subTournois[i] = malloc(sizeof(Tournoi));
        subTournois[i]->racine = current;
        current = current->frere;
    }
    //creer la file avec les subtournois de minTournoi
    FileBinomiale subfile_minTournoi = Construction_FB(*subTournois, count);
    //free
    for (int i = 0; i < count; i++) {
        free(subTournois[i]);
    }
    free(subTournois);

    return UnionFile(resteFBn, subfile_minTournoi); // faire l'union
}

//清理内存
// 释放一个二项树节点及其子节点和兄弟节点的内存
void freeArbreBinomialeNode(ArbreBinomialeNode *node) {
    if (node != NULL) {
        freeArbreBinomialeNode(node->child); // 递归释放子节点
        freeArbreBinomialeNode(node->frere); // 递归释放兄弟节点
        free(node); // 释放当前节点
    }
}

// 释放一个二项树的内存
void freeTournoi(Tournoi *t) {
    if (t != NULL && t->racine != NULL) {
        freeArbreBinomialeNode(t->racine); // 释放树的根节点及其所有子节点
    }
}

// 释放整个二项队列的内存
void freeFileBinomiale(FileBinomiale fb) {
    for (int i = 0; i < fb.size; i++) {
        freeTournoi(fb.file[i]); // 逐个释放队列中的二项树
        free(fb.file[i]); // 释放指向二项树的指针
    }
    free(fb.file); // 释放队列的数组
}



