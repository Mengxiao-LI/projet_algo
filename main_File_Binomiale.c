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

void testConstructionTime(const char* filename, const char* outputFilename, int repetitions) {
    FILE* file = fopen(filename, "r");
    FILE* outputFile = fopen(outputFilename, "w");

    if (file == NULL || outputFile == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(outputFile, "Count,AverageTime\n");

    Tournoi** tournois = malloc(sizeof(Tournoi*) * 5000); // 假设最多 20 万个 Tournoi
    int count = 0;

    while (!feof(file) && count < 5000) {
        Key128 key = readKey128FromFile(file);
        tournois[count] = createSingleItemTournoi(key);
        count++;

        double totalTimeSpent = 0;
        for (int i = 0; i < repetitions; i++) {
            clock_t start = clock();
            FileBinomiale* fb = Construction_FB(tournois, count);
            clock_t end = clock();

            totalTimeSpent += (double)(end - start) / CLOCKS_PER_SEC;
            freeFileBinomiale(fb);
        }

        double averageTimeSpent = totalTimeSpent / repetitions;
        fprintf(outputFile, "%d,%f\n", count, averageTimeSpent);
    }

    for (int i = 0; i < count; i++) {
        freeTournoi(tournois[i]);
    }
    free(tournois);

    fclose(file);
    fclose(outputFile);
}




int main() {
//complexite Construction

    testConstructionTime("../decode/jeu_4_nb_cles_5000.txt", "../construction_times2.csv",3);
    printf("fini\n");
//complexite Union

    return 0;
}