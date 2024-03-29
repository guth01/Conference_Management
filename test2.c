#include <stdio.h>
#include <string.h>

int strlength(char *str)
{
    int n;
    for (n = 0; *str != '\0'; n ++, *str ++);
    return n;
}


void swapped(char *from, char *to)
{
    int temp = *from;
    *from = *to;
    *to = temp;
}

void reverse(char *str, int len)
{
    int half = len / 2;
    for (int i = 0; i < half; i ++, str ++)
    {
        swapped(str, str + len - i - 1);
    }
}

void insertion_sort(char str[], int len)
{
    int i, j, c;
    for (i = 1; i < len; i ++)
    {
        j = i - 1;
        c = str[i];
        while (j >= 0 && c < str[j])
        {
            str[j + 1] = str[j];
            j --;
        }
        str[j + 1] = c;
    }
}

void bubble_sort(char str[], int len)
{
    int swap_flag = 0;
    for (int i = 0; i < len; i ++)
    {
        for (int j = 1; j < len - 1; j ++)
        {
            if (str[i] > str[j])
            {
                swapped(&str[i], &str[j]);
                swap_flag = 1;
            }
        }
        if (swap_flag == 0)
            break;
    }
}
void print_matrix(int **arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int** matrix_multiplication(int **arr1, int m1, int n1, int **arr2, int m2, int n2, int **result)
{
    if (n1 != m2)
    {
        printf("Invalid");
        return NULL;
    }
    
    int **arr = (int **)malloc(m1 * sizeof(int *));
    for (int i = 0; i < m1; i ++)
    {
        arr[i] = (int *)malloc(n2 * sizeof(int));
    }
    
    int sum;
    
    for (int i = 0; i < m1; i ++)
    {
        for (int j = 0; j < n2; j ++)
        {
            sum = 0;
            for (int n = 0; n < m2; n ++)
            {
                sum += arr1[i][n] * arr2[n][j];
            }
            arr[i][j] = sum;
        }
    }
    print_matrix(arr, m1, n2);
    result = arr;
    return arr;
}

int main()
{
    // Test case 1
    int *arr1[2] = { (int[]){1, 2, 3}, (int[]){4, 5, 6} };
    int *arr2[3] = { (int[]){7, 8}, (int[]){9, 10}, (int[]){11, 12} };
    int *result1[2] = { (int[]){0, 0}, (int[]){0, 0} };

    printf("Initial matrices:\n");
    printf("Matrix 1:\n");
    print_matrix(arr1, 2, 3);
    printf("Matrix 2:\n");
    print_matrix(arr2, 3, 2);

    matrix_multiplication(arr1, 2, 3, arr2, 3, 2, result1);

    printf("Resulting matrix:\n");
    print_matrix(result1, 2, 2);

    // Test case 2
    int *arr3[3] = { (int[]){13, 14}, (int[]){15, 16}, (int[]){17, 18} };
    int *arr4[2] = { (int[]){19, 20, 21}, (int[]){22, 23, 24} };
    int *result2[3] = { (int[]){0, 0, 0}, (int[]){0, 0, 0}, (int[]){0, 0, 0} };

    printf("Initial matrices:\n");
    printf("Matrix 3:\n");
    print_matrix(arr3, 3, 2);
    printf("Matrix 4:\n");
    print_matrix(arr4, 2, 3);

    matrix_multiplication(arr3, 3, 2, arr4, 2, 3, result2);

    printf("Resulting matrix:\n");
    print_matrix(result2, 3, 3);

    return 0;
}

// int main(void)
// {
//     char str[100];
//     scanf("%[^\n]s", str);
//     int len = strlength(str);
//     printf("%s\n", str);
//     reverse(str, len);
//     printf("%s\n", str);
//     insertion_sort(str, len);
//     printf("%s\n", str);
//     bubble_sort(str, len);
//     printf("%s\n", str);
// }

