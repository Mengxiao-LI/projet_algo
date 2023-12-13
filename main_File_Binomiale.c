#include <stdio.h>
#include <string.h>
#include <time.h>
//#include <intrin.h>
#include "echauffement/echauffement.h"
#include "tas/list.h"
#include "tas/tas.h"
#include "fileBinomiale/filebinomiale.h"
Key128 readKey128FromFile(FILE* file) {
    unsigned int part1, part2, part3, part4;
    fscanf(file, "%x %x %x %x", &part1, &part2, &part3, &part4);
    Key128 key = {part1, part2, part3, part4};
    return key;
}

Tournoi *createSingleItemTournoi(Key128 data) {
    Tournoi* t = malloc(sizeof(Tournoi));
    ArbreBinomialeNode *node = malloc(sizeof(ArbreBinomialeNode));
    node->data = data;
    node->child = NULL;
    node->frere = NULL;
    node->parent = NULL;
    t->racine = node;
    return t;
}

void testConstructionTime(const char* filename, const char* outputFilename) {
    FILE* file = fopen(filename, "r");
    FILE* outputFile = fopen(outputFilename, "w");

    if (file == NULL || outputFile == NULL) {
        perror("Error opening file");
        return;
    }

    // 写入 CSV 文件头
    fprintf(outputFile, "Count,Time\n");

    Tournoi** tournois = malloc(sizeof(Tournoi*) * 200000); // 假设最多 20 万个 Tournoi
    int count = 0;

    while (!feof(file) && count < 200000) {
        Key128 key = readKey128FromFile(file);
        tournois[count] = createSingleItemTournoi(key);
        count++;

        clock_t start = clock();
        FileBinomiale* fb = Construction_FB(tournois, count);
        clock_t end = clock();

        double timeSpent = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(outputFile, "%d,%f\n", count, timeSpent); // CSV 格式输出

        freeFileBinomiale(fb);
    }

    // 清理分配的 Tournoi
    for (int i = 0; i < count; i++) {
        freeTournoi(tournois[i]);
    }
    free(tournois);

    fclose(file);
    fclose(outputFile);
}



int main() {
//complexite Construction

    testConstructionTime("../decode/jeu_2_nb_cles_200000.txt", "../construction_times.csv");
    printf("fini\n");
//complexite Union

    return 0;
}