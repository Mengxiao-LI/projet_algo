//
// Created by lmx on 2023/12/12.
//
#include "echauffement/echauffement.h"
#include "arbreBR/arbreBR.h"
#include "hachage/md5.h"
#include "experimentale/experimentale.h"

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

    free(listMots);

    //
    freeABR(tree);
    free(array);
    return 0;
}
