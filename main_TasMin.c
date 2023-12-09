#include <stdio.h>
#include <string.h>
//#include <intrin.h>
#include "echauffement/echauffement.h"
#include "tas/list.h"
#include "tas/tas.h"
#include "tas/tasArbre.h"



int main() {

//Q2
    printf("Question2\n");
/*    printf("++++++++++++++++++Tas tableau+++++++++++++++++++++++\n");
    HP hp;

    HeapInit (&hp);
    printf("-----Q2.1 Ajout:-----\n");

    Key128 key,key1,key2,key3,key4;
    const char *hexStr = "0d09ef03 382fa280 d11bcf44 1bc2e4b7";
    const char *hexStra = "0d09ef03 382fa280 d11bcf44 1bc2e4b8";
    const char *hexStrb = "0d09ef03 382fa280 d11bcf44 1bc2e4b9";
    const char *hexStr3 = "0d09ef03 382fa280 d11bcf44 1bc2e4ba";
    const char *hexStr4 = "0d09ef03 382fa280 d11bcf44 1bc2e4bb";
    sscanf(hexStr, "%x %x %x %x", &key.part1, &key.part2, &key.part3, &key.part4);
    sscanf(hexStra, "%x %x %x %x", &key1.part1, &key1.part2, &key1.part3, &key1.part4);
    sscanf(hexStrb, "%x %x %x %x", &key2.part1, &key2.part2, &key2.part3, &key2.part4);
    sscanf(hexStr3, "%x %x %x %x", &key3.part1, &key3.part2, &key3.part3, &key3.part4);
    sscanf(hexStr4, "%x %x %x %x", &key4.part1, &key4.part2, &key4.part3, &key4.part4);

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
    Liste maListe = buildListFromFile("../decode/jeu_1_nb_cles_1000.txt");

    HP hp1;
    HeapInit (&hp1);
    AjoutsIteratifs(&hp1,maListe);

    AfficheTasArray(&hp1);
    printf("-----Q2.2 Construction:-----\n");
    printf("test: Construire par jeu_1_nb_cles_1000\n");
    HP* hp2 = Construction(maListe);
    AfficheTasArray(hp2);
    freeList(maListe);
    printf("-----Q2.2 Union:-----\n");
    HP hp3;
    HeapInit (&hp3);
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

    Ajout(&hp3,key6);
    Ajout(&hp3,key5);
    Ajout(&hp3,key7);
    Ajout(&hp3,key9);
    Ajout(&hp3,key8);
    printf(" tas1\n");
    AfficheTasArray(&hp);
    printf(" tas2\n");
    AfficheTasArray(&hp3);
    HP* hp4 = Union(&hp3,&hp);
    printf(" Union\n");
    AfficheTasArray(hp4);

    // 清理资源
    HeapDestroy(&hp);
    HeapDestroy(&hp1);
    HeapDestroy(&hp2);
    HeapDestroy(&hp3);
    HeapDestroy(&hp4);*/

    printf("++++++++++++++++++Tas Arbre+++++++++++++++++++++++\n");
    printf("-----Q2.1 Ajout:-----\n");
    HPArb* tr;
    initTasAB(&tr);
    Key128 key,key1,key2,key3,key4;
    const char *hexStr = "0d09ef03 382fa280 d11bcf44 1bc2e4b7";
    const char *hexStra = "0d09ef03 382fa280 d11bcf44 1bc2e4b8";
    const char *hexStrb = "0d09ef03 382fa280 d11bcf44 1bc2e4b9";
    const char *hexStr3 = "0d09ef03 382fa280 d11bcf44 1bc2e4ba";
    const char *hexStr4 = "0d09ef03 382fa280 d11bcf44 1bc2e4bb";
    sscanf(hexStr, "%x %x %x %x", &key.part1, &key.part2, &key.part3, &key.part4);
    sscanf(hexStra, "%x %x %x %x", &key1.part1, &key1.part2, &key1.part3, &key1.part4);
    sscanf(hexStrb, "%x %x %x %x", &key2.part1, &key2.part2, &key2.part3, &key2.part4);
    sscanf(hexStr3, "%x %x %x %x", &key3.part1, &key3.part2, &key3.part3, &key3.part4);
    sscanf(hexStr4, "%x %x %x %x", &key4.part1, &key4.part2, &key4.part3, &key4.part4);

    ajout(&tr,key);
    ajout(&tr,key3);
    ajout(&tr,key2);
    ajout(&tr,key1);
    ajout(&tr,key4);
    afficheAb(tr,0);
    printf("\n");
    printf("-----Q2.1 supprMin:-----\n");

    supprMin(&tr);
    afficheAb(tr,0);
    printf("-----Q2.1 AjoutsIteratifs:-----\n");
    printf("test: ajouter jeu_1_nb_cles_1000\n");
    Liste maListe = buildListFromFile("../decode/jeu_1_nb_cles_1000.txt");
    HPArb* tr1;
    initTasAB (&tr1);
    ajoutsIteratifs(&tr1,maListe);

    //afficheAb(tr1,0);
    printf("test afficher fils Gauche\n");
    afficheGauche(tr1);

    return 0;
}
