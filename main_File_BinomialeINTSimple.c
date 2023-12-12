#include <stdio.h>
#include <string.h>
#include "echauffement/echauffement.h"
#include "fileBinomialeINT/filebinomiale.h"


// 创建一个含有单个元素的二项树
Tournoi *createSingleItemTournoi(int data) {
    Tournoi* t = malloc(sizeof(Tournoi));
    ArbreBinomialeNode *node = malloc(sizeof(ArbreBinomialeNode));
    node->data = data;
    node->child = NULL;
    node->frere = NULL;
    node->parent = NULL;
    t->racine = node;
    return t;
}

int main() {
    //debut test tournois:
    Tournoi* t1 = createSingleItemTournoi(5);
    Tournoi* t2 = createSingleItemTournoi(10);

    Tournoi* t3 = Union2Tid(t1,t2);
    Tournoi* t4 = createSingleItemTournoi(15);
    Tournoi* t5 = createSingleItemTournoi(20);
    Tournoi* t6 = Union2Tid(t4,t5);
    //t7:2个child 4个节点，
    Tournoi* t7 = Union2Tid(t3,t6);
    int degre = Degre(*t3);
    int val_racine = t3->racine->data;
    int val_child = t3->racine->child->data;
//    int val_frere = t3.racine->child->frere->data;
    printf("degre: %d\n",degre);
    printf("val_racine: %d\n",val_racine);
    printf("vale_child: %d\n",val_child);
//    printf("val_frere: %d\n",val_frere);
    printf("2ieme partie\n");
    int degre2 = Degre(*t7);
    int val_racine2 = t7->racine->data;
    int val_child2 = t7->racine->child->data;
    int val_frere2 = t7->racine->child->frere->data;
    printf("degre: %d\n",degre2);
    printf("val_racine: %d\n",val_racine2);
    printf("vale_child: %d\n",val_child2);
    printf("val_frere: %d\n",val_frere2);
    printf("fin test tournois\n");
//fin test tournois
    Tournoi* ta1 = createSingleItemTournoi(3);
    Tournoi* ta2 = createSingleItemTournoi(10);
    Tournoi* ta = Union2Tid(ta1,ta2);
    printf("degre ta: %d\n", Degre(*ta));
    printf("val_racine ta: %d\n",ta->racine->data);
//file
    FileBinomiale* fb0 = File(ta);
    Tournoi* test = MinDeg(fb0);
//MinDeg valide
    printf("fb size: %d\n", fb0->size);
    int racineval = test->racine->data;
    printf("val_racine test: %d\n",racineval);
    printf("degre test: %d\n", Degre(*test));
    printf("val_racine test: %d\n",test->racine->data);
//ajoutMin
    Tournoi* t8 = createSingleItemTournoi(1);
    FileBinomiale* fb1 = AjoutMin(t8,fb0);
    printf("fb size apres de ajouter: %d\n", fb1->size);

//construction
    printf("test: construction \n");
    Tournoi* cons1 = createSingleItemTournoi(5);
    Tournoi* cons2 = createSingleItemTournoi(10);
    Tournoi* cons3 = createSingleItemTournoi(15);
    Tournoi* listTournoi[3] = {cons1,cons2,cons3};
//传递起始地址
    FileBinomiale* fb_TEST = Construction_FB(listTournoi, 3);
    printf("fb size apres de construction: %d\n", fb_TEST->size);
    printFileBinomiale(*fb_TEST);



    freeTournoi(t7);
    freeFileBinomiale(fb0);
    return 0;
}