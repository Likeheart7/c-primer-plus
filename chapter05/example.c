#include <stdio.h>

typedef size_t int32; // 定义类型别名
int main(void) {
    int num = 20;
    // C语言规定，sizeof返回size_t类型的值
    printf("%zd\n", sizeof num); // 4

    size_t digit = 29;
    printf("%zd", sizeof(digit)); // 8
}