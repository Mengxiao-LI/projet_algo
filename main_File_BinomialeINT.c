#include <stdio.h>
#include <string.h>
#include "echauffement/echauffement.h"
#include "fileBinomialeINT/filebinomiale.h"


// 创建一个含有单个元素的二项树
Tournoi createSingleItemTournoi(int data) {
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
    // 创建几个二项树
    Tournoi t1 = createSingleItemTournoi(5);
    Tournoi t2 = createSingleItemTournoi(10);
    Tournoi t3 = createSingleItemTournoi(15);


    Tournoi listTournoi[3] = {t1,t2,t3};
    //传递起始地址
    FileBinomiale fb = Construction_FB(listTournoi, 3);
    printf("size FB %d\n",fb.size);
    if (fb.size > 0 && fb.file[0] != NULL && fb.file[0]->racine != NULL) {
        // 打印 file[0] 的 racine 的值
        printf(" racine: %d\n",
               fb.file[0]->racine->data);
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