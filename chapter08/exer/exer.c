#include <stdio.h>
#include <ctype.h>

void exer1(void);
void exer2(void);
void exer3(void);
void exer4(void);
void exer5(void);
void exer6(void);
void exer7(void);
void exer8(void);
char charget_input(void);
float get_input_int(void);

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

// 这种方式，一个汉字会被记为3个字符
void exer1(void) {
    const char path[20] = "../io.c";
    FILE* fp  = fopen(path, "r");
    int count = 0;
    if (fp == NULL) printf("File open failed.");
    while (getc(fp) != EOF) count ++;
    printf("共计有%d个字符", count);
}

// 可以通过 exer.exe < ../../io.c 测试
void exer2(void) {
    char ch;
    // 用于显示控制字符
    char ascii[33][5] = {"NUL" ,"SOH","STX","ETX","EOT","ENQ","ACK","BEL","BS","HT","LF","VT","FF",
    "CR","SO","SI","DLE","DC1","DC2","DC3","DC4","NAK","SYN","ETB","CAN","EM","SUB","ESC","FS","GS","RS","US", "space"};
    while ((ch=getchar()) != EOF) {
        if (ch < 33) {
            printf("%5s -- %3d\n", ascii[ch-1], ch);
        }else {
            printf("%5c -- %d\n", ch, ch);
        }
    }
}

// 统计文件字母个数，通过重定向使用
void exer3(void) {
    char ch;
    int count = 0;
    while ((ch = getchar()) != EOF){
        if (isalpha(ch)) count ++;
    }
    printf("%d", count);
}

void exer4(void) {
    int word_count = 0;
    int char_count = 0;
    char ch;
    int cur_char_count = 0;
    while ((ch = getchar()) != EOF) {
        if (isalpha(ch)) {
            printf("%c", ch);
             cur_char_count ++;
        } else {            
            if (cur_char_count != 0){
                char_count += cur_char_count;
                word_count ++;
                cur_char_count = 0;
                printf("\n");
            }
        }
    }
    printf("%d %d\n", word_count, char_count);
    printf("The average number of letters in a word is:%.2lf", char_count / (word_count * 1.0));
}

void exer5(void) {
    printf("Choose a number, between 1 and 100.\n");
    printf("Respond with a y if my guess is right, with b if it is bigger and with s if it is small!\n");
    int pre = 0, cur = 100;
    int guess;
    int flag = 0;
    char result;
    while (1) {
        guess = (pre + cur) / 2;
        printf("I guess it is %d, is it right?\n", guess);
        result = charget_input();
        switch (result)
        {
        case 'y':
            printf("game over. I get the right number!");
            flag = 1;
            break;
        case 'b':
            cur = guess;
            printf("fine.\n");
            break;
        case 's':
            pre = guess;
            printf("fine.\n");
            break;
        
        default:
            printf("Please enter y or n.\n");
            break;
        }   
        if (flag) break;
    }
}

char charget_input(void) {
    char ch;
    while (ch = getchar()) {
        if (isalpha(ch)) {
            // 清空缓冲区多余字符
            while (getchar() != '\n') continue;
            return ch;
        }
    }
}
void exer6(void) {
    int ch;

     while (ch = getchar()) {
        // 有效字符
        if (isalpha(ch) || isdigit(ch)) {
            // 清空缓冲区
            while (getchar() != '\n');
            break;
        }
     }

    printf("%c", ch);
}

void exer7(void) {
    while (1) {
        char input = 0;
        int hour_count = 0;
        double saraly_per_hour = 0;
        double salary = 0.0;
        double tax = 0.0;
        printf("************************************************************\n");
        printf("Enter the number corresponding to the desired pay rate or action:\n");
        printf("a) $8.75/hr                             b)$9.33/hr\n");
        printf("c) $10.00/hr                            d)$11.20/hr\n");
        printf("q) quit\n");
        printf("************************************************************\n");
        printf("Choose your salary per hour: ");
        input = charget_input();
        if (input == 'q') {
            break;
        }
        if (input > 100 || input < 97) {
            printf("Please enter a right character(between a and d)\n");
            continue;
        }
        printf("Enter hours:  ");
        scanf("%d", &hour_count);
        switch (input)
        {
        case 'a':
            saraly_per_hour = 8.75;
            break;
        case 'b':
            saraly_per_hour = 8.75;
            break;
        case 'c':
            saraly_per_hour = 8.75;
            break;
        case 'd':
            saraly_per_hour = 8.75;
            break;
        }
        if (hour_count <= 40) {
            salary = 40 * 10.0;
        } else {
            salary = 40 * 10 + (hour_count - 40) * 1.5 * 10;
        }
        if (salary <= 300) tax += salary * 0.15;
        else if (salary > 300 && salary <= 450) tax += 300 * 0.15 + (salary - 300) * 0.2;
        else tax += 300 * 0.15 + 150 * 0.2 + (salary - 450) * 0.25;
        printf("工资总额：%.2lf，税金：%.2lf，净收入：%.2lf\n", salary, tax, salary-tax);
        printf("\n");
    }
}



void exer8(void) {
    float num_1 = 0, num_2 = 0;
    char operation;
    while (1) {
        printf("************************************************************\n");
        printf("Enter the operation of your choice:\n");
        printf("a) add                                s) substract\n");
        printf("m) multiply                           d)divide\n");
        printf("q) quit\n");
        printf("************************************************************\n");
        printf("Choose your operation(a、s、m、d or q): ");
        operation = charget_input();
        // 如果是q，结束程序
        if (operation == 'q') break;
        printf("Enter the first number:");
        num_1 = get_input_int();
        printf("Enter the second number:");
        num_2 = get_input_int();
        switch (operation)
        {
        case 'a':
            printf("%.2f + %.2f = %.2f\n", num_1, num_2, num_1 + num_2);
            break;
        case 's':
            printf("%.2f - %.2f = %.2f\n", num_1, num_2, num_1 - num_2);
            break;
        case 'm':
            printf("%.2f * %.2f = %.2f\n", num_1, num_2, num_1 * num_2);
            break;
        case 'd':
            if (num_2 == 0) {
                printf("You can't divide by 0!");
                continue;
            }
            printf("%.2f / %.2f = %.2f\n", num_1, num_2, num_1 / num_2);
            break;
        
        default:
            break;
        }
    }
}

float get_input_int(void) {
    float value;
    while (scanf("%f", &value) != 1) {
        // 如果读取失败，通过getchar清除前置字符
    }
    return value;
}