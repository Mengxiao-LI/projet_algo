//
// Created by zhengdao on 2023/12/15.
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
    //File binomiale
    printf("-----------Q6.3-----------\n");
    printf("--test 6.3---");

    int totalWords = 0;
    char** listMots = readWordsFromDirectory("../Shakespeare", &totalWords);
    Key128* array=convertToKey128Array(listMots, totalWords);

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

    gettimeofday(&start_fb, NULL);
    //
    for(int i=0;i<count;i++)
    {
        FileBinomiale* temp = Ajout_FB(tournois[i],fb);
        freeFileBinomiale(fb); // 释放旧的 FBn
        fb = temp;
    }
    gettimeofday(&end_fb, NULL);
    seconds_fb = (end_fb.tv_sec - start_fb.tv_sec);
    micros_fb = ((seconds_fb * 1000000) + end_fb.tv_usec) - (start_fb.tv_usec);
    totalMicros_fb += micros_fb;


    printf("time for keys: %ld microseconds\n", totalMicros_fb);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("--test 6.3---");
    printf("SupprMin Filebinomiale\n");
    totalMicros_fb = 0;


    gettimeofday(&start_fb, NULL);
    //
    for(int i=0;i<10;i++){
        SupprMin_FB(fb);
    }

    gettimeofday(&end_fb, NULL);
    seconds_fb = (end_fb.tv_sec - start_fb.tv_sec);
    micros_fb = ((seconds_fb * 1000000) + end_fb.tv_usec) - (start_fb.tv_usec);
    totalMicros_fb += micros_fb;


    printf("time for keys: %ld microseconds\n", totalMicros_fb);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("--test 6.3---");
    printf("Construction FileBinomiale\n");
    totalMicros_fb = 0;
    FileBinomiale* fbcons = malloc(sizeof (FileBinomiale));
    fbcons->size = 0;
    fbcons->file = NULL;
    Tournoi** tournoiscons = malloc(sizeof(Tournoi*) * totalWords);
    int countcons = 0;
    for(;countcons<totalWords;countcons++) {
        tournoiscons[countcons] = createSingleItemTournoi(array[countcons]);
    }

    gettimeofday(&start_fb, NULL);
    //
    FileBinomiale* FBTEST1 = Construction_FB(tournoiscons,countcons);

    gettimeofday(&end_fb, NULL);
    seconds_fb = (end_fb.tv_sec - start_fb.tv_sec);
    micros_fb = ((seconds_fb * 1000000) + end_fb.tv_usec) - (start_fb.tv_usec);
    totalMicros_fb += micros_fb;

    printf("time for keys: %ld microseconds\n", totalMicros_fb);
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

    gettimeofday(&start_fb, NULL);
    //
    FileBinomiale* fb_Union = UnionFile(FBTEST1, FBTEST2);

    gettimeofday(&end_fb, NULL);
    seconds_fb = (end_fb.tv_sec - start_fb.tv_sec);
    micros_fb = ((seconds_fb * 1000000) + end_fb.tv_usec) - (start_fb.tv_usec);
    totalMicros_fb += micros_fb;
    printf("time for keys: %ld microseconds\n", totalMicros_fb);
    //

//    freeABR(tree);
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