/**
 * WAF Smallest to find the smallest element in an array using pointer. 
 * Create a dynamically allocated array and read teh values from keyboard in main. 
 * Display the result in the main function
 */

#include <stdio.h>

int* smallest(int* walk, int* end, int* smallest)
{
    for(; walk<= end; walk++)
    {
        if((*smallest) > (*walk))
        {
            smallest = walk;
        }
    }

    return smallest; 
}

void main()
{
    // declaration and initialization 
    int n, i; 

    // reading the number of values from the user
    printf("Enter the number of values to be entered: "); 
    scanf("%d", &n);

    // creating an array of size n 
    int arr[n]; 

    // reading the array elements from the user
    printf("Please enter the array elements: \n"); 
    for(i = 0; i < n; i++)
    {
        printf("%d. ", (i+1));
        scanf("%d", &arr[i]);
    }

    // creating pointers to the array
    int* pbegin = arr; 
    int* pend = arr + n -1; 
    int* psmallest = arr; 

    // calling the function 
    psmallest = smallest(pbegin, pend, psmallest);

    // displaying the smallest value in the array
    printf("Smallest element in the array is: %d", (*psmallest));
}