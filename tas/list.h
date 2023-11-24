//
// Created by lmx on 2023/11/23.
//

#ifndef PROJET_MENGXIAO_ZHENGDAO_LIST_H
#define PROJET_MENGXIAO_ZHENGDAO_LIST_H
typedef struct Bloc
{
    int nombre;
    struct Bloc *suivant;

} Bloc;

typedef Bloc *Liste ;


void initVide(Liste *L);
Liste ajoute(int x, Liste l);
void empile(int x, Liste *L);
void affiche_rec(Liste l);

#endif //PROJET_MENGXIAO_ZHENGDAO_LIST_H
