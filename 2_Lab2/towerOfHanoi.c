/**
WAP to calculate the number of steps required to move n disks
using the tower of hanoi concept
*/

/**
Find the first capital letter in a string using recursion
*/

#include <stdio.h>
#include <math.h>

// C recursive function to solve tower of hanoi puzzle
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

void main()
{
    // declaration and initialization
    int disks;

    // reading the number of disks from the user
    printf("How many disks to be moved: ");
    scanf("%d", &disks);

    towerOfHanoi(disks, 'A', 'C', 'B');

    // displaying the number of steps required for moving the disks
    int moves = (int)(pow(2, disks)) - 1;
    printf("\n\nNo of disks movement: %d\n\n", moves);
}