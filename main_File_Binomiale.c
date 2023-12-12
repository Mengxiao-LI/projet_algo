#include <stdio.h>
#include <string.h>
//#include <intrin.h>
#include "echauffement/echauffement.h"
#include "tas/list.h"
#include "tas/tas.h"
#include "fileBinomiale/filebinomiale.h"


// 创建一个含有单个元素的二项树
Tournoi createSingleItemTournoi(Key128 data) {
    Tournoi t;
    ArbreBinomialeNode *node = malloc(sizeof(ArbreBinomialeNode));
    node->data = data;
    node->child = NULL;
    node->frere = NULL;
    node->parent = NULL;

    t.racine = node;
    return t;
}

int main() {
    Key128 myKey = {
            0x01234567, // part1
            0x89ABCDEF, // part2
            0xFEDCBA98, // part3
            0x76543210  // part4
    };
    Key128 myKey2 = {
            0xdf6943ba, // part1
            0x6d51464f, // part2
            0x6b021579, // part3
            0x33bdd9ad  // part4
    };
    Key128 myKey3 = {
            0xd5ac4f2e, // part1
            0xcf1a2f14, // part2
            0xd7e43f68, // part3
            0x70e731e4  // part4
    };
    // 创建几个二项树
    Tournoi t1 = createSingleItemTournoi(myKey);
    Tournoi t2 = createSingleItemTournoi(myKey2);
    Tournoi t3 = createSingleItemTournoi(myKey3);


    Tournoi listTournoi[3] = {t1,t2,t3};
    //传递起始地址
    FileBinomiale fb = Construction_FB(listTournoi, 3);
    printf("size FB %d\n",fb.size);
    if (fb.size > 0 && fb.file[0] != NULL && fb.file[0]->racine != NULL) {
        // 打印 file[0] 的 racine 的值
        printf("file[0] racine: part1: %x, part2: %x, part3: %x, part4: %x\n",
               fb.file[0]->racine->data.part1,
               fb.file[0]->racine->data.part2,
               fb.file[0]->racine->data.part3,
               fb.file[0]->racine->data.part4);
    } else {
        printf("file[0] is empty or does not exist.\n");
    }
    printf("bien ajoute\n");

    // 显示队列中的最小元素
    Tournoi *minTournoi = MinDeg(fb);

    if (minTournoi != NULL) {
        printf("Le plus petit tournoi a pour racine: %d\n", minTournoi->racine->data);
    } else {
        printf("La file binomiale est vide.\n");
    }

    // 移除最小元素并显示结果
    fb = SupprMin_FB(fb);
    minTournoi = MinDeg(fb);
    if (minTournoi != NULL) {
        printf("Apres suppression, le nouveau plus petit tournoi a pour racine: %d\n", minTournoi->racine->data);
    } else {
        printf("La file binomiale est vide apres suppression.\n");
    }

    // 清理内存
    freeFileBinomiale(fb);

    return 0;
}