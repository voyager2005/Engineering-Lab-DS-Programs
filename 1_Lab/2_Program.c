/**
 * WAP to find  triplets in the given array whose sum is 0
 * 
 * example: 
 * sample input: -1 -2 3 4 -7
 * output: 
 * -1 -2 3
 * 3 4 -7
 * 
 * sample input: 1 2 -2 0 1
 * output:
 * -1 0 1
 * 2 -2 0
 */

#include <stdio.h>
#include <stdbool.h>

void main()
{
    // declaration and initialization 
    int i; 
    int p, q, r; 


    // reading the number of values the user wants to enter: 
    int n; 
    printf("Please enter the number of values that are to be entered: "); 
    scanf("%d", &n); 

    // creating an array of size n
    int values[n]; 

    // reading the values from the user
    for(i = 0; i < n; i++)
    {
        printf("%d.", (i+1)); 
        scanf("%d", &values[i]);
    }

    // logic for finding distinct triplets whose sum is zero 
    printf("triplets are: \n");
    bool found = false; 
    for(p = 0 ; p < n; p++)
        for(q = p; q < n; q++)
            if(p!=q)
                for(r = q; r < n; r++)
                    if(r!=p && r!=q)
                        if(values[p] + values[q] + values[r] == 0)
                        {
                            printf("%d %d %d\n", values[p], values[q], values[r]);
                            found = true; 
                        }

    // final display statement
    if(!found)
        printf("There was no such triplet found");
}