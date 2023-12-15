#include <stdio.h>
#include "filebinomiale.h"
#include "../echauffement/echauffement.h"
#include <limits.h>

//primitive tournois
int Degre(Tournoi* t) {

    if (t->racine == NULL) {
        // Si t->racine Null,retourne 0
        fprintf(stderr, "erreur degre racine Null.\n");
        return 0;
    }else if (t->racine->child == NULL) {
        return 0;
    }

    int degre = 0;
    ArbreBinomialeNode* current = t->racine->child;
    while (current != NULL) {
        degre++;
        if(current->frere == NULL)
            return degre;
        current = current->frere;
    }
    return degre;
}

bool EstVide_T(Tournoi* t) {
    return t->racine == NULL;
}
Tournoi* Union2Tid(Tournoi* t1entree, Tournoi* t2entree) {
    //creer les copie de t1,t2 pour creer Un nouveau tournois
    //sinon les changement sur t1 et t2 vont affecter le nouveau tournois
    Tournoi* t1 = copyTournoi(t1entree);
    Tournoi* t2 = copyTournoi(t2entree);


    if (t1->racine == NULL) return t2;
    if (t2->racine == NULL) return t1;
    Tournoi* newTournoi=malloc(sizeof(Tournoi));;
    newTournoi->racine = NULL;
    // comparer les valeurs des tournois,la plus petite valeur est la racine
    if (inf(t1->racine->data , t2->racine->data)) {
        // inserer la racine de t2 a la droite de t1
        t2->racine->parent = t1->racine;
        ArbreBinomialeNode *current = t1->racine->child;
        if (current == NULL) {
            t1->racine->child = t2->racine;
        } else {
            while (current->frere != NULL) {
                current = current->frere;
            }
            current->frere = t2->racine;
        }
        newTournoi->racine = t1->racine;
    } else {
        // inserer la racine de t1 a la droite de t2
        t1->racine->parent = t2->racine;
        ArbreBinomialeNode *current = t2->racine->child;
        if (current == NULL) {
            t2->racine->child = t1->racine;
        } else {
            while (current->frere != NULL) {
                current = current->frere;
            }
            current->frere = t1->racine;
        }
        newTournoi->racine = t2->racine;
    }

    return newTournoi;
}

FileBinomiale* File(Tournoi* T) {
    // creer un nouveau file binomiale vide
    FileBinomiale* newFb = malloc(sizeof(FileBinomiale));
    newFb->size = 1; // cette file n'a que un seul tournois
    newFb->file = malloc(sizeof(Tournoi*) * newFb->size);
    // copie T et attribue : newFb->file[0]
    Tournoi* copiedT = malloc(sizeof(Tournoi));
    if (copiedT == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for Tournoi.\n");
        free(newFb->file);
        free(newFb);
        return NULL;
    }
    copiedT->racine = copyArbreBinomialeNode(T->racine);
    newFb->file[0] = copiedT;
    return newFb;
}


//primitive file binomiale
//bool EstVide_FB(FileBinomiale* F) {
//    return F->file == NULL;
//}
bool EstVide_FB(FileBinomiale* F) {
    if (F == NULL) {
        return true;
    }
    // verifie si F->file NULL ou F->size == 0
    //si F->size == 0 ,on considere ce cas comme F->file est NUll
    return (F->file == NULL || F->size == 0);
}

Tournoi* MinDeg(FileBinomiale* fb) {
    Tournoi* minTournoi = NULL;
    int minDeg = INT_MAX;
    //fb null
    if (fb->size == 0) {
        return NULL;
    }
    for (int i = 0; i < fb->size; i++) {
        int currentDeg = Degre(fb->file[i]);

        if (currentDeg < minDeg) {
            minDeg = currentDeg;
            minTournoi = fb->file[i];
        }
    }
    return minTournoi;
}

FileBinomiale* Reste(FileBinomiale* fb) {
    // fb NULL
    if (fb->size == 0) {
        return fb;
    }
    // find the minimum tournois
    Tournoi* minTournoi = MinDeg(fb);
    // creer un nouveau fb vide
    FileBinomiale* newFb = malloc(sizeof (FileBinomiale));
    newFb->size = fb->size - 1;
    newFb->file = malloc(sizeof(Tournoi*) * newFb->size);
    // copy tous les tournois sauf le minimum
    for (int i = 0, j = 0; i < fb->size; i++) {
        if (fb->file[i] != minTournoi) {
            newFb->file[j++] = fb->file[i];
        }
    }
    return newFb;
}

FileBinomiale* AjoutMin(Tournoi* T, FileBinomiale* F) {
    // malloc memoire
    FileBinomiale* newFb = malloc(sizeof(FileBinomiale));
    newFb->size = F->size + 1;
    newFb->file = malloc(sizeof(Tournoi*) * newFb->size);
    //creer un copie de T
    // T est ajoute comme le premier element
    newFb->file[0] = copyTournoi(T);
    // copy tous les Tournoi de F et les ajouter au newFb
    for (int i = 0; i < F->size; i++) {
        newFb->file[i + 1] = copyTournoi(F->file[i]);  // 同样使用 copyTournoi 函数
    }
    return newFb;
}

//consruction
FileBinomiale* Construction_FB(Tournoi **tournois, int size) {
    FileBinomiale* FBn = malloc(sizeof(FileBinomiale)*size);
    FBn->size = 0;
    FBn->file = NULL; // initialisation

    for (int i = 0; i < size; i++) {
        FileBinomiale* temp = Ajout_FB(tournois[i], FBn);
        if (FBn != temp) {
            freeFileBinomiale(FBn); // free old fn
            FBn = temp; // mise a jour FBn
        }
    }
    return FBn;
}
FileBinomiale* Ajout_FB(Tournoi *T, FileBinomiale* FBn) {
    // Créer une file binomiale FB1 contenant uniquement T
    FileBinomiale* FB1 = File(T);
    // faire l’union de FB1 et FBn
    return UnionFile(FB1, FBn);
}
FileBinomiale* UnionFile(FileBinomiale* F1, FileBinomiale* F2) {
    Tournoi *T = malloc(sizeof(Tournoi)); // Null
    T->racine = NULL;
    return UFret(F1, F2, T);
}

FileBinomiale* UFret(FileBinomiale* F1, FileBinomiale* F2, Tournoi* T) {
    if (EstVide_T(T)) {//T Null
        if (EstVide_FB(F1)) return F2;
        if (EstVide_FB(F2)) return F1;
        Tournoi* T1 = MinDeg(F1);
        Tournoi* T2 = MinDeg(F2);

        if (T1 == NULL)  {fprintf(stderr, "test1 F2:erreur UFret racine Null.\n");return F2;}
        if (T2 == NULL)  {fprintf(stderr, "test1 F1:erreur UFret racine Null.\n");return F1;}

        if (Degre(T1) < Degre(T2)) {
            return AjoutMin(T1, UnionFile(Reste(F1), F2));
        } else if (Degre(T2) < Degre(T1)) {
            return AjoutMin(T2, UnionFile(Reste(F2), F1));
        } else {
            return UFret(Reste(F1), Reste(F2), Union2Tid(T1, T2));
        }
    } else { //T non null
        if (EstVide_FB(F1)) return UnionFile(File(T), F2);
        if (EstVide_FB(F2)) return UnionFile(File(T), F1);
        Tournoi *T1 = MinDeg(F1);
        Tournoi *T2 = MinDeg(F2);


        if (T1 == NULL) {fprintf(stderr, "test2 F2 erreur UFret racine Null.\n");return F2;}
        if (T2 == NULL) {fprintf(stderr, "test2 F1 erreur UFret racine Null.\n");return F1;}

        if (Degre(T) < Degre(T1) && Degre(T) < Degre(T2)) {
            return AjoutMin(T, UnionFile(F1, F2));
        } else if (Degre(T) == Degre(T1) && Degre(T) == Degre(T2)) {
            return AjoutMin(T, UFret(Reste(F1), Reste(F2), Union2Tid(T1, T2)));
        } else if (Degre(T) == Degre(T1)) {
            return UFret(Reste(F1), F2, Union2Tid(T1, T));
        } else { // Degre(T) == Degre(T2)
            return UFret(Reste(F2), F1, Union2Tid(T2, T));
        }
    }
}


FileBinomiale* SupprMin_FB(FileBinomiale* FBn) {
    if (FBn->size == 0) {
        return FBn;
    }

    Tournoi * minTournoi = MinDeg(FBn); // Trouver l'arbre binaire avec la racine la plus petite
    FileBinomiale* resteFBn = Reste(FBn); // retirer cette arbre

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
    FileBinomiale* subfile_minTournoi = Construction_FB(subTournois, count);
    //free
    for (int i = 0; i < count; i++) {
        free(subTournois[i]);
    }
    free(subTournois);

    return UnionFile(resteFBn, subfile_minTournoi); // faire l'union
}

//free memoire
void freeArbreBinomialeNode(ArbreBinomialeNode *node) {
    if (node != NULL) {
        freeArbreBinomialeNode(node->child); // recursive free
        freeArbreBinomialeNode(node->frere); // recursive free
        free(node); // free le noeud courant
    }
}

//free memoire
void freeTournoi(Tournoi *t) {
    if (t != NULL && t->racine != NULL) {
        freeArbreBinomialeNode(t->racine);
    }
}

//free memoire
void freeFileBinomiale(FileBinomiale* fb) {
    for (int i = 0; i < fb->size; i++) {
        freeTournoi(fb->file[i]);
        free(fb->file[i]);
    }
    free(fb->file);
}

void printArbreBinomialeNode(ArbreBinomialeNode *node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data); // print le valeur,utilise pour FB de version INT(pour faciliter la test)
    printArbreBinomialeNode(node->child);
    printArbreBinomialeNode(node->frere);
}

void printFileBinomiale(FileBinomiale* fb) {
    printf("File Binomiale:\n");
    for (int i = 0; i < fb->size; i++) {
        printf("Tournoi %d: ", i);
        printArbreBinomialeNode(fb->file[i]->racine);
        printf("\n");
    }
}

ArbreBinomialeNode* copyArbreBinomialeNode(ArbreBinomialeNode* node) {
    if (node == NULL) {
        return NULL;
    }
    ArbreBinomialeNode* newNode = malloc(sizeof(ArbreBinomialeNode));
    if (newNode == NULL) {
        // erreur memoire
        fprintf(stderr, "Error: Unable to allocate memory for ArbreBinomialeNode.\n");
        return NULL;
    }
    newNode->data = node->data;
    newNode->child = copyArbreBinomialeNode(node->child);
    newNode->frere = copyArbreBinomialeNode(node->frere);
    newNode->parent = NULL; // on set le pointeur dans copyTournoi,Sinon,
                            // cela pourrait etre une boucle récursive infinie.
    return newNode;
}


Tournoi* copyTournoi(Tournoi* tournoi) {
    if (tournoi == NULL) {
        return NULL;
    }
    Tournoi* newTournoi = malloc(sizeof(Tournoi));
    newTournoi->racine = copyArbreBinomialeNode(tournoi->racine);
    // mise a jour le pointeur "parent"
    if (newTournoi->racine && newTournoi->racine->child) {
        newTournoi->racine->child->parent = newTournoi->racine;
    }
    return newTournoi;
}

Tournoi *createSingleItemTournoi(Key128 data) {
    Tournoi* t = malloc(sizeof(Tournoi));
    ArbreBinomialeNode *node = malloc(sizeof(ArbreBinomialeNode));
    node->data = data;
    node->child = NULL;
    node->frere = NULL;
    node->parent = NULL;
    t->racine = node;
    return t;
}


