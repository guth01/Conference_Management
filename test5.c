#include <stdio.h>

typedef struct
{
    int key;
    char *value;
}
Map;

Map *find_map(Map *maps, int n, int key)
{
    for (int i = 0; i < n; i ++)
    {
        if (maps[i].key == key)
        {
            return &maps[i];
        }
    }
    return NULL;
}
int main(void)
{
    Map m[2] = {{1, "abc"}, {2, "hey"}};
    printf("%s", find_map(m, 2, 2)->value);
    return 0;
}