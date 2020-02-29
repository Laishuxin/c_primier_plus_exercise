/*************************************************************************
File name : c primier plus chapter14 
Its function : 
Create time : 2020.2.29
Author : Lsx
*************************************************************************/
#include <stdio.h>
#include <string.h>
#define MAXTITLE 40
#define MAXAUTLEN 40
#define MAXBOOKCOUNT 100
#define LEN 20

// =======================================================================

struct Book
{
    char cpTitle[MAXTITLE];
    char cpAuthor[MAXAUTLEN];
    float fValue;
};

char *s_gets(char *cpStr, int iSize);
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
        {
            {"FirstName1", "LastName1"},
            10,
            111.1
        },
        {
            {"FirstName2", "LastName2"},
            .m_fAge = 20,
            .m_fHeight = 222.2
        }
    };

    // =======================================================================
    // 正常打印结构数组
    printf("first person info as follow : \n");
    printf("First name : %s\n", twoPersonInfo[0].m_Person.m_sFirst);
    printf("Last name : %s\n", twoPersonInfo[0].m_Person.m_sLast);
    printf("Age : %d\n", twoPersonInfo[0].m_fAge);
    printf("Height : %.2f\n",twoPersonInfo[0].m_fHeight);

    // 使用指针打印结构数组
    struct Info * pInfo = twoPersonInfo;
    printf("-----------------------------------------------------------\n");
    printf("first person info as follow : \n");
    printf("First name : %s\n", (*pInfo).m_Person.m_sFirst);
    printf("Last name : %s\n", (*pInfo).m_Person.m_sLast);
    printf("Age : %d\n", (*pInfo).m_fAge);
    printf("Height : %.2f\n",(*pInfo).m_fHeight);

    printf("-----------------------------------------------------------\n");
    // 这里与数组不同的是，结构数组的数组名并不是地址
    pInfo = &twoPersonInfo[1];
    printf("Second person info as follow : \n");
    printf("First name : %s\n", pInfo->m_Person.m_sFirst);
    printf("Last name : %s\n", pInfo->m_Person.m_sLast);
    printf("Age : %d\n", pInfo->m_fAge);
    printf("Height : %.2f\n",pInfo->m_fHeight);
}


int main(int argc, char const *argv[])
{
    //code144();
    code146();
    system("pause");
    return 0;
}

char *s_gets(char *cpStr, int iSize)
{
    char *cpRetVal;
    char *cpFind;
    cpRetVal = fgets(cpStr, iSize, stdin);
    if (cpRetVal)
    {
        cpFind = strchr(cpStr, '\n');
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