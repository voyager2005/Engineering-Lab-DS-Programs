/**
 * WAP to arrange the characters in a given string in ascending order
 */

#include <stdio.h>
#include <string.h>

void main()
{
    // declaration and initialization 
    char s[200]; 
    int i, j;

    // reading the sentence from the user
    printf("Please enter the sentence: ");
    scanf("%s", &s);

    // counting the number of characters in the string and converting any uppercase characters into lower case characters
    int length = 0; 
    char ch = s[length]; 
    while(ch != '\0')
    {
        if((int)(s[length]) < 97 && (int)(s[length])!=32)
        {
            s[length] = (char)((int)(s[length]) + 32);
        }
        length++;
        ch = s[length];
    }

    // arranging the characters in ascending order
    for(i = 0; i < length; i++)
    {
        for(j = i; j < length; j++)
        {
            if((int)(s[j])<(int)(s[i]))
            {
                char temp = s[j]; 
                s[j] = s[i]; 
                s[i] = temp;
            }
        }
    }

    // displaying the sorted string
    printf("the sorted string is: %s", s);
}