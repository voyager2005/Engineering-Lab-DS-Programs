#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LEN 500

bool isPalRec(char str[], int s, int e)
{
    // If there is only one character left in the string
    if (s == e)
        return true;

    // If the extreme characters of the string do not match
    if (str[s] != str[e])
        return false;

    // trim the first and last element and check if the rest of the string is a substring
    if (s < e + 1)
        return isPalRec(str, s + 1, e - 1);

    return true;
}



int main()
{
    // declaration and initialization 
    char str[MAX_LEN];

    // reading the word from the user
    printf("Enter word: "); 
    gets(str); 

    // calculating the length of the array
    int length = 0; 
    char ch = str[length];
    while(ch != '\0')
    {
        length++; 
        ch = str[length];
    }

    // calling palindrome checking function
    if (isPalRec(str, 0, length-1))
        printf("Yes");
    else
        printf("No");

    return 0;
}