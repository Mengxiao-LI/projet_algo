#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "echauffement/echauffement.h"
#include "fileBinomiale/filebinomiale.h"
Key128 readKey128FromFile(FILE* file) {
    unsigned int part1, part2, part3, part4;
    fscanf(file, "%x %x %x %x", &part1, &part2, &part3, &part4);
    Key128 key = {part1, part2, part3, part4};
    return key;
}

int main() {
    // Moyenne temps pour Construction
    printf("Moyenne Temps Construction\n");
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
            FileBinomiale* fb = Construction_FB(tournois, count);
            gettimeofday(&end, NULL);
            //
            long seconds = (end.tv_sec - start.tv_sec);
            long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            totalMicros += micros;
            free(myArray);
            freeFileBinomiale(fb);
            for(int i = 0;i<sizes[j];i++) {
                freeTournoi(tournois[i]);
            }

        }

        long averageMicros = totalMicros / num_tests;
        printf("Average execution time for %d keys: %ld microseconds\n", sizes[j], averageMicros);
    }

    // Moyenne temps pour Union
    printf("Moyenne Temps Union\n");
    const char* file_pattern1_union = "../decode/jeu_1_nb_cles_%d.txt";
    const char* file_pattern2_union = "../decode/jeu_%d_nb_cles_%d.txt"; // 其他四个文件
    const int num_tests_union = 5; // 测试次数
    const int sizes_union[] = {1000, 5000, 10000, 20000, 50000, 80000, 120000, 200000};
    const int num_sizes_union = 8;

    for (int j = 0; j < num_sizes_union; j++) {
        long totalMicros = 0;

        for (int i = 1; i < num_tests_union; i++) {
            char file_path1_union[1024], file_path2_union[1024];
            sprintf(file_path1_union, file_pattern1_union, sizes_union[j]);
            sprintf(file_path2_union, file_pattern2_union, i + 1, sizes_union[j]); // 避免重复使用 jeu_1 文件

            int size1, size2;
            Key128* keys1 = processFile(file_path1_union, &size1);
            Key128* keys2 = processFile(file_path2_union, &size2);

            Tournoi** tournoisA = malloc(sizeof(Tournoi*) * sizes_union[j]);
            Tournoi** tournoisB = malloc(sizeof(Tournoi*) * sizes_union[j]);
            int countA = 0;
            for(;countA<sizes_union[j];countA++) {
                tournoisA[countA] = createSingleItemTournoi(keys1[countA]);
            }
            int countB = 0;
            for(;countB<sizes_union[j];countB++) {
                tournoisB[countB] = createSingleItemTournoi(keys2[countB]);
            }
            FileBinomiale* fbA = Construction_FB(tournoisA, countA);
            FileBinomiale* fbB = Construction_FB(tournoisB, countB);
            struct timeval start, end;
            gettimeofday(&start, NULL);

            // Union 操作
            FileBinomiale* fb_Union = UnionFile(fbA, fbB);

            gettimeofday(&end, NULL);

            long seconds = (end.tv_sec - start.tv_sec);
            long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            totalMicros += micros;

            printf("Processing file: %s...%ld microseconds\n", file_path2_union, micros);

            free(keys1);
            free(keys2);
            freeFileBinomiale(fbA);
            freeFileBinomiale(fbB);
            for(int i = 0;i<sizes_union[j];i++) {
                freeTournoi(tournoisA[i]);
            }
            for(int i = 0;i<sizes_union[j];i++) {
                freeTournoi(tournoisB[i]);
            }


        }

        long averageMicros = totalMicros / 4;
        printf("Average execution time for %d keys: %ld microseconds\n", sizes_union[j], averageMicros);
    }


/////////////////////////////
//complexite Construction
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
//testConstructionTime("../decode/jeu_4_nb_cles_5000.txt", "../construction_times2.csv",3);
    printf("fini\n");
//complexite Union

    return 0;
}