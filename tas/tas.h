//
// Created by lmx on 2023/11/22.
//

#ifndef PROJET_MENGXIAO_ZHENGDAO_TAS_H
#define PROJET_MENGXIAO_ZHENGDAO_TAS_H
typedef int HeapDataType;

typedef struct heap {
    HeapDataType* data;
    int size;
    int capacity;
}heap;
typedef heap *minHp;
minHp HeapInit(int capacity);
void freeMinHeap(minHp minHp);
minHp SupprMin(minHp minHp);
minHp Ajout(minHp minHp,int cle);
minHp AjoutsIteratifs(minHp minHp,int cles[]);


#endif //PROJET_MENGXIAO_ZHENGDAO_TAS_H
