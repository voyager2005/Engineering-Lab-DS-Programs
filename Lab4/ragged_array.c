#include <stdio.h>
#include <stdlib.h>

void main()
{
    int rowNum, colNum, i, j;
    int ** table;
    printf("\nEnter the number of rows: ");
    scanf("%d", &rowNum);
    table = (int**) calloc(rowNum + 1, sizeof(int*));
    for(i = 0; i < rowNum; i++)
    {
        printf("Enter the size of the %d row: ", (i+1));
        scanf("%d", &colNum);
        table[i] = (int*)calloc(colNum+1, sizeof(int));
        printf("Enter %d row elements: \n", (i+1));
        for(j = 1; j <= colNum; j++)
        {
            scanf("%d", &table[i][j]);
        }

        table[i][0] = colNum;
        printf("size of the row number %d is = %d\n", i+1, table[i][0]);
    }

    table[i] = NULL;
    for(i = 0; i < rowNum; i++)
    {
        printf("Displaying row %d elements: ", i+1);
        for(j = 1; j < *table[i]; j++)
        {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}
