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
                freeQueue(queue);
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

        freeQueue(queue);
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

            freeQueue(queue);
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

    freeQueue(queue);
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

    freeQueue(queue);
    return count;
}

void deleteLastNode(HPArb **tas, int idlast){
    if (*tas == NULL || idlast <= 0) {
        return;
    }

    if (idlast == 1) {
        free(*tas);
        *tas = NULL;
        return;
    }

    int parentIndex = (idlast - 2) / 2;
    HPArb* parentNode = findNode(*tas, parentIndex);

    if (parentNode->fD != NULL) {
        free(parentNode->fD);
        parentNode->fD = NULL;
    } else if (parentNode->fG != NULL) {
        free(parentNode->fG);
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
            smallerChild = tas->fD;
        }

        if ( inf(smallerChild->data,tas->data) ) {
            change(tas, smallerChild);
            tas = smallerChild;
        } else {
            break;
        }
    }

}
void supprMin(HPArb **tas) {
    if (*tas == NULL) {
        return; // vide
    }
    int totalNodes = countNodes(*tas);
    HPArb* lastNode = findNode(*tas, totalNodes - 1);

    // Copiez les données du dernier nœud sur le nœud racine
    (*tas)->data = lastNode->data;

    // Supprimer le dernier nœud
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

    afficheAb(arbre->fD, niveau + 1);

    for (int i = 0; i < niveau; i++) {
        printf("           -         ");
    }

    printf("%08x%08x%08x%08x\n ",arbre->data.part1, arbre->data.part2, arbre->data.part3, arbre->data.part4);


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

    freeQueue(queue);;
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

    free(nodeRefs);
}
HPType* treeToArray(HPArb* root, int* arrayLength) {
    if (root == NULL) {
        *arrayLength = 0;
        return NULL;
    }

    int capacity = 5000;  // capacité initiale
    HPType* array = (HPType*)malloc(capacity * sizeof(HPType));
    if (!array) {
        *arrayLength = 0;
        return NULL;
    }

    Queue* queue = createQueue();
    enqueue(queue, root);

    int index = 0;
    while (queue->front != NULL) {
        HPArb* node = dequeue(queue);

        // Expansion
        if (index >= capacity) {
            capacity *= 2;
            HPType* temp = (HPType*)realloc(array, capacity * sizeof(HPType));
            if (!temp) {
                free(array);
                free(queue);
                *arrayLength = 0;
                return NULL;
            }
            array = temp;
        }

        array[index++] = node->data;

        if (node->fG != NULL) enqueue(queue, node->fG);
        if (node->fD != NULL) enqueue(queue, node->fD);
    }

    *arrayLength = index;

    freeQueue(queue);
    return array;
}



HPArb* UnionA(HPArb *tas1, HPArb *tas2) {
    int arrayLength1, arrayLength2;
    HPType *array1 = treeToArray(tas1, &arrayLength1);
    HPType *array2 = treeToArray(tas2, &arrayLength2);

    // Fusionner deux tableaux
    HPType *mergedArray = (HPType*)malloc((arrayLength1 + arrayLength2) * sizeof(HPType));
    memcpy(mergedArray, array1, arrayLength1 * sizeof(HPType));
    memcpy(mergedArray + arrayLength1, array2, arrayLength2 * sizeof(HPType));
    free(array1);
    free(array2);
    HPArb* tas;
    initTasAB(&tas);
    construction1(&tas, mergedArray, arrayLength1 + arrayLength2);

    free(mergedArray);

    return tas;
}
//Imprimez uniquement le plus à gauche
void afficheGauche(HPArb* arbre) {
    if (arbre == NULL) {
        return;
    }


    printf("%08x%08x%08x%08x\n", arbre->data.part1, arbre->data.part2, arbre->data.part3, arbre->data.part4);


    afficheGauche(arbre->fG);
}
/*------------fin tas arbre-----------------*/