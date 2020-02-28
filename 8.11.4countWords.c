#include <stdio.h>
#include <ctype.h>

void practice4(void)
{
    /*
    编写一个程序， 在遇到EOF之前， 把输入作为字符流读取。 该程序要
    报告平均每个单词的字母数。 不要把空白统计为单词的字母。 实际上， 标点
    符号也不应该统计， 但是现在暂时不同考虑这么多（如果你比较在意这点，
    考虑使用ctype.h系列中的ispunct()函数） */

    // ispunc可以判断是否为标点符号
    char ch_curr, ch_pre; // 当前char和前一个char
    int totalChars, totalWords;
    double average;

    totalChars = 0;
    totalWords = 0;

    printf("请输入一段文字：\n");
    // 处理文件开头的非字母符号。
    while (ch_curr = getchar())
    {
        if (isalpha(ch_curr))
        {
            totalChars++; // 这里提前取出一个字符，需要加回去
            totalWords++; // 单词开始计算
            ch_pre = ch_curr;
            break;
        }
    }

    while ((ch_curr = getchar()) != EOF)
    {
        if (isalpha(ch_curr))
            totalChars++;

        // 判断是否为字母，并且前一个char为空格或者标识符如，。
        // 是的话单词数+1
        if (isalpha(ch_curr) && (isspace(ch_pre) || ispunct(ch_pre)))
        {
            totalWords++;
        }

        ch_pre = ch_curr;
    }

    average = (double)totalChars / (double)totalWords;
    printf("总的字母数有：%d个，总的单词数有：%d个，平均单词数为：%.2f\n",
           totalChars, totalWords, average);
}

void practice6(void)
{
    /*
    6.修改程序清单8.8中的get_first()函数， 让该函数返回读取的第1个非空
    白字符， 并在一个简单的程序中测试。
    */
    printf("Please a something\n");
    int ch;
    while (!isalpha(ch = getchar()))
    {
        continue;
    }
    while (getchar() != '\n')
        continue;
    printf("the return of the character is %c\n", ch);

    // 测试缓冲区是否还有字符串
    int ch2;
    printf("if buffer is empty, please enter something\n");
    ch2 = getchar();
    printf("ch2 = %c\n", ch2);
}

void practice7(void)
{
    /*
    7.修改第7章的编程练习8， 用字符代替数字标记菜单的选项。 用q代替5
    作为结束输入的标记。
    */
    ;
}

char getChoice(void);
float add(float num1, float num2);
float subtract(float num1, float num2);
float multiply(float num1, float num2);
float divide(float num1, float num2);
float getNum();
void practice8(void)
{
    /*
    8.编写一个程序， 显示一个提供加法、 减法、 乘法、 除法的菜单。 获得
    用户选择的选项后， 程序提示用户输入两个数字， 然后执行用户刚才选择的
    操作。 该程序只接受菜单提供的选项。 程序使用float类型的变量储存用户输
    入的数字， 如果用户输入失败， 则允许再次输入。 进行除法运算时， 如果用
    户输入0作为第2个数（除数） ， 程序应提示用户重新输入一个新值。 该程序
    的一个运行示例如下：
    */

    printf("Please enter operation of your choice(enter q to quit):\n");
    printf("a. add\t\ts. subtract\nm. multiply\td. divide\n");
    char choice; // 用户的选择
    float ret;   // 计算的结果
    float num1, num2;

    while ((choice = getChoice()) != 'q')
    {
        switch (choice)
        {
        case 'a': //加法
            printf("请输入第一个数:\n");
            num1 = getNum();
            printf("请输入第二个数:\n");
            num2 = getNum();
            ret = add(num1, num2);
            printf("%.2f + %.2f = %.2f\n", num1, num2, ret);
            break;
        case 's': //减法
            printf("请输入第一个数:\n");
            num1 = getNum();
            printf("请输入第二个数:\n");
            num2 = getNum();
            ret = subtract(num1, num2);
            printf("%.2f - %.2f = %.2f\n", num1, num2, ret);
            break;
        case 'm': //乘法
            printf("请输入第一个数:\n");
            num1 = getNum();
            printf("请输入第二个数:\n");
            num2 = getNum();
            ret = multiply(num1, num2);
            printf("%.2f x %.2f = %.2f\n", num1, num2, ret);
            break;
        case 'd': //除法
            printf("请输入第一个数:\n");
            num1 = getNum();
            printf("请输入第二个数(除数不能为0):\n");
            while ((num2 = getNum()) == 0)
            {
                printf("请输入第二个数(除数不能为0):\n");
            }
            ret = divide(num1, num2);
            printf("%.2f / %.2f = %.2f\n", num1, num2, ret);
            break;
        default:
            printf("您输入有误，请重新输入！\n");
        }
        printf("Please enter operation of your choice(enter q to quit):\n");
        printf("a. add\t\ts. subtract\nm. multiply\td. divide\n");
    }
    printf("Bye!\n");
}

int main(void)
{

    // practice4();
    //practice6();
    practice7();
    practice8();
    system("pause");
    return 0;
}

char getChoice(void)
{
    // 只获取第一个字符，并刷新缓冲区
    // 如果第一个字符不是字符，则要求用户重新输入
    int ch;
    while (!isalpha(ch = getchar()))
    {
        printf("请输入字母！！\n");
        while (getchar() != '\n')
            continue;
    }
    while (getchar() != '\n')
        continue;
    return ch;
}

float add(float num1, float num2)
{
    return num1 + num2;
}

float subtract(float num1, float num2)
{
    return num1 - num2;
}

float multiply(float num1, float num2)
{
    return num1 * num2;
}
float divide(float num1, float num2)
{
    return num1 / num2;
}

float getNum(void)
{
    float num;
    while (scanf("%f", &num) != 1)
    {
        printf("您输入有误，请重新输入！\n");
        // 清空缓冲区
        while (getchar() != '\n')
            continue;
    }
    while (getchar() != '\n')
        continue;

    // printf("num = %f\n", num);
    return num;
}