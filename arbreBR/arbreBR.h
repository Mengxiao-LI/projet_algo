

#ifndef PROJET_MENGXIAO_ZHENGDAO_ARBREBR_H
#define PROJET_MENGXIAO_ZHENGDAO_ARBREBR_H

#include "../echauffement/echauffement.h"


typedef Key128 Type;
typedef struct ABR {
    Type data;
    struct ABR* fG;  // fils Gauche
    struct ABR* fD;  // fils Droit
} ABR;
ABR* CreateNode(Type data);
ABR* InsertNode(ABR* root, Type data);
void PrintTree(ABR *root);
//vérifier si une valeur (data) est présente dans l'Arbre
bool estDans(ABR * root,Type data);
void freeABR(ABR* root);

#endif //PROJET_MENGXIAO_ZHENGDAO_ARBREBR_H
