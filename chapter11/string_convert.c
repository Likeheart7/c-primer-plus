#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str = "20";
    int i = atoi(str);
    printf("%d\n", i);
    char s[10];
    itoa(i, s, 10);
    puts(s);
}