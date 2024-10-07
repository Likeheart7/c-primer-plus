#include <stdio.h>
#include <string.h>
#include <float.h>

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
    char firstname[10];
    char lastname[10];
    printf("输入你的名：");
    // 对于数组不需要使用&
    scanf("%s", firstname);
    printf("输入你的姓：");
    scanf("%s", lastname);
    printf("%s,%s\n\n", firstname, lastname);

}

void exer2(void) {
    char name[20];
    printf("请输入你的名字：");
    scanf("%s", name);
    printf("\"%s\"\n", name);
    printf("\"%20s\"\n", name);
    printf("\"%-20s\"\n", name);
    // 第一个参数是替换*的，表示宽度
    printf("\"%*s\"", strlen(name) +3, name);

}

void exer3(void) {
    double number;
    printf("输入一个小数：");
    scanf("%lf", &number);
    printf("The input is %.1f or %.1e.\n", number, number);
    printf("The input is %+.3f or %.3e.\n", number,number);

}

void exer4(void) {
    char name[20];
    float height;
    printf("输入身高和姓名，格式为：身高 姓名: ");
    scanf("%f %s", &height, name);
    printf("%s, you are %.3f feet tall.", name, height);

}

void exer5(void) {
    float download_speed;
    float file_size;
    printf("请输入下载速度(单位Mb/s)：");
    scanf("%f", &download_speed);
    printf("请输入文件大小(单位：MB)：");
    scanf("%f", &file_size);

    printf("At %.2f megabits per seconds, a file of %.2f megabytes downloads in %.2f seconds", 
            download_speed, file_size, file_size * 8 / download_speed);
}

void exer6(void) {
    char firstname[20], lastname[20];
    printf("请输入名：");
    scanf("%s", firstname);
    printf("请输入姓：");
    scanf("%s", lastname);

    printf("%s %s\n", firstname, lastname);
    printf("%*d %*d", strlen(firstname), strlen(firstname), strlen(lastname), strlen(lastname));

}

void exer7(void) {
    double num1 = 1.0/3.0;
    float num2 = 1.0/3.0;

    printf("%f %lf\n", FLT_DIG, DBL_DIG);
    printf("%.6f %.6f\n", num1, num2);
    printf("%.12f %.12f\n", num1, num2);
    printf("%.16f %.16f\n", num1, num2);

}

void exer8(void) {
    const float litre = 3.785;
    const float kilometer = 1.609;
    float total_miles, total_oil;
    printf("输入里程数(英里)：");
    scanf("%f", &total_miles);
    printf("输入油耗(加仑)：");
    scanf("%f", &total_oil);

    //英里/加仑
    printf("%.1f 英里/加仑\n", total_miles/total_oil);
    // 升/100公里
    printf("%.1f 升/百公里", (total_oil * litre) / (total_miles * kilometer / 100));
}