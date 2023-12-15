#include <stdio.h>
#include <string.h>
#include <sys/time.h>
//#include <intrin.h>
#include "echauffement/echauffement.h"

#include "tas/tas.h"
#include "tas/tasArbre.h"



int main() {
    Key128 key,key1,key2,key3,key4;
    const char *hexStr = "0d09ef03 382fa280 d11bcf44 1bc2e4b9";
    const char *hexStra = "0d09ef03 382fa280 d11bcf44 1bc2e4b7";
    const char *hexStrb = "0d09ef03 382fa280 d11bcf44 1bc2e4b6";
    const char *hexStr3 = "0d09ef03 382fa280 d11bcf44 1bc2e4ba";
    const char *hexStr4 = "0d09ef03 382fa280 d11bcf44 1bc2e4bb";
    sscanf(hexStr, "%x %x %x %x", &key.part1, &key.part2, &key.part3, &key.part4);
    sscanf(hexStra, "%x %x %x %x", &key1.part1, &key1.part2, &key1.part3, &key1.part4);
    sscanf(hexStrb, "%x %x %x %x", &key2.part1, &key2.part2, &key2.part3, &key2.part4);
    sscanf(hexStr3, "%x %x %x %x", &key3.part1, &key3.part2, &key3.part3, &key3.part4);
    sscanf(hexStr4, "%x %x %x %x", &key4.part1, &key4.part2, &key4.part3, &key4.part4);
    Key128 key5,key6,key7,key8,key9;
    const char *hexStr5 = "0d09ef03 382fa280 d11bcf44 1bc2e4a7";
    const char *hexStr6 = "0d09ef03 382fa280 d11bcf44 1bc2e4c8";
    const char *hexStr7 = "0d09ef03 382fa280 d11bcf44 1bc2e4d9";
    const char *hexStr8 = "0d09ef03 382fa280 d11bcf44 1bc2e45a";
    const char *hexStr9 = "0d09ef03 382fa280 d11bcf44 1bc2e42b";
    sscanf(hexStr5, "%x %x %x %x", &key5.part1, &key5.part2, &key5.part3, &key5.part4);
    sscanf(hexStr6, "%x %x %x %x", &key6.part1, &key6.part2, &key6.part3, &key6.part4);
    sscanf(hexStr7, "%x %x %x %x", &key7.part1, &key7.part2, &key7.part3, &key7.part4);
    sscanf(hexStr8, "%x %x %x %x", &key8.part1, &key8.part2, &key8.part3, &key8.part4);
    sscanf(hexStr9, "%x %x %x %x", &key9.part1, &key9.part2, &key9.part3, &key9.part4);

    //Q2
    printf("Question2\n");
    printf("++++++++++++++++++Tas tableau+++++++++++++++++++++++\n");
    HP hp;

    HeapInit (&hp);
    printf("-----Q2.1 Ajout:-----\n");




    Ajout(&hp,key);
    Ajout(&hp,key3);
    Ajout(&hp,key2);
    Ajout(&hp,key1);
    Ajout(&hp,key4);
    AfficheTasArray(&hp);
    printf("-----Q2.1 supprMin:------\n");
    SupprMin(&hp);
    AfficheTasArray(&hp);
    printf("-----Q2.1 AjoutsIteratifs:-----\n");
    printf("test: ajouter jeu_1_nb_cles_1000\n");
    const char* filename = "../decode/jeu_1_nb_cles_1000.txt";
    int size;
    Key128* myArray = processFile(filename, &size);

    HP hp1;
    HeapInit (&hp1);
    AjoutsIteratifs(&hp1,myArray,size);

    AfficheTasArray(&hp1);
    printf("-----Q2.2 Construction:-----\n");
    Key128 keys[5];
    const char *hexStrings[] = {
            "0d09ef03 382fa280 d11bcf44 1bc2e4b7",
            "0d09ef03 382fa280 d11bcf44 1bc2e4b8",
            "0d09ef03 382fa280 d11bcf44 1bc2e4b9",
            "0d09ef03 382fa280 d11bcf44 1bc2e4ba",
            "0d09ef03 382fa280 d11bcf44 1bc2e4bb"
    };


    for (int i = 0; i < 5; i++) {
        sscanf(hexStrings[i], "%x %x %x %x", &keys[i].part1, &keys[i].part2, &keys[i].part3, &keys[i].part4);
    }

//
    HP *hp3;



    Construction(&hp3, keys, 5);


    AfficheTasArray(hp3);
    printf("test: Construire par jeu_1_nb_cles_1000\n");
    HP* hp2;
    //HeapInit (&hp2);
    Construction(&hp2,myArray,size);
    AfficheTasArray(hp2);




    printf("-----Q2.2 Union:-----\n");
    HP hp4;
    HeapInit (&hp4);


    Ajout(&hp4,key6);
    Ajout(&hp4,key5);
    Ajout(&hp4,key7);
    Ajout(&hp4,key9);
    Ajout(&hp4,key8);
    printf(" tas1\n");
    AfficheTasArray(&hp);
    printf(" tas2\n");
    AfficheTasArray(&hp4);
    HP* hp5 = Union(&hp4,&hp);
    printf(" Union\n");
    AfficheTasArray(hp5);

    // free
    HeapDestroy(&hp);
    HeapDestroy(&hp1);
    HeapDestroy(hp2);
    HeapDestroy(hp3);
    HeapDestroy(&hp4);
    HeapDestroy(hp5);

    printf("++++++++++++++++++Tas Arbre+++++++++++++++++++++++\n");
    printf("-----Q2.1 Ajout:-----\n");
    HPArb* tr;
    initTasAB(&tr);
    ajout(&tr,key2);
    ajout(&tr,key4);
    ajout(&tr,key3);
    ajout(&tr,key);
    ajout(&tr,key1);


    afficheAb(tr,0);
    printf("\n");
    printf("-----Q2.1 supprMin:-----\n");

    supprMin(&tr);
    afficheAb(tr,0);
    printf("-----Q2.1 AjoutsIteratifs:-----\n");

    HPArb* tr10;
    initTasAB (&tr10);
    ajoutsIteratifs(&tr10,keys,5);
    afficheAb(tr10,0);
    printf("test: ajouter jeu_1_nb_cles_1000\n");


    HPArb* tr1;
    initTasAB (&tr1);
    ajoutsIteratifs(&tr1,myArray,size);

    printf("test afficher fils Gauche\n");
    afficheGauche(tr1);
    printf("-----Q2.2 Construction:-----\n");


    HPArb* tr2;
    initTasAB (&tr2);
    construction1(&tr2,keys,5);
    afficheAb(tr2,0);
    HPArb* tr3;
    initTasAB (&tr3);

    construction1(&tr3,myArray,size);
    printf("test: Construire par jeu_1_nb_cles_1000\n");
    printf("test afficher fils Gauche\n");
    afficheGauche(tr3);

    printf("-----Q2.2 Union:-----\n");
    HPArb* tr4;
    initTasAB(&tr4);


    ajout(&tr4,key5);
    ajout(&tr4,key9);
    ajout(&tr4,key8);
    ajout(&tr4,key6);
    ajout(&tr4,key7);
    printf(" +++tas1+++\n");
    afficheAb(tr10,0);
    printf(" +++tas2+++\n");
    afficheAb(tr4,0);
    printf(" +++tasUnion+++\n");
    HPArb* tr5= UnionA(tr10,tr4);
    afficheAb(tr5,0);
    printf(" +++test2+++\n");
    const char* filename1 = "../decode/jeu_2_nb_cles_20000.txt";
    int size1;
    Key128* myArray1 = processFile(filename1, &size1);

    HPArb* tr7;
    initTasAB (&tr7);
    construction1(&tr7,myArray1,size1);
    HPArb *tr6= UnionA(tr3,tr7);
    afficheGauche(tr6);
    free(myArray);
    free(myArray1);
    freeTree(tr1);
    freeTree(tr);
    freeTree(tr4);
    freeTree(tr10);
    freeTree(tr3);
    freeTree(tr2);
    freeTree(tr7);
    freeTree(tr5);
    freeTree(tr6);
    return 0;
}
