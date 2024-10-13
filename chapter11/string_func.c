#include <stdio.h>
#include <string.h>
#define MSG "message"


/*
puts()：只用于字符串，而且会在末尾补一个换行
*/
void ptr_and_arr(void) {
    char msg[] = MSG;
    char *msg_ptr = MSG;
    /*
    00007FF687145050
    000000EB263FFD90
    00007FF687145050
    */
    printf("%p\n", MSG);
    printf("%p\n", msg);    // 和第一个不同，因为实际上是一份拷贝
    printf("%p\n", msg_ptr); // 和第一个相同
    // 允许，因为修改的是副本的
    msg[0] = 'S';
    puts(msg);
    puts(MSG);
    // msg_ptr[0] = 'S'; // 不允许，并且因为指向字符串本身，如果修改会影响所有字符串
    // puts(msg_ptr);

    // msg = msg_ptr; // 不允许
    msg_ptr = msg; // 允许
    printf("%p\n", msg_ptr); // 和第一个相同
}

void io_func(void) {
    const int SIZE = 100;
    char arr[SIZE];
    // ************ gets()
    /*
    1.只能对字符数组使用，因为字符指针的初始化是一个未知地址
    2. 可能出现溢出问题导致内存错误
    */
    // gets(arr);  

    // ************ fgets()
    // fgets(arr, SIZE, stdin); // 可以指定最大长度。
    // printf("%s", arr);

    // ************ scanf()
    // scanf("%s", arr);   // scanf只会读取第一个单词

    // ************ puts()
    // gets()丢弃输入中的换行符，但是puts()在输出中添加换行符
    // puts(arr); // puts在遇到第一个空字符时结束，并添加一个换行符打印
    // 如果没有换行符,会一直打印后续内存直到遇到换行符
    // char arr2[] = {'d', 'o', 'n','t','!'};
    // puts(arr2);
    
    // ************ fputs() 针对文件的函数
    // fgets()保留输入中的换行符，fputs()不在输出中添加换行符
    char line[81];
    while(fgets(line, 81, stdin))
        fputs(line, stdout);

}

void string_func(void) {
    // **** strlen()统计字符串长度
    char *ptr = "hello, I'm the one.";
    printf("%d\n", strlen(ptr));
    // ****** strcat()合并字符串
    char str[80] = "dont look back in anger.";
    printf("%s\n", strcat(str, ptr));
    printf("%p\n%p\n", str, strcat(str, ptr)); // 地址一致，说明是合并到第一个字符数组中，可能溢出。
    // ****** strcmp() 比较字符串内容是否相同,两个字符串参数相同，该函数就返回0，否则返回非零值
    char * string = "dont look back in anger.";
    printf("%p\n%p\n", str, string); // 地址不同
    printf("string equals str: %s\n", strcmp(string, str) == 0 ? "true" : "false");
    printf("%d\n", strcmp(string, ptr)); // 不相同的情况，字符之间差值为正返回1或差值，为负返回-1或差值
    // ****** strcpy() & strncpy()
    // strcpy()可能溢出
    char str_cpy[80];
    strcpy(str_cpy, str);
    puts(str_cpy);
    char strn_cpy[30];
    strncpy(strn_cpy, str, 30); // strn_cpy拷贝指定数目
    puts(strn_cpy);
    // ******  sprintf() 写入数据
    char arr[10];
    sprintf(arr, "%s, %d, %.2lf", "hi", 10, 2.33);
    puts(arr); // hi, 10, 2.33

}

int main(void) {
//    ptr_and_arr();
    // io_func();
    string_func();
}