#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define NAME_LEN 20
#define MAXTITLE 40
#define MAXAUTLEN 40
#define MAXBOOK 100
#define FILE_NAME "14.book.dat"
typedef struct Person
{
    char sFirstNm[NAME_LEN];
    char sMidNm[NAME_LEN];
    char sLastNm[NAME_LEN];
} PERSON;

static struct SocSecurity
{
    long luId;
    PERSON person;
};

typedef struct Book
{
    char sTitle[MAXTITLE];
    char sAuthor[MAXAUTLEN];
    float fValue;
} BOOK;

char *s_gets(char *str, int iSize);
void show_info(struct SocSecurity *pSecurity);
void practice4(void)
{
    // 4.编写一个程序， 创建一个有两个成员的结构模板：
    // a.第1个成员是社会保险号， 第2个成员是一个有3个成员的结构， 第1个
    // 成员代表名， 第2个成员代表中间名， 第3个成员表示姓。 创建并初始化一个
    // 内含5个该类型结构的数组。 该程序以下面的格式打印数据：
    // Dribble, Flossie M.–– 302039823
    // 如果有中间名， 只打印它的第1个字母， 后面加一个点（.） ； 如果没有
    // 中间名， 则不用打印点。 编写一个程序进行打印， 把结构数组传递给这个函
    // 数。
    // b.修改a部分， 传递结构的值而不是结构的地址。
    // =======================================================================

    // =======================================================================
    // 初始化结构体
    char sTemp[NAME_LEN];
    unsigned long luTempId;
    struct SocSecurity personInfo;
    struct SocSecurity *pSecurity;
    pSecurity = &personInfo;
    printf("Enter your info(press [Enter] to quit) : \n");
    printf("Enter your first name :");
    while (s_gets(sTemp, NAME_LEN) != NULL && sTemp[0] != '\0')
    {
        strcpy(pSecurity->person.sFirstNm, sTemp);
        printf("Now enter your mid name(not mid name pass enter):");
        s_gets(sTemp, NAME_LEN);
        if (sTemp[0] != '\0')
        {
            strcpy(pSecurity->person.sMidNm, sTemp);
        }
        else
        {
            pSecurity->person.sMidNm[0] = '\0';
        }

        printf("Now enter your last name:");
        while (1)
        {
            if (s_gets(sTemp, NAME_LEN) != NULL || sTemp[0] == '\0')
            {
                if (sTemp[0] != '\0')
                    strcpy(pSecurity->person.sLastNm, sTemp);
                break;
            }
            else
                printf("Your enter is error, please try again!\n");
        }
        printf("Now enter your social security id : ");
        while (1)
        {
            if (scanf("%lu", &luTempId) == 1)
            {
                if ((int)luTempId != 0)
                {
                    pSecurity->luId = luTempId;
                    while (getchar() != '\n')
                        continue;
                }
                break;
            }
            else
            {
                printf("You entered incorrectly, please try again(type 0 to quit)!");
            }
        }
        show_info(pSecurity);
        printf("Enter your info(press [Enter] to quit) : \n");
        printf("Enter your first name :");
    }
    printf("Done!\n");
}

void practice6(void)
{
    struct SoftBallPlayer
    {
        char m_firstNm[NAME_LEN];
        char m_lastNm[NAME_LEN];
        int m_play_times;
        int m_hit_times;
        int m_run_bar_times;
        int m_Rbi;
        double m_hit_rate;
    };

    struct SoftBallPlayer players[19] = {{'\0', '\0', 0, 0, 0, 0, 0.0}};
    struct SoftBallPlayer player;
    int iPlayerNum;
    FILE *fp;
    char *FILENAME = "14.players.dat";
    if ((fp = fopen(FILENAME, "r")) == NULL)
    {
        fprintf("Can't open \"%s\" file.\n", FILENAME);
        return;
    }
    while (feof(fp) == 0)
    {
        fscanf(fp, "%d", &iPlayerNum);
        fscanf(fp, "%s", &player.m_firstNm);
        fscanf(fp, "%s", &player.m_lastNm);
        fscanf(fp, "%d", &player.m_play_times);
        fscanf(fp, "%d", &player.m_hit_times);
        fscanf(fp, "%d", &player.m_run_bar_times);
        fscanf(fp, "%d", &player.m_Rbi);
        if (players[iPlayerNum].m_firstNm[0] == '\0')
            players[iPlayerNum] = player;
        else
        {
            players[iPlayerNum].m_play_times += player.m_play_times;
            players[iPlayerNum].m_hit_times += player.m_hit_times;
            players[iPlayerNum].m_run_bar_times += player.m_run_bar_times;
            players[iPlayerNum].m_Rbi += player.m_Rbi;
        }
    }
    for (size_t i = 0; i < 19; i++)
    {
        if (players[i].m_firstNm[0] != '\0')
        {
            players[i].m_hit_rate = (double)players[i].m_hit_times / players[i].m_play_times;
            printf("No.%2d %s %s play times : %2d  hit times : %2d  run bar times : %d  RBI : %2d  hit rate : %.2lf\n",
                   i, players[i].m_firstNm, players[i].m_lastNm, players[i].m_play_times, players[i].m_hit_times,
                   players[i].m_run_bar_times, players[i].m_Rbi, players[i].m_hit_rate);
        }
    }
}

static struct Seat
{
    unsigned int m_seatId;
    bool m_isOrder;
    char m_firstNm[NAME_LEN];
    char m_lastNm[NAME_LEN];
};

char get_choice(void);
void show_menu(void);
void show_empty_seat(const struct Seat *seat_list, int size);
void show_empty_seat_count(const struct Seat *seat_list, int size);
void show_seat_by_alpha(const struct Seat *seat_list, int size);
void assign_seat(struct Seat *seat_list, int size);
void delete_seat_assign(struct Seat *seat_list, int size);
void practice7(voide)
{
    // 修改程序清单 14.14， 从文件中读取每条记录并显示出来， 允许用户
    // 删除记录或修改记录的内容。 如果删除记录， 把空出来的空间留给下一个要
    // 读入的记录。 要修改现有的文件内容， 必须用"r+b"模式， 而不是"a+b"模
    // 式。 而且， 必须更加注意定位文件指针， 防止新加入的记录覆盖现有记录。
    // 最简单的方法是改动储存在内存中的所有数据， 然后再把最后的信息写入文
    // 件。 跟踪的一个方法是在book结构中添加一个成员表示是否该项被删除。
    // =======================================================================

    // 初始化数据
    int iCount = 0;
    int iBookCount = 0;
    int iSize = sizeof(BOOK);
    BOOK book_list[MAXBOOK] = {{'\0', '\0', 0.0}};
    FILE *fp;
    if ((fp = fopen(FILE_NAME, "r+b")) == NULL)
    {
        fprintf("Fail to open %s file.\n", FILE_NAME);
        return;
    }

    // =======================================================================
    // 从文件中加载数据
    rewind(fp);
    while (iCount < MAXAUTLEN && fread(&book_list[iCount], iSize, 1, fp) == 1)
    {
        if (iCount == 0)
            printf("Current contents of %s :\n", FILE_NAME);
        printf("Book %2d : Title-%-20s Author-%-20s Value-%.2f\n",
               iCount + 1, book_list[iCount].sTitle, book_list[iCount].sAuthor, book_list[iCount].fValue);
        // printf("Title : %-20s  Author : %-20s  Value : %.2f\n",
        //        book_list[iCount].sTitle, book_list[iCount].sAuthor, book_list[iCount].fValue);
        iCount++;
    }

    // =======================================================================
    // 写入数据到文件中
    iBookCount = iCount;
    if (iCount == MAXBOOK)
    {
        printf("The %s is full.\n", FILE_NAME);
        return;
    }
    printf("Please enter the new book title(press Enter to quit):");
    while (iCount < MAXBOOK && s_gets(book_list[iCount].sTitle, MAXTITLE) != NULL && book_list[iCount].sTitle[0] != '\0')
    {
        printf("Now please enter the book <<%s>>'s author:", book_list[iCount].sTitle);
        s_gets(book_list[iCount].sAuthor, MAXAUTLEN);
        printf("Now please enter the book <<%s>>'s value:", book_list[iCount].sTitle);
        scanf("%f", &book_list[iCount].fValue);
        while (getchar() != '\n')
            continue;
        iCount++;
        if (iCount < MAXBOOK)
        {
            printf("Please enter the next new book title:");
        }
    }
    // 判断是否新加条目
    if ((iCount - iBookCount) > 0)
    {
        fwrite(&book_list[iBookCount], iSize, iCount - iBookCount, fp);
        printf("Saved successfully!\n");
    }
    fclose(fp);
    // =======================================================================
    // 重新打印图书列表
    if (iCount > 0 && iCount != iBookCount)
    {
        for (size_t i = 0; i < iCount; i++)
        {
            printf("Book %2d : Title-%-20s Author-%-20s Value-%.2f\n",
                   i + 1, book_list[i].sTitle, book_list[i].sAuthor, book_list[i].fValue);
        }
    }
    else if (iCount == 0)
    {
        printf("There is no book in the library.\n");
        return;
    }

    // =======================================================================
    // TODO{LSX:2020.3.2} : 添加修改/删除操作
    // 删除/修改
    char cChoice;
    int iIndex;
    printf("m : modify item     d : delete item\nc : cancel\n");
    printf("Enter your choice : ");
    while (1)
    {
        cChoice = getchar();
        if (cChoice == 'm' || cChoice == 'd')
        {
            break;
        }
        else if (cChoice == 'c')
            return;
        printf("You entered incorrectly! Please try again\n");
        printf("m : modify item     d : delete item\nc : cancel\n");
        printf("Enter your choice : ");
    }

    while (getchar() != '\n')
    {
        continue;
    }
    if (cChoice == 'm')
    {
        printf("Please enter the number of item you want to modify(enter 0 to quit):");
    }
    else if (cChoice == 'd')
    {
        printf("Please enter the number of item you want to delete(enter 0 to quit):");
    }

    // 获取删除/修改索引
    while (1)
    {
        if (scanf("%d", &iIndex) == 1)
        {
            if (iIndex > 0 && iIndex < iCount)
            {
                while (getchar() != '\n')
                    continue;
                break;
            }
            else if (iIndex == 0)
            {
                printf("Cancel!\n");
                return;
            }
            else
            {
                printf("Index out of range(1-%d).", iCount);
                printf("Please try again(enter 0 to quit) : ");
            }
        }
        else
        {
            printf("You entered incorrectly.\n");
            printf("Please try again(enter 0 to quit) : ");
        }
        while (getchar() != '\n')
            continue;
    }

    // 开始删除/修改
    // 修改
    char sTempTitle[MAXTITLE];
    char sTempAut[MAXAUTLEN];
    float fTempValue;
    bool bFlag = false;
    printf("Current item : \n");
    printf("Book %2d : Title-%-20s Author-%-20s Value-%.2f\n",
           iIndex, book_list[iIndex - 1].sTitle, book_list[iIndex - 1].sAuthor, book_list[iIndex - 1].fValue);
    if (cChoice == 'm')
    {
        printf("Please enter new title(keep it as it is press [Enter]) : ");
        s_gets(sTempTitle, MAXTITLE);
        printf("Please enter new Author(keep it as it is press [Enter]) : ");
        s_gets(sTempAut, MAXTITLE);
        printf("Please enter new Value(keep it as it is type -1) : ");
        while (1)
        {
            if (scanf("%f", &fTempValue) == 1)
            {
                break;
            }
            else
            {
                printf("You entered incorrectly! Please try again : \n");
            }
        }
        if (sTempTitle[0] != '\0')
        {
            bFlag = true;
            strcpy(book_list[iIndex - 1].sTitle, sTempTitle);
        }
        if (sTempAut[0] != '\0')
        {
            bFlag = true;
            strcpy(book_list[iIndex - 1].sAuthor, sTempAut);
        }
        if ((int)fTempValue != -1)
        {
            bFlag = true;
            book_list[iIndex - 1].fValue = fTempValue;
        }
        if (bFlag)
        {
            if ((fp = fopen(FILE_NAME, "w")) == NULL)
            {
                fprintf(stderr, "Fail to open \"%s\" fill.\n", FILE_NAME);
                return;
            }
            fwrite(&book_list[0], iSize, iCount, fp);
            fclose(fp);
        }
        printf("Book %2d : Title-%-20s Author-%-20s Value-%.2f\n",
               iIndex, book_list[iIndex - 1].sTitle, book_list[iIndex - 1].sAuthor, book_list[iIndex - 1].fValue);
    }
    // 删除操作
    else
    {
        char cConfirm;
        printf("Are you sure to delete this book(press y to confirm)? ");
        cConfirm = getchar();
        if (cConfirm == 'y')
        {
            bFlag = true;
        }
        if (bFlag)
        {
            if ((fp = fopen(FILE_NAME, "w")) == NULL)
            {
                fprintf(stderr, "Fail to open \"%s\" fill.\n", FILE_NAME);
                return;
            }
            for (size_t i = 0; i < iCount; i++)
            {
                if (i == iIndex - 1)
                {
                    continue;
                }
                fwrite(&book_list[i], iSize, 1, fp);
            }
            fclose(fp);
        }
    }

    printf("Done!\n");
}

/*************************************************************************
Description
-----------
巨人航空公司的机群由 12 个座位的飞机组成。 它每天飞行一个航
班。 根据下面的要求， 编写一个座位预订程序。
a.该程序使用一个内含 12 个结构的数组。 每个结构中包括： 一个成员
表示座位编号、 一个成员表示座位是否已被预订、 一个成员表示预订人的
名、 一个成员表示预订人的姓。
b.该程序显示下面的菜单：
To choose a function, enter its letter label:
a) Show number of empty seats
b) Show list of empty seats
c) Show alphabetical list of seats
d) Assign a customer to a seat assignment
e) Delete a seat assignment
q) Quit
c.该程序能成功执行上面给出的菜单。 选择d)和e)要提示用户进行额外
输入， 每个选项都能让用户中止输入。
d.执行特定程序后， 该程序再次显示菜单， 除非用户选择q)

*************************************************************************/
void practice8(void)
{
    char *nameSeed = "ABCDEFGHIJKLMNOPQ";
    const int seatCount = 12;
    struct Seat seat_list[seatCount];
    for (size_t i = 0; i < seatCount; i++)
    {
        char firstNm[NAME_LEN] = "first";
        char lastNm[NAME_LEN] = "last";
        int firstNmLen = strlen(firstNm);
        int lastNmLen = strlen(lastNm);
        seat_list[i].m_seatId = i + 1;
        if ((i % 5) == 1)
        {
            seat_list[i].m_isOrder = false;
            continue;
        }
        seat_list[i].m_isOrder = true;
        firstNm[firstNmLen] = nameSeed[i];
        strcpy(seat_list[i].m_firstNm, firstNm);
        lastNm[lastNmLen] = nameSeed[i];
        strcpy(seat_list[i].m_lastNm, lastNm);
    }

    char choice;
    show_menu();
    printf("Please enter your choice : ");
    while ((choice = get_choice()))
    {
        switch (choice)
        {
        case 'a':
            show_empty_seat_count(&seat_list, seatCount);
            break;
        case 'b':
            show_empty_seat(&seat_list, seatCount);
            break;
        case 'c':
            show_seat_by_alpha(&seat_list, seatCount);
            break;
        case 'd':
            assign_seat(&seat_list, seatCount);
            break;
        case 'e':
            delete_seat_assign(&seat_list, seatCount);
            break;
        case 'q':
            printf("Bye!\n");
            return;
            break;
        default:
            printf("You entered incorrectly!\n");
            system("pause");
            break;
        }
        printf("----------------------------------------------------\n");
        show_menu();
        printf("Please enter your choice : ");
    }
}

void transform(const double sourceArr[], double targetArr[], int num, double (*pf)(double));
void practice11(void)
{
    // 11.编写一个名为transform()的函数， 接受4个参数： 内含double类型数据
    // 的源数组名、 内含double类型数据的目标数组名、 一个表示数组元素个数的
    // int类型参数、 函数名（或等价的函数指针） 。 transform()函数应把指定函数
    // 应用于源数组中的每个元素， 并把返回值储存在目标数组中。 例如：
    // transform(source, target, 100, sin);
    // 该声明会把target[0]设置为sin(source[0])， 等等， 共有100个元素。 在一
    // 个程序中调用transform()4次， 以测试该函数。 分别使用math.h函数库中的两
    // 个函数以及自定义的两个函数作为参数。
    int size = 100;
    double sourceArr[size];
    double targetArr[size];
    for (size_t i = 0; i < size; i++)
    {
        sourceArr[i] = -((double)i + 0.1);
    }
    transform(sourceArr, targetArr, size, fabs);
    printf("source arr : \n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%5.2lf ", sourceArr[i]);
        if (i % 10 == 9)
            putchar('\n');
    }

    printf("target arr : \n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%5.2lf ", targetArr[i]);
        if (i % 10 == 9)
            putchar('\n');
    }
    printf("Done!\n");
}

int main(int argc, char const *argv[])
{
    // practice4();
    //practice6();
    // practice7();
    // practice8();
    practice11();
    system("pause");
    return 0;
}

void show_info(struct SocSecurity *pSecurity)
{
    printf("%s, %s", pSecurity->person.sFirstNm, pSecurity->person.sLastNm);
    if (pSecurity->person.sMidNm[0] != '\0')
        printf(" %s.", pSecurity->person.sMidNm);
    printf("--%lu\n", pSecurity->luId);
}

char *s_gets(char *str, int iSize)
{
    char *sRet;
    sRet = fgets(str, iSize, stdin);
    if (sRet)
    {
        char *sFind;
        sFind = strchr(str, '\n');
        if (sFind)
            *sFind = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return sRet;
}

char get_choice(void)
{
    // 使用字符串获取字符，只获取用户输入第一个字符
    // 由于字符串需要一个\0所以这里使用长度为2的char*
    char string[2];
    if (s_gets(string, 2))
        return string[0];
}
void show_menu(void)
{
    printf("To choose a function, enter its letter label:\n");
    printf("a) Show number of empty seats\n");
    printf("b) Show list of empty seats\n");
    printf("c) Show alphabetical list of seats\n");
    printf("d) Assign a customer to a seat assignment\n");
    printf("e) Delete a seat assignment\n");
    printf("q) Quit\n");
}
void show_empty_seat(const struct Seat *seat_list, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (!seat_list[i].m_isOrder)
        {
            printf("seat id : %d is empty.\n", seat_list[i].m_seatId);
        }
    }
}
void show_empty_seat_count(const struct Seat *seat_list, int size)
{
    int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        count += (bool)seat_list[i].m_isOrder;
    }
    printf("There is %d empty seats.\n", size - count);
}
void show_seat_by_alpha(const struct Seat *seat_list, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (seat_list[i].m_isOrder)
        {
            printf("seat id: %d booked by %s %s\n",
                   seat_list[i].m_seatId, seat_list[i].m_firstNm, seat_list[i].m_lastNm);
        }
    }
}
void assign_seat(struct Seat *seat_list, int size)
{
    int seatNum;
    char firstNm[NAME_LEN];
    char lastNm[NAME_LEN];
    while (1)
    {
        printf("Please enter the seat number you want to book(type 0 to quit): ");
        if (scanf("%d", &seatNum) != 1)
        {
            printf("You enter is error, please try again(type 0 to quit):");
            while (getchar() != '\n')
            {
                continue;
            }
        }
        else
        {
            while (getchar() != '\n')
            {
                continue;
            }
            if (seatNum == 0)
            {
                printf("Quit assign seat.\n");
                return;
            }
            else if (seatNum < 0 || seatNum > size)
            {
                printf("Your enter is out of range.\n");
                printf("Enter range of 1 to %d.\n", size);
            }
            else
            {
                if (seat_list[seatNum - 1].m_isOrder)
                {
                    printf("Sorry the seat id %d is not empty, please choose a empty seat to book.\n",
                           seatNum);
                }
                else
                {
                    printf("Enter your first name: ");
                    s_gets(firstNm, NAME_LEN);
                    printf("please enter your last name: ");
                    s_gets(lastNm, NAME_LEN);
                    strcpy(seat_list[seatNum - 1].m_firstNm, firstNm);
                    strcpy(seat_list[seatNum - 1].m_lastNm, lastNm);
                    seat_list[seatNum - 1].m_isOrder = true;
                    break;
                }
            }
        }
    }
    printf("Book successfully!\n");
    printf("seat id : %d is booked by %s %s.\n",
           seat_list[seatNum - 1].m_seatId, seat_list[seatNum - 1].m_firstNm, seat_list[seatNum - 1].m_lastNm);
}
void delete_seat_assign(struct Seat *seat_list, int size)
{
    int seatNum;
    while (1)
    {
        printf("Please enter the seat number you want to delete(type 0 to quit): ");
        if (scanf("%d", &seatNum) != 1)
        {
            printf("You enter is error, please try again(type 0 to quit):");
            while (getchar() != '\n')
            {
                continue;
            }
        }
        else
        {
            while (getchar() != '\n')
            {
                continue;
            }
            if (seatNum == 0)
            {
                printf("Quit delete seat.\n");
                return;
            }
            else if (seatNum < 0 || seatNum > size)
            {
                printf("Your enter is out of range.\n");
                printf("Enter range of 1 to %d.\n", size);
            }
            else
            {
                // seat_list[seatNum].m_firstNm[0]= '\0';
                // seat_list[seatNum].m_lastNm[0]= '\0';
                seat_list[seatNum - 1].m_isOrder = false;
                break;
            }
        }
    }
    printf("seat %d have been deleted!\n", seatNum);
}

void transform(const double sourceArr[], double targetArr[], int num, double (*pf)(double))
{
    for (size_t i = 0; i < num; i++)
    {
        targetArr[i] = (*pf)(sourceArr[i]);
    }
    
}