/*
**
** Feel free to use the code. No restrictions.
** Added code to better understand pointers to functions
** base class and derived class concepts of C++ can be
** be exploited using structures and function pointers
** and pointers to arrays.
** author: nihar goli; email: nihargoli@gmail.com
**/

#include<stdio.h>

int my_pointed_fun(int test_var)
{
    printf("test var is %d\n", test_var);
}

int my_pointed_fun1(int test_var)
{
    printf("test var after increment is %d\n", ++test_var);
}

typedef int (*procFn)(int test);

typedef struct listFunPointers
{
    int abc;
    procFn nameFn;
    procFn incFn;

}listFunPointers;

int main()
{

   listFunPointers lfp;
   lfp.nameFn = my_pointed_fun;
   lfp.nameFn(10); 
   lfp.incFn = my_pointed_fun1;
   lfp.incFn(10); 

}
