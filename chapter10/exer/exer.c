#include <stdio.h>
#define MONTHS 12        // 一年的月份数
#define YEARS   5        // 年数

void exer1(void) {
    /* rain.c  -- 计算每年的总降水量、年平均降水量和5年中每月的平均降水量 */
     // 用2010～2014年的降水量数据初始化数组
     const float rain[YEARS][MONTHS] =
     {
          { 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
          { 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
          { 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },
          { 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
          { 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }
     };
     int year, month;
     float subtot, total;

     printf(" YEAR    RAINFALL  (inches)\n");
     for (year = 0, total = 0; year < YEARS; year++)
     {                    // 每一年，各月的降水量总和
          for (month = 0, subtot = 0; month < MONTHS; month++)
               subtot += *(*(rain + year) + month);
          printf("%5d %15.1f\n", 2010 + year, subtot);
          total += subtot;    // 5年的总降水量
     }
     printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
     printf("MONTHLY AVERAGES:\n\n");
     printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct ");
     printf(" Nov  Dec\n");

     for (month = 0; month < MONTHS; month++)
     {                    // 每个月，5年的总降水量
          for (year = 0, subtot = 0; year < YEARS; year++)
               subtot += *(*(rain + year) + month);
          printf("%4.1f ", subtot / YEARS);
     }
     printf("\n");
}

void print_arr(double arr[], int size) {
    for (int i = 0; i< size; i++) {
        printf("%.1lf ", arr[i]);
    }
    printf("\n");
}

void copy_arr(double tar[], double src[], int size) {
    for (int i = 0; i<size; i++) {
        tar[i] = src[i];
    }
}
void copy_ptr(double tar[], double src[], int size) {
    double *p = tar;
    double *src_p = src;
    for (int i = 0; i<size; i++) {
        *(p + i) = *(src_p + i);
    }
}
void copy_ptrs(double tar[], double src[], double *after_arr) {
    // 注意这里形参是一个指针，所以sizeof(src) 是8
    // printf("%d", sizeof(src));
    for (int i = 5; i > 0; i--) {
        *(tar) = *(after_arr - i);
        tar ++;
    }
}

void exer2(void) {
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    copy_arr(target1, source, 5);
    print_arr(target1, 5);
    copy_arr(target2, source, 5);
    print_arr(target2, 5);
    copy_ptrs(target3, source, source + 5);
    print_arr(target3, 5);
}

int select_max(int *arr, int size) {
    int max = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

void exer3(void) {
    int arr[] = {2, 4, 10, 5, 1};
    printf("max value is: %d", select_max(arr, (sizeof(arr) / sizeof(arr[0]))));
}

int select_max_index(double arr[], int size) {
    int max_index = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > arr[max_index]) max_index = i;
    }
    return max_index;
}

void exer4(void) {
    double arr[] = {2.2, 4.2, 10.2, 5.1, 1.3};
    printf("max value's index is: %d", select_max_index(arr, (sizeof(arr) / sizeof(arr[0]))));
}

double calc_diff(double arr[], int size) {
    double max = arr[0];
    double min = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    return max - min;
}
void exer5(void) {
    double arr[] = {2.2, 4.2, 10.2, 5.1, 1.3};
    printf("max value's index is: %.2lf", calc_diff(arr, (sizeof(arr) / sizeof(arr[0]))));
}

void sort_arr(double arr[], int size) {
    // 冒泡排序
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                double temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void exer6(void) {
    double arr[] = {1222.2, 4.2, 10.2, 5.1, 1.3};
    sort_arr(arr, 5);
    print_arr(arr, 5);
}
void exer7(void) {
    double arr1[2][2] = {{1,2}, {3, 4}};
    double arr2[2][2];
    double arr[1];
    for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++) {
        copy_arr(arr2[i], arr1[i], sizeof(arr1[i]) / sizeof(arr1[i][0]));
        print_arr(arr2[i], 2);
    }
}

void exer8(void) {
    double arr1[6] = {1.1, 2.2, 3.3, 4.4, 5.6, 6.6};
    double arr2[3];
    copy_ptr(arr2, &arr1[2], 3);
    print_arr(arr2, 3);
}

void copy_vla(double src[][5], double tar[][5], int size) {
    for (int i = 0; i < size; i++) {
        copy_arr(tar[i], src[i], 5);
    }
}

void print_vla(double arr[][5], int size) {
    for (int i = 0; i < size; i++) {
        print_arr(arr[i], sizeof(arr[i]) / sizeof(arr[i][0]));
    }
}

void exer9(void) {
    int n = 3;
    int m = 5;
    double arr[n][m]; // 变长数组，使用变量声明数组维度的数组，不能直接赋值
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = j + 0.2;
        }
    }
    // int i = 0;
    // while (i < 3) {
    //     print_arr(arr[i++], 5);
    // }
    double tar[n][m];
    copy_vla(arr, tar, n);
    print_vla(arr, n);
    print_vla(tar, n);
}

void merge_array(int src1[], int src2[], int tar[], int size) {
    for (int i = 0; i < size; i++) {
        tar[i] = src1[i] + src2[i];
    }
}

void exer10(void) {
    int arr1[4] = {2, 4, 5, 8};
    int arr2[4] = {1, 0, 4, 8};
    int length = 4;
    int tar[length];
    merge_array(arr1, arr2, tar, length);
    for (int i = 0; i < length; i++) {
        printf("%d ", tar[i]);
    }
}

void print_td_arr(int arr[][5], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < sizeof(arr[0]) / sizeof(arr[0][0]); j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void double_arr(int arr[][5], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < sizeof(arr[0]) / sizeof(arr[0][0]); j++) {
            arr[i][j] = arr[i][j] * 2;
        }
    }
}

void exer11(void) {
    int arr[3][5] = {{1,2,3,4,5}, {9,8,7,6,0}, {2,4,6,8,1}};
    int td_length = sizeof(arr) / sizeof(arr[0]);
    print_td_arr(arr, td_length);
    double_arr(arr, td_length);
    print_td_arr(arr, td_length);
}

void exer12(void) {} // 没意义，省略

void insert_value(double arr[][5], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < sizeof(arr[0])/ sizeof(arr[0][0]); j++){
            scanf("%lf", &arr[i][j]);
        }
    }
}

int calc_sum(double arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

void calc_group_average(double arr[][5], int size) {
    int inner_arr_size = sizeof(arr[0])/ sizeof (arr[0][0]);
    for (int i = 0; i < size; i++) {
        double group_sum = calc_sum(arr[i], inner_arr_size);
        printf("第 %d 组的平均值为：%.2lf\n", i, group_sum / inner_arr_size);
    }
}
void calc_average(double arr[][5], int size) {
    int inner_arr_size = sizeof(arr[0])/ sizeof (arr[0][0]);
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += calc_sum(arr[i], inner_arr_size);
    }
    printf("总平均值为：%.2lf\n", sum / (inner_arr_size*size));
}
void select_treble_max(double arr[][5], int size) {
    int inner_arr_size = sizeof(arr[0])/ sizeof (arr[0][0]);
    double max = 0.0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < inner_arr_size; j++) {
            if (arr[i][j] > max) max = arr[i][j];
        }
    }
    printf("最大值为：%.2lf", max);
}

void exer13(void) {
    int n = 3, m = 5;
    double arr[n][m];

    insert_value(arr, n);
    calc_group_average(arr, n);
    calc_average(arr, n);
    select_treble_max(arr, n);
}

int  main(void) {
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
    // exer11();
    // exer12();
    exer13();
}