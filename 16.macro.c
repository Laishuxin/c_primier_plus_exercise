#include <stdio.h>
#include <math.h>
#define PRINTF(X, ...) printf("Message " #X ":"__VA_ARGS__)
#define CHECKING
#define SQRT(X) _Generic((X),\
long double:sqrtl,\
float:sqrtf,\
default:sqrt)(X)

void cod163(void)
{
    int x = 1;
    int y = 2;
    PRINTF(x, "y = %d\n", y);
}

void code1663(void)
{
    int total = 0;
    for (size_t i = 0; i < 5; i++)
    {
        total += i * i;

#ifdef CHECKING
        printf("Total = %d \n", total);
#endif // DEBUG
    }
#undef CHECKING
    printf("Total = %d \n", total);
}

void code1664(void)
{
    printf("File name : %s\n", __FILE__);
    printf("Data : %s\n", __DATE__);
    printf("Time : %s \n", __TIME__);
    printf("Version : %ld\n", __STDC_VERSION__);
    printf("Line : %d\n", __LINE__);
    printf("Func : %s\n", __func__);
}

void code1610(void)
{
    // 泛型编程
    int x = 4; 
    float xx = 4.0f;
    long double xxx = 400.0L;
    printf("SQRT(x) = %lf\n", SQRT(x));
    printf("SQRT(xx) = %f\n", SQRT(xx));
    printf("Long double xxx = %.50Lf\n", xxx);
    printf("SQRT(xxx) = %Lf\n", SQRT(xxx));
}

int main(int argc, char const *argv[])
{
    //cod163();
    //code1663();
    //code1664();
    long double x = 400.0L;
    printf("long double x = %Lf.\n", x);
    //code1610();
    system("pause");
    return 0;
}
