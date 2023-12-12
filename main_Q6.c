//
// Created by lmx on 2023/12/12.
//
#include "echauffement/echauffement.h"
#include "arbreBR/arbreBR.h"
#include "hachage/md5.h"

int main() {

    printf("-----------Q6.1-----------\n");

    printf("--Q6.1,ABR--\n");
    ABR *tree = NULL;
    const char* filename1 = "../decodeMd5/1henryiv.txt";
    int size1;
    Key128* myArray1 = processFile1(filename1, &size1);

// 插入数据
    Key128 * array=malloc(sizeof(Key128));
    int size=0;
    for (int i = 0; i < size1; i++) {
        if(!estDans(tree,myArray1[i])){
            tree = InsertNode(tree, myArray1[i]);
            array= resizeArray(array, size + 1);
            array[size]=myArray1[i];
            size++;
        }
       // printf("Key1: part1:%x + part2:%x + part3:%x + part4:%x\n", myArray1[i].part1, myArray1[i].part2, myArray1[i].part3, myArray1[i].part4);
    }

   // PrintTree(tree);
    printf("%d",size);
    for(int j=0;j<size;j++){
        printf("Key1: part1:%x + part2:%x + part3:%x + part4:%x\n", array[j].part1, array[j].part2, array[j].part3, array[j].part4);
    }
    free(myArray1);

    return 0;
}
