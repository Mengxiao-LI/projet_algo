//
// Created by lmx on 2023/11/22.



#include<stdio.h>
#include<stdlib.h>

#include "tasArbre.h"





/**********************************************/
/************       tas arbre     *************/
/**********************************************/

HPArb* NouveauNoeud(int cle) {
    HPArb* noeud = (HPArb*)malloc(sizeof(HPArb));
    if (noeud == NULL) {
        return NULL; // 内存分配失败
    }
    noeud->data = cle;
    noeud->fG = NULL;
    noeud->fD = NULL;
    return noeud;
}
/*------------fin tas arbre-----------------*/