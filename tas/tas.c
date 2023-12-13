//
// Created by lmx on 2023/11/22.



#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "tas.h"

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
    while (fils > 0 ) {
        if( inf(minHp->a[fils],minHp->a[parent])){
            // 交换 fils 和 parent 的值
            Key128 temp = minHp->a[fils];
            minHp->a[fils] = minHp->a[parent];
            minHp->a[parent] = temp;

            // 更新 fils 和 parent 的索引
            fils = parent;
            parent = (fils - 1) / 2;
        } else{
            break;
        }

    }
    return minHp;
}

//ajout un list dans un tas

HP *AjoutsIteratifs(HP *minHp, Key128* keys, int n) {
    for (int i = 0; i < n; i++) {
        Ajout(minHp, keys[i]);
    }
    return minHp;
}

// 堆的下沉调整操作
void remonte(HP* minHp, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHp->size && inf(minHp->a[left], minHp->a[smallest])) {
        smallest = left;
    }
    if (right < minHp->size && inf(minHp->a[right], minHp->a[smallest])) {
        smallest = right;
    }

    if (smallest != index) {
        HPDataType temp = minHp->a[index];
        minHp->a[index] = minHp->a[smallest];
        minHp->a[smallest] = temp;
        remonte(minHp, smallest);
    }
}

// Construire un tas à partir d'un tableau
void Construction(HP **minHp, Key128* keys, int n) {
    *minHp = (HP*)malloc(sizeof(HP));
    if (*minHp == NULL) {
        exit(-1); // 内存分配失败
    }

    HeapInit(*minHp);
    (*minHp)->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
    if ((*minHp)->a == NULL) {
        exit(-1); // 内存分配失败
    }
    (*minHp)->capacity = n;
    (*minHp)->size = n;

    for (int i = 0; i < n; i++) {
        (*minHp)->a[i] = keys[i];
    }

    // 开始从最后一个非叶子节点进行下沉调整
    for (int i = (n - 2) / 2; i >= 0; i--) {
        remonte(*minHp, i);
    }
}



/*删
 * 复杂度计算
*/

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

    for (int i = 0; i < minHp1->size; i++) {
        minHp->a[i] = minHp1->a[i];
    }
    for (int i = 0; i < minHp2->size; i++) {
        minHp->a[i + minHp1->size] = minHp2->a[i];
    }

    // 从最后一个非叶子节点开始，向上进行下沉调整
    for (int i = (minHp->size - 2) / 2; i >= 0; i--) {
        remonte(minHp, i);
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







