//
// Created by lmx on 2023/12/10.
//
#include "arbreBR.h"


ABR* CreateNode(Type data) {
    ABR *newNode = (ABR*)malloc(sizeof(ABR));
    if (newNode == NULL) {
        // 处理内存分配失败的情况
        return NULL;
    }
    newNode->data = data;
    newNode->fG = NULL;
    newNode->fD = NULL;
    return newNode;
}
//插入元素
ABR* InsertNode(ABR* root, Type data) {
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }
    if (inf(data,root->data)  ) {
        root->fG = InsertNode(root->fG, data);
    } else{
        root->fD = InsertNode(root->fD, data);
    }
    return root;
}
void PrintTree(ABR *root) {
    if (root == NULL) {
        return;
    }

    PrintTree(root->fG);

    printf("%08x %08x %08x %08x\n", root->data.part1, root->data.part2, root->data.part3, root->data.part4);

    PrintTree(root->fD);

}
bool estDans(ABR *root, Type data) {
    if (root == NULL) {
        return false;
    }
    if (eg(data, root->data)) {
        return true;
    } else if (inf(data, root->data)) {
        return estDans(root->fG, data);
    } else {
        return estDans(root->fD, data);
    }
}