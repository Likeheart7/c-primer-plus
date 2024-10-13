#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void get_char(int n, char arr[]) {
    for(int i=0; i<n; i++) {
        arr[i] = getchar();
    }
}

void print_arr(char arr[]) {
    while (*arr != '\0') {
        printf("%c", *arr++);
    }
}

void exer1(void) {
    char arr[20];
    get_char(10, arr);
    print_arr(arr);
}

void get_char2(int n, char arr[]) {
    char ch;
    for(int i=0; i<n; i++) {
        ch =  getchar();
        if (ch == '\t' || ch == '\n' || ch == ' ') {
            arr[i] = '\0';
            break;
        }   
        arr[i] = ch;
    }
}

void exer2(void) {
    char arr[20];
    get_char2(10, arr);
    print_arr(arr);
}

void exer3(void) {
    char str[20];
    // scanf会跳过前面的空格并在单词后的空格停止
    scanf("%s", str);
    puts(str);
} 

void exer4(void) {
    char str[20];
    scanf("%3s", &str);
    puts(str);
} 

void exer5(void) {
    char arr[] = "hello";
    char *ptr = strchr(arr, 'o');
    printf("%p %c", ptr, *ptr);
}

int is_within(char ch, char *ptr) {
    char *res = strchr(ptr, ch);
    return res == NULL ? 0 : 1;
}
void exer6(void) {
    char ch = 'a';
    char *ptr = "this is my name";
    printf("%d", is_within(ch, ptr));
}

// 没意义
void exer7(void) {

}

char* string_in(char* ptr1, char* ptr2) {
    // strstr()字符串包含判断，包含返回指针，不包含返回NULL
    return strstr(ptr1, ptr2);
}
void exer8(void) {
    char *ptr1 = "hello";
    char *ptr2 = "lo";
    char* res = string_in(ptr1, ptr2);
    puts(res);
    printf("%p\n%p", &ptr1[3], res); // 地址一样
}

void reverse_str(char* str) {
    int length = strlen(str);
    int i = 0;
    char temp;
    while (i < (length/2)) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
        i++;
    }
}
void exer9(void) {
    char str[] = "hello";
    reverse_str(str);
    puts(str);
}

void replace_blank(char *str) {
    char *p = str;
    int i = 0;
    while (*p != '\0') {
        if (*p != ' ') {
            str[i++] = *p;
        }
        p++;    
    }
    str[i] = '\0'; // 补充字符串结尾
}

void exer10(void) {
    char str[] = "dont look back in anger.";
    replace_blank(str);
    puts(str);
    // printf("%c", str[strlen(str) + 2]); // 这种方式实际上后续的字符还是存在的，只是覆盖了前置下标值是“ ” 的部分
}

void print_td_arr(char arr[][20], int size) {
    for (int i=0; i<size; i++) {
        puts(arr[i]);
    }
}


void print_td_arr_ascii(char arr[][20], int size) {
    for (int i=0; i<size-1; i++) {
        for (int j=0; j<size-i-1; j++) {
            if (strcmp(arr[j], arr[j+1]) > 0) {
                char temp[20];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
    }
    print_td_arr(arr, size);
}

void print_td_arr_length(char arr[][20], int size) {
    for (int i=0; i<size-1; i++) {
        for (int j=0; j<size-i-1; j++) {
            if (strlen(arr[j])>strlen(arr[j+1])) {
                char temp[20];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
    }
    print_td_arr(arr, size);
}
void print_td_arr_limit(char arr[][20], int size) {
    printf("===> %s", arr[0]);
    int limit = strlen(arr[0]);
    printf("===> %d", limit);
    for (int i=0; i<size; i++) {
        printf("%.*s\n", limit, arr[i]);
    }
}

void exer11(void) {
    int n = 10, m=20;
    char str[n][m]; // 存储十个字符串;
    puts("请输入十个字符串");
    
    for (int i=0; i<n; i++){
        char temp[20];
        gets(temp);
        strcpy(str[i], temp);
    }

    // printf("%d", strlen(str[0]));
    // 菜单
    while (1) {
        int choice = 0;
        puts("*****************************************");
        puts("1.打印源字符串列表   2.以ASCII顺序打印");
        puts("3.按长度递增打印     4.按字符串中第一个单词的长度打印");
        puts("5.退出");
        puts("*****************************************");
        puts("输入你的选择：");
        scanf("%d", &choice);
        if (choice == 5) {
            break;
        }
        switch (choice)
        {
        case 1:
            print_td_arr(str, n);
            break;
        case 2:
            print_td_arr_ascii(str, n);
            break;
        case 3:
            print_td_arr_length(str, n);
            break;
        case 4:
            print_td_arr_limit(str,n);
            break;
        default:
        puts("请输入正确的选项(1-5)");
            break;
        }
    }
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
    // exer11(); // 实现会修改原数组
    // 下列未完成
    // exer12();
    // exer13();
    // exer14();
    // exer15();
    // exer16();
}