#include <stdio.h>
#include <math.h>

void exer1(void);
void exer2(void);
void exer3(void);
void exer4(void);
void exer5(void);
void exer6(void);
int cube(int number);
void exer7(void);
void exer8(void);
void exer9(void);
void Temperatures(double temperatrue);

int main(void) {
    // exer1();
    // exer2();
    // exer3();
    // exer4();
    // exer5();
    // exer6();
    // exer7();
    // exer8();
    exer9();
}

void exer1(void) {
    const int rate = 60;
    int minutes = 0;
    printf("输入分钟数：");
    scanf("%d", &minutes);
    printf("%02d时%02d分", minutes/rate, minutes%rate);
    printf("\n");
}

void exer2(void) {
    int input = 0;
    printf("输入一个数字：");
    scanf("%d", &input);
    int i = input;
    while (i <= input + 10) {
        printf("%d ", i ++);
    }
    printf("\n");
}

void exer3(void) {
    const int rate = 7;
    int num_of_day = 0;
    while (1) {
        printf("输入总天数：");
        scanf("%d", &num_of_day);
        if(num_of_day <= 0) break;
        printf("%d周%d天", num_of_day / rate, num_of_day % rate);
        printf("\n");
    }

}

void exer4(void) {
    const double cm2feet = 30.48;
    const double cm2inch = 2.54;
    double height = 0;
    while (1) {
        printf("输入身高：");
        scanf("%lf", &height);
        if (height <= 0) break;
        printf("%.2lf cm = %d feet, %.1lf inches", height, (int) (height/cm2feet), fmod(height, cm2feet)/cm2inch);
        printf("\n");
    }

}

void exer5(void) {
    double sum = 0.0;
    double num = 0.0;
    while (1) {
        printf("输入今日营业额：");
        scanf("%lf", &num);
        if (num <= 0) {
            printf("总营业额：%.2lf", sum);
            break;
        }
        sum += num  ;
    }
    printf("\n");
}

void exer6(void) {
    int num = 0;
    while(1) {
        printf("输入一个数字：");
        scanf("%d", &num);
        if (num == 0) break;
        printf("%d的平方是：%d\n", num, num*num);
    }
    printf("\n");
}

void exer7(void) {
    int number = 0;
    printf("输入一个数字：");
    scanf("%d", &number);
    int result = cube(number);
    printf("%d的立方是：%d", number, result);
    printf("\n");

}
int cube(int number) {
    return number * number * number;
}

void exer8(void) {
    int second_operand = 0;
    int first_operand = 0;
    printf("输入第二个操作数：");
    scanf("%d", &second_operand);
    while (1) {
        printf("输入第一个操作数: ");
        scanf("%d", &first_operand);
        if (first_operand == 0) break;
        printf("%d %% %d is %d\n", first_operand, second_operand, first_operand % second_operand);
    }
    printf("\n");
}

void exer9(void) {
    double temperature = 0;
    while (1) {
        printf("输入华氏温度：");
        int input_count = scanf("%lf", &temperature);
        // printf("读取数量%d\n", input_count);
        if (input_count != 1) break;
        Temperatures(temperature);
    }
}
void Temperatures(double temperature) {
    double stemper = 5.0 / 9.0 * (temperature - 32.0);
    double ktemper = stemper + 273.16;
    printf("摄氏温度为：%lf\n", stemper);
    printf("开氏温度为：%lf\n", ktemper);

}