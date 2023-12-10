//
// Created by lmx on 2023/12/9.
//

#ifndef PROJET_MENGXIAO_ZHENGDAO_TEST_H
#define PROJET_MENGXIAO_ZHENGDAO_TEST_H
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include "../echauffement/echauffement.h"

typedef Key128 HPDataTpye;

//大堆
typedef struct Heap
{
    HPDataTpye* a;
    int size;
    int capacity;
}HP;

void swap(HPDataTpye* a, HPDataTpye* b);
void AdjustDown(HPDataTpye* a, int n, int parent);
void AdjustUp(HPDataTpye* a, int n);
void HeapPrint(HP* php);
void HeapInit(HP* php, HPDataTpye* a, int n);
void HeapDestroy(HP* php);
void HeapPush(HP* php, HPDataTpye x);
void hhaa(HP* php, HPDataTpye* a, int n);
void HeapPop(HP* php);
HPDataTpye HeapTop(HP* php);
bool HeapEmpty(HP* php);
int HeapSize(HP* php);


#endif //PROJET_MENGXIAO_ZHENGDAO_TEST_H
