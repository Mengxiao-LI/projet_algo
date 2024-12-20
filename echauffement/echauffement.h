//
// Created by lmx on 2023/11/22.
//

#ifndef PROJET_MENGXIAO_ZHENGDAO_ECHAUFFEMENT_H
#define PROJET_MENGXIAO_ZHENGDAO_ECHAUFFEMENT_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>

//Q1.1
/*************************************************/
/*          definition type change bit           */
/*************************************************/
//une clé de 128 bits est divisée en 4 parties dont chacune contient 32 bits.
typedef struct {
    unsigned int part1;
    unsigned int part2;
    unsigned int part3;
    unsigned int part4;
} Key128;


/*************************************************/
/*                                               */
/*                predeclarations                */
/*                                               */
/*************************************************/
Key128 createKey(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4);
//Q1.2
bool inf(Key128 key1, Key128 key2);
//Q1.3
bool eg(Key128 key1, Key128 key2);

//Pour verifier
Key128 hexTokey128(const char* hex);
void convertHexToKey128(const char *inputFile, const char *outputFile);
void convertAllFilesInFolder(const char *inputFolder, const char *outputFolder);
//
Key128* buildArrayFromFile(const char* filename, int* size);
Key128* resizeArray(Key128* array, int newSize);
Key128* processFile(const char* filename, int* size);
Key128* processFile1(const char* filename, int* size);
#endif //PROJET_MENGXIAO_ZHENGDAO_ECHAUFFEMENT_H
