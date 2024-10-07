#include <stdio.h>

void show(void); // 函数原型

int main(void) {
    printf("this is main function;\n");
    show();
    return 0;
}

// 函数定义
void show(void) {
    printf("i want print the function 'show()';");
}

