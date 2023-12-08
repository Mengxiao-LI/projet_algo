#include <stdio.h>
//#include <malloc.h>
#ifdef _MSC_VER
// MSVC Compiler
#include <malloc.h>
#else
#include <stdlib.h>
#endif
#include "list.h"

//
// Created by lmx on 2023/11/23.
//

void initVide( Liste *L)
{
    *L = NULL ;
}
Liste ajoute(Key128 x, Liste l)
{
    Liste tmp = (Liste) malloc(sizeof(Bloc)) ;

    tmp->nombre = x ;
    tmp->suivant = l ;
    return tmp ;
}
void empile(Key128 x, Liste *L)
{
    *L = ajoute(x,*L) ;
}

void affiche_rec(Liste l) {
    if (l == NULL)
        printf("\n");
    else {
        printf("%08x %08x %08x %08x\n", l->nombre.part1, l->nombre.part2, l->nombre.part3, l->nombre.part4);
        affiche_rec(l->suivant);
    }
}

Liste buildListFromFile(const char* filename) {
    FILE *fp = fopen(filename, "r");
    char line[100];
    Liste maListe;
    initVide(&maListe);

    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    while (fgets(line, sizeof(line), fp)) {
        Key128 key;
        sscanf(line, "%x %x %x %x", &key.part1, &key.part2, &key.part3, &key.part4);
        empile(key, &maListe);
    }

    fclose(fp);
    return maListe;
}
void freeList(Liste l) {
    Bloc *current, *next;
    current = l;
    while (current != NULL) {
        next = current->suivant;
        free(current);
        current = next;
    }
}
