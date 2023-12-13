

#ifndef PROJET_MENGXIAO_ZHENGDAO_fileBinomiale_H
#define PROJET_MENGXIAO_ZHENGDAO_fileBinomiale_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../echauffement/echauffement.h"



//struct arbre binomiale node
typedef struct ArbreBinomialeNode {
    Key128 data; // data of node
    struct ArbreBinomialeNode *child; // 指向最左子节点
    struct ArbreBinomialeNode *frere; // 指向兄弟节点
    struct ArbreBinomialeNode *parent; // 指向父节点
} ArbreBinomialeNode;

//struct tournoi binomial
typedef struct Tournoi {
    ArbreBinomialeNode *racine; // pointe vers la racine
} Tournoi;

//struct file binomiale
typedef struct FileBinomiale{
    Tournoi ** file; //pointe vers un pointeur
    int size;
//    int index;??
}FileBinomiale;

//primitive tournois
bool EstVide_T(Tournoi* t);
int Degre(Tournoi* t);
Tournoi* Union2Tid(Tournoi* t1,Tournoi* t2);
//Renvoie le tournoi de degre minimal dans la file
Tournoi* MinDeg(FileBinomiale* fb);
//primitive file binomiale
FileBinomiale* File(Tournoi* t);
bool EstVide_FB(FileBinomiale* fb);

FileBinomiale* Reste(FileBinomiale* fb);
FileBinomiale* AjoutMin(Tournoi* t,FileBinomiale* fb);
FileBinomiale* Ajout_FB(Tournoi* t,FileBinomiale* fb);
FileBinomiale* UnionFile(FileBinomiale* fb1,FileBinomiale* fb2);
FileBinomiale* UFret(FileBinomiale* fb1,FileBinomiale* fb2,Tournoi* t);
FileBinomiale* SupprMin_FB(FileBinomiale* fb);
FileBinomiale* Construction_FB(Tournoi** list_tournois,int size);
void freeArbreBinomialeNode(ArbreBinomialeNode *node);
void freeTournoi(Tournoi *t);
void freeFileBinomiale(FileBinomiale* fb);
//primitive supplementaire-copy
ArbreBinomialeNode* copyArbreBinomialeNode(ArbreBinomialeNode* node);
Tournoi* copyTournoi(Tournoi* tournoi);
//primitive supplementaire-print
void printFileBinomiale(FileBinomiale* fb);
void printArbreBinomialeNode(ArbreBinomialeNode *node);

Tournoi *createSingleItemTournoi(Key128 data);
#endif
