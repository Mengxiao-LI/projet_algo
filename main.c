#include <stdio.h>
#include <string.h>
//#include <intrin.h>
#include "echauffement/echauffement.h"
#include "echauffement/test/testEchauffement.h"
#include "tas/list.h"
#include "tas/tas.h"



int main() {
    printf("Question1\n");
    //从随机两个文件里取两个数
    char** randomFiles = getTwoRandomFiles();
    char fullPath1[1024];
    char fullPath2[1024];
    const char* basePath = "../cles_alea/";
    if (randomFiles != NULL) {
        printf("From:\n");

        printf("file1: %s\n", randomFiles[0]);
        printf("file2 2: %s\n", randomFiles[1]);

        char* file1 = randomFiles[0];
        char* file2 = randomFiles[1];

        strcpy(fullPath1, basePath);
        strcat(fullPath1, file1);
        strcpy(fullPath2, basePath);
        strcat(fullPath2, file2);
        // 释放由 getTwoRandomFiles 分配的内存
        free(randomFiles[0]);
        free(randomFiles[1]);
        free(randomFiles);
    } else {
        printf("无法获取随机文件名。\n");
        return 1;
    }


    char* hexStr1 = getRandomLine(fullPath1);
    char* hexStr2 = getRandomLine(fullPath2);

    if (hexStr1 != NULL && hexStr2 != NULL) {
        printf("hexadecimal1 is: %s\n", hexStr1);
        printf("hexadecimal2 is: %s\n", hexStr2);

        // 转换
        Key128 key1 = hexTokey128(hexStr1);
        Key128 key2 = hexTokey128(hexStr2);

        // 打印转换结果
        printf("Key1: part1:%x + part2:%x + part3:%x + part4:%x\n", key1.part1, key1.part2, key1.part3, key1.part4);
        printf("Key2: part1:%x + part2:%x + part3:%x + part4:%x\n", key2.part1, key2.part2, key2.part3, key2.part4);

        //测试算法
        if (inf(key1, key2)) {
            printf("Key1 is less than Key2\n");
        }else{
            printf("Key1 is more than Key2\n");
        }

        if (eg(key1, key2)) {
            printf("Key1 is equal to Key2\n");
        }else{
            printf("Key1 is not equal to Key2\n");
        }

        free(hexStr1);
        free(hexStr2);
    }
    convertHexToKey128("../cles_alea/jeu_1_nb_cles_1000.txt", "../decode/output.txt");
    convertAllFilesInFolder("../cles_alea", "../decode");

//Q2
    printf("Question2\n");



    // 初始化堆
    HP hp;

    HeapInit (&hp);
    printf("-----Q2.1 Ajout:-----\n");
    AfficheTasArray(&hp);
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
    Liste maListe = buildListFromFile("../decode/jeu_1_nb_cles_1000.txt");

    HP hp1;
    HeapInit (&hp1);
    AjoutsIteratifs(&hp1,maListe);

    AfficheTasArray(&hp1);
    printf("-----Q2.2 Construction:-----\n");
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
    AfficheTasArray(&hp);

    AfficheTasArray(&hp3);
    HP* hp4 = Union(&hp3,&hp);
    AfficheTasArray(hp4);

    // 清理资源
    HeapDestroy(&hp);
    HeapDestroy(&hp1);
    HeapDestroy(&hp2);
    HeapDestroy(&hp3);
    HeapDestroy(&hp4);
    return 0;
}
