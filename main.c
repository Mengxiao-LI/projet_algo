#include <stdio.h>
#include <string.h>
//#include <intrin.h>
#include "echauffement/echauffement.h"
#include "echauffement/test/testEchauffement.h"
#include "tas/list.h"
#include "tas/tas.h"


int main() {
    printf("Question1\n");
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
        if (isLessThan(key1, key2)) {
            printf("Key1 is less than Key2\n");
        }else{
            printf("Key1 is more than Key2\n");
        }

        if (isEqual(key1, key2)) {
            printf("Key1 is equal to Key2\n");
        }else{
            printf("Key1 is not equal to Key2\n");
        }

        free(hexStr1);
        free(hexStr2);
    }
//Q2
    printf("Question2\n");



    // 初始化堆
    HP hp;

    HeapInit (&hp);
    printf("-----Q2.1 Ajout:-----\n");
    AfficheTasArray(&hp);
    Ajout(&hp,10);
    Ajout(&hp,3);
    Ajout(&hp,5);
    Ajout(&hp,1);
    Ajout(&hp,2);
    Ajout(&hp,4);
    AfficheTasArray(&hp);
    AfficheTasArbre(&hp);
    printf("-----Q2.1 supprMin:------\n");
    SupprMin(&hp);
    AfficheTasArray(&hp);
    AfficheTasArbre(&hp);


    printf("-----Q2.1 AjoutsIteratifs:-----\n");
    Liste l1;
    initVide (&l1);
    empile(5, &l1);
    empile(4, &l1);
    empile(3, &l1);
    empile(10, &l1);
    empile(2, &l1);
    empile(19, &l1);
    empile(13, &l1);
    empile(41, &l1);
    printf("list is: ");
    affiche_rec(l1);
    HP hp1;
    HeapInit (&hp1);
    AjoutsIteratifs(&hp1,l1);
    AfficheTasArray(&hp1);
    AfficheTasArbre(&hp1);

    printf("-----Q2.2 Construction:-----\n");
    HP* hp2 = Construction(l1);
    AfficheTasArray(hp2);
    AfficheTasArbre(hp2);
    printf("-----Q2.2 Union:-----\n");
    HP* hp3 = Union(hp2,&hp1);
    AfficheTasArray(hp3);
    AfficheTasArbre(hp3);
    // 清理资源
    HeapDestroy(&hp);
    HeapDestroy(&hp1);
    HeapDestroy(&hp2);
    return 0;
}
