/*
WAP to perform binary search using recursion
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int bubbleSort(int a[], int n)
{
    
    return a; 
}

bool binarySearch(int low, int high, int key, int a[])
{
    int mid; 
    if(low>high)
    {
        return false;
    }
    else
    {
        mid = (low+high)/2;
        if(key == a[mid])
            return(true); 
        else if(key <a[mid])
            return(binarySearch(low, mid-1, key, a));
        else
            return(binarySearch(mid+1, high, key, a));
    }
}


void main()
{
    int n, i, j, position, key;
    bool value; 
    printf("Enter the number of items: "); 
    scanf("%d", &n); 
    int a[n]; 
    printf("Please enter the values: "); 
    for(i = 0; i < n; i++)
    {
        printf("%d.", (i+1));
        scanf("%d", &a[i]); 
    }
    for(i = 0; i< n; i++)
        for(j = i; j<n; j++)
            if(a[j] > a[i])
            {
                int temp = a[j]; 
                a[j] = a[i]; 
                a[i] = temp; 
            }
    printf("Please enter the element to search for: ");
    scanf("%d", &key); 
    printf("%s", (binarySearch(0, n-1, key, a))?"key was found": "key was not found");
}