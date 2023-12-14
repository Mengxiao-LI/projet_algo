//
// Created by lmx on 2023/11/22.



#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include "tasArbre.h"






/**********************************************/
/************       tas arbre     *************/
/**********************************************/
void initTasAB(HPArb**tas){
    *tas = NULL ;
}
HPArb* nouveauNoeud(HPType data) {
    HPArb* noeud = (HPArb*)malloc(sizeof(HPArb));
    if (noeud == NULL) {
        return NULL; // 内存分配失败
    }
    noeud->data = data;
    noeud->fG = NULL;
    noeud->fD = NULL;
    return noeud;
}
void freeTree(HPArb* root) {
    if (root == NULL) return;

    freeTree(root->fG);
    freeTree(root->fD);
    free(root);
}
// 向完全二叉树的最后添加一个节点
int insertLast(HPArb **tas, HPType data, int *pInt) {
    HPArb* newNode = nouveauNoeud(data);
    if (*tas == NULL) {
        // 如果树为空，新节点成为根节点
        *tas = newNode;
        return 1; // 返回新节点的位置
    } else {
        // 使用队列来找到最后一个位置
        HPArb* queue[200000]; // 使用队列保存节点
        int first = 0;
        int last = 0;
        int parentID=0;
        queue[last++] = *tas;

        while (first < last) {
            //等于当前节点
            HPArb* current = queue[first++];
            if (current->fG == NULL) {
                // 如果左子节点为空，插入新节点
                current->fG = newNode;
                return last; // 返回新节点的位置
            } else {
                // 否则将左子节点加入队列
                queue[last++] = current->fG;
            }

            if (current->fD == NULL) {
                // 如果右子节点为空，插入新节点
                current->fD = newNode;
                return last; // 返回新节点的位置
            } else {
                // 否则将右子节点加入队列
                queue[last++] = current->fD;
            }
            parentID++;
        }
        return -1; // 如果未找到空闲位置，返回-1表示错误
    }
}
//找节点
HPArb* findNode(HPArb* tas, int index) {
    if (tas == NULL) {
        return NULL;
    }

    int count = 0;
    HPArb* queue[200000]; // 临时队列
    int first = 0;
    int last = 0;
    queue[last++] = tas;

    while (first < last) {
        HPArb* node = queue[first++];

        if (count == index) {

            return node;
        }

        if (node->fG != NULL) {
            queue[last++] = node->fG;
        }
        if (node->fD != NULL) {
            queue[last++] = node->fD;
        }

        count++;
    }

    return NULL; // 如果未找到指定索引的节点
}
void change(HPArb* a, HPArb* b) {
    HPType temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void remonter(HPArb **tas, int idlast) {
    if (*tas == NULL || idlast < 0) {
        return; // 检查树非空且索引有效
    }

    int i = idlast;
    while (i > 0) {
        int parentIndex = (i - 1) / 2;
        HPArb* parentNode = findNode(*tas, parentIndex);
        HPArb* currentNode = findNode(*tas, i);

        if (parentNode == NULL || currentNode == NULL) {
            printf("NO\n");
            return ; // 确保找到有效的节点
        }

        if ( inf(currentNode->data,parentNode->data)) {
            change(currentNode, parentNode);
            i = parentIndex;
        } else {
            break;
        }
    }
}
void ajout(HPArb **tas, HPType data) {
    if (*tas == NULL) {
        *tas = nouveauNoeud(data);
    } else {
        int idlast;
        int parentid=0;
        idlast= insertLast(tas, data, &parentid);
        remonter(tas,idlast);
    }
}


int countNodes(HPArb* tas) {
    if (tas == NULL) {
        return 0; // 空树没有节点
    }

    int count = 0;
    HPArb* queue[200000]; // 临时队列
    int first = 0;
    int last = 0;
    queue[last++] = tas;

    while (first < last) {
        HPArb* node = queue[first++]; // 取出队列中的节点
        count++; // 对节点计数

        if (node->fG != NULL) {
            queue[last++] = node->fG; // 将左子节点加入队列
        }
        if (node->fD != NULL) {
            queue[last++] = node->fD; // 将右子节点加入队列
        }
    }

    return count; // 返回节点总数
}
void deleteLastNode(HPArb **tas, int idlast){
    if (*tas == NULL || idlast <= 0) {
        return; // 树为空或节点数不正确
    }

    if (idlast == 1) {
        free(*tas); // 只有一个节点，直接释放
        *tas = NULL;
        return;
    }

    int parentIndex = (idlast - 2) / 2; // 最后一个节点父节点的索引
    HPArb* parentNode = findNode(*tas, parentIndex); // 查找父节点

    if (parentNode->fD != NULL) {
        free(parentNode->fD); // 释放右子节点
        parentNode->fD = NULL;
    } else if (parentNode->fG != NULL) {
        free(parentNode->fG); // 释放左子节点
        parentNode->fG = NULL;
    }
}
void desentre(HPArb *tas){
    if(tas==NULL){
        return;
    }
    while (tas->fG != NULL){
        HPArb* smallerChild = tas->fG;
        if (tas->fD != NULL && inf(tas->fD->data,tas->fG->data)  ) {
            smallerChild = tas->fD; // 右子节点更小
        }

        if ( inf(smallerChild->data,tas->data) ) {
            change(tas, smallerChild); // 与较小的子节点交换
            tas = smallerChild; // 继续下沉
        } else {
            break; // 如果节点小于其子节点，下沉结束
        }
    }

}
void supprMin(HPArb **tas) {
    if (*tas == NULL) {
        return; // 堆为空，无法删除
    }
    int totalNodes = countNodes(*tas);
    HPArb* lastNode = findNode(*tas, totalNodes - 1);

    // 将最后一个节点的数据复制到根节点
    (*tas)->data = lastNode->data;

    // 删除最后一个节点
    deleteLastNode(tas, totalNodes - 1);

    desentre(*tas);
}
void ajoutsIteratifs(HPArb **tas, Key128* keys, int n) {
    for (int i = 0; i < n; i++) {
        ajout(tas, keys[i]);
    }
}
void afficheAb(const HPArb* arbre, int niveau) {
    if (arbre == NULL) {
        return;
    }

    // 打印右子树，递归调用
    afficheAb(arbre->fD, niveau + 1);

    // 打印当前节点
    for (int i = 0; i < niveau; i++) {
        printf("           -         ");  // 缩进用于表示层级关系
    }

    printf("%08x%08x%08x%08x\n ",arbre->data.part1, arbre->data.part2, arbre->data.part3, arbre->data.part4);

    // 打印左子树，递归调用
    afficheAb(arbre->fG, niveau + 1);
}

#define MAX_NODES 200000



void remonte1(int totalNodes, HPArb* nodeRefs[]) {
    int size = totalNodes - 1;
    HPArb* parentNode;
    HPArb* filsG;
    HPArb* filsD;
    for (int parent = (totalNodes - 1) / 2; parent >= 0; parent--) {
        while(true){
            int smallest = parent;
            int fG=2*parent+1;
            int fD=2*parent+2;
            if(fG>size){
                break;
            }
            parentNode = nodeRefs[parent];

            filsG = nodeRefs[fG];
            filsD = (fD <= size) ? nodeRefs[fD] : NULL;

            if (filsG != NULL && inf(filsG->data,parentNode->data)  ) {
                smallest = fG;
            }

            if (filsD != NULL && inf(filsD->data,parentNode->data)) {
                smallest = fD;
            }
            if (smallest != parent) {
                change(nodeRefs[smallest], parentNode);
                parent = smallest;
            } else {
                break;
            }
        }
    }
}

void createCAB1(HPArb** tas, HPType array[], int arrayLength, int* lastId, HPArb* nodeRefs[]) {
    if (arrayLength == 0) return;

    int index = 0;
    *tas = nouveauNoeud(array[0]);
    nodeRefs[index++] = *tas;

    HPArb* queue[arrayLength];
    int first = 0, last = 0;
    queue[last++] = *tas;

    int current = 1;
    while (current < arrayLength && index < arrayLength) {
        HPArb* parent = queue[first++];

        if (parent->fG == NULL) {
            parent->fG = nouveauNoeud(array[current]);
            queue[last++] = parent->fG;
            nodeRefs[index++] = parent->fG;
            current++;
        }

        if (current < arrayLength && parent->fD == NULL) {
            parent->fD = nouveauNoeud(array[current]);
            queue[last++] = parent->fD;
            nodeRefs[index++] = parent->fD;
            current++;
        }
    }
    *lastId = index - 1;

}
void construction1(HPArb **tas, HPType array[], int arrayLength) {
    HPArb** nodeRefs = (HPArb**)malloc(arrayLength * sizeof(HPArb*));
    if (nodeRefs == NULL) {
        free(nodeRefs);
        return;
    }

    int lastId = 0;
    createCAB1(tas, array, arrayLength, &lastId, nodeRefs);
    remonte1( lastId + 1, nodeRefs);

    free(nodeRefs); // 用完后释放内存
}
void treeToArray(HPArb* root, HPType* array,int arrayLength) {
    if (root == NULL) return;

    HPArb* queue[arrayLength];
    int first = 0, last = 0;
    queue[last++] = root;

    int index = 0; // 用于追踪数组中的位置
    while (first < last) {
        HPArb* node = queue[first++];
        array[index++] = node->data; // 将节点数据存入数组

        if (node->fG != NULL) queue[last++] = node->fG;
        if (node->fD != NULL) queue[last++] = node->fD;
    }
}


HPArb* UnionA(HPArb *tas1, HPArb *tas2){
    int arrayLength1 = countNodes(tas1);  // 假设这个函数可以计算树中的节点数
    int arrayLength2 = countNodes(tas2);  // 同上
    HPType *array1 = (HPType*)malloc(arrayLength1 * sizeof(HPType));
    HPType *array2 = (HPType*)malloc(arrayLength2 * sizeof(HPType));

    // 假设 treeToArray 函数可以将树转换为数组
    treeToArray(tas1, array1,arrayLength1);
    treeToArray(tas2, array2,arrayLength2);

    // 合并两个数组
    HPType *mergedArray = (HPType*)malloc((arrayLength1 + arrayLength2) * sizeof(HPType));
    memcpy(mergedArray, array1, arrayLength1 * sizeof(HPType));
    memcpy(mergedArray + arrayLength1, array2, arrayLength2 * sizeof(HPType));
    free(array1);
    free(array2);
    HPArb* tas;
    initTasAB(&tas);
    construction1(&tas, mergedArray, arrayLength1 + arrayLength2);

    // 清理

    free(mergedArray);

    return tas;
}
void afficheGauche(HPArb* arbre) {
    if (arbre == NULL) {
        return; // 如果节点为空，返回
    }

    // 打印当前节点的值
    printf("%08x%08x%08x%08x\n", arbre->data.part1, arbre->data.part2, arbre->data.part3, arbre->data.part4);

    // 递归地打印左子节点
    afficheGauche(arbre->fG);
}
/*------------fin tas arbre-----------------*/