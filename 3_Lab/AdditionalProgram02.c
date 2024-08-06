#include <stdio.h> 
#include <string.h>
#include <stdbool.h>
#define MAX_LEN 500

void main()
{
    // declaration and initialization
    char s[MAX_LEN]; 

    // reading the sentence from the user
    printf("Enter the sentence: "); 
    gets(s);

    // calculating the length of the string
    char ch = s[0]; 
    int length = 0; 
    while(ch != '\0')
    {
        length++;
        ch = s[length];
    }

    // creating the array pointers for the string
    char* pbegin = s; 
    char* pend = s + length -1; 

    // checking if the string is a palindrome
    bool palindrome = true;
    for(; pbegin < pend; pbegin++, pend--)
        if((*pbegin)!=(*pend))
        {
            palindrome = false; 
            break; 
        }
    
    // final display statement
    printf(palindrome?"It is a palindrome":"Not a palindrome"); 
}