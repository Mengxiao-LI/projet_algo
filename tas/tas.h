//
// Created by lmx on 2023/11/22.
//

#ifndef PROJET_MENGXIAO_ZHENGDAO_TAS_H
#define PROJET_MENGXIAO_ZHENGDAO_TAS_H

#include "list.h"

typedef int HPDataType;

typedef struct Heap
{
    HPDataType* a;
    int size;
    int capacity;
}HP;

void HeapInit(HP* minHp);
void HeapDestroy(HP* minHp);
void AfficheTasArray(HP *  minHp);
void AfficheTasArbre(HP *  minHp);
HP * Ajout(HP * minHp,int cle);
HP *  SupprMin(HP * minHp);
HP *  AjoutsIteratifs(HP *  minHp,Liste l);



#endif //PROJET_MENGXIAO_ZHENGDAO_TAS_H
