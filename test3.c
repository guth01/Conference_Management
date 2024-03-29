// // pascals triangle
// #include <stdio.h>
// #include <stdlib.h>
// void pascal_trig(int *arr, int n, int j)
// {
//     int *temp;
//     temp = (void *) malloc((n + 2) * sizeof(int));
//     if (n == 0)
//         exit(0);

//     *arr = 0;
//     *(arr + 1) = 1;
//     *(arr + 2) = 0;

//     n --;
//     for (int i = 1; i < j; j ++)
//     {
//         temp[i] = arr[i - 1] + arr[i]; 
//     }
// }
// int main(void)
// {
//     int n;
//     scanf("%d", &n);
//     int arr[n + 2];

//     pascal_trig(arr, n, 4);


// }

// #include <stdio.h>

// void print_arr(int arr[], int *len) 
// {
//     for (int i = 0; i < *len; i ++) 
//         printf("%d ", arr[i]);
//     printf("\n");
// }

// void delete(int arr[], int *len, int n)
// {
//     if (n >= *len || (n < -*len && n < 0))
//         return;

//     *len = *len - 1;
//     for (int i = n; i < *len; i ++)
//     {
//         arr[i] = arr[i + 1];
//     }
// }

// int main(void)
// {
//     int len = 5;
//     int arr[] = {11, 22, 33, 44, 55};

//     int n;
//     scanf("%d", &n);
//     delete(arr, &len, n);
//     print_arr(arr, &len);
// }

// #include <stdio.h>
// int main(void)
// {
//     int n;
//     scanf("%i", &n);
//     int temp = 0;
//     while(n)
//     {
//         temp = (temp * 10) + (n % 10);
//         n /= 10;
//     }
//     printf("%i", temp);
// }
// #include <stdio.h>
// int main(void)
// {
//     int num;
//     scanf("%d", &num);

//     int bin = 0;
//     int i = 1;
//     while (num)
//     {
//         bin += i * (num % 2);
//         i *= 10;
//         num /= 2;
//     }
//     printf("%d", bin);
// }

// Insertion
// #include <stdio.h>

// void print_arr(int *arr, int *len)
// {
//     for (int i = 0; i < *len; i ++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }
// int main(void)
// {
//     int arr[6] = {1, 2, 3, 4, 5};
//     int len = 5;
//     int pos;
//     int val;
//     int i = 0;
//     scanf("%i %i", &pos, &val);

//     print_arr(arr, &len);
//     if (pos > len)
//         return -1;

//     for (i = len; i >= pos; i --)
//     {
//         arr[i + 1] = arr[i];
//     }

//     arr[i + 1] = val;
//     len ++;
//     print_arr(arr, &len);
// }

// #include <stdio.h>
// #define ARR_MAX 50


// int main(void)
// {
    
//     int arr[ARR_MAX];
//     int f_max = 0;
//     int s_max = 0;
//     int elem;


//     int n;
//     scanf("%i", &n);
//     for (int i = 0; i < n; i ++) 
//         scanf("%d", &arr[i]);

//     for (int i = 0; i < n; i ++)
//     {
//         elem = arr[i];

//         if (elem > f_max)
//         {
//             s_max = f_max;
//             f_max = elem;
//         }
//         else if (elem > s_max && elem < f_max) 
//         {
//             s_max = elem;
//         }
//     }
//     printf("%d-%d\n", f_max, s_max);
// }

// #include <stdio.h>
// #include <stdlib.h>

// void malloc_2d(int ***matrix, int m, int n)
// {
//     *matrix = (int **) malloc(m * sizeof(int *));
//     for (int i = 0; i < m; i ++) (*matrix)[i] = (int *) malloc(n * sizeof(int));
// }

// void print_2d(int **matrix, int m, int n)
// {
//     for (int i = 0; i < m; i ++)
//     {
//         printf("\n");
//         for (int j = 0; j < n; j ++)
//         {
//             printf("%i ", matrix[i][j]);
//         }
//     }
//     printf("\n");
// }

// void values_2d(int **matrix, int m, int n)
// {
//     for (int i = 0; i < m; i ++)
//     {
//         for (int j = 0; j < n; j ++)
//         {
//             scanf("%i", &matrix[i][j]);
//         }
//     }
// }

// void free_2d(int **matrix, int m)
// {
//     for (int i = 0; i < m; i ++)
//     {
//         free(matrix[i]);
//     }
// }

// int **matrix_multiplication(int **mat1, int m1, int n1, int **mat2, int m2, int n2)
// {
//     int **mat;
//     int sum;
//     if (n1 != m2)
//     {
//         printf("Invalid Dimensions");
//         return NULL;
//     }
    
//     malloc_2d(&mat, m1, n2);
//     for (int i = 0; i < m1; i ++)
//     {
//         for (int j = 0; j < n2; j ++)
//         {
//             sum = 0;
//             for (int k = 0; k < m2; k ++)
//             {
//                 sum += mat1[i][k] * mat2[k][j];
//             }
//             mat[i][j] = sum;
//         }
//     }


//     return mat;
// }
// int main(void)
// {
//     int **matrix1;
//     int **matrix2;
//     int **matrix;
//     int m1, n1, m2, n2;
//     scanf("%i %i %i %i", &m1, &n1, &m2, &n2);

//     malloc_2d(&matrix1, m1, n1);
//     malloc_2d(&matrix2, m2, n2);
//     values_2d(matrix1, m1, n1);
//     values_2d(matrix2, m2, n2);
//     print_2d(matrix1, m1, n1);
//     print_2d(matrix2, m2, n2);
//     matrix = matrix_multiplication(matrix1, m1, n1, matrix2, m2, n2);

//     print_2d(matrix1, m2, n2);
//     free_2d(matrix1, m1);
//     free_2d(matrix2, m2);
//     free_2d(matrix, m1);
//     matrix1 = NULL;
//     matrix2 = NULL;
//     matrix = NULL;
// }

// #include <stdio.h>
// int main(void)
// {
//     int a;
//     read:
//     scanf("%d", &a);
//     printf("%d ", a);
//     if (a > 2) goto read;
//     printf("--", a);
// }
#include <stdio.h>
int main(void)
{
    int a = 5;
    int b = 6;
    printf("%d", a & b);
}