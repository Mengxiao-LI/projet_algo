//
// Created by lmx on 2023/12/12.
//
#include <sys/time.h>
#include "echauffement/echauffement.h"
#include "arbreBR/arbreBR.h"
#include "hachage/md5.h"
#include "fileBinomiale/filebinomiale.h"
#include "experimentale/experimentale.h"
#include "tas/tas.h"

#define MAX_FILES 37
#define MAX_FILENAME_LEN 256


//将listmot 转换成key128


int main() {

    printf("-----------Q6.1-----------\n");

    printf("--Q6.1,ABR--\n");
    ABR *tree = NULL;
    //从已经编译过的md5文件，找不同的值放入abr（少）
    readTxtFiles("../decodeMd5", &tree);
    PrintTree(tree);

    printf("--Q6.1,liste de mot--\n");//多
    int totalWords = 0;
    char** listMots = readWordsFromDirectory("../Shakespeare", &totalWords);
    printf("%d\n",totalWords);
    for (int i = 0; i < totalWords; i++) {
        printf("%s\n", listMots[i]);
        //free(listMots[i]);  //
    }

//Q2
    printf("-----------Q6.2-----------\n");
//将上面的liste mode -md5-key128
//查看是否有编译不一样的词
    Key128* array=convertToKey128Array(listMots, totalWords);
    bool hasCollision=false;
    int j=0;
    for (int i = 0; i < totalWords; i++) {
        if(!estDans(tree,array[i])){
            j++;
            printf("Key%d: part1:%08x + part2:%08x + part3:%08x + part4:%08x\n",j, array[i].part1, array[i].part2, array[i].part3, array[i].part4);
            hasCollision=true;
        }
        //printf("%08x %08x %08x %08x\n", array[i].part1, array[i].part2, array[i].part3, array[i].part4);

    }
//查看是否有重复md5的词
    ABR *tree1 = NULL;

    int cpt=0;
    for (int i = 0; i < totalWords; i++) {
        if(!estDans(tree1,array[i])){
            tree1 = InsertNode(tree1, array[i]);
        }else{
            cpt++;
            printf("Key%d: part1:%08x + part2:%08x + part3:%08x + part4:%08x\n",j, array[i].part1, array[i].part2, array[i].part3, array[i].part4);
            hasCollision=true;
        }

    }
    if(!hasCollision){
        printf("-----Q6.2no Collision, il y a %d\n",totalWords);
    }else{
        printf("-----Q6.2yes Collision, il y a %d\n",totalWords);
    }

    //Question 6.3
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("-----------Q6.3-----------\n");
    printf("--test 6.3---");
    long seconds;
    long micros;
    printf("AjoutsIteratifs tas\n");
    struct timeval start, end;
    long totalMicros = 0;
    HP hp1;
    HeapInit (&hp1);
    //HeapPrint(&hp);

    gettimeofday(&start, NULL);
    //
    AjoutsIteratifs(&hp1,array,totalWords);


    gettimeofday(&end, NULL);
    seconds = (end.tv_sec - start.tv_sec);
    micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
    totalMicros += micros;


    printf("time for keys: %ld microseconds\n", totalMicros);

            //最后写free(array);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("--test 6.3---");
    printf("SupprMin tas\n");
     totalMicros = 0;


    gettimeofday(&start, NULL);
    //
    for(int i=0;i<10;i++){
        SupprMin(&hp1);
    }

    gettimeofday(&end, NULL);
    seconds = (end.tv_sec - start.tv_sec);
    micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
    totalMicros += micros;


    printf("time for keys: %ld microseconds\n", totalMicros);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("--test 6.3---");
    printf("Construction tas\n");
    totalMicros = 0;
    HP hp2;
    HeapInit (&hp2);

    gettimeofday(&start, NULL);
    //
    Construction(&hp2, array, totalWords);

    gettimeofday(&end, NULL);
    seconds = (end.tv_sec - start.tv_sec);
    micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
    totalMicros += micros;


    printf("time for keys: %ld microseconds\n", totalMicros);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("--test 6.3---");
    printf("Union tas\n");
    HP hp3;
    HeapInit (&hp3);

    int size1;
    Key128* keys1 = processFile("../decode/jeu_1_nb_cles_1000.txt", &size1);
    Construction(&hp3, keys1, size1);
    gettimeofday(&start, NULL);
    //
    HP *hpUnion = Union(&hp3, &hp2);

    gettimeofday(&end, NULL);
    seconds = (end.tv_sec - start.tv_sec);
    micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
    totalMicros += micros;
    printf("time for keys: %ld microseconds\n", totalMicros);
    //

    freeABR(tree);
    free(keys1);
    HeapDestroy(&hp1);
    HeapDestroy(&hp2);
    HeapDestroy(&hp3);
    HeapDestroy(&hpUnion);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //File binomiale
    printf("-----------Q6.3-----------\n");
    printf("--test 6.3---");
    long seconds_fb;
    long micros_fb;
    printf("AjoutFB FileBinomiale\n");
    struct timeval start_fb, end_fb;
    long totalMicros_fb = 0;
    FileBinomiale* fb = malloc(sizeof (FileBinomiale));
    fb->size = 0;
    fb->file = NULL;
    Tournoi** tournois = malloc(sizeof(Tournoi*) * totalWords);
    int count = 0;
    for(;count<totalWords;count++) {
        tournois[count] = createSingleItemTournoi(array[count]);
    }

    gettimeofday(&start, NULL);
    //
    for(int i=0;i<count;i++)
    {
       FileBinomiale* temp = Ajout_FB(tournois[count],fb);
        freeFileBinomiale(fb); // 释放旧的 FBn
        fb = temp;
    }
    gettimeofday(&end, NULL);
    seconds = (end.tv_sec - start.tv_sec);
    micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
    totalMicros += micros;


    printf("time for keys: %ld microseconds\n", totalMicros);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("--test 6.3---");
    printf("SupprMin Filebinomiale\n");
    totalMicros = 0;


    gettimeofday(&start, NULL);
    //
    for(int i=0;i<10;i++){
        SupprMin_FB(fb);
    }

    gettimeofday(&end, NULL);
    seconds = (end.tv_sec - start.tv_sec);
    micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
    totalMicros += micros;


    printf("time for keys: %ld microseconds\n", totalMicros);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("--test 6.3---");
    printf("Construction FileBinomiale\n");
    totalMicros = 0;
    FileBinomiale* fbcons = malloc(sizeof (FileBinomiale));
    fbcons->size = 0;
    fbcons->file = NULL;
    Tournoi** tournoiscons = malloc(sizeof(Tournoi*) * totalWords);
    int countcons = 0;
    for(;countcons<totalWords;countcons++) {
        tournoiscons[countcons] = createSingleItemTournoi(array[countcons]);
    }

    gettimeofday(&start, NULL);
    //
    FileBinomiale* FBTEST1 = Construction_FB(tournoiscons,countcons);

    gettimeofday(&end, NULL);
    seconds = (end.tv_sec - start.tv_sec);
    micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
    totalMicros += micros;

    printf("time for keys: %ld microseconds\n", totalMicros);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("--test 6.3---");
    printf("Union Filebinomiale\n");
    FileBinomiale* fbcons2 = malloc(sizeof (FileBinomiale));
    fbcons2->size = 0;
    fbcons2->file = NULL;
    int size2;
    Key128* keys2 = processFile("../decode/jeu_1_nb_cles_1000.txt", &size2);
    Tournoi** tournoiscons2 = malloc(sizeof(Tournoi*) * size2);

    int countcons2 = 0;
    for(;countcons2<size2;countcons2++) {
        tournoiscons2[countcons2] = createSingleItemTournoi(keys2[countcons2]);
    }
    FileBinomiale* FBTEST2 = Construction_FB(tournoiscons,countcons);

    gettimeofday(&start, NULL);
    //
    FileBinomiale* fb_Union = UnionFile(FBTEST1, FBTEST2);

    gettimeofday(&end, NULL);
    seconds = (end.tv_sec - start.tv_sec);
    micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
    totalMicros += micros;
    printf("time for keys: %ld microseconds\n", totalMicros);
    //

    freeABR(tree);
    free(keys2);
//    freeFileBinomiale(fb);
//    freeFileBinomiale(fbcons);
//    freeFileBinomiale(fbcons2);
//    freeFileBinomiale(FBTEST1);
//    freeFileBinomiale(FBTEST2);
//    for(int i = 0;i<totalWords;i++) {
//        freeTournoi(tournois[i]);
//    }
//    for(int i = 0;i<totalWords;i++) {
//        freeTournoi(tournoiscons[i]);
//    }
//    for(int i = 0;i<size2;i++) {
//        freeTournoi(tournoiscons2[i]);
//    }


    free(array);
    return 0;
}
