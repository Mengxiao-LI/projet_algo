//
// Created by lmx on 2023/11/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>



#define MAX_LINE_LENGTH 200000 // 定义一个足够大的数以容纳一行中的所有字符

char* getRandomLine(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    int lineCount = 0;
    char line[MAX_LINE_LENGTH];

    // 计算文件中的总行数
    while (fgets(line, sizeof(line), file)) {
        lineCount++;
    }

    if (lineCount == 0) {
        fclose(file);
        return NULL; // 文件为空
    }

    // 生成一个随机行号
    srand(time(NULL));
    int randomLine = rand() % lineCount;

    // 重新定位到文件开始
    fseek(file, 0, SEEK_SET);

    // 读取到所选的行
    for (int i = 0; i <= randomLine; ++i) {
        if (!fgets(line, sizeof(line), file)) {
            fclose(file);
            return NULL; // 读取失败
        }
    }

    fclose(file);

    // 去除换行符
    line[strcspn(line, "\n")] = 0;

    // 复制并返回所选行的内容，不包含换行符
    return strdup(line);
}


char** getTwoRandomFiles() {
    DIR* dir;
    struct dirent* entry;
    char** files = malloc(2 * sizeof(char*));
    int count = 0;

    const char *basePath="../cles_alea";

    if ((dir = opendir(basePath)) == NULL) {
        perror("opendir() error");
        return NULL;
    }

    // 第一遍遍历，计算文件数量
    while ((entry = readdir(dir)) != NULL) {

            count++;

    }

    if (count < 2) {
        printf("Not enough files found.\n");
        closedir(dir);
        return NULL;
    }

    srand(time(NULL));
    int randomIndex1 = rand() % count;
    int randomIndex2;
    do {
        randomIndex2 = rand() % count;
    } while (randomIndex1 == randomIndex2);

    // 第二遍遍历，获取随机文件名称
    rewinddir(dir);
    count = 0;
    while ((entry = readdir(dir)) != NULL) {

            if (count == randomIndex1 || count == randomIndex2) {
                files[count == randomIndex1 ? 0 : 1] = strdup(entry->d_name);
                if (count == randomIndex1 && count == randomIndex2) {
                    break;
                }
            }
            count++;
        
    }

    closedir(dir);
    return files;
}
