/**
Complex Number arithmetics
*/

#include <stdio.h>
#include <stdbool.h>

void main()
{
    bool condition = true;
    char choice = 'y';
    do
    {
        // declaration and initlialization
        int user_input;

        // reading the operation to be performed from the user
        printf("Please enter the operation do be performed on the complex numbers: \n1. Additon\n2. Subtraction\n3.Multiplication\n");
        scanf("%d", &user_input);

        int r1, r2, i1, i2;
        printf("Please enter the real component of the first term: ");
        scanf("%d", &r1);
        printf("Please enter the imaginary component of the first term: ");
        scanf("%d", &i1);
        printf("Please enter the real component of the second term: ");
        scanf("%d", &r2);
        printf("Please enter the imaginary component of the second term: ");
        scanf("%d", &i2);

        if(user_input == 1)
            printf("addition: %d + %d i", (r1+r2), (i1+i2));
        else if(user_input == 2)
           printf("subtraction: %d + %d i", (r1-r2), (i1-i2));
        else if(user_input == 3)
            printf("multiplication: %d + %d i", (r1*r2 - i1*i2), (r1*i2 + r2*i1));
        else
            printf("Invalid option");

        printf("\nDo you wish to continue the program? [y/n]\n");
        scanf("%c", &choice);
        scanf("%c", &choice);

        printf("\n\n");
    }while(choice != 'n');
}
