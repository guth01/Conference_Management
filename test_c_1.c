// #include <stdio.h>

// int main(void){
// 	// int num;
	
// 	// scanf("%d", &num);
	
// 	// int i = 2;
// 	// printf("%d", 1);
// 	// while (num >= 2 && i < num){
// 	// 	if (num % i == 0) printf(", %d", i);
// 	// 	i ++;
// 	// }
// 	// printf(", %d\n", num);
// 	// return 0;
// }
// #include <ctype.h>
// #include <stdio.h>
// int myAtoi(char* s) {
//     int c;
//     int prev = ' ';
//     int prev_dig_flag = 0;
//     int num = 0;
//     int neg_flag = 0;
//     for (int i = 0; ((c = s[i]) != '\0'); i ++) {
//         // if (c == ' ');
// 		printf("%d|",c);
//         if (c == '-'){
// 			printf("- ");
//             neg_flag = 1;
// 		}
//         else if (prev_dig_flag && !(isdigit(c))){
// 			printf("-- ");
//             break;
// 		}
//         else {
//             num = num * 10 + (c - '0');
//             prev_dig_flag = 1;
// 			printf("---<%d> ", num);
//         }
//     }
//     if (neg_flag) 
//         return -num;
//     else 
//         return num;
// }
// int main(void){
// 	printf("%d", myAtoi("   -42"));

// }
// #include <stdio.h>
// #include <stdlib.h>
// int maxArea(int* height, int heightSize) 
// {
//     int n = sizeof(height);
//     int i = 0, j = n, area = 0, max_area = 0;
//     // Initialise two pointers

//     for (int x_dist, y_dist; i < n; i ++)
//     {
//         for (; i < j; j ++)
//         {
//             // x distance = difference between indices
//             x_dist = j - i; 
//             // y distance = absolute value of difference in values of height in the array
//             y_dist = abs(height[i] - height[j]);
//             // area = x distance * y distance
//             area = x_dist * y_dist;
//             // update area
//             if (area > max_area) max_area = area;
//         }
//     }
//     return max_area;
// #include <stdio.h>
// int main(void)
// {
//     int num1;
//     int *num2;

//     num1 = 5;
//     num2 = &num1;
//     printf("%d\n", *num2);
//     printf("%p\n", num2);
//     printf("%p\n", &num1);
//     printf("%p", &num2);



// }
// #include <stdio.h>
// #include <math.h>
// #include <stdbool.h>

// void num_to_dig_arr(int num, int *arr_add, int size)
// {
//     for (int i = size - 1; i >= 0; i --)
//     {
//         *(arr_add + i) = num % 10;
//         num = floor(num / 10);
//     }
// }
// void swap(int *first, int *second)
// {
//     int temp = *first;
//     *first = *second;
//     *second = temp;
// }
// void sort(int *arr_add, int size)
// {
//     // bubble sort algorithm
//     int change;
//     do
//     {
//         change = false;
        
//         for (int *curr, i = 0; i < size - 1; i ++)
//         {
//             curr = arr_add + i;
//             if (*(curr) > *(curr + 1))
//             {
//                 swap(curr, curr + 1);
//                 change = true;
//             }
//         }
//     }
//     while (change == true);
// }

// int main(void)
// {
//     int num;
//     int dig_arr[4] = {0};
//     scanf("%i", &num);
//     if (num < 0)
//     {
//         printf("Invalid");
//         return 0;
//     }
    
//     num_to_dig_arr(num, dig_arr, 4);
//     sort(dig_arr, 4);

//     printf("%i\n", (dig_arr[0] * 10) + dig_arr[2] + (dig_arr[1] * 10) + dig_arr[3]);
//     return 0;
// }

// int main(void)
// {
//     char *num;
//     scanf("%s", num);
//     printf("%c", num[2]);
// }

#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[] = {2, 9, 12, 15, 16, 24, 45, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int* odd = malloc(n * sizeof(int));
    int* even = malloc(n * sizeof(int));
    int odd_count = 0, even_count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even[even_count++] = arr[i];
        } else {
            odd[odd_count++] = arr[i];
        }
    }

    qsort(odd, odd_count, sizeof(int), compare);
    qsort(even, even_count, sizeof(int), compare);

    printf("Odd Players elements: ");
    for (int i = 0; i < odd_count; i++) {
        printf("%d ", odd[i]);
    }
    printf("\n");

    printf("Even Players elements: ");
    for (int i = 0; i < even_count; i++) {
        printf("%d ", even[i]);
    }
    printf("\n");

    free(odd);
    free(even);

    return 0;
}