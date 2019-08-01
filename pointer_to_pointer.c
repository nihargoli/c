/**
** Feel free to use the code. No restrictions.
** Added code to better understand pointers to integers
** and pointers to arrays.
** author: nihar goli; email: nihargoli@gmail.com
**/

#include <stdio.h>
#include <stdlib.h>

// Caller frees after allocation
void pointerAlloc(int **testP)
{

    *testP = (int *)malloc(sizeof(int));
    **testP = 10;

}

int main(int argc, char **argv)
{

    // Alloc this pointer in pointerAlloc()
    int *testP;
    pointerAlloc(&testP);
    printf("%d\n", *testP);
    free(testP);

}
