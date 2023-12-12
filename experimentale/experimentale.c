//
// Created by lmx on 2023/12/12.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "../echauffement/echauffement.h"
#include "../arbreBR/arbreBR.h"
#include "../hachage/md5.h"

char** addUniqueWord(char** array, int* size, const char* word) {
    // 检查单词是否已存在于数组中
    for (int i = 0; i < *size; i++) {
        if (strcmp(array[i], word) == 0) {
            // 单词已存在，不再添加
            return array;
        }
    }

    // 单词不存在于数组中，添加它
    char** newArray = realloc(array, (*size + 1) * sizeof(char*));
    if (!newArray) {
        perror("Unable to reallocate memory");
        exit(EXIT_FAILURE);
    }
    newArray[*size] = strdup(word);
    (*size)++;
    return newArray;
}

char** readWordsFromDirectory(const char* dirPath, int* totalSize) {
    char** uniqueWords = NULL;
    int size = 0;
    DIR* dir = opendir(dirPath);
    if (!dir) {
        perror("Unable to open directory");
        return NULL;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char filePath[1024];
            snprintf(filePath, sizeof(filePath), "%s/%s", dirPath, entry->d_name);
            FILE* file = fopen(filePath, "r");
            if (!file) continue;

            char word[256];
            while (fscanf(file, "%255s", word) != EOF) {
                uniqueWords = addUniqueWord(uniqueWords, &size, word);
            }
            fclose(file);
        }
    }
    closedir(dir);

    *totalSize = size;
    return uniqueWords;
}
//从decode文件建立ABR

void readTxtFiles(const char *directory, ABR** tree) {

    DIR *d;
    struct dirent *dir;
    d = opendir(directory);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (strstr(dir->d_name, ".txt")) {
                char filepath[1024];
                sprintf(filepath, "%s/%s", directory, dir->d_name);
                int size1;
                Key128* myArray1 = processFile1(filepath, &size1);

                for (int i = 0; i < size1; i++) {
                    if(!estDans(*tree,myArray1[i])){
                        *tree = InsertNode(*tree, myArray1[i]);


                    }

                }

                free(myArray1);
            }
        }
        closedir(d);
    } else {
        perror("opendir failed");
    }

}


//将listmot 转换成key128
Key128* convertToKey128Array(char** listMots, int totalWords) {
    Key128* array = malloc(totalWords * sizeof(Key128));
    if (array == NULL) {
        perror("Error allocating memory for Key128 array");
        exit(EXIT_FAILURE);
    }

    uint8_t result[16]; // MD5哈希值大小

    for (int j = 0; j < totalWords; ++j) {
        md5((uint8_t *)listMots[j], strlen(listMots[j]), result);

        array[j].part1 = ((uint32_t)result[0] << 24) | ((uint32_t)result[1] << 16) | ((uint32_t)result[2] << 8) | result[3];
        array[j].part2 = ((uint32_t)result[4] << 24) | ((uint32_t)result[5] << 16) | ((uint32_t)result[6] << 8) | result[7];
        array[j].part3 = ((uint32_t)result[8] << 24) | ((uint32_t)result[9] << 16) | ((uint32_t)result[10] << 8) | result[11];
        array[j].part4 = ((uint32_t)result[12] << 24) | ((uint32_t)result[13] << 16) | ((uint32_t)result[14] << 8) | result[15];


    }

    return array;
}