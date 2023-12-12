#include <stdio.h>
#include <string.h>
#include "echauffement/echauffement.h"
#include "fileBinomialeINT/filebinomiale.h"


// 创建一个含有单个元素的二项树
Tournoi createSingleItemTournoi(int data) {
    Tournoi t;
    ArbreBinomialeNode *node = malloc(sizeof(ArbreBinomialeNode));
    node->data = data;
    node->child = NULL;
    node->frere = NULL;
    node->parent = NULL;

    t.racine = node;
    return t;
}

int main() {
    Tournoi t1 = createSingleItemTournoi(5);
    Tournoi t2 = createSingleItemTournoi(10);

    Tournoi t3 = Union2Tid(t1,t2);
    Tournoi t4 = createSingleItemTournoi(15);
    Tournoi t5 = createSingleItemTournoi(20);
    Tournoi t6 = Union2Tid(t4,t5);
    Tournoi t7 = Union2Tid(t3,t6);
    int degre = Degre(t3);
    int val_racine = t3.racine->data;
    int val_child = t3.racine->child->data;
//    int val_frere = t3.racine->child->frere->data;
    printf("degre: %d\n",degre);
    printf("val_racine: %d\n",val_racine);
    printf("vale_child: %d\n",val_child);
//    printf("val_frere: %d\n",val_frere);
    printf("2ieme partie\n");
    int degre2 = Degre(t7);
    int val_racine2 = t7.racine->data;
    int val_child2 = t7.racine->child->data;
    int val_frere2 = t7.racine->child->frere->data;
    printf("degre: %d\n",degre2);
    printf("val_racine: %d\n",val_racine2);
    printf("vale_child: %d\n",val_child2);
    printf("val_frere: %d\n",val_frere2);
    freeTournoi(&t1);
    freeTournoi(&t2);
    freeTournoi(&t3);
    freeTournoi(&t4);
    freeTournoi(&t5);
    freeTournoi(&t6);
    freeTournoi(&t7);
    return 0;
}