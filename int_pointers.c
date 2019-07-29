/**
** Feel free to use the code. No restrictions.
** Added code to better understand pointers to integers
** and pointers to arrays.
** author: nihar goli; email: nihargoli@gmail.com
**/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

    // auto storage specifier.
    // variable stored on stack; scope within this block; auto is by default prepended
    auto int num = 10;
    // Pointer to hold address of num
    int *ptr_num;
    // pointer to a pointer to hold address of ptr_num;
    int **dptr_num;
 
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    // a pointer to the beginning of an array
    int *ptr_arr;
    // array of 10 integer pointers
    int *ptr_arr_ints[10];

    int twod_arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    // pointer to array of block of 10 integers. An increment of
    // ++ptr_arr_block will point to the memory location after 10 integers.
    int (*ptr_arr_block)[10];
    // pointer to array of block of 3 integers. An increment of
    // ++ptr_arr_block will point to the memory location after 3 integers.
    // Essentially a 2d array with each row containing 3 elements
    int (*ptr_2darr_block)[3];

    // ===============================
    // Usage: pointers to integer
    ptr_num = &num;
    // dereference
    printf("num is %d\n", *ptr_num);
    // address of ptr_num
    printf("address held in ptr_num is %p\n", ptr_num);
    // ptr_num holds num address
    printf("address of num is %p\n", &num);

    dptr_num = &ptr_num; 
    // dereference
    printf("num is %d\n", **dptr_num);
    // address of ptr_num
    printf("address held in dptr_num is %p\n", dptr_num);
    // dptr_num holds ptr_num address
    printf("address of num is %p\n", &ptr_num);
    // ================================

    // ================================
    // Usage: pointers and arrays
    printf("elements in array are using array of pointers: "); 
    for(int i = 0; i < 10; i++)
    {
        // Notice the increment moves to next element.
        *(ptr_arr_ints + i) = &arr[i]; 
        // can also be written as
        //ptr_arr_ints[i] = &arr[i]; 
        printf("%d ", **(ptr_arr_ints+i));
    }
    printf("\n");

    ptr_arr = arr; // is same as ptr_arr = &arr, since arr holds the address of beginning of array
    printf("initial ptr_arr address is %p\n", ptr_arr);
    printf("elements in array using a pointer to an array: "); 
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", *ptr_arr++);
    }
    printf("\n");

    // ptr_2darr_block = point to array block
    ptr_2darr_block = twod_arr;
    // 2D Array of integers
    printf("elements in 2d array are: ");
    for (int j = 0; j < 3; j++)
        for (int k = 0; k < 3; k++)
           printf ("%d ",*(*(ptr_2darr_block + j) + k));
    printf("\n");

    // Declare two dimensional array using pointers
    int rows = 2, columns = 4;
    int **pointer2dArray;
    // non contigous memory allocation.
    pointer2dArray = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        *(pointer2dArray + i) = (int *)malloc(columns * sizeof(int));
    }
    printf("elements in 2d array are allocated wiht pointer non contigous mem: ");
    for (int j = 0; j < rows; j++) {
        for (int k = 0; k < columns; k++) {
            *(*(pointer2dArray + j) + k) = j + k;
            printf ("%d ",*(*(pointer2dArray + j) + k));
        }
    }
    printf("\n");
    for (int i = 0; i < rows; i++) {
        free(*(pointer2dArray + i));
    }
    free(pointer2dArray);
    pointer2dArray = NULL;
    // contiguos memory allocation
    pointer2dArray  = (int **)malloc(rows * sizeof(int *));
    *pointer2dArray = (int *)malloc(rows * columns * sizeof(int));
    //pointer2dArray[0] = (int *)malloc(rows * columns * sizeof(int));
    for (int i = 1; i < rows; i++) {
        pointer2dArray[i] = pointer2dArray[0] + (i * columns);
    }
    // since memory is contiguous access using array subscripts:
    printf("elements in 2d array are allocated wiht pointer contigous mem: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            pointer2dArray[i][j] = i + j;
            printf("%d ",pointer2dArray[i][j]);
         }
    }
    printf("\n");
    free(*pointer2dArray); 
    free(pointer2dArray); 
}
