

#ifndef PROJET_MENGXIAO_ZHENGDAO_fileBinomiale_H
#define PROJET_MENGXIAO_ZHENGDAO_fileBinomiale_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../tas/list.h"
#include "../tas/tas.h"
//struct arbre binomiale node
typedef struct ArbreBinomialeNode {
    int data; // data of node
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
    Tournoi ** tree; //pointe vers un pointeur
    int size;
}FileBinomiale;

//primitive
bool EstVide(Tournoi t);
int Degre(Tournoi t);


#endif
