//
// Created by lmx on 2023/12/12.
//
#include "../echauffement/echauffement.h"
#include "../arbreBR/arbreBR.h"
#include "../hachage/md5.h"
#ifndef PROJET_MENGXIAO_ZHENGDAO_EXPERIMENTALE_H
#define PROJET_MENGXIAO_ZHENGDAO_EXPERIMENTALE_H
char** readWordsFromDirectory(const char* dirPath, int* totalSize);
void readTxtFiles(const char *directory, ABR** tree);
Key128* convertToKey128Array(char** listMots, int totalWords);
#endif //PROJET_MENGXIAO_ZHENGDAO_EXPERIMENTALE_H
