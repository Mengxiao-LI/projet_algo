#include"test.h"

void swap(HPDataTpye* a, HPDataTpye* b)
{
    HPDataTpye tmp = *a;
    *a = *b;
    *b = tmp;
}

void AdjustDown(HPDataTpye* a, int n, int parent)
{
    int child = parent * 2 + 1;
    while (child < n)
    {
        if ((child + 1 < n) && inf(a[child],a[child + 1])  )
        {
            ++child;
        }

        if (inf(a[parent],a[child])  )
        {
            swap(&a[child], &a[parent]);
            parent = child;
            child = 2 * parent + 1;
        }
        else
        {
            break;
        }
    }
}

void AdjustUp(HPDataTpye* a, int child)
{
    int parent = (child - 1) / 2;
    while (child > 0)
    {
        if (inf(a[parent],a[child])  )
        {
            swap(&a[child], &a[parent]);
            child = parent;
            parent = (child - 1) / 2;
        }
        else
        {
            break;
        }
    }
}
void HeapPrint(HP* php)
{
    for (int i = 0; i < php->size; i++)
    {
        printf("size:%d %08x%08x%08x%08x ", i,php->a[i].part1, php->a[i].part2, php->a[i].part3, php->a[i].part4);
    }
    printf("\n");
}

void HeapInit(HP* php, HPDataTpye* a, int n)
{
    assert(php);
    php->a = (HPDataTpye*)malloc(sizeof(HPDataTpye) * n);
    if (php->a==NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    memcpy(php->a, a, sizeof(HPDataTpye) * n);

    //建堆
    for (int i = (n - 2) / 2; i >= 0; --i)
    {
        AdjustDown(php->a, n, i);
    }

    php->size = n;
    php->capacity = n;
}
void HeapDestroy(HP* php)
{
    assert(php);
    free(php->a);
    php->a = NULL;
    php->size = php->capacity = 0;
}

void HeapPush(HP* php, HPDataTpye x)
{
    assert(php);
    if (php->size == php->capacity)
    {
        HPDataTpye* tmp = (HPDataTpye*)realloc(php->a, php->capacity * 2 * sizeof(HPDataTpye));
        if (php->a == NULL)
        {
            printf("realloc fail\n");
            exit(-1);
        }
        php->capacity *= 2;
    }
    php->a[php->size] = x;
    php->size++;

    AdjustUp(php->a, php->size - 1);


}

void HeapPop(HP* php)
{
    assert(php);
    assert(!HeapEmpty(php));
    swap(&php->a[0], &php->a[php->size - 1]);
    --php->size;

    AdjustDown(php->a, php->size, 0);
}

HPDataTpye HeapTop(HP* php)
{
    assert(php);
    assert(!HeapEmpty(php));

    return php->a[0];
}
bool HeapEmpty(HP* php)
{
    assert(php);
    return php->size == 0;
}
int HeapSize(HP* php)
{
    assert(php);
    return php->size;
}
void PrintTopK(HPDataTpye* a, int n, int k)
{
    HP hp;
    HeapInit(&hp, a, k); //建小堆

    for (int i = k; i < n; ++i)
    {
        if (inf(HeapTop(&hp),a[i])  )
        {
            HeapPop(&hp);
            HeapPush(&hp, a[i]);
        }
    }

    HeapPrint(&hp);
    HeapDestroy(&hp);
}
void hhaa(HP* php, HPDataTpye* a, int n) {
    for (int i = 0; i < n; i++) {
        HeapPush(php, a[i]); // 直接传递 php 而不是 &php
    }
}