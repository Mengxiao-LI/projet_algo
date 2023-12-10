#include <stdio.h>
#include <string.h>
#include <sys/time.h>
//#include <intrin.h>
#include "echauffement/echauffement.h"
#include "tas/list.h"
#include "tas/test.h"



int main()
{
    //int a[] = { 27,37,28,18,19,34,65,25,49,15 };

    //int len = sizeof(a) / sizeof(a[0]);
    //HeapInit(&hp, a, len);
    //HeapPrint(&hp);

    Key128 keys[5];
    const char *hexStrings[] = {
            "0d09ef03 382fa280 d11bcf44 1bc2e4b7",
            "0d09ef03 382fa280 d11bcf44 1bc2e4b8",
            "0d09ef03 382fa280 d11bcf44 1bc2e4b9",
            "0d09ef03 382fa280 d11bcf44 1bc2e4ba",
            "0d09ef03 382fa280 d11bcf44 1bc2e4bb"
    };

    for (int i = 0; i < 5; i++) {
        sscanf(hexStrings[i], "%x %x %x %x", &keys[i].part1, &keys[i].part2, &keys[i].part3, &keys[i].part4);
    }
    int len = sizeof(hexStrings) / sizeof(hexStrings[0]);
    HP hp;

    HeapInit(&hp, hexStrings, len);
    HeapPrint(&hp);
/*
    const char* filename = "../decode/jeu_1_nb_cles_1000.txt";
    int size;
    Key128* myArray = processFile(filename, &size);
    HP hp;

    HeapInit(&hp, myArray, size);

    //hhaa(&hp, myArray, size);
    HeapPrint(&hp);

    *//*HeapPush(&hp, key);
    HeapPrint(&hp);
    HeapPush(&hp, key1);
    HeapPrint(&hp);*//*

    const char* file_pattern = "../decode/jeu_%d_nb_cles_%d.txt";
    const int num_tests = 5; // 1.2.3.4.5
    const int sizes[] = {1000, 5000, 10000, 20000,50000, 80000, 120000, 200000};
    const int num_sizes = 8;
    char file_path[1024];

    printf("Question2.8\n");
    printf("AjoutsIteratifs arbre\n");



    for (int j = 0; j < num_sizes; j++) {
        long totalMicros = 0;

        for (int i = 0; i < num_tests; i++) {
            sprintf(file_path, file_pattern, i + 1, sizes[j]);
            printf("Processing file: %s\n", file_path);

            int size;
            Key128* myArray = processFile(file_path, &size);

            HP hp;



            //HeapPrint(&hp);

            struct timeval start, end;
            gettimeofday(&start, NULL);
            //
            HeapInit(&hp, myArray, size);


            gettimeofday(&end, NULL);
            //
            long seconds = (end.tv_sec - start.tv_sec);
            long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            totalMicros += micros;


        }

        long averageMicros = totalMicros / num_tests;
        printf("Average execution time for %d keys: %ld microseconds\n", sizes[j], averageMicros);
    }

    free(myArray);*/
    return 0;

}
