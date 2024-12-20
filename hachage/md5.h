#ifndef PROJET_MENGXIAO_ZHENGDAO_MD5_H
#define PROJET_MENGXIAO_ZHENGDAO_MD5_H
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    uint64_t data_deja;//Taille du message traité
    uint32_t buffer[4];//Valeur de hachage actuelle
    uint8_t data_current[64];//Tampon d'entrée utilisé pour stocker le bloc de données actuellement traité de 512 bits
    uint8_t res[16];//Résultat de hachage
} MD5Context;

//operation left rotate utilise dans main loop
#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))
#define A 0x67452301
#define B 0xefcdab89
#define C 0x98badcfe
#define D 0x10325476

//void md5_k_Init(uint32_t k[64]);
void md5_context_Init(MD5Context *ctx);
void md5_DecouperMessage(uint8_t *paddedMessage, size_t paddedMessageLen, MD5Context *ctx);
void md5_PadMessage(uint8_t *message, size_t messageLen, uint64_t messageLen_Debut);
void md5_MainLoop(MD5Context *ctx);
void md5_Final(MD5Context *ctx);
void md5(const uint8_t *message, size_t messageLen,uint8_t *res);
void convertTextToHachage(const char *inputPath, const char *outputPath);
void convertFilesInFolder(const char *inputFolder, const char *outputFolder);
#endif //PROJET_MENGXIAO_ZHENGDAO_MD5_H
