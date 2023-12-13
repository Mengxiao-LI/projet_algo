#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
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

//void testConstructionTime(const char* filename, const char* outputFilename, int repetitions) {
//    FILE* file = fopen(filename, "r");
//    FILE* outputFile = fopen(outputFilename, "w");
//
//    if (file == NULL || outputFile == NULL) {
//        perror("Error opening file");
//        return;
//    }
//
//    fprintf(outputFile, "Count,AverageTime\n");
//
//    Tournoi** tournois = malloc(sizeof(Tournoi*) * 5000); // 假设最多 20 万个 Tournoi
//    int count = 0;
//
//    while (!feof(file) && count < 5000) {
//        Key128 key = readKey128FromFile(file);
//        tournois[count] = createSingleItemTournoi(key);
//        count++;
//
//        double totalTimeSpent = 0;
//        for (int i = 0; i < repetitions; i++) {
//            clock_t start = clock();
//            FileBinomiale* fb = Construction_FB(tournois, count);
//            clock_t end = clock();
//
//            totalTimeSpent += (double)(end - start) / CLOCKS_PER_SEC;
//            freeFileBinomiale(fb);
//        }
//
//        double averageTimeSpent = totalTimeSpent / repetitions;
//        fprintf(outputFile, "%d,%f\n", count, averageTimeSpent);
//    }
//
//    for (int i = 0; i < count; i++) {
//        freeTournoi(tournois[i]);
//    }
//    free(tournois);
//
//    fclose(file);
//    fclose(outputFile);
//}





int main() {
    printf("Question2.8\n");
    printf("AjoutsIteratifs tableau last\n");
    const char* file_pattern = "../decode/jeu_%d_nb_cles_%d.txt";
    const int num_tests = 5; // 1.2.3.4.5
    const int sizes[] = {1000, 5000, 10000, 20000,50000, 80000, 120000, 200000};
    const int num_sizes = 8;
    char file_path[1024];


    for (int j = 0; j < num_sizes; j++) {
        long totalMicros = 0;

        for (int i = 0; i < num_tests; i++) {
            int size;
            sprintf(file_path, file_pattern, i + 1, sizes[j]);
            Key128* myArray = processFile(file_path, &size);
            printf("Processing file: %s\n", file_path);
            Tournoi** tournois = malloc(sizeof(Tournoi*) * sizes[j]);
            int count = 0;
            for(;count<sizes[j];count++) {
                tournois[count] = createSingleItemTournoi(myArray[count]);
            }


            struct timeval start, end;
             gettimeofday(&start, NULL);
            //
//            AjoutsIteratifs(&hp1,myArray,size);
            FileBinomiale* fb = Construction_FB(tournois, count);

            gettimeofday(&end, NULL);
            //
            long seconds = (end.tv_sec - start.tv_sec);
            long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            totalMicros += micros;
            free(myArray);
            freeFileBinomiale(fb);


        }

        long averageMicros = totalMicros / num_tests;
        printf("Average execution time for %d keys: %ld microseconds\n", sizes[j], averageMicros);
    }

/////////////////////////////
//complexite Construction

//    testConstructionTime("../decode/jeu_4_nb_cles_5000.txt", "../construction_times2.csv",3);
    printf("fini\n");
//complexite Union

    return 0;
}