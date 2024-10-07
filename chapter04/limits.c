#include <stdio.h>
// 定义了各种类型的范围常量
#include <limits.h>
#include <float.h>


int main(void) {
    printf("%d\n", INT_MAX);
    printf("%d\n", INT_MIN);
    printf("%zd\n", UINT_MAX);
    printf("%f\n", FLT_MAX);
    printf("%f\n", FLT_MIN);
}