#include <stdio.h>
#include <string.h>

#define DESITY 62.4 // 人体密度 磅/立方英尺
int main(void) {
     float weight, volume;
    int size, letters;
    char name[40]; // 字符数组

    printf("Hi! What's your first name?\n");
    scanf("%s", name);
    printf("%s, what's your weight in kilogram?\n");
    scanf("%f", &weight);
    size = sizeof(name);    // 获取数组的大小，40个char，共40 bytes
    letters = strlen(name); // 获取字符串数组中实际存储的字符的数量，遇到\0就停止
    volume = weight/DESITY;
    printf("Well, %s, your volume is %2.2f cubic feet.\n", name, volume);
    printf("Also, your firstname has %d letters,\n", letters);
    printf("and we have %d bytes to store it.\n", size);

    return 0;
}