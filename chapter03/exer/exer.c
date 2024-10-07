#include <stdio.h>

void exer1(void);
void exer2(void);
void exer3(void);
void exer4(void);
void exer5(void);
void exer6(void);
void exer7(void);
void exer8(void);

int main(void) {
    // exer1();
    // exer2();
    // exer3();
    // exer4();
    // exer5();
    // exer6();
    // exer7();
    exer8();
}

void exer1(void) {
    long long num = 4300000000L; // 溢出
    printf("%ld\n", num); // 5032704
}

void exer2(void) {
    int input = 0;
    printf("输入一个小于127的数字：");
    scanf("%d", &input);
    printf("该数字对应的字符是: %c\n", (char) input);
}

void exer3(void) {
    printf("\a");
    printf("Startled by the sudden sound, Sally shouted,\n\"By the Great Pumkin, what was that!\"\n");
}

void exer4(void) {
    double num = 64.25;
    printf("fixed-pointed: %f\n", num);
    printf("exponential: %e\n", num);
    printf("p: %.2a\n", num);

}

void exer5(void) {
    int age = 0;
    int seconds = 3.156e7;
    printf("请输入你的年龄：");
    scanf("%d", &age);
    long long total =  age*seconds;
    printf("你大约经历过 %ld 秒\n", total);
}

void exer6(void) {
    /// 错误的，有问题的。
    int quart = 0;
    double quality = 3.0e-23;
    printf("输入水的夸脱数量：");
    scanf("%d", &quart);
    printf("水分子数量约为：%e\n", quart * 950 / quality);
}

void exer7(void) {
    double inch2cm = 2.54;
    int inches = 0;
    printf("输入你的身高，单位英寸: ");
    scanf("%d", &inches);
    printf("转换单位后为：%.2fcm\n", inch2cm * inches);
}

void exer8(void) {
    int cupCount = 0;
    printf("输入总杯数：");
    scanf("%d", &cupCount);
    printf("对应为：\n%.1f品脱\n%d盎司\n%d大汤勺\n%d茶勺", cupCount / 2.0, cupCount * 8, cupCount * 8 * 2, cupCount * 8 * 2 * 3);
}