#include <stdio.h>

void exer1(void);
void exer2(void);
void exer3(void);
void exer4(void);
void exer5(void);
void exer6(void);
void exer7(void);
void exer8(void);
void jolly(void);
void deny(void);
void br(void);
void ic(void);
void one_three(void);
void two(void);
int main(void) {
    exer1();
    exer2();
    exer3();
    exer4();
    exer5();
    exer6();
    exer7();
    exer8();
    return 0;
}

void exer1(void) {
    printf("------exercise 1------\n");
    /*
    like heart
    like
    heart
    like heart
    */
    printf("like heart\n");
    printf("like\nheart\n");
    printf("like ");
    printf("heart\n");
}

void exer2(void) {
    printf("------exercise 2------\n");
    printf("my name is likeheart.\n");
    printf("my address is xiachen community.\n");
}

void exer3(void) {
    printf("------exercise 3------\n");
    int age = 24;
    int dayOfAge = age * 365;
    printf("my age is %d, it is %d days.\n", age, dayOfAge);
}

void exer4(void) {
    printf("------exercise 4------\n");
    jolly();
    deny();
}
void jolly(void) {
    for (int i=0; i<3; i++) {
        printf("For he's a jolly good fellow!\n");
    }
}
void deny(void) {
    printf("Which nobody can deny!\n");
}


void exer5(void) {
    printf("------exercise 5------\n");
    br();
    printf(", ");
    ic();
    printf("\n");
    ic();
    printf("\n");
    br();
    printf("\n");

}
void br(void) {
    printf("Brazil, Russia");
}
void ic(void) {
    printf("India, China");
}

void exer6(void) {
    printf("------exercise 6------\n");
    int toes = 10;
    printf("toes is %d, toes's square is %d, toes's cube is %d.\n", toes, toes*toes, toes*toes*toes);
}

void exer7(void) {
    printf("------exercise 7------\n");
    for (int i = 3; i>0; i--) {
        for (int j=0; j<i; j++){
            printf("Smile!");
        }
        printf("\n");
    }
    printf("\n");
}

void exer8(void) {
    printf("------exercise 8------\n");
    printf("starting now:\n");
    one_three();
    printf("done!");
}
void one_three(void) {
    printf("one\n");
    two();
    printf("three\n");
}
void two(void) {
    printf("two\n");
}