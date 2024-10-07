#include <stdio.h>

// 以十进制，十六进制，八进制打印100
int main(void) {
    int number = 100;
    // %#x表示带前缀
    // 十进制：100, 十六进制: 0x64, 八进制: 0144
    printf("十进制：%d, 十六进制: %#x, 八进制: %#o", number, number, number);
    return 0;
}