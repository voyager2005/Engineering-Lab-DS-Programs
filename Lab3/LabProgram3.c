#include <stdio.h>

void main()
{
    // using pointer to pointer
    int a[7] = {-1,4,5,-3,8};
    int* ptr = a;
    int* pp = &ptr;
    printf("array value: %d \n", a[0]);
    printf("using pointer: %d \n", (*ptr+1));
    printf("using pointer to pointer: %p\n",(*pp));
    printf("using pointer to pointer: %d",(*pp));
}
