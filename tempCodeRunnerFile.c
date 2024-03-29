#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void showTime()
{
    time_t t = time(0);
    struct tm* now = localtime(&t);
    printf("\n\nThe code was executed at: %d-%d-%d %d:%d:%d\n",
           now->tm_year + 1900, now->tm_mon + 1, now->tm_mday,
           now->tm_hour, now->tm_min, now->tm_sec);
}
typedef struct
{
    int eno;
    char ename[15];
    int esalary;
}
Employee;

int checked_inp(const char inp[])
{
    int c;
    int num = 0;
    for (int i = 0; (c = inp[i]) != '\0'; i ++)
    {
        if (!isalnum(c))
        {
            printf("Invalid");
            exit(0);
        }
        num = num * 10 + (c - '0');
    }
    return num;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    getchar();
    Employee* emp;
    emp = (void* ) malloc(n * sizeof(Employee));
    char temp[20];
    
    for (int i = 0; i < n; i ++)
    {
        scanf("%d", &(emp + i) -> eno);
        getchar();
        scanf("%[^\n]s", (emp + i) -> ename);
        getchar();
        scanf("%[^\n]s", temp);
        getchar();
        (emp + i) -> esalary = checked_inp(temp);
    }
    
    int highestSal = 0;
    char highestName[15];
    int highestENo;
    bool cannotDetermine = false;
    for (int i = 0; i < n; i ++)
    {
        if (highestSal < ((emp + i) -> esalary))
        {
            highestSal = ((emp + i) -> esalary);
            highestENo = ((emp + i) -> eno);
            strcpy(highestName, (emp + i) -> ename);
            
            cannotDetermine = false;
        }
        else if (highestSal == (emp + i) -> esalary)
        {
            cannotDetermine = true;
        }
    }
    if (cannotDetermine == true)
    {
        printf("Cannot Determine");
    }
    else 
    {
        printf("%d,%s,%d", highestENo, highestName, highestSal);
    }
    free(emp);
}