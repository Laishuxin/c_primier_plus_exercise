/*************************************************************************
File name : c primier plus chapter14 
Its function : 
Create time : 2020.2.29
Author : Lsx
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITLE 40
#define MAXAUTLEN 40
#define MAXBOOK 15
#define MAXBOOKCOUNT 100
#define LEN 20
#define NLEN 40

// =======================================================================
char *s_gets(char *sStr, int iSize);
struct Book
{
    char cpTitle[MAXTITLE];
    char cpAuthor[MAXAUTLEN];
    float fValue;
};

struct Person
{
    char *sFirstNm;
    char *sLastNm;
    int iLetters;
};

struct MotableStruct
{
    int iCount;
    char sName[NLEN];
    double dpMotableArr[];
};

char *s_gets(char *sStr, int iSize);
void code144(void)
{
    struct Book books[MAXBOOKCOUNT];
    int iCount = 0;
    printf("Please enter the book title.\n");
    printf("Press [Enter] at the start of a line to stop.\n");
    while ((iCount < MAXBOOKCOUNT && s_gets(books[iCount].cpTitle, MAXTITLE)) && books[iCount].cpTitle[0] != '\0')
    {
        printf("Now enter the author of %s.\n", books[iCount].cpTitle);
        s_gets(books[iCount].cpAuthor, MAXAUTLEN);
        printf("Now enter the value of %s.\n", books[iCount].cpTitle);
        scanf("%f", &books[iCount].fValue);
        iCount++;
        while (getchar() != '\n')
            continue;
        if (iCount < MAXBOOKCOUNT)
            printf("Enter the next book title.\n");
    }
    if (iCount > 0)
    {
        printf("Here is the books info :\n");
        printf("=======================================================\n");
        printf("%-40s %-40s %-10s\n", "Titile", "Author", "Value");
        for (size_t i = 0; i < iCount; i++)
        {
            printf("%-40s %-40s %-10.2f\n", books[i].cpTitle, books[i].cpAuthor, books[i].fValue);
        }
        printf("=======================================================\n");
    }
    else
    {
        printf("No book in library.\n");
    }
    printf("Done!\n");
}

void code146(void)
{
    struct Names
    {
        char m_sFirst[LEN];
        char m_sLast[LEN];
    };
    struct Info
    {
        struct Names m_Person;
        int m_fAge;
        float m_fHeight;
    };

    // 存储两个人的信息
    struct Info twoPersonInfo[2] =
        {
            {{"FirstName1", "LastName1"},
             10,
             111.1},
            {{"FirstName2", "LastName2"},
             .m_fAge = 20,
             .m_fHeight = 222.2}};

    // =======================================================================
    // 正常打印结构数组
    printf("first person info as follow : \n");
    printf("First name : %s\n", twoPersonInfo[0].m_Person.m_sFirst);
    printf("Last name : %s\n", twoPersonInfo[0].m_Person.m_sLast);
    printf("Age : %d\n", twoPersonInfo[0].m_fAge);
    printf("Height : %.2f\n", twoPersonInfo[0].m_fHeight);

    // 使用指针打印结构数组
    struct Info *pInfo = twoPersonInfo;
    printf("-----------------------------------------------------------\n");
    printf("first person info as follow : \n");
    printf("First name : %s\n", (*pInfo).m_Person.m_sFirst);
    printf("Last name : %s\n", (*pInfo).m_Person.m_sLast);
    printf("Age : %d\n", (*pInfo).m_fAge);
    printf("Height : %.2f\n", (*pInfo).m_fHeight);

    printf("-----------------------------------------------------------\n");
    // 这里与数组不同的是，结构数组的数组名并不是地址
    pInfo = &twoPersonInfo[1];
    printf("Second person info as follow : \n");
    printf("First name : %s\n", pInfo->m_Person.m_sFirst);
    printf("Last name : %s\n", pInfo->m_Person.m_sLast);
    printf("Age : %d\n", pInfo->m_fAge);
    printf("Height : %.2f\n", pInfo->m_fHeight);
}

// =======================================================================
// 传入地址
void print_book(const struct Book *book);
void change_book(struct Book *book);
void print_book_copy(struct Book book);
void code147(void)
{
    // 传递指向结构的指针
    struct Book book1 = {
        "The ordinary world",
        "Lu Yao ",
        25.5};
    print_book(&book1);
    change_book(&book1);
    print_book(&book1);
    print_book_copy(book1);
}

void get_info(struct Person *person);
void make_info(struct Person *person);
void show_info(const struct Person *person);
void free_info(struct Person *person);
void code1477(void)
{
    // 动态管理结构数组
    struct Person person;
    get_info(&person);
    make_info(&person);
    show_info(&person);
    free_info(&person);
}

void make_motable_struct(struct MotableStruct *pMotable, int n);
void show_motable_struct(const struct MotableStruct *pMotable);
void free_motable_struct(struct MotableStruct *pMotable);
void code1479(void)
{
    // 可变成结构体
    // 只要结构体内部含有不定长的数组则为可变长结构体
    // 可变长结构体需要用 struct Xxx* xxx = malloc(sizeof(struct Xxx) + n * sizeof(Type))
    // 其中n为可变长结构体中可变长数组的长度
    // ***********************************************************************
    // 注意事项：
    // 不能通过拷贝构造新的可变长结构体，因为两者占用的内存不一样
    // 可变长结构体在函数传参时，只能要地址(指针)传参，因为值传递会复制新的结构体，但其占用内存是未知的
    // 同样的，可变长结构体也无法作为其他结构体的成员
    // ***********************************************************************

    // ***********************************************************************
    // 错误，可变长数组需要用指针初始化，无法用强制类型转换malloc
    // int n2 = 10;
    // struct MotableStruct pMotable1;
    // pMotable1 = (struct MotableStruct)malloc(sizeof(struct MotableStruct) + n2 * sizeof(double));
    // ***********************************************************************

    int n = 5;
    struct MotableStruct *pMotable1;
    // 这里不需要用强制类型转换
    pMotable1 = malloc(sizeof(struct MotableStruct) + n * sizeof(double));
    // 由于是用指针初始化，所以都不需要传入地址
    make_motable_struct(pMotable1, n);
    show_motable_struct(pMotable1);
    free_motable_struct(pMotable1);
}

/*************************************************************************
Description
-----------
加载图书数据，并计算图书条目

Parameters
-----------
book : struct Book*
    存放图书数据的结构体数组
fp : FILE * 
    图书数组存放的文件指针

Returns
-------/
iFileCout : int
    图书条目

*************************************************************************/
int load_books(struct Book book[], FILE *fp);

/*************************************************************************
Description
-----------
判断当前图书库是否满了，如果还没满的话，通过stdin添加图书

Parameters
-----------
book : struct Book*
    存放图书数据的结构体数组
fp : FILE * 
    图书数组存放的文件指针
iFileCount : int
    在结构数组的结尾开始添加数据

Returns
-------
iCount : int
    添加的图书数量

*************************************************************************/
int add_books(struct Book *book, const FILE *fp, int iFileCount);

/*************************************************************************
Description
-----------
将图书数据写入文件中

Parameters
-----------
book : struct Book*
    存放图书数据的结构体数组
fp : FILE * 
    图书数组存放的文件指针
iStart : int
    从结构体的第i处把图书数据写入，避免把之前读进去的图书数据再一次写入
iCount : int
    新加入的图书数量

Returns
-------
void

*************************************************************************/
void write_books(const struct Book *book, const FILE *fp, int iStart, int iCount);

/*************************************************************************
Description
-----------
显示图书结构体数组的数据

Parameters
-----------
book : struct Book*
    存放图书数据的结构体数组
iCount : int
    结构体数组当前的数量

Returns
-------


*************************************************************************/
void show_books(const struct Book *book, int iCount);
void code148(void)
{
    // 将结构数组写入文件
    struct Book bookList[MAXBOOK];
    int iCount = 0;     // 新添加图书的个数
    int iFileCount = 0; // 文件中图书的个数
    // int iBookSize = sizeof(struct Book);
    FILE *fp;
    if ((fp = fopen("14.book.dat", "a+b")) == NULL)
    {
        fprintf(stderr, "Fail to open 14.book.dat file.\n");
        return;
    }
    // =======================================================================
    // 获取图书数据
    iFileCount = load_books(bookList, fp);
    // =======================================================================
    // 添加图书数据
    iCount = add_books(bookList, fp, iFileCount);
    write_books(bookList, fp, iFileCount, iCount);
    // =======================================================================
    // 显示图书数据
    show_books(bookList, iFileCount + iCount);
    if (fp != NULL)
    {
        fclose(fp);
        fp = NULL;
    }
}

int main(int argc, char const *argv[])
{
    //code144();
    //code146();
    //code147();
    //code1477();
    code148();
    system("pause");
    return 0;
}

char *s_gets(char *sStr, int iSize)
{
    char *cpRetVal;
    char *cpFind;
    cpRetVal = fgets(sStr, iSize, stdin);
    if (cpRetVal)
    {
        cpFind = strchr(sStr, '\n');
        if (cpFind)
        {
            *cpFind = '\0';
        }
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return cpRetVal;
}

void print_book(const struct Book *book)
{
    printf("The book <<%s>>, its author is %s and value %.2f.\n",
           book->cpTitle, book->cpAuthor, book->fValue);
}

void change_book(struct Book *book)
{
    char *sTemp = "11";
    strcat((*book).cpTitle, sTemp);
    strcat((*book).cpAuthor, sTemp);
}

void print_book_copy(struct Book book)
{
    printf("==========================================\n");
    printf("The book <<%s>> its author is %s and value %.2f\n",
           book.cpTitle, book.cpAuthor, book.fValue);
    printf("==========================================\n");
}

void get_info(struct Person *person)
{
    char sTemp[NLEN];
    printf("please enter your first name : ");
    s_gets(sTemp, NLEN);
    // 分配空间
    person->sFirstNm = (char *)malloc(strlen(sTemp) + 1);
    strcpy(person->sFirstNm, sTemp);
    printf("Please enter your last name : ");
    s_gets(sTemp, NLEN);
    person->sLastNm = (char *)malloc(strlen(sTemp) + 1);
    strcpy(person->sLastNm, sTemp);
}

void make_info(struct Person *person)
{
    person->iLetters = strlen(person->sFirstNm) + strlen(person->sLastNm);
}

void show_info(const struct Person *person)
{
    printf("First name : %s.\n", person->sFirstNm);
    printf("Last name : %s.\n", person->sLastNm);
    printf("Name letters : %d.\n", person->iLetters);
}

void free_info(struct Person *person)
{
    if (person->sFirstNm != NULL)
    {
        free(person->sFirstNm);
        person->sFirstNm = NULL;
    }
    if (person->sLastNm != NULL)
    {
        free(person->sLastNm);
        person->sLastNm = NULL;
    }
}

void make_motable_struct(struct MotableStruct *pMotable, int n)
{
    pMotable->iCount = n;
    strcpy(pMotable->sName, "sName");
    for (size_t i = 0; i < pMotable->iCount; i++)
    {
        pMotable->dpMotableArr[i] = 1.0 + i;
    }
}

void show_motable_struct(const struct MotableStruct *pMotable)
{
    printf("iCount = %d\n", pMotable->iCount);
    printf("sName = %s\n", pMotable->sName);
    for (size_t i = 0; i < pMotable->iCount; i++)
    {
        printf("%.2lf ", pMotable->dpMotableArr[i]);
    }
    printf("\n");
}

void free_motable_struct(struct MotableStruct *pMotable)
{
    if (pMotable != NULL)
    {
        free(pMotable);
    }
}

int load_books(struct Book book[], FILE *fp)
{
    int iCount = 0;
    int iSize = sizeof(struct Book);
    rewind(fp);
    while (iCount < MAXBOOK && fread(&book[iCount], iSize, 1, fp) == 1)
    {
        printf("book : %p, &book[iCount] : %p.\n", book + iCount, &book[iCount]);
        book - iCount;
        if (iCount == 0)
        {
            printf("current contents of 14.book.dat : \n");
        }
        printf("Titile : %-20s, Author : %-20s, Value : %.2f\n",
               book[iCount].cpTitle, book[iCount].cpAuthor, book[iCount].fValue);
        iCount++;
    }
    return iCount;
}

int add_books(struct Book *book, const FILE *fp, int iFileCount)
{
    int iCount = 0;
    if (iFileCount == MAXBOOK)
    {
        fprintf(stderr, "The 14.book.dat file is full.\n");
        exit(EXIT_FAILURE);
    }
    printf("Please enter new books titles(Press [Enter] at the start of a line to stop.) : ");
    while ((iCount + iFileCount) < MAXBOOK &&
           s_gets((book + (iFileCount + iCount))->cpTitle, MAXTITLE) != NULL &&
           (book + (iFileCount + iCount))->cpTitle[0] != '\0')
    {
        printf("Now enter the author : ");
        s_gets((book + (iFileCount + iCount))->cpAuthor, MAXAUTLEN);
        printf("Please enter the value : ");
        scanf("%f", &(book + (iFileCount + iCount))->fValue);
        while (getchar() != '\n')
            continue;
        iCount++;
        if ((iCount + iFileCount) < MAXBOOK)
            printf("Enter the next title :");
    }
    return iCount;
}

void write_books(const struct Book *book, const FILE *fp, int iStart, int iCount)
{
    // printf("Title : %-20s, Author : %-20s, Value : %.2f.\n",
    //         (book+iStart)->cpTitle, (book+iStart)->cpAuthor, (book+iStart)->fValue);
    int ret;
    int iSize = sizeof(struct Book);
    ret = fwrite(book + iStart, iSize, iCount, fp);
    printf("Ret = %d\n", ret);
}

void show_books(const struct Book *book, int iCount)
{
    if (iCount > 0)
    {
        for (size_t i = 0; i < iCount; i++)
        {
            printf("Title : %-20s, Author : %-20s, Value : %.2f.\n",
                   book->cpTitle, book->cpTitle, book->fValue);
            book++;
        }
    }
}