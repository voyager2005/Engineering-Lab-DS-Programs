/**
 * 
 */

#include <stdio.h> 
#include <stdlib.h>

void main()
{
    // declaration and initialization 
    int i, j, row, col, n; 
    int *a, *b, *sum;

    // reading the order of the matrix from the user
    printf("How many rows: "); 
    scanf("%d", &row); 
    printf("How many columns: "); 
    scanf("%d", &col); 
    n = row*col; 

    // creating dynamic memory 
    a = (int*)malloc(n* sizeof(int));
    b = (int*)malloc(n* sizeof(int));
    sum = (int*)malloc(n* sizeof(int));
    int c[row][col]; 

    // reading the elements of the array from the user
    // reading the elements of matrix 1 from the user
    printf("Enter elements of Matrix 1: "); 
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf("%dx%d", i, j);
            scanf("%d", (*(a+i)+j));
        }
    }
    // reading the elements of matrix 2 from the user
    printf("Enter elements of Matrix 2: "); 
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf("%dx%d", i, j);
            scanf("%d", (*(b+i)+j));
        }
    }

    // calculating the sum of the matrix
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
           c[i][j]= (*(a + i) + j) + (*(b + i) + j);
           printf("%d", c); 
        }
        printf("\n");
    }
}