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

double calc_price(double record[]);
double calc_express_price(double weight);
double calc_discount(double price);

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
    exer11();
}
void exer1(void) {
    int space_count = 0;
    int enter_count = 0;
    int other_count = 0;
    char curChar;
    while(1) {
        scanf("%c", &curChar);
        if (curChar == '#')
            break;
        else if (curChar == '\n') {
            enter_count ++;
        }
        else if (curChar == 32) {
            space_count ++;
        }
        else {
            other_count ++;
        }
    }
    printf("空格有%d个，换行有%d个，其他字符有%d个", space_count, enter_count, other_count);
}

void exer2(void) {
    char chars[255];
    char curChar;
    int cnt = 0;
    while (1) {
        scanf("%c", &curChar);
        if (curChar == '\n') continue;
        if (curChar == '#') break;
        chars[cnt++] = curChar;
    }
    for (int i = 0; i < cnt; i++) {
        if (i != 0 && i % 8 == 0) printf("\n");
        printf("%c-%03d ", chars[i], chars[i]);
    }
}

void exer3(void) {
    int even_count = 0, even_sum = 0, odd_count = 0, odd_sum = 0;
    int input = 0;
    while (1) {
        scanf("%d", &input);
        if (input == 0) break;
        if (input % 2 == 0) {
            even_count ++;
            even_sum += input;
        } else {
            odd_count ++;
            odd_sum += input;
        }
    }
    printf("用户输入偶数%d个，平均值为%.2f\n用户输入的奇数%d个，平均值%.2f", 
            even_count, (even_sum *1.0) / even_count,
            odd_count, (odd_sum * 1.0)/odd_count);
}

void exer4(void) {
    int count = 0;
    char input;
    while (1) {
        scanf("%c", &input);
        if (input == '#') break;
        if (input == '!') count ++;
        else if (input == '.') count ++;
    }
    printf("进行了%d次替换", count);
}

void exer5(void) {
    int count = 0;
    char input;
    while (1) {
        scanf("%c", &input);
        if (input == '#') break;
        switch (input)
        {
            case '!':
                count ++;
                break;
            case '.':
                count ++;
        }
    }
    printf("进行了%d次替换", count);
}

void exer6(void) {
    char preChar, curChar;
    int count = 0;
    while (1) {
        scanf("%c", &curChar);
        if (curChar == '#') break;
        if (preChar == 'e' && curChar == 'i') count ++;
        preChar = curChar;
    }
    printf("ei出现了%d次", count);

}

void exer7(void) {
    int hour_count = 0;
    double salary = 0, tax = 0;
    printf("工作小时数：");
    scanf("%d", &hour_count);
    if (hour_count <= 40) {
        salary = 40 * 10.0;
    } else {
        salary = 40 * 10 + (hour_count - 40) * 1.5 * 10;
    }
    if (salary <= 300) tax += salary * 0.15;
    else if (salary > 300 && salary <= 450) tax += 300 * 0.15 + (salary - 300) * 0.2;
    else tax += 300 * 0.15 + 150 * 0.2 + (salary - 450) * 0.25;
    printf("工资总额：%.2lf，税金：%.2lf，净收入：%.2lf", salary, tax, salary-tax);

}

void exer8(void) {
    while (1) {
        int input = 0;
        int hour_count = 0;
        double saraly_per_hour = 0;
        double salary = 0.0;
        double tax = 0.0;
        printf("************************************************************\n");
        printf("Enter the number corresponding to the desired pay rate or action:\n");
        printf("1) $8.75/hr                             2)$9.33/hr\n");
        printf("3) $10.00/hr                            4)$11.20/hr\n");
        printf("5) quit\n");
        printf("************************************************************\n");
        printf("Choose your salary per hour: ");
        scanf("%d", &input);
        if (input == 5) {
            break;
        }
        if (input < 1 || input > 5) {
            printf("Please enter a right number(between 1 and 5)\n");
            continue;
        }
        printf("Enter hours:  ");
        scanf("%d", &hour_count);
        switch (input)
        {
        case 1:
            saraly_per_hour = 8.75;
            break;
        case 2:
            saraly_per_hour = 8.75;
            break;
        case 3:
            saraly_per_hour = 8.75;
            break;
        case 4:
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

void exer9(void) {
    int input = 0;
    printf("输入一个正整数：");
    scanf("%d", &input);
    printf("小于等于该数的素数有：");
    for(int i = 2; i <= input; i++) {
        // 判断是不是素数，是就输出
        int flag = 1;
        for (int j = 2; j <= sqrt(i); j++) {
            if ((i % j) == 0) {
                // printf("%d %d \n", i, j);
                flag = 0;
                break;
            }
        }
        if (flag) printf("%d ", i);
    }
}

void exer10(void) {
    while (1) {
        const int single_base = 17850;
        const int holder_base = 23900;
        const int married_base = 29750;
        const int divorced_base = 14875;
        int type = 0;
        double income = 0.0;
        double tax = 0.0;
        printf("************************************************************\n");
        printf("Choose your salary per hour: \n");
        printf("1) 单身                                   2) 户主\n");
        printf("3) 已婚, 共有                             4)已婚，离异\n");
        printf("5) quit\n");
        printf("************************************************************\n");
        scanf("%d", &type);
        printf("输入你的收入：");
        scanf("%lf", &income);

        switch (type)
        {
        case 1:
            tax = income <= single_base ? income * 0.15 : single_base * 0.15 + (income - single_base) * 0.28;
            break;
        case 2:
            tax = income <= holder_base ? income * 0.15 : single_base * 0.15 + (income - holder_base) * 0.28;
            break;
        case 3:
            tax = income <= married_base ? income * 0.15 : single_base * 0.15 + (income - married_base) * 0.28;
            break;
        case 4:
            tax = income <= divorced_base ? income * 0.15 : single_base * 0.15 + (income - divorced_base) * 0.28;
            break;
        }

        printf("税金为：%lf\n", tax);

    }
}
void exer11(void) {
    double record[3] = {0,0,0};
    int type = 0;
    double price = 0.0;
    double weight = 0.0;
    double total_weight = 0.0;
    double discount = 0;
    double express_price = 0.0;
    while (1) {
        printf("************************************************************\n");
        printf("Choose the type: \n");
        printf("1) artichoke                                    2) carrot\n");
        printf("3) beet                                         4)calc\n");
        printf("************************************************************\n");
        scanf("%d", &type);
        if (type == 4) break;
        switch (type)
        {
            case 1:
                printf("请输入洋蓟的磅数：");
                scanf("%lf", &weight);
                record[0] += weight;
                break;
            case 2: 
                printf("请输入胡萝卜的磅数：");
                scanf("%lf", &weight);
                record[1] += weight;
                break;
            case 3:
                printf("请输入甜菜的磅数：");
                scanf("%lf", &weight);
                record[2] += weight;
                break;
        }
        total_weight += weight;
    }
    
    price = calc_price(record);
    discount = calc_discount(price);
    express_price = calc_express_price(total_weight);
    printf("洋蓟：%.2lf磅，胡萝卜：%.2lf磅， 甜菜：%.2lf磅\n", record[0], record[1], record[2]);
    printf("总价格：%.2lf\n", price);
    printf("运费：%.2lf\n", express_price);
    printf("折扣：%.2lf\n", discount);
    printf("应付款：%.2lf", price + express_price - discount);
}

double calc_price(double record[]) {
    const double artichoke = 2.05;
    const double carrot = 1.09;
    const double beet = 1.15;
    return record[0] * artichoke + record[1] * carrot + record[2] * beet;
}
double calc_express_price(double weight){
    return weight <= 5 ? 6.5 : 
        weight <= 20 ? 14 : 14 + ceil(weight - 20) * 0.5;
}
double calc_discount(double price) {
    if (price <= 100) return 0;
    return price * 0.05;
}
