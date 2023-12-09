//
// Created by lmx on 2023/11/22.



#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include "tas.h"
#include "list.h"
#include "../echauffement/echauffement.h"







//initialiser le tas
void HeapInit(HP* minHp)
{
    assert(minHp);
    minHp->a = NULL;
    minHp->size = minHp->capacity = 0;
}
//détruire le tas
void HeapDestroy(HP* minHp)
{
    assert(minHp);
    free(minHp->a);
    minHp->a = NULL;
    minHp->size = minHp->capacity = 0;
}
//Suppr le Min
HP * SupprMin(HP * minHp){
    if(minHp->size==0){
        return minHp;
    }
    minHp->a[0]=minHp->a[minHp->size-1];
    minHp->size--;
    int parent=0;
    int fG=2*parent+1;
    int fD=2*parent+2;

    while (fG < minHp->size) {
        int smallerChild = fG;

        //if (fD < minHp->size && minHp->a[fD] < minHp->a[fG]) {
        if (fD < minHp->size && inf(minHp->a[fD],minHp->a[fG])) {
            smallerChild = fD;
        }

        //if (minHp->a[parent] > minHp->a[smallerChild]) {
        if (inf(minHp->a[smallerChild],minHp->a[parent])) {
            HPDataType temp = minHp->a[parent];
            minHp->a[parent] = minHp->a[smallerChild];
            minHp->a[smallerChild] = temp;

            parent = smallerChild;
            fG = 2 * parent + 1;
            fD = 2 * parent + 2;
        } else {
            break;
        }
    }

    return minHp;
}
//Ajout un cle dans un tas
HP * Ajout(HP* minHp, Key128 x)
{
    assert(minHp);
    if (minHp->size == minHp->capacity)//扩容
    {
        int newcapacity = minHp->capacity == 0 ? 4 : minHp->capacity * 2;
        //realloc扩容
        HPDataType* tmp = (HPDataType*)realloc(minHp->a, sizeof(HPDataType) * newcapacity);
        if (tmp == NULL)
        {
            printf("realloc fail\n");
            exit(-1);
        }
        minHp->a = tmp;
        minHp->capacity = newcapacity;
    }
    minHp->size++;
    int fils = minHp->size - 1;
    int parent = (fils - 1) / 2;
    minHp->a[fils] = x;
    //while (fils > 0 && minHp->a[fils] < minHp->a[parent]) {
    while (fils > 0 && inf(minHp->a[fils],minHp->a[parent])) {
        // 交换 fils 和 parent 的值
        Key128 temp = minHp->a[fils];
        minHp->a[fils] = minHp->a[parent];
        minHp->a[parent] = temp;

        // 更新 fils 和 parent 的索引
        fils = parent;
        parent = (fils - 1) / 2;
    }
    return minHp;
}

//ajout un list dans un tas
HP *AjoutsIteratifs(HP *minHp,Liste l){
    while (l !=NULL){
        Ajout(minHp,l->nombre);
        l = l->suivant;
    }
    return minHp;

}


//Construire un tas par un liste
void Construction(HP **minHp, Liste l) {
    if (minHp == NULL) {
        return;
    }

    *minHp = (HP*)malloc(sizeof(HP));
    if (*minHp == NULL) {
        exit(-1); // 内存分配失败
    }

    HeapInit(*minHp);
    while (l != NULL) {
        if ((*minHp)->size == (*minHp)->capacity) {
            (*minHp)->capacity = ((*minHp)->capacity == 0) ? 4 : (*minHp)->capacity * 2;
            (*minHp)->a = (HPDataType*)realloc((*minHp)->a, sizeof(HPDataType) * (*minHp)->capacity);
            if ((*minHp)->a == NULL) {
                exit(-1); // 内存分配失败
            }
        }

        (*minHp)->a[(*minHp)->size] = l->nombre;
        (*minHp)->size++;
        l = l->suivant;
    }

    int parent = ((*minHp)->size - 2) / 2;
    while (parent >= 0) {
        while(true){
            int fG=2*parent+1;
            int fD=2*parent+2;
            int smaller = parent;
            //if (fG < minHp->size && minHp->a[fG] < minHp->a[smaller]) {
            if (fG < (*minHp)->size && inf((*minHp)->a[fG],(*minHp)->a[smaller])) {
                smaller = fG;
            }
            if (fD < (*minHp)->size && inf((*minHp)->a[fD],(*minHp)->a[smaller])) {
                smaller = fD;
            }

            if (smaller!=parent) {
                HPDataType temp = (*minHp)->a[parent];
                (*minHp)->a[parent] = (*minHp)->a[smaller];
                (*minHp)->a[smaller] = temp;
                parent = smaller;
            }else{
                break;
            }

        }

        parent--;
    }

}
/*删
 * 复杂度计算
https://blog.csdn.net/weixin_44611096/article/details/123608836*/

HP *Union(HP *minHp1, HP *minHp2) {

    if (minHp1 == NULL || minHp2 == NULL) {
        return NULL;
    }

    HP* minHp = (HP*)malloc(sizeof(HP));
    if (minHp == NULL) {
        exit(-1);
    }
    HeapInit(minHp);

    minHp->capacity = minHp1->size + minHp2->size;
    minHp->size = minHp->capacity;
    minHp->a = (HPDataType*)malloc(sizeof(HPDataType) * minHp->capacity);

    if (minHp->a == NULL) {
        free(minHp);
        return NULL;
    }

    // 合并两个堆的数据
    for (int i = 0; i < minHp1->size; i++) {
        minHp->a[i] = minHp1->a[i];
    }
    for (int i = 0; i < minHp2->size; i++) {
        minHp->a[i + minHp1->size] = minHp2->a[i];
    }

    int parent = (minHp->size - 2) / 2;
    while (parent>=0){
        while(true){
            int fG=2*parent+1;
            int fD=2*parent+2;
            int smaller = parent;

            if (fG < minHp->size && inf(minHp->a[fG],minHp->a[smaller])  ) {
                smaller = fG;
            }
            if (fD < minHp->size && inf(minHp->a[fD],minHp->a[smaller])) {
                smaller = fD;
            }

            if (smaller!=parent) {
                HPDataType temp = minHp->a[parent];
                minHp->a[parent] = minHp->a[smaller];
                minHp->a[smaller] = temp;
                parent = smaller;
            }else{
                break;
            }

        }

        parent--;
    }


    return minHp;
}





//afficher pour vérifier
//afficher un tas tableau par tableau
void AfficheTasArray(HP *hp) {
    printf("tasArray:");
    for (int i = 0; i < hp->size; i++) {
        printf("size:%d %08x%08x%08x%08x ", i,hp->a[i].part1, hp->a[i].part2, hp->a[i].part3, hp->a[i].part4);
    }
    printf("\n");
}







