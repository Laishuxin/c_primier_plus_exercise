#include <stdio.h>
#include <ctype.h>

void practice4(void)
{
    /*
    ��дһ������ ������EOF֮ǰ�� ��������Ϊ�ַ�����ȡ�� �ó���Ҫ
    ����ƽ��ÿ�����ʵ���ĸ���� ��Ҫ�ѿհ�ͳ��Ϊ���ʵ���ĸ�� ʵ���ϣ� ���
    ����Ҳ��Ӧ��ͳ�ƣ� ����������ʱ��ͬ������ô�ࣨ�����Ƚ�������㣬
    ����ʹ��ctype.hϵ���е�ispunct()������ */

    // ispunc�����ж��Ƿ�Ϊ������
    char ch_curr, ch_pre; // ��ǰchar��ǰһ��char
    int totalChars, totalWords;
    double average;

    totalChars = 0;
    totalWords = 0;

    printf("������һ�����֣�\n");
    // �����ļ���ͷ�ķ���ĸ���š�
    while (ch_curr = getchar())
    {
        if (isalpha(ch_curr))
        {
            totalChars++; // ������ǰȡ��һ���ַ�����Ҫ�ӻ�ȥ
            totalWords++; // ���ʿ�ʼ����
            ch_pre = ch_curr;
            break;
        }
    }

    while ((ch_curr = getchar()) != EOF)
    {
        if (isalpha(ch_curr))
            totalChars++;

        // �ж��Ƿ�Ϊ��ĸ������ǰһ��charΪ�ո���߱�ʶ���磬��
        // �ǵĻ�������+1
        if (isalpha(ch_curr) && (isspace(ch_pre) || ispunct(ch_pre)))
        {
            totalWords++;
        }

        ch_pre = ch_curr;
    }

    average = (double)totalChars / (double)totalWords;
    printf("�ܵ���ĸ���У�%d�����ܵĵ������У�%d����ƽ��������Ϊ��%.2f\n",
           totalChars, totalWords, average);
}

void practice6(void)
{
    /*
    6.�޸ĳ����嵥8.8�е�get_first()������ �øú������ض�ȡ�ĵ�1���ǿ�
    ���ַ��� ����һ���򵥵ĳ����в��ԡ�
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

    // ���Ի������Ƿ����ַ���
    int ch2;
    printf("if buffer is empty, please enter something\n");
    ch2 = getchar();
    printf("ch2 = %c\n", ch2);
}

void practice7(void)
{
    /*
    7.�޸ĵ�7�µı����ϰ8�� ���ַ��������ֱ�ǲ˵���ѡ� ��q����5
    ��Ϊ��������ı�ǡ�
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
    8.��дһ������ ��ʾһ���ṩ�ӷ��� ������ �˷��� �����Ĳ˵��� ���
    �û�ѡ���ѡ��� ������ʾ�û������������֣� Ȼ��ִ���û��ղ�ѡ���
    ������ �ó���ֻ���ܲ˵��ṩ��ѡ� ����ʹ��float���͵ı��������û���
    ������֣� ����û�����ʧ�ܣ� �������ٴ����롣 ���г�������ʱ�� �����
    ������0��Ϊ��2������������ �� ����Ӧ��ʾ�û���������һ����ֵ�� �ó���
    ��һ������ʾ�����£�
    */

    printf("Please enter operation of your choice(enter q to quit):\n");
    printf("a. add\t\ts. subtract\nm. multiply\td. divide\n");
    char choice; // �û���ѡ��
    float ret;   // ����Ľ��
    float num1, num2;

    while ((choice = getChoice()) != 'q')
    {
        switch (choice)
        {
        case 'a': //�ӷ�
            printf("�������һ����:\n");
            num1 = getNum();
            printf("������ڶ�����:\n");
            num2 = getNum();
            ret = add(num1, num2);
            printf("%.2f + %.2f = %.2f\n", num1, num2, ret);
            break;
        case 's': //����
            printf("�������һ����:\n");
            num1 = getNum();
            printf("������ڶ�����:\n");
            num2 = getNum();
            ret = subtract(num1, num2);
            printf("%.2f - %.2f = %.2f\n", num1, num2, ret);
            break;
        case 'm': //�˷�
            printf("�������һ����:\n");
            num1 = getNum();
            printf("������ڶ�����:\n");
            num2 = getNum();
            ret = multiply(num1, num2);
            printf("%.2f x %.2f = %.2f\n", num1, num2, ret);
            break;
        case 'd': //����
            printf("�������һ����:\n");
            num1 = getNum();
            printf("������ڶ�����(��������Ϊ0):\n");
            while ((num2 = getNum()) == 0)
            {
                printf("������ڶ�����(��������Ϊ0):\n");
            }
            ret = divide(num1, num2);
            printf("%.2f / %.2f = %.2f\n", num1, num2, ret);
            break;
        default:
            printf("�������������������룡\n");
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
    // ֻ��ȡ��һ���ַ�����ˢ�»�����
    // �����һ���ַ������ַ�����Ҫ���û���������
    int ch;
    while (!isalpha(ch = getchar()))
    {
        printf("��������ĸ����\n");
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
        printf("�������������������룡\n");
        // ��ջ�����
        while (getchar() != '\n')
            continue;
    }
    while (getchar() != '\n')
        continue;

    // printf("num = %f\n", num);
    return num;
}