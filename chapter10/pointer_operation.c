#include <stdio.h>

int main(void) {
    // 针对指针类型的操作
    int arr[] = {1,2,3,4,5,6};
    int *arr_p1 = &arr[0];
    // 指针运算
    // 指针的运算是以类型长度为单位的
    printf("%d\n", *(++arr_p1)); // 2
    int *arr_p2 = &arr[2];
    // 1  指两个指针之间相差一个int
    printf("pointer a substract pointer b: %td\n", arr_p2 - arr_p1); 

    //000000D4571FFB98 - 1 = 000000D4571FFB94, 被减数单位是指针类型大小
    printf("pointer a substract pointer b: %p - %d = %p\n",arr_p2, 1, arr_p2 - 1); 
    int tw_arr[2][2]= {{1,2}, {2,3}};
    // 这两个相等
    printf("tw_arr value is: %p\n", tw_arr);
    printf("tw_arr[0] address value is: %p\n", &tw_arr[0]);
    // 这两个不相等，因为tw_arr指向的对象占两个int，tw_arr[0]指向的实际上是zippo[0][0]的地址，是一个int
    printf("tw_arr value is: %p\n", tw_arr + 1);
    printf("tw_arr[0] address value is: %p\n", (tw_arr[0] + 1));
    
    // tw_arr[0]和tw_arr[0][0]地址相同
    printf("tw_arr[0] and tw_arr[0][0] address value is: tw_arr[0] = %p, tw_arr[0][0] = %p\n", tw_arr[0], &tw_arr[0][0]);

}