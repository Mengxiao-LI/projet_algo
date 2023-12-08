//

//

#ifndef PROJET_MENGXIAO_ZHENGDAO_TASARBRE_H
#define PROJET_MENGXIAO_ZHENGDAO_TASARBRE_H

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef Key128 HPDataType;


typedef struct HPArb {
    int data;
    struct HPArb* fG;  // 左子树
    struct HPArb* fD;  // 右子树
} HPArb;

HPArb* NouveauNoeud(int cle);
void ajout(HPArb **tas,int data);



#endif //PROJET_MENGXIAO_ZHENGDAO_TASARBRE_H
