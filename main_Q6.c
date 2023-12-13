//
// Created by lmx on 2023/12/12.
//
#include <sys/time.h>
#include "echauffement/echauffement.h"
#include "arbreBR/arbreBR.h"
#include "hachage/md5.h"
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
    if(!hasCollision){
        printf("-----Q6.2no Collision\n");
    }else{
        printf("-----Q6.2yes Collision \n");
    }
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
    free(array);
    free(keys1);
    HeapDestroy(&hp1);
    HeapDestroy(&hp2);
    HeapDestroy(&hp3);
    HeapDestroy(&hpUnion);
    return 0;
}
