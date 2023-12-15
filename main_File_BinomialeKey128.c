#include <stdio.h>
#include <string.h>
#include "echauffement/echauffement.h"
#include "fileBinomiale/filebinomiale.h"

Key128 createKey128(unsigned int part1, unsigned int part2, unsigned int part3, unsigned int part4) {
    Key128 key;
    key.part1 = part1;
    key.part2 = part2;
    key.part3 = part3;
    key.part4 = part4;
    return key;
}



int main() {
    // print
//    printf("Key1: part1:%x + part2:%x + part3:%x + part4:%x\n", key1.part1, key1.part2, key1.part3, key1.part4);
    Key128 data5 = createKey128(5, 0, 0, 0);
    Key128 data10 = createKey128(10, 0, 0, 0);
    Key128 data15 = createKey128(15, 0, 0, 0);
    Key128 data20 = createKey128(20, 0, 0, 0);
    Key128 data1 = createKey128(1, 0, 0, 0);
    Key128 data3 = createKey128(3, 0, 0, 0);

    //debut test tournois:
    Tournoi* t1 = createSingleItemTournoi(data5);
    Tournoi* t2 = createSingleItemTournoi(data10);

    Tournoi* t3 = Union2Tid(t1,t2);
    Tournoi* t4 = createSingleItemTournoi(data15);
    Tournoi* t5 = createSingleItemTournoi(data20);
    Tournoi* t6 = Union2Tid(t4,t5);
    //t7:2个child 4 noeuds，
    Tournoi* t7 = Union2Tid(t3,t6);
    int degre = Degre(t3);
    Key128 val_racine = t3->racine->data;
    Key128 val_child = t3->racine->child->data;
//    int val_frere = t3.racine->child->frere->data;
    printf("degre: %d\n",degre);
    printf("val_racine: part1:%x + part2:%x + part3:%x + part4:%x\n", val_racine.part1, val_racine.part2, val_racine.part3, val_racine.part4);
    printf("val_child: part1:%x + part2:%x + part3:%x + part4:%x\n", val_child.part1, val_child.part2, val_child.part3, val_child.part4);
//    printf("val_frere: %d\n",val_frere);
    printf("2ieme partie\n");
    int degre2 = Degre(t7);
    Key128 val_racine2 = t7->racine->data;
    Key128 val_child2 = t7->racine->child->data;
    Key128 val_frere2 = t7->racine->child->frere->data;
    printf("degre: %d\n",degre2);
    printf("val_racine2: part1:%x + part2:%x + part3:%x + part4:%x\n", val_racine2.part1, val_racine2.part2, val_racine2.part3, val_racine2.part4);
    printf("val_child2: part1:%x + part2:%x + part3:%x + part4:%x\n", val_child2.part1, val_child2.part2, val_child2.part3, val_child2.part4);
    printf("val_frere: part1:%x + part2:%x + part3:%x + part4:%x\n", val_frere2.part1, val_frere2.part2, val_frere2.part3, val_frere2.part4);
    printf("fin test tournois\n");
//fin test tournois
    Tournoi* ta1 = createSingleItemTournoi(data3);
    Tournoi* ta2 = createSingleItemTournoi(data10);
    Tournoi* ta = Union2Tid(ta1,ta2);
    printf("degre ta: %d\n", Degre(ta));
    printf("val_racine ta: part1:%x + part2:%x + part3:%x + part4:%x\n", ta->racine->data.part1, ta->racine->data.part2, ta->racine->data.part3, ta->racine->data.part4);
//file
    FileBinomiale* fb0 = File(ta);
    Tournoi* test = MinDeg(fb0);
//MinDeg valide
    printf("fb size: %d\n", fb0->size);
    Key128 racineval = test->racine->data;
    printf("val_racine test: part1:%x + part2:%x + part3:%x + part4:%x\n", racineval.part1, racineval.part2, racineval.part3, racineval.part4);
    printf("degre test: %d\n", Degre(test));
    printf("val_racine test: part1:%x + part2:%x + part3:%x + part4:%x\n", test->racine->data.part1, test->racine->data.part2, test->racine->data.part3, test->racine->data.part4);
//ajoutMin valide
    Tournoi* t8 = createSingleItemTournoi(data10);
    FileBinomiale* fb1 = AjoutMin(t8,fb0);
    printf("fb size apres de ajouter: %d\n", fb1->size);
    Tournoi* tournoi_fb1_first = fb1->file[0];
    Tournoi* tournoi_fb1_second = fb1->file[1];
//    printFileBinomiale(fb1);
    Tournoi* test2 = MinDeg(fb1);
//MinDeg valide
    printf("val_racine_mindeg test: part1:%x + part2:%x + part3:%x + part4:%x\n", test2->racine->data.part1, test2->racine->data.part2, test2->racine->data.part3, test2->racine->data.part4);
//construction
    printf("test: construction \n");
    Tournoi* cons1 = createSingleItemTournoi(data5);
    Tournoi* cons2 = createSingleItemTournoi(data10);
    Tournoi* cons3 = createSingleItemTournoi(data15);
    Tournoi* listTournoi[3] = {cons1,cons2,cons3};
//传递起始地址
    FileBinomiale* fb_TEST = Construction_FB(listTournoi, 3);
    printf("fb size apres de construction: %d\n", fb_TEST->size);
    Tournoi* tournoi_fbTEST_first = fb_TEST->file[0];
    Tournoi* tournoi_fbTEST_second = fb_TEST->file[1];
    printf("val_racine test: part1:%x + part2:%x + part3:%x + part4:%x\n", tournoi_fbTEST_first->racine->data.part1, tournoi_fbTEST_first->racine->data.part2, tournoi_fbTEST_first->racine->data.part3, tournoi_fbTEST_first->racine->data.part4);
    printf("val_racine test: part1:%x + part2:%x + part3:%x + part4:%x\n", tournoi_fbTEST_second->racine->data.part1, tournoi_fbTEST_second->racine->data.part2, tournoi_fbTEST_second->racine->data.part3, tournoi_fbTEST_second->racine->data.part4);
//    printFileBinomiale(fb_TEST);



    freeTournoi(t7);
    freeFileBinomiale(fb0);
    return 0;
}