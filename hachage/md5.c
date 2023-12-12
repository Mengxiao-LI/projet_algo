#include <string.h>
#include <stdio.h>
#include <sys/dirent.h>
#include <dirent.h>
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
//消息的初始长度通常以字节为单位表示，这是因为字节是计算机处理和存储数据的基本单位
void md5_PadMessage(uint8_t *message, size_t messageLen, uint64_t messageLen_Debut) {
    // 第一步：添加一个"1"位
    message[messageLen++] = 0x80; // 0x80 = 10000000
    // 第二步：填充"0"位，直到消息长度达到448 mod 512
    //messageLen是以字节为单位的长度 byte，需要*8
    while ((messageLen*8) % 512 != 448) {
        //Économiser des ressources et adopter des méthodes plus efficaces：while (messageLen % 64 != 56)
        message[messageLen++] = 0x00;
    }
    // 第三步：添加原始消息长度（以位为单位）的64位小端表示codée en 64-bit little-endian au message
    messageLen_Debut *= 8; // 从字节转换成位
    for (size_t i = 0; i < 8; i++) {//64位=8个字节，每次移动一个字节
        message[messageLen++] = (uint8_t)(messageLen_Debut >> (i * 8));//(unit8_t)忽略高位，只保留8位，所以我们每次向右移动8位
    }
}

//main loop
void md5_MainLoop(MD5Context *ctx) {
    uint32_t w[16];
    uint32_t a, b, c, d, f, g, temp;
    size_t i;

    // 将512位块分解为16个32位的字（little-endian）
    //32位=4个字节 i * 4->第一个字节 i * 4 + 1->第二个字节....
    for (i = 0; i < 16; i++) {//在md5_DecouperMessage中data_current中存储了64个字节
        w[i] = (uint32_t) ctx->data_current[i * 4] |
               (uint32_t) ctx->data_current[i * 4 + 1] << 8 |
               (uint32_t) ctx->data_current[i * 4 + 2] << 16 |
               (uint32_t) ctx->data_current[i * 4 + 3] << 24;
//        ctx->data_current[i * 4 + 3] << 24：
//        这是当前字的第四个字节（最高有效字节）。左移24位，使其成为32位字中的第四个字节。
    }

    // 初始化哈希值
    a = ctx->buffer[0];
    b = ctx->buffer[1];
    c = ctx->buffer[2];
    d = ctx->buffer[3];

    // 主循环
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

// 将这一块的结果加到当前的哈希值中
    ctx->buffer[0] += a;
    ctx->buffer[1] += b;
    ctx->buffer[2] += c;
    ctx->buffer[3] += d;
}


//Découpage en blocs de 512 bits :
void md5_DecouperMessage(uint8_t *paddedMessage, size_t paddedMessageLen, MD5Context *ctx) {
    for (size_t offset = 0; offset < paddedMessageLen; offset += 64) {
        // 遍历填充后的消息，每次处理64字节（512位）的数据块
        // ctx->input：MD5上下文中用于存储当前处理块的数组
        // paddedMessage + offset：指向填充消息中当前处理块的起始位置
        // 64：每次复制64字节的数据
        memcpy(ctx->data_current, paddedMessage + offset, 64);
        md5_MainLoop(ctx);
    }
}

void md5_Final(MD5Context *ctx) {
    // 将 h0, h1, h2, h3 按小端格式拼接到 res 中
    for (int i = 0; i < 4; i++) {//8*4=32位 32*4=128位的哈希值
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

    // 初始化MD5上下文
    md5_context_Init(&ctx);

    // 计算填充后的消息长度（必须是64字节的倍数）
    paddedMessageLen = ((messageLen + 8) / 64 + 1) * 64;
    paddedMessage = malloc(paddedMessageLen);
    if (paddedMessage == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // 复制原始消息到新分配的内存并进行填充
    memcpy(paddedMessage, message, messageLen);
    md5_PadMessage(paddedMessage, messageLen, messageLen);

    // 处理每个64字节的分块消息
    md5_DecouperMessage(paddedMessage, paddedMessageLen, &ctx);

    // 将最终的哈希值拼接成128位的结果
    md5_Final(&ctx);

    // 复制结果到提供的res数组
    memcpy(res, ctx.res, 16);

    // 释放分配的内存
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
        fclose(inputFile); // 先关闭已打开的输入文件
        exit(EXIT_FAILURE);
    }

    char word[256]; // 假设单词不超过255字符
    uint8_t result[16]; // MD5哈希值大小

    while (fscanf(inputFile, "%255s", word) != EOF) { // 读取每个单词
        md5((uint8_t *)word, strlen(word), result);

        // 将哈希值写入到输出文件
        for (int i = 0; i < 16; ++i) {
            fprintf(outputFile, "%02x", result[i]); // 将哈希值以十六进制形式写入
        }
        fprintf(outputFile, "\n"); // 每个哈希值后换行
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
            continue; // 忽略当前目录和上级目录的条目
        }

        // 构建完整的文件路径
        sprintf(inputPath, "%s/%s", inputFolder, entry->d_name);

        // 检查是否为普通文件
        if (entry->d_type == DT_REG) {
            // 构建输出文件的路径
            sprintf(outputPath, "%s/%s", outputFolder, entry->d_name);

            // 转换文件
            convertTextToHachage(inputPath, outputPath);
        }
    }

    closedir(dir);
}
