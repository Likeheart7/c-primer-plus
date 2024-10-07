#include <stdio.h>

int main(void) {
    int inch;
    printf("请输入英寸长度：");
    scanf("%d", &inch);
    printf("%d", inch);
    int cm = inch * 2.54;
    printf("对应的厘米长度为：%d inches = %d cm", inch, cm);
    return 0;
}