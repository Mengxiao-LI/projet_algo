//
// Created by lmx on 2023/11/22.



#include <stdlib.h>
#include <stdio.h>
#include "tas.h"
minHp HeapInit(int capacity) {
    minHp newHeap = (minHp)malloc(sizeof(heap));

    newHeap->data = (HeapDataType*)malloc(capacity * sizeof(HeapDataType));

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
    if(minHp->size==0){
        return minHp;
    }

    int parent;
    parent = 1;
    while (2 * parent <= minHp->size) {
        int leftChild = 2 * parent;
        int rightChild = 2 * parent + 1;
        int smallerChild = leftChild;

        if (rightChild <= minHp->size && minHp->data[rightChild] < minHp->data[leftChild]) {
            smallerChild = rightChild;
        }

        if (minHp->data[parent] <= minHp->data[smallerChild]) {
            break;
        }

        HeapDataType temp = minHp->data[parent];
        minHp->data[parent] = minHp->data[smallerChild];
        minHp->data[smallerChild] = temp;

        parent = smallerChild;
    }

    return minHp;
}

minHp Ajout(minHp minHp,int cle){
    if(minHp->size==minHp->capacity){
        minHp->capacity++;
    }
    minHp->size++;
    int i = minHp->size;
    while (i > 1 && cle < minHp->data[i / 2]) {
        minHp->data[i] = minHp->data[i / 2];
        i /= 2;
    }
    minHp->data[i]=cle;
    return minHp;
}

minHp AjoutsIteratifs(minHp minHp,int cles[]){
    int length = sizeof(cles) / sizeof(cles[0]);
    //上面不安全，需要改
    int i=0;
    while (i<length){
        Ajout(&minHp,cles[i]);
        i++;
    }
    return minHp;

}