#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100
#define MAX_EXPRESSION_LENGTH 100

// Structure for a stack
struct Stack {
    int top;
    int array[MAX_SIZE];
};

// Function to initialize a stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char *expression) {
    struct Stack stack;
    initialize(&stack);
    int i;

    for (i = 0; expression[i] != '\0'; i++)
    {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator\n");
                    return -1;
            }
        }
    }

    return pop(&stack);
}

int main() {
    char expression[MAX_EXPRESSION_LENGTH];
    printf("Please enter an expression: ");
    gets(expression);
    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);
    return 0;
}
