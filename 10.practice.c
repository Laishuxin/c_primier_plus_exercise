#include <stdio.h>
#define SIZE 5

void printArr(double arr[], int size);
void printArr2(int rows, int cols, double arr[rows][cols]);
void copy_arr(double target[], double source[], int size);
void copy_ptr(double target[], double *ptr, int size);
void copy_ptrs(double target[], double source[], double *ptr);
void practice2(void)
{
    double source[SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double target1[SIZE];
    double target2[SIZE];
    double target3[SIZE];
    // 1.带数组表示法进行拷贝
    copy_arr(target1, source, SIZE);

    // 2. 带指针表示法和指针递增进行拷贝
    copy_ptr(target2, source, SIZE);

    // 3. 目标数组名，源数组名，源数组最后一个元素进行复制
    copy_ptrs(target3, source, source + SIZE);

    printArr(source, SIZE);
    printArr(target1, SIZE);
    printArr(target2, SIZE);
    printArr(target3, SIZE);
}

void getRange(int arr[], int size);
void practice5(void)
{
    //编写一个函数， 返回储存在double类型数组中最大值和最小值的差
    //值， 并在一个简单的程序中测试该函数。
    int arr[9] = {5, 4, 3, 6, 7, 2, 1, 8, 9};
    getRange(arr, 9);
    getRange((int[]){1, 1, 1, 1}, 4);
}

void reverseArr(double arr[], int size);
void practice6(void)
{
    //编写一个函数， 把double类型数组中的数据倒序排列， 并在一个简单
    //的程序中测试该函数。
    double arr[5] = {.1, .2, .3, .4, .5};
    printf("not be reversed yet!\n");
    printArr(arr, 5);
    printf("have been reversed yet!\n");
    reverseArr(arr, 5);
    printArr(arr, 5);
}

void copy_arr2(double target[][3], double source[][3], int rows, int cols);
void practice7(void)
{
    //编写一个程序， 初始化一个double类型的二维数组， 使用编程练习2中
    //的一个拷贝函数把该数组中的数据拷贝至另一个二维数组中（因为二维数组
    //是数组的数组， 所以可以使用处理一维数组的拷贝函数来处理数组中的每个
    //子数组） 。
    double arr2[2][3] = {
        {1., 2., 3.},
        {10., 20., 30.}};
    double target[2][3];
    copy_arr2(target, arr2, 2, 3);
    printArr2(2, 3, arr2);
    printArr2(2, 3, target);
}

void practice8(void)
{
    /*
    使用编程练习2中的拷贝函数， 把一个内含7个元素的数组中第3～第5
    个元素拷贝至内含3个元素的数组中。 该函数本身不需要修改， 只需要选择
    合适的实际参数（实际参数不需要是数组名和数组大小， 只需要是数组元素
    的地址和待处理元素的个数）
    */
    double arr[7] = {1, 2, 3, 4, 5, 6, 7};
    double target[3];
    copy_ptrs(target, arr + 2, arr + 5);
    printArr(arr, 7);
    printArr(target, 3);
}

void copy_VLA(const double arr1[], const double arr2[], double arr3[], int size);
void practice10(void)
{
    /*
    编写一个函数， 把两个数组中相对应的元素相加， 然后把结果储存
    到第 3 个数组中。 也就是说， 如果数组1中包含的值是2、 4、 5、 8， 数组2中
    包含的值是1、 0、 4、 6， 那么该函数把3、 4、 9、 14赋给第3个数组。 函数接
    受3个数组名和一个数组大小。 在一个简单的程序中测试该函数。
    */
    const int size = 5;
    double arr1[size];
    double arr2[size];
    double arr3[size];
    for (int i = 0; i < size; i++)
    {
        arr1[i] = i + 1;
        arr2[i] = i + 11;
    }
    copy_VLA(arr1, arr2, arr3, size);
    printArr(arr1, size);
    printArr(arr2, size);
    printArr(arr3, size);
}

void init_arr(double d_arr[][5], int rows);
void average_arr(double d_arr[][5], int rows);
void average_all_arr(double d_arr[][5], int rows);
void max_all_arr(double d_arr[][5], int rows);
void practice13(void)
{
    // .编写一个程序， 提示用户输入3组数， 每组数包含5个double类型的数
    //（假设用户都正确地响应， 不会输入非数值数据） 。 该程序应完成下列任务。
    // a.把用户输入的数据储存在3×5的数组中
    // b.计算每组（5个） 数据的平均值
    // c.计算所有数据的平均值
    // d.找出这15个数据中的最大值
    // e.打印结果
    double d_arr[3][5];
    init_arr(d_arr, 3);
    average_arr(d_arr, 3);
    average_all_arr(d_arr, 3);
    max_all_arr(d_arr, 3);
    printArr2(3, 5, d_arr);
}

int main(int argc, char const *argv[])
{
    //practice2();
    //practice5();
    //practice6();
    //practice7();
    //practice8();
    //practice10();
    practice13();
    system("pause");
    return 0;
}

void printArr(double arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%.2f  ", arr[i]);
    }
    printf("\n");
}

void copy_arr(double target[], double source[], int size)
{
    for (int i = 0; i < size; i++)
    {
        target[i] = source[i];
    }
}

void copy_ptr(double target[], double *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        target[i] = *(ptr + i);
    }
}

void copy_ptrs(double target[], double source[], double *ptr)
{
    //printf("ptr's address is %p\n", ptr);
    for (int i = 0; &source[i] != ptr; i++)
    {
        target[i] = source[i];
        //printf("&source[%d] = % p\n", i, &source[i]);
    }
}

void getRange(int arr[], int size)
{
    int max, min;
    for (int i = 0; i < size; i++)
    {
        if (i == 0) // 从第一个数据开始比较
        {
            min = arr[i];
            max = arr[i];
            continue;
        }
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    printf("Range is %d\n", max - min);
}

void reverseArr(double arr[], int size)
{
    // 奇数数组反转
    // 偶数数组反转
    int mid = size / 2;
    double temp;
    for (int i = 0; i < mid; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void copy_arr2(double target[][3], double source[][3], int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        copy_arr(target[r], source[r], cols);
    }
}

void printArr2(int rows, int cols, double arr[rows][cols])
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%.2f ", arr[r][c]);
        }
        putchar('\n');
    }
    printf("\n");
}

void copy_VLA(const double arr1[], const double arr2[], double arr3[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr3[i] = arr1[i] + arr2[i];
    }
}

void init_arr(double d_arr[][5], int rows)
{
    for (int r = 0; r < rows; r++)
    {
        printf("please enter the %d row datas\(type Enter to input the next row\):",
               r + 1);
        //scanf("%f,%f,%f,%f,%f", d_arr[r], d_arr[r+1], d_arr[r+2], d_arr[r])
        for (int c = 0; c < 5; c++)
        {
            scanf("%lf", &d_arr[r][c]);
        }
    }
}
void average_arr(double d_arr[][5], int rows)
{
    double total;
    for (int r = 0; r < rows; r++)
    {
        total = 0;
        for (int c = 0; c < 5; c++)
        {
            total += d_arr[r][c];
        }
        printf("the average of the %d row is %.2f.\n", r, total / 5.0);
    }
}
void average_all_arr(double d_arr[][5], int rows)
{
    double total;
    total = 0;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            total += d_arr[r][c];
        }
    }
    printf("the average of the all data is %.2f.\n", total / (rows * 5.0));
}
void max_all_arr(double d_arr[][5], int rows)
{
    double max;
    max = d_arr[0][0];
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (d_arr[r][c] > max)
                max = d_arr[r][c];
        }
    }
    printf("the max value of the all data is %.2f.\n", max);
}
