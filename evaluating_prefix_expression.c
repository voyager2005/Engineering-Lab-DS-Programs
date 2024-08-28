#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

// structure for the stack implementation
typedef struct{
    int arr[MAX];
    int top;
}Stack;

// initializing the members of the stack
void initialize(Stack *s){
    s->top = -1;
}

// pushing into the stack
void push(Stack *s, int value){
    s->arr[++s->top] = value;
}

//popping from the stack
int pop(Stack *s){
    return s->arr[s->top--];
}

int evaluate(char *expression){
    // declaration and initialization
    Stack s;
    initialize(&s);
    int i;

    //evaluating the expression
    for(i = 0; expression[i] != '\0'; i++){
        char ch = expression[i];

        if(isdigit(ch)){
            push(&s, expression[i] - '0');
        }
        else{
            int op1 = pop(&s);
            int op2 = pop(&s);
            switch(ch){
                case '+':
                    push(&s, op1 + op2);
                    break;
                case '-':
                    push(&s, op1 - op2);
                    break;
                case '*':
                    push(&s, op1 * op2);
                    break;
                case '/':
                    push(&s, op1 / op2);
                    break;
                default:
                    printf("Invalid operator\n");
                    return -1;
            }
        }
    }

    return pop(&s);
}

int main() {
    char expression[MAX];
    printf("Please enter an expression: ");
    gets(expression);
    int result = evaluate(strrev(expression));
    printf("Result: %d\n", result);
    return 0;
}


