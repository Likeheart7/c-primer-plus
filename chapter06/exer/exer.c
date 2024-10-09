#include <stdio.h>
#include <math.h>
#include <string.h>

void exer1(void);
void exer2(void);
void exer3(void);
void exer4(void);
void exer5(void);
void exer6(void);
void exer7(void);
void exer8(void);
void exer9(void);
void exer10(void);
void exer11(void);
void exer12(void);
void exer13(void);
void exer14(void);
void exer15(void);
void exer16(void);
void exer17(void);
void exer18(void);

double calc(double x, double y);

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
    // exer11();
    // exer12();
    // exer13();
    // exer14();
    // exer15();
    // exer16();
    // exer17();
    exer18();
}
void exer1(void) {
    char characters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i','j','k','l','m','n','o','p', 'q', 'r', 's','t','u','v','w','x','y','z'};
    for (int i=0;i<sizeof(characters)/sizeof(characters[0]); i++) {
        printf("%c", characters[i]);
    }
}

void exer2(void) {
    for(int i = 1; i < 6; i ++) {
        for (int j = i; j > 0; j--) {
            printf("$");
        }
        printf("\n");
    }
    printf("\n");
}

void exer3(void) {
    const int base = 70;
    for (int i = 0; i<6; i++) {
        for(int j = 0; j <= i; j++) {
            printf("%c", base - j);
        }
        printf("\n");
    }
    printf("\n");
}

void exer4(void) {
    int base = 65;
    for (int i = 1; i<7; i++) {
        for (int j = 0; j < i; j++) {
            printf("%c", base++);
        }
        printf("\n");
    }
    printf("\n");
}

void exer5(void) {
    const int base = 65;
    char flag;
    printf("输入一个大写英文字母：");
    scanf("%c", &flag);
    int length = (flag - base) * 2 + 1;
    int diff = flag - base;
    for (int i = 0; i < diff+1; i++) {
        for (int x = 0; x < diff-i; x ++) {
            printf(" ");
        }
        for (int y = 0; y <= i; y++) {
            printf("%c", base + y);
        }
        for(int z = 1; z <= i; z++) {
            printf("%c", base + i - z);
        }
        printf("\n");
    }
    printf("\n");
}

void exer6(void) {
    int start=0, end = 0;
    printf("输入上限：");
    scanf("%d", &start);
    printf("输入下限：");
    scanf("%d", &end);
    printf("%10s %10s %10s", "num", "square", "cube");
    printf("\n");
    for (int i = start; i <= end; i++) {
        printf("%10d %10d %10d", i, i*i, i*i*i);
        printf("\n");
    }
    printf("\n");

}

void exer7(void) {
    char str[200];
    printf("输入字符串：");
    scanf("%s", str);
    for (int i = strlen(str); i > 0; i--) {
        printf("%c ", str[i - 1]);
    }
    printf("\n");

}

void exer8(void) {
    double x, y;
    while (1) {
        printf("输入两个浮点数：");
        if (scanf("%lf", &x) ==0 || scanf("%lf", &y)==0) {
            break;
        }
        printf("%.2lf\n", (y-x)/(y*x));
    }
}

void exer9(void) {
    double x, y;
    while (1) {
        printf("输入两个浮点数：");
        if (scanf("%lf", &x) ==0 || scanf("%lf", &y)==0) {
            break;
        }
        printf("%.2lf\n", calc(x, y));
    }
}

double calc(double x, double y) {
    return  (y-x)/(y*x);
}

void exer10(void) {
    int start, end;
    while (1) {
        printf("Enter lower and upper integer limits:");
        scanf("%d %d", &start, &end);
        if (start >= end) break;
        int sum = 0;
        for (int i = start; i<=end; i++) {
            sum += i*i;
        }
        printf("The sums of the squares from %d to %d is %d\n", start*start, end *end, sum);
    }
}

void exer11(void) {
    int numbers[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    for (int i =sizeof(numbers)/sizeof(numbers[0]); i>0; i--) {
        printf("%d", numbers[i-1]);
    }
}

void exer12(void) {
    int count = 0;
    printf("输入次数：");
    scanf("%d", &count);
    double sum1, sum2;
    for (int i = 1; i<=count; i++) {
        sum1 += 1.0/i;
        sum2 += pow(-1, i-1) / i;
    }
    printf("%.2lf\n", sum1);
    printf("%.2lf\n", sum2);
}

void exer13(void) {
    int numbers[8];
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        numbers[i] = pow(2, i);
    }
    int cnt = 0;
    do{
        printf("%d\n", numbers[cnt]);
    } while (++cnt < 8);

}
void exer14(void) {
    double inputs[8];
    double sums[8];
    for (int i = 0; i < 8; i++) {
        printf("请输入第%d个值:", i);
        scanf("%lf", &inputs[i]);
    }
    printf("输入完成\n");
    for(int i = 0; i < 8; i++) {
        if (i == 0) {
            sums[i] = inputs[i];
        } else {
            sums[i] = sums[i - 1] + inputs[i];
        }
    }
    for(int i = 0; i < 8; i++) {
        printf("%10.2lf", inputs[i]);
    }
    printf("\n");
    for(int i = 0; i < 8; i++) {
        printf("%10.2lf", sums[i]);
    }
}

void exer15(void) {
    char inputs[255];
    /*
    基于%s转换的实现
    scanf("%s", inputs);
    for(int i = strlen(inputs); i > 0; i--) {
        printf("%c\n", inputs[i-1]);
    }
    */
   // 基于%c的实现
    int cnt = 0;
    while (1) {
        char curChar;
        scanf("%c", &curChar);
        if (curChar == '\n') break;
        inputs[cnt ++] = curChar;
    }
    for(int i = strlen(inputs); i > 0; i--) {
        printf("%c\n", inputs[i-1]);
    }
}

void exer16(void) {
    double baseMoney = 100;
    double daphneMoney = 100, deirdreMoney = 100;
    int years = 0;
    while (daphneMoney >= deirdreMoney) {
        daphneMoney += 10;
        deirdreMoney += deirdreMoney * 0.05;
        years ++;
    }
    printf("Daphne's money is: %.2lf, Deirdre's money is: %.2lf, %d years.", daphneMoney, deirdreMoney, years);
}

void exer17(void) {
    const double rate = 0.08;
    double money = 1000000;
    int years = 0;
    while (1) {
        money += money * rate;
        money -= 100000;
        years ++;
        printf("%lf\n", money);
        if (money <= 0) break;
    }
    printf("After %d years, Chuckie take all money.", years);
}

void exer18(void) {
    const int DUNBAR_NUMBER = 150;
    int friend_count = 5;
    int week_count = 0;
    while (friend_count < DUNBAR_NUMBER) {
        friend_count = (friend_count - week_count - 1) * 2;
        week_count ++;
    }
    printf("一共经过了%d周", week_count);
}

