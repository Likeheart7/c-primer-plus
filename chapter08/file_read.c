#include <stdio.h>
#include <stdlib.h>

void print_file(FILE* fp);
int main(void) {
    FILE * fp;
    const char path[10] = "./io.txt";
    fp = fopen(path, "r");
    print_file(fp);
}

void print_file(FILE *fp) {
    if (fp == NULL) {
        printf("open file failed.");
        exit(1);
    }
    char ch;
    // 从文件中读取
    // 当输入汉字时，因为汉字是3个字节，所以实际上调试可以看到一个汉字会调用三次putchar，然后控制台才有输出
    while ((ch = getc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

