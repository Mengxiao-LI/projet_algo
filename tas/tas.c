//
// Created by lmx on 2023/11/22.



#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include "tas.h"
#include "list.h"

//初始化堆ok
void HeapInit(HP* minHp)
{
    assert(minHp);
    minHp->a = NULL;
    minHp->size = minHp->capacity = 0;
}
//销毁堆ok
void HeapDestroy(HP* minHp)
{
    assert(minHp);
    free(minHp->a);
    minHp->a = NULL;
    minHp->size = minHp->capacity = 0;
}
//删除ok
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

        if (fD < minHp->size && minHp->a[fD] < minHp->a[fG]) {
            smallerChild = fD;
        }

        if (minHp->a[parent] > minHp->a[smallerChild]) {
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
//charu ok
HP * Ajout(HP* minHp, int x)
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
    while (fils > 0 && minHp->a[fils] < minHp->a[parent]) {
        // 交换 fils 和 parent 的值
        int temp = minHp->a[fils];
        minHp->a[fils] = minHp->a[parent];
        minHp->a[parent] = temp;

        // 更新 fils 和 parent 的索引
        fils = parent;
        parent = (fils - 1) / 2;
    }
    return minHp;
}

HP *AjoutsIteratifs(HP *minHp,Liste l){
    while (l !=NULL){
        Ajout(minHp,l->nombre);
        l = l->suivant;
    }
    return minHp;

}
void AfficheTasArray(HP *hp){
    printf("tasArray:");
    for (int i = 0; i < hp->size; i++)
    {
        printf("%d ", hp->a[i]);
    }
    printf("\n");
}
void AfficheTasArbre(HP *hp) {
    if (hp == NULL || hp->size == 0) {
        printf("The heap is empty.\n");
        return;
    }
    printf("tasArbre\n");
    int level = 0;
    int count = 0;
    int maxLevelNodes = 1;

    for (int i = 0; i < hp->size; i++) {
        printf("%d ", hp->a[i]);
        count++;

        if (count == maxLevelNodes) { // 当前层级打印完毕
            printf("\n");
            level++;
            count = 0;
            maxLevelNodes *= 2; // 下一层的节点数是当前层的两倍
        }
    }

    if (count > 0) { // 打印最后一层的剩余部分
        printf("\n");
    }
}

HP* Construction(Liste l) {
    HP* minHp = (HP*)malloc(sizeof(HP));
    if (minHp == NULL) {
        exit(-1);
    }
    HeapInit(minHp);
    while (l != NULL) {
        if (minHp->size == minHp->capacity) {
            minHp->capacity = (minHp->capacity == 0) ? 4 : minHp->capacity * 2;
            minHp->a = (int*)realloc(minHp->a, sizeof(int) * minHp->capacity);
            if (minHp->a == NULL) {
                exit(-1); // 内存分配失败
            }
        }

        minHp->a[minHp->size] = l->nombre;
        minHp->size++;
        l = l->suivant;
    }

    int parent = (minHp->size - 2) / 2;
    while (parent>=0){
        while(true){
            int fG=2*parent+1;
            int fD=2*parent+2;
            int smaller = parent;

            if (fG < minHp->size && minHp->a[fG] < minHp->a[smaller]) {
                smaller = fG;
            }
            if (fD < minHp->size && minHp->a[fD] < minHp->a[smaller]) {
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
    minHp->a = (int*)malloc(sizeof(int) * minHp->capacity);

    if (minHp->a == NULL) {
        free(minHp);
        return NULL; // 内存分配失败
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

            if (fG < minHp->size && minHp->a[fG] < minHp->a[smaller]) {
                smaller = fG;
            }
            if (fD < minHp->size && minHp->a[fD] < minHp->a[smaller]) {
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
