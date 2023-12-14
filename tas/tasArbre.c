//
// Created by lmx on 2023/11/22.



#include<stdio.h>
#include<stdlib.h>
#include <string.h>


#include "queue.h"

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
int insertLast(HPArb **tas, HPType data, int *parentID) {
    HPArb* newNode = nouveauNoeud(data);
    if (*tas == NULL) {
        *tas = newNode;
        *parentID = -1; // 根节点没有父节点
        return 0; // 返回根节点的ID
    } else {
        Queue* queue = createQueue();
        enqueue(queue, *tas);

        int currentID = 0; // 当前节点的ID

        while (queue->front != NULL) {
            HPArb* current = dequeue(queue);
            int leftChildID = currentID * 2 + 1;
            int rightChildID = currentID * 2 + 2;

            if (current->fG == NULL) {
                current->fG = newNode;
                *parentID = currentID;
                free(queue);
                return leftChildID; // 返回新插入节点的ID
            } else {
                enqueue(queue, current->fG);
            }

            if (current->fD == NULL) {
                current->fD = newNode;
                *parentID = currentID;
                free(queue);
                return rightChildID; // 返回新插入节点的ID
            } else {
                enqueue(queue, current->fD);
            }

            currentID++;
        }

        free(queue);
        return -1; // 如果未找到空闲位置，返回-1表示错误
    }
}


//找节点
HPArb* findNode(HPArb* tas, int index) {
    if (tas == NULL) {
        return NULL;
    }

    Queue* queue = createQueue();
    enqueue(queue, tas);

    int count = 0;

    while (queue->front != NULL) {
        HPArb* node = dequeue(queue);

        if (count == index) {
            // 注意：在实际应用中，这里可能需要在返回之前释放队列
            free(queue);
            return node;
        }

        if (node->fG != NULL) {
            enqueue(queue, node->fG);
        }
        if (node->fD != NULL) {
            enqueue(queue, node->fD);
        }

        count++;
    }

    free(queue); // 释放队列资源
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
        return 0;
    }

    int count = 0;
    Queue* queue = createQueue();
    enqueue(queue, tas);

    while (queue->front != NULL) {
        HPArb* node = dequeue(queue);
        count++;

        if (node->fG != NULL) {
            enqueue(queue, node->fG);
        }
        if (node->fD != NULL) {
            enqueue(queue, node->fD);
        }
    }

    free(queue);
    return count;
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
//为了更快的每一次插入，我希望将插入到最后的时间改成o（1）,我们调用
void ajoutsIteratifs1(HPArb **tas, Key128* keys, int n){

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

    Queue* queue = createQueue();
    enqueue(queue, *tas);

    int current = 1;
    while (current < arrayLength && index < arrayLength) {
        HPArb* parent = dequeue(queue);

        if (parent->fG == NULL) {
            parent->fG = nouveauNoeud(array[current]);
            enqueue(queue, parent->fG);
            nodeRefs[index++] = parent->fG;
            current++;
        }

        if (current < arrayLength && parent->fD == NULL) {
            parent->fD = nouveauNoeud(array[current]);
            enqueue(queue, parent->fD);
            nodeRefs[index++] = parent->fD;
            current++;
        }
    }
    *lastId = index - 1;

    free(queue); // 释放队列资源
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
void treeToArray(HPArb* root, HPType* array, int arrayLength) {
    if (root == NULL) return;

    Queue* queue = createQueue();
    enqueue(queue, root);

    int index = 0; // 用于追踪数组中的位置
    while (queue->front != NULL) {
        HPArb* node = dequeue(queue);
        array[index++] = node->data; // 将节点数据存入数组

        if (node->fG != NULL) enqueue(queue, node->fG);
        if (node->fD != NULL) enqueue(queue, node->fD);
    }

    free(queue); // 释放队列资源
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