/*
To read a line of text and write it out backwards using Recursion
*/

#include <stdio.h>
#define MAX_LEN 500

/* Function to print reverse of the passed string */
void reverse(char *str)
{
    if (*str)
    {
        reverse(str + 1);
        printf("%c", *str);
    }
}

/* Driver program to test above function */
int main()
{
    char a[MAX_LEN];
    printf("Sentence: ");
    gets(a);
    reverse(a);
    return 0;
}