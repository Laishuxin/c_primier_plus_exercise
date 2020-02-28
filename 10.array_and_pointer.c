#include <stdio.h>
#include <math.h>
#define SIZE 10
#define ROWS 3
#define COLS 4
#define LENGTH 5

void pointerAndArr103(void)
{
    const int size = 4;
    int intArr[size];
    double doubleArr[size];

    int *pInt;
    double *pDouble;

    pInt = intArr;
    pDouble = doubleArr;

    for (int i = 0; i < size; ++i)
    {
        intArr[i] = i;
        doubleArr[i] = (double)10.0 * i;
    }
    printf("%10s   %15s   %10s   %15s\n",
           "intArr[i]", "doubleArr[i]", "pInt + i", "pDouble + i");
    for (int i = 0; i < size; ++i)
    {
        printf("%10d   %15.2f   %10d  %15d\n",
               intArr[i], doubleArr[i], pInt + i, pDouble + i);
    }
    printf("intArr = %p\n", intArr);
    printf("intArr = %d\n", (int)intArr);
    printf("doubleArr = %p\n", doubleArr);
    printf("doubleArr = %d\n", (int)doubleArr);
}

int sum_arr(int arr[], int n);
void code104(void)
{
    int marbles[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int answer;
    answer = sum_arr(marbles, SIZE);
    printf("The total number of marbles is %d.\n", answer);
    printf("the size of marbles is %zd bytes.\n", sizeof(marbles));
}

int sump(int *start, int *end);
void code105(void)
{
    int marbles[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int answer;
    answer = sump(marbles, marbles + SIZE);
    printf("the answer is :%d\n", answer);
}

void code1071(void)
{
    int zippo[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}};
    int(*pz)[2];
    pz = zippo;

    printf("pz = %p, pz+1 = %p\n", pz, pz + 1);
    printf("pz[0] = %p, pz[0]+1 = %p\n", pz[0], pz[0] + 1);
    printf("*pz=%p, *pz+1=%p\n", *pz, *pz + 1);
    printf("**pz = %d\n", **pz);
    printf("pz[0][0] = %d\n", pz[0][0]);
    printf("*pz[0] = %d\n", *pz[0]);
    printf("pz[2][1] = %d\n", pz[2][1]);
    printf("*(*(pz+2) + 1) = %d\n", *(*(pz + 2) + 1));
}

void sum_rows(int (*arr)[COLS], int rows, int cols);
void sum_cols(int arr[][COLS], int rows, int cols);
int sum2d(int arr[][COLS], int rows, int cols);
void code1073(void)
{
    int arr[ROWS][COLS] =
        {
            {1, 2, 3, 4},
            {10, 20, 30, 40},
            {100, 200, 300, 400}};

    sum_rows(arr, ROWS, COLS);
    sum_cols(arr, ROWS, COLS);

    int total = sum2d(arr, ROWS, COLS);
    printf("total = %d\n", total);
}

// 这里必须先指定rows和cols，这样后面的arr才能正常使用
int sumVLA(int rows, int cols, int arr[rows][cols]);
void code108(void)
{
    // 使用变长数组的函数统计数组中所有值的总和
    // 使用宏定义
    // 这里ROWS = 3;  COLS = 4;
    int arr1[ROWS][COLS] =
        {
            {1, 2, 3, 4},
            {10, 20, 30, 40},
            {100, 200, 300, 400}};

    // 使用变长数组
    int rows = 3;
    int cols = 4;
    int arr2[rows][cols];
    // 这里不能使用arr2[rows][cols] = {};初始化
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; j++)
        {
            arr2[i][j] = (j + 1) * (int)pow(10, (double)i);
        }
    }
    int ret;
    ret = sumVLA(ROWS, COLS, arr1);
    printf("total of the arr1 is %d\n", ret);

    ret = sumVLA(rows, cols, arr2);
    printf("total of the arr2 is %d\n", ret);
}

double average1d(const int arr[], int length);
double average2d(const int arr[][COLS], int rows);
void code109(void)
{
    double ret;
    // 复合字面量，也可以称之为匿名变量
    // 创建一个指针维护1维数组，并求平均值(指针指向匿名变量)

    int *p1d;
    p1d = (int[LENGTH]){1, 2, 3, 4, 5};

    ret = average1d(p1d, LENGTH);
    printf("ret = %f\n", ret);

    // 创建一个直至维护2维数组，并求平均值(指针指向匿名变量)
    int(*p2d)[COLS];
    p2d = (int[ROWS][COLS]){
        {1, 2, 3, 4},
        {10, 20, 30, 40},
        {100, 200, 300, 400}};
    ret = average2d(p2d, ROWS);
    printf("ret = %f\n", ret);
}

int main()
{
    //pointerAndArr103();
    //code104();
    // code105();
    //code1071();
    //code1073();
    //code108();
    code109();
    int *ptr;
    int fort[2][2] = {{12}, {14,16}};
    ptr = fort[0];
    printf("main : %d\n", *(ptr+2));
    system("pause");
    return 0;
}

int sum_arr(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; ++i)
    {
        total += arr[i];
    }
    printf("the size of marbles is %zd bytes.\n", sizeof(arr));
    return total;
}

int sump(int *start, int *end)
{
    int total = 0;
    while (start < end)
    {
        total += *start;
        start++;
    }
    // for (int i=0; i<SIZE; ++i)
    // {
    //     printf("in sump: start[%d] = %d\n",i,start[i]);
    // }
    return total;
}

void sum_rows(int (*arr)[COLS], int rows, int cols)
{
    int total;
    for (int i = 0; i < rows; ++i)
    {
        total = 0;
        for (int j = 0; j < cols; ++j)
        {
            total += arr[i][j];
        }
        printf("row : %d  total : %d\n", i, total);
    }
}
void sum_cols(int arr[][COLS], int rows, int cols)
{
    int total;
    for (int i = 0; i < cols; ++i)
    {
        total = 0;
        for (int j = 0; j < rows; ++j)
        {
            total += arr[j][i];
        }
        printf("col : %d total : %d\n", i, total);
    }
}
int sum2d(int arr[][COLS], int rows, int cols)
{
    int total = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            total += arr[i][j];
        }
    }
    return total;
}

int sumVLA(int rows, int cols, int arr[rows][cols])
{
    int total = 0;
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            total += arr[row][col];
        }
    }
    return total;
}

double average1d(const int arr[], int length)
{
    int total = 0;
    for (int i = 0; i < length; i++)
    {
        total += arr[i];
    }
    return (double)total / length;
}
double average2d(const int arr[][COLS], int rows)
{
    int total = 0;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            total += arr[r][c];
        }
    }
    return (double)total / (rows * COLS);
}
