#include <stdio.h>
#include <string.h>

// 预处理器会在编译前将所有的NAME替换成对应的值
#define NAME "chenx"

int main(void) {
    int size, length;
    size = sizeof(NAME);
    length = strlen(NAME);
    /*
    sizeof 的计算结果是：6
    strlen 的计算结果是：5
    */
   // sizeof会计算'\0'，而strlen不会
   // C99和C11标准专门为sizeof运算符的返回类型添加了%zd转换说明，这对于strlen()同样适用
    printf("sizeof 的计算结果是：%zd\n", size);
    printf("strlen 的计算结果是：%zd", length);
}