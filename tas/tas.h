//
// Created by lmx on 2023/11/22.
//

#ifndef PROJET_MENGXIAO_ZHENGDAO_TAS_H
#define PROJET_MENGXIAO_ZHENGDAO_TAS_H

#include "list.h"
#include "../echauffement/echauffement.h"

typedef Key128 HPDataType;
//tas tableau
typedef struct HP
{
    HPDataType* a;
    int size;
    int capacity;
}HP;


//tas tableau
void HeapInit(HP* minHp);
void HeapDestroy(HP* minHp);
void AfficheTasArray(HP *  minHp);
HP * Ajout(HP * minHp,Key128 cle);
HP *  SupprMin(HP * minHp);
HP *  AjoutsIteratifs(HP *  minHp,Liste l);
void Construction(HP **minHp, Liste l);
HP * Union( HP * m1 , HP * m2);



#endif //PROJET_MENGXIAO_ZHENGDAO_TAS_H
