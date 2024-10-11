#include <stdio.h>

int main(void) {
    int i = 29;
    printf("i的地址: %p\n", &i);
    int * addr = &i;
    printf("i的地址: %p\n", addr);
    printf("i的地址的指针的地址: %p\n", &addr);
    printf("指向i的指针指向的值: %d\n", *addr);
}