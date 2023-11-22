#include <stdio.h>
#include <intrin.h>
#include "echauffement/echauffement.h"
#include "echauffement/test/testEchauffement.h"

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




    return 0;
}
