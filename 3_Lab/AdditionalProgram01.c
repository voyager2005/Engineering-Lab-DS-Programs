/**
 * WAF Reverse to reverse the elements of an integer array using pointers. 
 * Access the elements of the array using dereference operator. 
 * Read the values from the keyboard in main function
 * Display the result in main function
 */

#include <stdio.h>

void main()
{
    // declaration and initialization 
    int n, i; 

    // reading the number of values from the user
    printf("Enter the number of values to be entered: "); 
    scanf("%d", &n);

    // creating an array of size n 
    int arr[n]; 
    int rev[n];

    // reading the array elements from the user
    printf("Please enter the array elements: \n"); 
    for(i = 0; i < n; i++)
    {
        printf("%d. ", (i+1));
        scanf("%d", &arr[i]);
    }

    // creating pointer for array 
    int* pfront = arr; 
    int* pback = arr + n -1;

    // displaying the array 
    printf("\nTraversing forwards: "); 
    for(; pfront <= pback; pfront++)
        printf("%d ", (*pfront));
    printf("\nTraversing backwards: "); 
    pfront = pfront - n; 
    for(; pback >= pfront; pback--)
        printf("%d ", (*pback));

}