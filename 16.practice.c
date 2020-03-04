// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
#include "16.practice.h"
#define HAMMONIC_MEAN(X, Y) (2 * (X) * (Y)) / ((X) + (Y))
#define SIZE 100
#define NDEBUG
void init_arr(int arr[], int count);
void show_arr(int *arr, int count);
int my_compare(const void *p1, const void *p2);
void review13(void)
{
    // 3.假设 scores 是内含 1000 个 int 类型元素的数组， 要按降序排序该数
    // 组中的值。 假设你使用qsort()和comp()比较函数。
    // a.如何正确调用qsort()？
    // b.如何正确定义comp()？
    int count = 50;
    int iArr[count];
    init_arr(iArr, count);
    printf("unsorted : \n");
    show_arr(iArr, count);
    qsort(iArr, count, sizeof(int), my_compare);
    printf("sorted : \n");
    show_arr(iArr, count);
}

typedef struct MyArr
{
    int data1[SIZE];
    int data2[3 * SIZE];
} MYARR;

void review14(void)
{
    // 假设data1是内含100个double类型元素的数组， data2是内含300个
    // double类型元素的数组。
    // a.编写memcpy()的函数调用， 把data2中的前100个元素拷贝到data1中。
    // b.编写memcpy()的函数调用， 把data2中的后100个元素拷贝到data1中。
    MYARR myArr;
    //int tempArr[SIZE];
    for (size_t i = 0; i < (3 * SIZE); i++)
    {
        myArr.data2[i] = i + 1;
    }
    printf("myArr.data2 : \n");
    show_arr(myArr.data2, 3 * SIZE);
    //memcpy(tempArr, myArr.data2, sizeof(int));
    memcpy(myArr.data1, myArr.data2, SIZE * sizeof(int));
    printf("myArr.data1 : \n");
    show_arr(myArr.data1, 100);

    printf("myArr.data1 second : \n");
    memcpy(myArr.data1, &myArr.data2[100], SIZE * sizeof(int));
    show_arr(myArr.data1, SIZE);
}

void practice2(void)
{
    // 两数的调和平均数这样计算： 先得到两数的倒数， 然后计算两个倒数
    // 的平均值， 最后取计算结果的倒数。 使用#define指令定义一个宏“函数”， 执
    // 行该运算。 编写一个简单的程序测试该宏。
    int x = 4;
    int y = 5;
    double ret = (double)HAMMONIC_MEAN(x, y);
    double ret2 = (double)(2 * x * y) / (x + y);
    assert((int)ret == 4);
    printf("the hammonic mean of 4 and 5 is %lf.\n", ret);
    printf("the hammonic mean of 4 and 5 is %lf.\n", ret2);
}

void practice4(void)
{
    // #include <time.h>
    // clock_t clock (void);
    // 这里， clock_t是定义在time.h中的类型。 该函数返回处理器时间， 其单
    // 位取决于实现（如果处理器时间不可用或无法表示， 该函数将返回-1） 。 然
    // 而， CLOCKS_PER_SEC（也定义在time.h中） 是每秒处理器时间单位的数
    // 量。 因此， 两个 clock()返回值的差值除以 CLOCKS_PER_SEC得到两次调用
    // 之间经过的秒数。 在进行除法运算之前， 把值的类型强制转换成double类
    // 型， 可以将时间精确到小数点以后。 编写一个函数， 接受一个double类型的
    // 参数表示时间延迟数， 然后在这段时间运行一个循环。 编写一个简单的程序
    // 测试该函数
    long long testTimes = 1000000001;
    long long total = 0;
    clock_t clock1 = clock();
    assert(clock1 != -1);
    for (size_t i = 0; i < testTimes; i++)
    {
        total += testTimes;
    }
    printf("total : %lld\n", total);
    clock_t clock2 = clock();
    printf("waste %lf second.\n", ((double)clock2 - (double)clock1) / CLOCKS_PER_SEC);
}

void show_array(const double dArr[], int size);
double *new_d_arr(int argc, ...);
void practice7(void)
{
    // new_d_array()函数接受一个int类型的参数和double类型的参数。 该函数
    // 返回一个指针， 指向由malloc()分配的内存块。 int类型的参数指定了动态数
    // 组中的元素个数， double类型的值用于初始化元素（第1个值赋给第1个元
    // 素， 以此类推） 。 编写show_array()和new_d_array()函数的代码， 完成这个
    // 程序
    double *p1, *p2;
    p1 = new_d_arr(5, 1.0, 2.1, 3.2, 4.3, 5.4);
    p2 = new_d_arr(4, 4.4, 3.3, 2.2, 1.1);
    show_array(p1, 5);
    show_array(p2, 4);
    if (p1)
    {
        free(p1);
    }
    if (p2)
    {
        free(p2);
    }
}

int main(int argc, char const *argv[])
{
    //review13();
    // review14();
    //practice2();
    //practice4();
    practice7();
    system("pause");
    return 0;
}

void init_arr(int arr[], int count)
{
    // void *ptrTemp = (char *)malloc(count * size);
    // ptrTemp = arr;
    for (int i = 0; i < count; i++)
    {
        arr[i] = rand();
    }
}
void show_arr(int *arr, int count)
{
    for (size_t i = 0; i < count; i++)
    {
        printf("%6d ", arr[i]);
        if ((i % 10) == 9)
            putchar('\n');
    }
}

int my_compare(const void *p1, const void *p2)
{
    const int *num1 = (const int *)p1;
    const int *num2 = (const int *)p2;
    if (*num1 < *num2)
        return 1;
    else if (*num1 == *num2)
        return 0;
    else
        return -1;
}

void show_array(const double dArr[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%lf ", dArr[i]);
    }
    putchar('\n');
}
double *new_d_arr(int argc, ...)
{
    double *dArr = (double *)malloc(argc * sizeof(double));
    va_list argv;
    va_start(argv, argc);
    for (size_t i = 0; i < argc; i++)
    {
        *dArr = va_arg(argv, double);
        printf("*dArr = %lf\n", *dArr);
        dArr++;
    }

    va_end(argv);

    return dArr - argc;
}