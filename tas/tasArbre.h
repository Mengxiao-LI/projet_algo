//

//

#ifndef PROJET_MENGXIAO_ZHENGDAO_TASARBRE_H
#define PROJET_MENGXIAO_ZHENGDAO_TASARBRE_H

#include <stdio.h>
#include <stdlib.h>

#include "../echauffement/echauffement.h"



typedef Key128 HPType;
typedef struct HPArb {
    HPType data;
    struct HPArb* fG;  // fils gauche
    struct HPArb* fD;  // fils droit
} HPArb;

void initTasAB(HPArb**tas);
HPArb* nouveauNoeud(HPType data);
//2.4
void ajout(HPArb **tas,HPType data);
void supprMin(HPArb **tas);
void ajoutsIteratifs(HPArb **tas, Key128* keys, int n);
//2.5
HPArb* UnionA(HPArb *tas1, HPArb *tas2);
//2.6
void construction1(HPArb **tas, HPType array[], int arrayLength);

void freeTree(HPArb* root);
void afficheAb(const HPArb* arbre, int niveau);
void afficheGauche(HPArb* arbre);
#endif //PROJET_MENGXIAO_ZHENGDAO_TASARBRE_H