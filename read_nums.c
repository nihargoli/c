/*
**
** Feel free to use the code. No restrictions.
** Added code to better understand pointers to integers
** and pointers to arrays.
** author: nihar goli; email: nihargoli@gmail.com
*/


/*
** spaces/new lines & chars are ignored by
** scanf("%d")
** This program helps you to understand how to take
** inputs in most of the coding challenges.
** First line of input one numner
** 3
** sencond line of input 3 space seperated numbers
** 1 2 3
*/

#include <stdio.h>

int main(int argc, char **argv)
{

    int scan_num;
    printf("Enter number\n");
    scanf("%d", &scan_num);
    int scan_nums[scan_num];
    for (int i = 0; i < scan_num; i++)
        scanf("%d", &scan_nums[i]);

     
    for (int i = 0; i < scan_num; i++)
        printf("%d", scan_nums[i]);

}
