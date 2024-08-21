#include <stdio.h>

#include <stdlib.h>
#include <stdbool.h>
#include <stdbool.h>
#define SIZE 5

static int top = -1;
int inp_array[SIZE];
void push();
void pop();
void show();
bool IsFull();
bool IsEmpty();

int main()
{
    int choice;

    while (true)
    {
        printf("\nWhich operation to perform on the stack:");
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);

        default:
            printf("\nInvalid choice!!");
        }
    }
}

void push()
{
    int x;

    if (IsFull())
    {
        printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", &x);
        top = top + 1;
        inp_array[top] = x;

    }
    else
    {
       printf("\nOverflow!!");
    }
}

void pop()
{
    if (!IsEmpty())
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nPopped element: %d", inp_array[top]);
        top = top - 1;
    }
}

void display()
{
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nElements present in the stack: \n");
        int i;
        for (i = top; i >= 0; --i)
            printf("%d\n", inp_array[i]);
    }
}

bool IsFull()
{
    bool condition = true;
    if(top == SIZE - 1)
        condition = false;
    return condition;
}

bool IsEmpty()
{
    bool condition = true;
    if(top == -1)
        condition = false;
    return condition;
}
