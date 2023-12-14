#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
//#include <intrin.h>
#include "echauffement/echauffement.h"

#include "tas/tas.h"
#include "tas/tasArbre.h"
//#include "tas/tasArbre.h"
//#include "tas/test.h"


int main() {
    //Q2
/*    const char* file_pattern = "../decode/jeu_%d_nb_cles_%d.txt";
    const int num_tests = 5; // 1.2.3.4.5
    const int sizes[] = {1000, 5000, 10000, 20000,50000, 80000, 120000, 200000};
    const int num_sizes = 8;
    char file_path[1024];*/

/*    printf("Question2.8\n");
    printf("AjoutsIteratifs tableau last\n");
    const char* file_pattern = "../decode/jeu_%d_nb_cles_%d.txt";
    const int num_tests = 5; // 1.2.3.4.5
    const int sizes[] = {1000, 5000, 10000, 20000,50000, 80000, 120000, 200000};
    const int num_sizes = 8;
    char file_path[1024];


    for (int j = 0; j < num_sizes; j++) {
        long totalMicros = 0;

        for (int i = 0; i < num_tests; i++) {
            sprintf(file_path, file_pattern, i + 1, sizes[j]);
            printf("Processing file: %s\n", file_path);

            int size;
            Key128* myArray = processFile(file_path, &size);

            HP hp1;
            HeapInit (&hp1);





            //HeapPrint(&hp);

            struct timeval start, end;
            gettimeofday(&start, NULL);
            //
            AjoutsIteratifs(&hp1,myArray,size);


            gettimeofday(&end, NULL);
            //
            long seconds = (end.tv_sec - start.tv_sec);
            long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            totalMicros += micros;
            free(myArray);
            HeapDestroy(&hp1);


        }

        long averageMicros = totalMicros / num_tests;
        printf("Average execution time for %d keys: %ld microseconds\n", sizes[j], averageMicros);
    }*/
   /* printf("Question2.8\n");
    printf("Con tableau last\n");



    for (int j = 0; j < num_sizes; j++) {
        long totalMicros = 0;

        for (int i = 0; i < num_tests; i++) {
            sprintf(file_path, file_pattern, i + 1, sizes[j]);
            printf("Processing file: %s\n", file_path);

            int size;
            Key128* myArray = processFile(file_path, &size);

            HP hp1;
            HeapInit (&hp1);

            struct timeval start, end;
            gettimeofday(&start, NULL);
            //
            Construction(&hp1,myArray,size);


            gettimeofday(&end, NULL);
            //
            long seconds = (end.tv_sec - start.tv_sec);
            long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            totalMicros += micros;

            free(myArray);
            HeapDestroy(&hp1);
        }

        long averageMicros = totalMicros / num_tests;
        printf("Average execution time for %d keys: %ld microseconds\n", sizes[j], averageMicros);
    }

    printf("Question2.8\n");
    printf("ajout arbre\n");



    for (int j = 0; j < num_sizes; j++) {
        long totalMicros = 0;

        for (int i = 0; i < num_tests; i++) {
            sprintf(file_path, file_pattern, i + 1, sizes[j]);
            printf("Processing file: %s\n", file_path);


            int size;
            Key128* myArray = processFile(file_path, &size);

            HPArb* tr1;
            initTasAB (&tr1);


            struct timeval start, end;
            gettimeofday(&start, NULL);
            //

            ajoutsIteratifs(&tr1,myArray,size);

            gettimeofday(&end, NULL);
            //
            long seconds = (end.tv_sec - start.tv_sec);
            long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            totalMicros += micros;

            free(myArray);

        }

        long averageMicros = totalMicros / num_tests;
        printf("Average execution time for %d keys: %ld microseconds\n", sizes[j], averageMicros);
    }*/

//Q2


/*
    //Q2

    printf("Question2.8\n");
    printf("AjoutsIteratifs arbre last\n");



    for (int j = 0; j < num_sizes; j++) {
        long totalMicros = 0;

        for (int i = 0; i < num_tests; i++) {
            sprintf(file_path, file_pattern, i + 1, sizes[j]);
            printf("Processing file: %s\n", file_path);

            int size;
            Key128* myArray = processFile(file_path, &size);

            HPArb* tr1;
            initTasAB (&tr1);

            struct timeval start, end;
            gettimeofday(&start, NULL);
            //

            ajoutsIteratifs(&tr1,myArray,size);
            gettimeofday(&end, NULL);

            long seconds = (end.tv_sec - start.tv_sec);
            long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            totalMicros += micros;

            free(myArray);


        }

        long averageMicros = totalMicros / num_tests;
        printf("Average execution time for %d keys: %ld microseconds\n", sizes[j], averageMicros);
    }
*/
/*
    printf("Question2.8 last\n");
    printf("con arbre\n");



    for (int j = 0; j < num_sizes; j++) {
        long totalMicros = 0;

        for (int i = 0; i < num_tests; i++) {
            sprintf(file_path, file_pattern, i + 1, sizes[j]);
            printf("Processing file: %s\n", file_path);

            int size;
            Key128* myArray = processFile(file_path, &size);

            HPArb* tr1;
            initTasAB (&tr1);

            struct timeval start, end;
            gettimeofday(&start, NULL);
            //

            construction1(&tr1,myArray,size);
            gettimeofday(&end, NULL);

            long seconds = (end.tv_sec - start.tv_sec);
            long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            totalMicros += micros;

            free(myArray);
            freeTree(tr1);

        }

        long averageMicros = totalMicros / num_tests;
        printf("Average execution time for %d keys: %ld microseconds\n", sizes[j], averageMicros);
    }*/

/*    printf("Union Tests tableau\n");
    const char* file_pattern1 = "../decode/jeu_1_nb_cles_%d.txt";
    const char* file_pattern2 = "../decode/jeu_%d_nb_cles_%d.txt"; // 其他四个文件
    const int num_tests = 5; // 测试次数
    const int sizes[] = {1000, 5000, 10000, 20000, 50000, 80000, 120000, 200000};
    const int num_sizes = 8;

    for (int j = 0; j < num_sizes; j++) {
        long totalMicros = 0;

        for (int i = 1; i < num_tests; i++) {
            char file_path1[1024], file_path2[1024];
            sprintf(file_path1, file_pattern1, sizes[j]);
            sprintf(file_path2, file_pattern2, i + 1, sizes[j]); // 避免重复使用 jeu_1 文件

            int size1, size2;
            Key128* keys1 = processFile(file_path1, &size1);
            Key128* keys2 = processFile(file_path2, &size2);

            HP *m1, *m2;
            Construction(&m1,keys1, size1);
            Construction(&m2,keys2, size2);

            struct timeval start, end;
            gettimeofday(&start, NULL);

            // Union 操作
            HP *result = Union(m1, m2);

            gettimeofday(&end, NULL);

            long seconds = (end.tv_sec - start.tv_sec);
            long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            totalMicros += micros;

            printf("Processing file: %s...%ld microseconds\n", file_path2, micros);

            free(keys1);
            free(keys2);
            HeapDestroy(m1);
            HeapDestroy(m2);
            HeapDestroy(result);
        }

        long averageMicros = totalMicros / 4;
        printf("Average execution time for %d keys: %ld microseconds\n", sizes[j], averageMicros);
    }*/
    printf("Union Tests arbre\n");
    const char* file_pattern1 = "../decode/jeu_1_nb_cles_%d.txt";
    const char* file_pattern2 = "../decode/jeu_%d_nb_cles_%d.txt"; // 其他四个文件
    const int num_tests1 = 5; // 测试次数
    const int sizes1[] = {1000, 5000, 10000, 20000, 50000, 80000, 120000, 200000};
    const int num_sizes1 = 8;

    for (int j = 0; j < num_sizes1; j++) {
        long totalMicros = 0;

        for (int i = 1; i < num_tests1; i++) {
            char file_path1[1024], file_path2[1024];
            sprintf(file_path1, file_pattern1, sizes1[j]);
            sprintf(file_path2, file_pattern2, i + 1, sizes1[j]); // 避免重复使用 jeu_1 文件

            int size1, size2;
            Key128* keys1 = processFile(file_path1, &size1);
            Key128* keys2 = processFile(file_path2, &size2);


            HPArb* tr1,*tr2;
            initTasAB (&tr1);
            initTasAB (&tr2);
            construction1(&tr1,keys1,size1);
            construction1(&tr2,keys2,size2);


            struct timeval start, end;
            gettimeofday(&start, NULL);

            // Union 操作
            HPArb* result= UnionA(tr1,tr2);

            gettimeofday(&end, NULL);

            long seconds = (end.tv_sec - start.tv_sec);
            long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            totalMicros += micros;

            printf("Processing file: %s...%ld microseconds\n", file_path2, micros);

            free(keys1);
            free(keys2);

            freeTree(tr1);
            freeTree(tr2);
            freeTree(result);

        }

        long averageMicros = totalMicros / 4;
        printf("Average execution time for %d keys: %ld microseconds\n", sizes1[j], averageMicros);
    }


    return 0;
}
