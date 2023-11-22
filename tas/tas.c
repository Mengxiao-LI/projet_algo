//
// Created by lmx on 2023/11/22.



#include <stdlib.h>
#include "tas.h"
minHp HeapInit(int capacity) {
    minHp newHeap = (minHp)malloc(sizeof(heap));
    if (newHeap == NULL) {
        return NULL;
    }

    newHeap->data = (HeapDataType*)malloc(capacity * sizeof(HeapDataType));
    if (newHeap->data == NULL) {
        free(newHeap);
        return NULL;
    }

    newHeap->size = 0;
    newHeap->capacity = capacity;

    return newHeap;
}
void freeMinHeap(minHp minHp) {
    if (minHp != NULL) {
        free(minHp->data);
        free(minHp);
    }
}
minHp SupprMin(minHp minHp){

}
minHp Ajout(minHp minHp,int cle){

}
minHp AjoutsIteratifs(minHp minHp,int cles[]){

}