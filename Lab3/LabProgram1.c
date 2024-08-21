/**
 * WAF Reverse to reverse the elements of an integer array using pointers.
 * Access the elements of the array using dereference operator.
 * Read the values from the keyboard in main function
 * Display the result in main function
 */

#include <stdio.h>

void reverse(int* begin, int* end)
{
    for(; begin<end; begin++, end--)
    {
        int temp = (*begin);
        (*begin) = (*end);
        (*end) = temp;
    }
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

    // display the array before reversing
    printf("before reversing array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // creating pointer for array
    int* pbegin = arr;
    int* pend = arr + n -1;

    // calling reverse function
    reverse(pbegin, pend);

    // displaying the reversed array
    printf("\nreversed array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
