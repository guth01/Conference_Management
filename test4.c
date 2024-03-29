#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
    char str[20];
} 
StringList;

typedef struct
{
    int key;
    char str[20];
} 
Map;

void *mem(int size)
{
    void *ptr = (void *) malloc(size);
    if (ptr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;

}
int main(void)
{
    /*
    int n = 2;
    StringList *l;
    l = malloc(n * sizeof(StringList));
    if (l == NULL) 
    {
        printf("Not Enough Memory");
        return -1;
    }
    
    int len;
    for (int i = 0; i < n; i ++)
    {
        fgets(l[i].str, sizeof(l[i].str), stdin);
    }
    printf("%s", l[0].str);
    printf("%s", l[1].str);
    printf("%c", l[0].str[0]);
    printf("%c", l[1].str[0]);
    */
    int n = 3;
    int m;
    Map* d = (Map *) mem(n * sizeof(Map));
    for (int i = 0; i < n; i ++)
    {
        scanf("%d", &d[i].key);
        fflush(stdin);
        scanf("%s", d[i].str);
    }
    StringList *s = (StringList *) mem(n * sizeof(StringList));
    for (int i = 0; i < n; i ++)
    {

        if (d[i].key < 14) 
        {
            strcpy(s[0].str, d[i].str);
            // printf("%s", d[i].str);
        }
    }

    for (int i = 0; i < m; i ++)
    {
        printf("%s", s[i].str);
    }

    for (int i = 0; i < n; i ++) free(d[i].str);
    free(d);
    for (int i = 0; i < n; i ++) free(s[i].str);
    free(s);

}