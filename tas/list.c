#include <stdio.h>
#include <malloc.h>
#include "list.h"

//
// Created by lmx on 2023/11/23.
//

void initVide( Liste *L)
{
    *L = NULL ;
}
Liste ajoute(int x, Liste l)
{
    Liste tmp = (Liste) malloc(sizeof(Bloc)) ;

    tmp->nombre = x ;
    tmp->suivant = l ;
    return tmp ;
}
void empile(int x, Liste *L)
{
    *L = ajoute(x,*L) ;
}

void affiche_rec(Liste l)
{

    if(l==NULL)
        printf("\n");
    else
    {
        printf("%d ", l->nombre);
        affiche_rec(l->suivant);
    }
}

