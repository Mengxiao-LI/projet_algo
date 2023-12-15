#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/dirent.h>
#include "md5.h"

//on obtient k[64] par:
//void md5_k_Init(uint32_t k[64]){
//    for (int i = 0; i < 64; i++) {
//        double sinValue = fabs(sin(i + 1));  // 计算 sin 值并取绝对值
//        double scaledValue = sinValue * pow(2, 32);  // 将 sin 值缩放到 [0, 2^32] 范围内
//        k[i] = (uint32_t) scaledValue;  // 将缩放后的值转换为32位整数并存储在数组中
//    }
//}
//initialisation k[]
//printf("print K[64]\n");
//md5_k_Init(k);
//for (int i = 0; i < 64; i++) {
//printf("k[%d] = 0x%08x\n", i, k[i]);
//}

//Définir k r comme suit :
static uint32_t k[] = {0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
                       0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
                       0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
                       0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
                       0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
                       0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
                       0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
                       0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
                       0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
                       0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
                       0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
                       0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
                       0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
                       0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
                       0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
                       0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

static const uint32_t r[] = {
        7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
        5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
        4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
        6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};
//initialisation Préparation des variables :
void md5_context_Init(MD5Context *ctx) {
    ctx->data_deja = 0;
    ctx->buffer[0] = (uint32_t)A;
    ctx->buffer[1] = (uint32_t)B;
    ctx->buffer[2] = (uint32_t)C;
    ctx->buffer[3] = (uint32_t)D;
}

//Préparation du message (padding) :
void md5_PadMessage(uint8_t *message, size_t messageLen, uint64_t messageLen_Debut) {
    // ajoute bit '1'
    message[messageLen++] = 0x80; // 0x80 = 10000000
    // pad bit '0' jouqu'a 448 mod 512
    //"messageLen" est la longueur en octets (byte) du message, elle doit être multipliée par 8 pour être exprimée en bits.
    while ((messageLen*8) % 512 != 448) {
        //Économiser des ressources et adopter des méthodes plus efficaces：while (messageLen % 64 != 56)
        message[messageLen++] = 0x00;
    }
    // codée en 64-bit little-endian au message
    messageLen_Debut *= 8; // convertir byte vers bit
    for (size_t i = 0; i < 8; i++) {//8 byte = 64 bit，decaler 1 byte chaque fois
        message[messageLen++] = (uint8_t)(messageLen_Debut >> (i * 8));//(unit8_t) ignorer les bit de poids fort，
                                                                      // conserver que 8 bit，du coup on decale a droit 8bits chaque tour
    }
}

//main loop
void md5_MainLoop(MD5Context *ctx) {
    uint32_t w[16];
    uint32_t a, b, c, d, f, g, temp;
    size_t i;

// Divise un bloc de 512 bits en 16 mots de 32 bits (petit-boutiste).
// 32 bits = 4 octets, i * 4 -> premier octet, i * 4 + 1 -> deuxième octet, ...
// Dans la fonction md5_DecouperMessage, data_current stocke 64 octets.
    for (i = 0; i < 16; i++) {
        w[i] = (uint32_t) ctx->data_current[i * 4] |
               (uint32_t) ctx->data_current[i * 4 + 1] << 8 |
               (uint32_t) ctx->data_current[i * 4 + 2] << 16 |
               (uint32_t) ctx->data_current[i * 4 + 3] << 24;
    }
    //        ctx->data_current[i * 4 + 3] << 24：
// C'est le quatrième octet du mot actuel (octet le plus significatif).
// Il est déplacé de 24 bits vers la gauche pour devenir le quatrième octet dans un mot de 32 bits.

    // initialisation de la valeur hachage
    a = ctx->buffer[0];
    b = ctx->buffer[1];
    c = ctx->buffer[2];
    d = ctx->buffer[3];

    // main loop
    for (i = 0; i < 64; i++) {
        if (i < 16) {
            f = (b & c) | (~b & d);
            g = i;
        } else if (i < 32) {
            f = (d & b) | (~d & c);
            g = (5 * i + 1) % 16;
        } else if (i < 48) {
            f = b ^ c ^ d;
            g = (3 * i + 5) % 16;
        } else {
            f = c ^ (b | ~d);
            g = (7 * i) % 16;
        }
        temp = d;
        d = c;
        c = b;
        b = b + LEFTROTATE(a + f + k[i] + w[g], r[i]);
        a = temp;
    }

// concatenation de val hachage
    ctx->buffer[0] += a;
    ctx->buffer[1] += b;
    ctx->buffer[2] += c;
    ctx->buffer[3] += d;
}


//Découpage en blocs de 512 bits :
void md5_DecouperMessage(uint8_t *paddedMessage, size_t paddedMessageLen, MD5Context *ctx) {
    for (size_t offset = 0; offset < paddedMessageLen; offset += 64) {
        // Parcours de la message rempli, traitant chaque bloc de données de 64 octets (512 bits) à chaque fois.
// ctx->input : un tableau dans le contexte MD5 utilisé pour stocker le bloc actuellement traité.
// paddedMessage + offset : pointe vers le début du bloc actuellement traité dans le message rempli.
// 64 : copie 64 octets de données à chaque fois.
        memcpy(ctx->data_current, paddedMessage + offset, 64);
        md5_MainLoop(ctx);
    }
}

void md5_Final(MD5Context *ctx) {
    // Concatène h0, h1, h2, h3 dans res en utilisant le format little-endian.
    for (int i = 0; i < 4; i++) {//8*4=32bit 32*4=128bit val hachage
        ctx->res[i * 4] = (uint8_t)(ctx->buffer[i] & 0xFF);
        ctx->res[i * 4 + 1] = (uint8_t)((ctx->buffer[i] >> 8) & 0xFF);
        ctx->res[i * 4 + 2] = (uint8_t)((ctx->buffer[i] >> 16) & 0xFF);
        ctx->res[i * 4 + 3] = (uint8_t)((ctx->buffer[i] >> 24) & 0xFF);
    }
}

void md5(const uint8_t *message, size_t messageLen,uint8_t *res){
    MD5Context ctx;
    uint8_t *paddedMessage;
    size_t paddedMessageLen;

    // initialisation context MD5
    md5_context_Init(&ctx);

    // Calcule la longueur du message rempli (doit être un multiple de 64 octets).
    paddedMessageLen = ((messageLen + 8) / 64 + 1) * 64;
    paddedMessage = malloc(paddedMessageLen);
    if (paddedMessage == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Copie le message d'origine dans une mémoire nouvellement allouée et le remplit.
    memcpy(paddedMessage, message, messageLen);
    md5_PadMessage(paddedMessage, messageLen, messageLen);

    // Traite chaque bloc de message de 64 octets (512 bits).
    md5_DecouperMessage(paddedMessage, paddedMessageLen, &ctx);

    // Concatène les valeurs finales de hachage pour obtenir un résultat de 128 bits.
    md5_Final(&ctx);

    // copie resultat
    memcpy(res, ctx.res, 16);

    // free memoire
    free(paddedMessage);
}
//Q6
void convertTextToHachage(const char *inputPath, const char *outputPath) {
    FILE *inputFile = fopen(inputPath, "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputPath, "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile); // Commence par fermer le fichier d'entrée qui était ouvert précédemment.
        exit(EXIT_FAILURE);
    }

    char word[256]; // Suppose que les mots ne dépassent pas 255 caractères.
    uint8_t result[16];

    while (fscanf(inputFile, "%255s", word) != EOF) { // Lit chaque mot.
        md5((uint8_t *)word, strlen(word), result);

        // Écrit la valeur de hachage dans le fichier de sortie.
        for (int i = 0; i < 16; ++i) {
            fprintf(outputFile, "%02x", result[i]); // Écrit la valeur de hachage en format hexadécimal.
        }
        fprintf(outputFile, "\n"); // Ajoute un saut de ligne après chaque valeur de hachage.
    }

    fclose(inputFile);
    fclose(outputFile);
}
void convertFilesInFolder(const char *inputFolder, const char *outputFolder) {
    DIR *dir;
    struct dirent *entry;
    char inputPath[1024];
    char outputPath[1024];
    FILE *file;

    dir = opendir(inputFolder);
    if (dir == NULL) {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Ignore les entrées pour le répertoire actuel (".") et le répertoire parent ("..").
        }

        // Construit le chemin complet du fichier.
        sprintf(inputPath, "%s/%s", inputFolder, entry->d_name);

        // Vérifie si c'est un fichier ordinaire.
        if (entry->d_type == DT_REG) {
            // construire le path
            sprintf(outputPath, "%s/%s", outputFolder, entry->d_name);

            // convert fichier
            convertTextToHachage(inputPath, outputPath);
        }
    }

    closedir(dir);
}
