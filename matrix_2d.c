#include <stdio.h>
#include <stdlib.h>

void malloc_2d(int ***matrix, int m, int n)
{
    *matrix = (int **) malloc(m * sizeof(int *));
    for (int i = 0; i < m; i ++) (*matrix)[i] = (int *) malloc(n * sizeof(int));
}

void print_2d(int **matrix, int m, int n)
{
    for (int i = 0; i < m; i ++)
    {
        printf("\n");
        for (int j = 0; j < n; j ++)
        {
            printf("%i ", matrix[i][j]);
        }
    }
    printf("\n");
}

void values_2d(int **matrix, int m, int n)
{
    for (int i = 0; i < m; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            scanf("%i", &matrix[i][j]);
        }
    }
}

void free_2d(int **matrix, int m)
{
    for (int i = 0; i < m; i ++)
    {
        free(matrix[i]);
    }
}

int **matrix_multiplication(int **mat1, int m1, int n1, int **mat2, int m2, int n2)
{
    int **mat;
    int sum;
    if (n1 != m2)
    {
        printf("Invalid Dimensions");
        return NULL;
    }
    
    malloc_2d(&mat, m1, n2);
    for (int i = 0; i < m1; i ++)
    {
        for (int j = 0; j < n2; j ++)
        {
            sum = 0;
            for (int k = 0; k < m2; k ++)
            {
                sum += mat1[i][k] * mat2[k][j];
            }
            mat[i][j] = sum;
        }
    }


    return mat;
}
int main(void)
{
    int **matrix1;
    int **matrix2;
    int **matrix;
    int m1, n1, m2, n2;
    scanf("%i %i %i %i", &m1, &n1, &m2, &n2);

    malloc_2d(&matrix1, m1, n1);
    malloc_2d(&matrix2, m2, n2);
    values_2d(matrix1, m1, n1);
    values_2d(matrix2, m2, n2);
    print_2d(matrix1, m1, n1);
    print_2d(matrix2, m2, n2);
    matrix = matrix_multiplication(matrix1, m1, n1, matrix2, m2, n2);

    print_2d(matrix1, m2, n2);
    free_2d(matrix1, m1);
    free_2d(matrix2, m2);
    free_2d(matrix, m1);
    matrix1 = NULL;
    matrix2 = NULL;
    matrix = NULL;
}