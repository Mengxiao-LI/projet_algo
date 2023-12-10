#include <stdio.h>
#include <string.h>
//#include <intrin.h>
#include "echauffement/echauffement.h"
#include "echauffement/test/testEchauffement.h"

#include "arbreBR/arbreBR.h"


int main() {
    printf("-----------Q5-----------\n");
    printf("minTest insert\n");
    const char* testData[] = {
            "5bf4217f", "1f6e9ed6", "a37109ca", "5b1345a1",
            "5bf4217f", "1f6e9ed6", "a37109ca", "5b1345a4",
            "5bf4217f", "1f6e9ed6", "a37109ca", "5b1345a2",
            "5bf4217f", "1f6e9ed6", "a37109ca", "5b1345a3",
            "5bf4217f", "1f6e9ed6", "a37109ca", "5b1345a0"
    };
    int numKeys = sizeof(testData) / sizeof(testData[0]) / 4;

    // 创建树
    ABR *tree = NULL;

    // 插入数据
    for (int i = 0; i < numKeys; i++) {
        unsigned int p1, p2, p3, p4;
        sscanf(testData[4 * i], "%x", &p1);
        sscanf(testData[4 * i + 1], "%x", &p2);
        sscanf(testData[4 * i + 2], "%x", &p3);
        sscanf(testData[4 * i + 3], "%x", &p4);
        Key128 key = createKey(p1, p2, p3, p4);

        tree = InsertNode(tree, key);
    }
    PrintTree(tree);

    printf("---------\n");
    ABR *tree1 = NULL;
    const char* filename = "../decode/jeu_1_nb_cles_1000.txt";
    int size;
    Key128* myArray = processFile(filename, &size);

// 插入数据
    for (int i = 0; i < size; i++) {
        tree1 = InsertNode(tree1, myArray[i]);
    }

    PrintTree(tree1);

free(myArray);
    printf("bool\n");
    Key128 keyfind,keyNfind;

    const char *hexStr = "002c5863 05ff9d3a 96c26885 4dc8fc25";
    const char *hexStr1 = "002c5863 05ff9d3a 96c26885 4dc8fc26";

    sscanf(hexStr, "%x %x %x %x", &keyfind.part1, &keyfind.part2, &keyfind.part3, &keyfind.part4);
    sscanf(hexStr1, "%x %x %x %x", &keyNfind.part1, &keyNfind.part2, &keyNfind.part3, &keyNfind.part4);
    if (estDans(tree1, keyfind)) {
        printf("keyfind is in the tree.\n");

    } else {
        printf("keyfind is not in the tree.\n");
    }

    if (estDans(tree1, keyNfind)) {
        printf("keyNfind is in the tree.\n");

    } else {
        printf("keyNfind is not in the tree.\n");
    }
    return 0;
}
