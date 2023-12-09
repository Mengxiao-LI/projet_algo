//
// Created by lmx on 2023/11/23.
//

#ifndef PROJET_MENGXIAO_ZHENGDAO_LIST_H
#define PROJET_MENGXIAO_ZHENGDAO_LIST_H
#include "../echauffement/echauffement.h"
typedef struct Bloc
{
    Key128 nombre;
    struct Bloc *suivant;

} Bloc;

typedef Bloc *Liste ;


void initVide(Liste *L);
Liste ajoute(Key128 x, Liste l);
void empile(Key128 x, Liste *L);
void affiche_rec(Liste l);
Liste buildListFromFile(const char* filename);
void freeList(Liste l);
Liste uninonLists(Liste l1, Liste l2);

#endif //PROJET_MENGXIAO_ZHENGDAO_LIST_H
