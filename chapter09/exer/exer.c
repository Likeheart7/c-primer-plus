#include <stdio.h>
#include <ctype.h>

double min(double x, double y) {
    return x > y ? y : x;
}

void exer1(void) {
    printf("%.2lf", min(2.0, 2.1));
}

void chline(char ch, int i, int j) {
    for (int x = 0; x < j; x++) {
        for (int y = 0; y < i; y ++) {
            putchar(ch);
        }
        putchar('\n');
    }
}
void exer2(void) {
    chline('#', 3, 4);
}

void chprint(char ch, int col, int line) {
    for (int x = 0; x < line; x++) {
        for (int y = 0; y < col; y++) {
            putchar(ch);
        }
        putchar('\n');
    }
}
void exer3(void) {
    chprint('@', 10, 4);
}

double harmonic_mean(double x, double y) {
    //求两个数的倒数
    double x_rev = 1/ x;
    double y_rev = 1/y;
    // 求倒数平均值
    double rev_mean = (x_rev + y_rev) / 2;
    // 平均值的倒数就是调和平均数
    double result = 1 / rev_mean;
    return result;
}

void exer4(void) {
    double x = 3, y = 4;
    printf("%.3lf 和 %.3lf的调和平均数是%.3lf", x, y, harmonic_mean(3, 4));
}

void large_of(double* x, double * y) {
    if (*x > *y) {
        *y = *x;
    } else {
        *x = *y;
    }
    printf("结果为：x=%.3lf, y=%.3lf", *x, *y);
}

void exer5(void) {
    double x = 3.2;
    double y = 32.2;
    large_of(&x, &y);
}

void reorder(double *x, double *y, double *z) {
    double min = *x > *y ? (*y > *z ? *z : *y ) 
                         : ( *x > *z ? *z : * x);
    double max = *x > *y ? (*x > *z ? *x : *z)
                         : (*y > *z ? *y : *z);
    double mid = (*x == min || *x == max) ? (*y == min || *y ==max ? *z : *y) : *x;
    *x = min;
    *y = mid;
    *z = max;
    printf("Result is: %.2lf, %.2lf, %.2lf", *x, *y, *z);
}

void exer6(void) {
    double x = 100, y=270, z=30;
    reorder(&x, &y, &z);
}

int alpha(char ch) {
    if (isalpha(ch)) {
        return ch >= 97 ? ch - 96 : ch - 64;
    }
    return -1;
}

void exer7(void) {
    char ch;
    int index;
    while((ch = getchar()) != EOF) {
        index = alpha(ch);
        if (index != -1) printf("%c's index is %d\n", ch, index);
    }
}

double power(double base, double idx) {
    if (base == 0) {
        if (idx == 0) {
            printf("0的0次幂未定义，做1处理\n");
            return 1;
        }
        return 0;
    }
    if (idx == 0) return 1;
    if (idx == 1) return base;
    double result = idx > 0 ? base : 1/base;
    if (idx > 0) {
        for (int i = 1; i < idx; i++) {
            result *= base;
        }
    } else {
        for (int i = 1; i < -idx; i++) {
            result *=  1/base;
        }
    }
    return result;
}

void exer8(void) {
    printf("%.2lf\n", power(2, 10));
    printf("%.2lf\n", power(0, 0));
    printf("%.2lf\n", power(3, 0));
    printf("%.4lf\n", power(2, -3));
}

double power_recursion(double base, double idx) {
    if (base == 0) {
        if (idx == 0) {
            printf("0的0次幂未定义，做1处理\n");
            return 1;
        }
        return 0;
    }
    if (idx == 0) return 1;
    if (idx == 1) return base;
    if (idx == -1) return 1/base;
    double result = idx > 0 ? base : 1/base;
    if (idx > 0) {
        result *= power_recursion(result, idx - 1);
    } else {
        result *= power_recursion(base, idx + 1);
    }
    return result;
}

void exer9(void) {
    printf("%.8lf\n", power_recursion(2,10));
    printf("%.8lf\n", power_recursion(2,-3));
}

void to_scale(int origin, int scale) {
    int r;
    r = origin % scale;
    if (origin >= scale) to_scale(origin/scale, scale);
    printf("%d", r);
}

void to_base_n(int origin, int scale) {
    to_scale(origin, scale);
    printf("\n");
}

void exer10(void) {
    to_base_n(5, 2);
    to_base_n(129, 8);
}

// 计算前n个斐波那契数
int fibonacci(int idx) {
    if (idx == 0) return 0;
    if (idx == 1) return 1;
    int pre = 1;
    int cur = 1;
    int result = 0;
    for (int i = 0; i < idx - 1; i++) {
        result += pre;
        pre = cur;
        cur = result;
    }
    return result;
}
//经典斐波那契
void exer11(void) {
    printf("%d\n", fibonacci(1));
    printf("%d\n", fibonacci(2));
    printf("%d\n", fibonacci(3));
    printf("%d\n", fibonacci(4));
    printf("%d\n", fibonacci(5));
    printf("%d\n", fibonacci(6));
    printf("%d\n", fibonacci(7));
    printf("%d\n", fibonacci(11));
}
int main(void) {
    // exer1();
    // exer2();
    // exer3();
    // exer4();
    // exer5();
    // exer6();
    // exer7();
    // exer8();
    // exer9();
    // exer10();
    exer11();
}