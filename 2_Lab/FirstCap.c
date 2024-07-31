/*
WAP to find the first capital letter in a string using recursion 
*/

#include <stdio.h>
#include <string.h>
#define MAX_LEN 500

char caps(char s[], int index)
{
    char ch = s[index];
    if(ch == '\0')
        return '!';

    if((int)(ch) >= 65 && (int)(ch)<=90)
        return ch; 
    else
        caps(s, index+1);
}

void main()
{
    // declaration and initialization 
    char str[MAX_LEN];

    // reading the string from the user
    printf("Sentence: ");
    gets(str);

    // calling the function 
    char cap = caps(str, 0);

    // display statement 
    if (cap=='!')
        printf("No capital letter found"); 
    else
        printf("%c was the first capital letter encountered", cap); 
    
}