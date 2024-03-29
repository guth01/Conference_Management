#include <stdio.h>
#include <string.h>
#define OUT_TEXT "\n\nprogram executed successfully"

// int main(){
//     int fahr;
//     char c, *str;
//     str = "";
//     for (fahr = 0; fahr <= 300; fahr = fahr + 100) {
//         c = getchar();
//         strncat(str,c,1);
//     };
//     printf("%s\n",str);
//     printf(OUT_TEXT);
// }

// int main(){
//     int c;
//     int n_white, n_digit, n_other;

//     n_digit = n_white = n_other = 0;
//     while ((c = getchar()) != EOF){
//         if (c == '\n'){
//             printf("\nwhite : %d digit : %d other : %d", n_white, n_digit, n_other);
//             // n_white, n_digit, n_other = 0, 0, 0;
//             break;
//         }
//         else if (c == '\t' || c == ' ') ++ n_white;
//         else if (c >= '0' && c <= '9') ++ n_digit;
//         else ++ n_other;
//     }
//     printf(OUT_TEXT);
// }
// int main(){
//     int c;
//     int i;
//     int n_white, n_digit, n_other;
//     int n_list[10];
//     n_digit = n_white = n_other = 0;

//     for (i = 0; i < 10; ++ i) n_list[i] = 0;

//     while ((c = getchar()) != EOF){
//         if (c == '\n'){
//             printf("\nwhite : %d digit : %d other : %d", n_white, n_digit, n_other);
//             for (i = 0; i < 10; ++i) {
//                 printf("\n[%d] - %d", i, n_list[i]);
//             }
//             // n_white, n_digit, n_other = 0, 0, 0;
//             break;
//         }
//         else if (c == '\t' || c == ' ') ++ n_white;
//         else if (c >= '0' && c <= '9') {
//             ++ n_list[c - '0'];
//             ++ n_digit;
//         }
//         else ++ n_other;
//     }
//     printf(OUT_TEXT);
// }

// int main(){
//     printf("\n%s::\n",(1 == 0) ? "true" : "false");
//     printf(OUT_TEXT);
//     return 0;
// }

// #define IN 1
// #define OUT 0

// int main(){
//     int c;
//     int flag = OUT;



//     while ((c = getchar()) != EOF && (c != '\n')){
//         if (c == '\t' || c == ' '){
//             flag = OUT;
//         }
//         else{
//             if (flag == OUT){
//                 flag = IN;
//                 printf("\n");
//             }
//             printf("-");
//         }
//     }

//     printf(OUT_TEXT);
//     return 0;
// }

// #define IN 1
// #define OUT 0
// // histogram vertical
// int main(){
//     int c;
//     int i = 0;
//     int c_arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//     int len = 0;
//     int status = OUT;
//     int max_len = 0;

//     while ((c = getchar()) != EOF && c != '\n'){
//         if (c == ' ' || c == '\t'){
//             if (status == IN){
//                 c_arr[i] = len;
//                 ++ i;
//                 if (len > max_len){
//                     max_len = len;
//                 }
//                 len = 0;
//             }
//             status = OUT;
//         }
//         else{
//             ++ len;
//             if (status == OUT){
//                 status = IN;
//             }
//         }
//     }
//     c_arr[i] = len;
//     ++ i;
//     if (len > max_len){
//         max_len = len;
//     }

//     // printf("%d :::", max_len);
//     // for (int k = 0; k <= 4; ++ k){
//     //     printf("%d ", c_arr[k]);
//     // }
//     for (; max_len > 0; -- max_len){
//         for (int j = 0; j < i; ++ j){
//             if (c_arr[j] >= max_len){
//                 printf("*");
//             }
//             else printf(" ");
//         }
//         printf("\n");

//     }

//     printf(OUT_TEXT);
//     return 0;
// }
// #include <stdio.h>

// void insertionSort(int arr[], int n) {
//     int i, key, j;
//     for (i = 1; i < n; i++) {
//         key = arr[i];
//         j = i - 1;

//         printf("Iteration %d: key = %d\n", i, key);

//         /* Move elements of arr[0..i-1], that are
//         greater than key, to one position ahead
//         of their current position */
//         while (j >= 0 && arr[j] > key) {
//             printf("  Moving %d to position %d\n", arr[j], j+1);
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         printf("  Inserting %d at position %d\n", key, j+1);
//         arr[j + 1] = key;
//     }
// }

// void printArray(int arr[], int n) {
//     int i;
//     for (i = 0; i < n; i++)
//         printf("%d ", arr[i]);
//     printf("\n");
// }

// int main() {
//     int arr[] = {12, 11, 13, 5, 6};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     printf("Initial array: ");
//     printArray(arr, n);

//     insertionSort(arr, n);

//     printf("Sorted array: ");
//     printArray(arr, n);

//     return 0;
// }
// #include <stdio.h>

// void num_to_dig_arr(int num, int arr[], int size) {
//     for (int i = size - 1; i >= 0; i--) {
//         arr[i] = num % 10;
//         num /= 10;
//     }
// }

// void sort(int arr[], int size) {
//     for (int i = 0; i < size; i++) {
//         for (int j = i + 1; j < size; j++) {
//             if (arr[i] > arr[j]) {
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
// }

// int smallestTwoDigitSum(int num) {
//     int a = num / 1000;
//     int b = (num / 100) % 10;
//     int c = (num / 10) % 10;
//     int d = num % 10;

//     int sum1 = a + b;
//     int sum2 = a + c;
//     int sum3 = a + d;
//     int sum4 = b + c;
//     int sum5 = b + d;
//     int sum6 = c + d;

//     int smallest = sum1;
//     if (sum2 < smallest) smallest = sum2;
//     if (sum3 < smallest) smallest = sum3;
//     if (sum4 < smallest) smallest = sum4;
//     if (sum5 < smallest) smallest = sum5;
//     if (sum6 < smallest) smallest = sum6;

//     return smallest;
// }

// int main(void) {
//     int num;
//     int dig_arr[4] = {0};
//     // scanf("%i", &num);
//     // if (num < 0) {
//     //     printf("Invalid");
//     //     return 0;
//     // }
//     for (num = 1000; num < 2000; num ++)
//     {
//         num_to_dig_arr(num, dig_arr, 4);
//         sort(dig_arr, 4);

//         int sum = (dig_arr[0] * 10) + dig_arr[2] + (dig_arr[1] * 10) + dig_arr[3];
//         //printf("%i\n", sum);

//         int smallestSum = smallestTwoDigitSum(num);
//         //printf("The smallest possible two-digit sum is: %d\n", smallestSum);

//         if (sum == smallestSum);
//         else {
//             printf("The sums are not equal.\n");
//             printf("num : %d, my sum : %d, actual sum : %d\n", num, smallestSum);
            
//         }
//     }

//     return 0;
// }
// #include <stdio.h>
// void fn(int *x, int *y)
// {
//     int sum = *x + *y;
//     int prod = *x * *y;
//     *x = sum;
//     *y = prod;
// }
// int main(void)
// {
//     int a = 5, b = 10;
//     printf("%d, %d\n", a, b);
//     fn(&a, &b);
//     printf("%d, %d\n", a, b);
// }

#include <stdio.h>
#include <stdlib.h>
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
int main(void)
{
    char str[1000] = "12346";
    char str2[10] = "avbs";
    strcat(str, str2);
    printf("%s", str);
}