//
// Created by lmx on 2023/11/22.
//
#include <stdio.h>
#include <string.h>
#include "echauffement.h"
#include <dirent.h>


Key128 createKey(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4) {
    Key128 newKey = {p1, p2, p3, p4};
    return newKey;
}
//Q1.2
bool inf(Key128 key1, Key128 key2) {
    if (key1.part1 < key2.part1) return true;
    if (key1.part1 > key2.part1) return false;

    if (key1.part2 < key2.part2) return true;
    if (key1.part2 > key2.part2) return false;

    if (key1.part3 < key2.part3) return true;
    if (key1.part3 > key2.part3) return false;

    return key1.part4 < key2.part4;
}
//Q1.3
bool eg(Key128 key1, Key128 key2) {
    return key1.part1 == key2.part1 && key1.part2 == key2.part2 &&
           key1.part3 == key2.part3 && key1.part4 == key2.part4;
}
//verifier
//删，一个十六进制占4bit。32bit就是8个
Key128 hexTokey128(const char* hex){
    Key128 key = {0, 0, 0, 0};
    char temp[9];
    size_t len=strlen(hex);
    if (len >= 2 && (hex[0] == '0') && (hex[1] == 'x' || hex[1] == 'X')) {
        hex += 2; // 跳过前缀
        len -= 2; // 调整长度
    }
    if (len > 32) {
        printf("more than 128bit\n");
        return key;
    }
    for(int i=0;i<4;i++){
        //删，从第四位开始算4.3.2.1
        size_t start = len >= 8 * (i+1) ?len- 8 * (i + 1) : 0;
        size_t end = len > 8 * i ? len - 8 * i : 0;
        if (end > start) {
            memset(temp, 0, 9);
            strncpy(temp, &hex[start], end - start);
            unsigned int *part = &key.part1 + 3-i;
            sscanf(temp, "%8x", part);
        }

    }
    return key;
}

void convertHexToKey128(const char *inputFile, const char *outputFile) {
    FILE *fp = fopen(inputFile, "r");
    FILE *fp_out = fopen(outputFile, "w");
    char line[100];

    if (fp == NULL || fp_out == NULL) {
        perror("Error opening file");
        exit(-1);
    }

    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = 0;
        Key128 key = hexTokey128(line);
        fprintf(fp_out, "%08x %08x %08x %08x\n", key.part1, key.part2, key.part3, key.part4);
    }

    fclose(fp);
    fclose(fp_out);
}
void convertAllFilesInFolder(const char *inputFolder, const char *outputFolder) {
    DIR *dir;
    struct dirent *entry;
    char inputPath[1024];
    char outputPath[1024];
    FILE *file;

    dir = opendir(inputFolder);
    if (dir == NULL) {
        perror("Error opening directory");
        exit(-1);
    }

    while ((entry = readdir(dir)) != NULL) {
        // 构建完整的文件路径
        sprintf(inputPath, "%s/%s", inputFolder, entry->d_name);

        // 尝试打开文件以检测是否为普通文件
        file = fopen(inputPath, "r");
        if (file) {
            fclose(file); // 关闭文件，因为它将在 convertHexToKey128 中重新打开

            // 构建输出文件的路径
            sprintf(outputPath, "%s/%s", outputFolder, entry->d_name);

            // 转换文件
            convertHexToKey128(inputPath, outputPath);
        }
    }

    closedir(dir);
}