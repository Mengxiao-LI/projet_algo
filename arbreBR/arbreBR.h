

#ifndef PROJET_MENGXIAO_ZHENGDAO_ARBREBR_H
#define PROJET_MENGXIAO_ZHENGDAO_ARBREBR_H

#include "../echauffement/echauffement.h"


typedef Key128 Type;
typedef struct ABR {
    Type data;
    struct ABR* fG;  // 左子树
    struct ABR* fD;  // 右子树
} ABR;
ABR* CreateNode(Type data);
ABR* InsertNode(ABR* root, Type data);
void PrintTree(ABR *root);
bool estDans(ABR * root,Type data);
void freeABR(ABR* root);
#endif //PROJET_MENGXIAO_ZHENGDAO_ARBREBR_H
