
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure for a stack
struct Stack {
    char data[MAX_SIZE];
    int top;
};

// Function to initialize a stack
void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if a stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to check if a stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto a stack
void push(struct Stack *stack, char item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = item;
}

// Function to pop an element from a stack
char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    char item = stack->data[stack->top];
    stack->top--;
    return item;
}

// Function to check the precedence of an operator
int precedence(char operator) {
    if (operator == '^')
        return 3;
    else if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '+' || operator == '-')
        return 1;
    else
        return -1;
}

// Function to convert an infix expression to prefix
void infixToPrefix(char infix[], char prefix[]) {
    struct Stack stack;
    initializeStack(&stack);
    int i, j = 0;
    int len = strlen(infix);

    for (i = len - 1; i >= 0; i--) {
        if (isalnum(infix[i])) {
            prefix[j++] = infix[i];
        } else if (infix[i] == ')') {
            push(&stack, infix[i]);
        } else if (infix[i] == '(') {
            while (!isEmpty(&stack) && stack.data[stack.top] != ')') {
                prefix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.data[stack.top] == ')') {
                pop(&stack);
            }
        } else {
            while (!isEmpty(&stack) && precedence(infix[i]) <= precedence(stack.data[stack.top])) {
                prefix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }

    while (!isEmpty(&stack)) {
        prefix[j++] = pop(&stack);
    }

    prefix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", strrev(prefix));


    return 0;
}
