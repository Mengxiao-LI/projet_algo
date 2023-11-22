#include <stdio.h>
#include "echauffement/echauffement.h"

int main() {
    printf("Question1\n");
    // 示例字符串
    const char* hexStr1 = "0x938a808e2fc71db5fc3639947b95c6d3";
    const char* hexStr2 = "0xda2dbd534a39796e0fd5f8945be61d5b";

    // 转换
    Key128 key1 = hexTokey128(hexStr1);
    Key128 key2 = hexTokey128(hexStr2);

    // 打印转换结果
    printf("Key1: part1:%x + part2:%x + part3:%x + part4:%x\n", key1.part1, key1.part2, key1.part3, key1.part4);
    printf("Key2: part1:%x + part2:%x + part3:%x + part4:%x\n", key2.part1, key2.part2, key2.part3, key2.part4);

    //测试算法
    if (isLessThan(key1, key2)) {
        printf("Key1 is less than Key2\n");
    }else{
        printf("Key1 is more than Key2\n");
    }

    if (isEqual(key1, key2)) {
        printf("Key1 is equal to Key2\n");
    }else{
        printf("Key1 is not equal to Key2\n");
    }
    return 0;
}
