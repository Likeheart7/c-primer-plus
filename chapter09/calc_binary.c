#include <stdio.h>

// 前置定义充当函数原型和函数定义
void to_binary(int origin) {
    // 利用递归计算二进制
    // 递归适合处理倒序问题
    int r;
    r = origin % 2;
    if (origin >= 2) to_binary(origin / 2);
    putchar(r == 0 ? '0' : '1');
    // printf("%d", r);
}

int main(void) {
    int origin = 0;
    printf("Enter a number:");
    scanf("%d", &origin);
    to_binary(origin);
}