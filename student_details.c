#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int no;
    char name[15];
    float marks[5];
}
Student;

void *mem(int size)
{
    void *ptr = (void *) malloc(size);
    if (ptr == NULL)
    {
        fprintf(stderr, "Memory Allocation Failed");
        exit(EXIT_FAILURE);
    }
    return ptr;
}
int main(void)
{
    int n;
    scanf("%d", n);
    Student *s = (Student *) mem(n * sizeof(Student)) ;
    for (int i = 0; i < n; i ++)
    {
        scanf("%d", );
        fflush(stdin);
        scanf("%s", s -> name);
    }
    return 0;
}