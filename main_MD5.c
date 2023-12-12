#include <stdio.h>
#include <string.h>
//#include <intrin.h>
#include "hachage/md5.h"





int main() {
    const uint8_t message[] = "message";
    uint8_t res[16];
    md5(message, strlen((char *)message), res);

    printf("MD5: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", res[i]);
    }
    printf("\n");
    convertFilesInFolder("../Shakespeare", "../decodeMd5");
    return 0;

}
