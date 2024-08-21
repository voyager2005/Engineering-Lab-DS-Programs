#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct stack {
  char stck[MAX];
  int top;
}s;
void push(char item) {
  if (s.top == (MAX - 1))
    printf("Stack Full\n");
  else {
    s.top = s.top + 1;
    s.stck[s.top] = item;
  }
}
void pop() {
  if (s.top == -1)
    printf("Stack Empty\n");
  else
    s.top = s.top - 1;
}
int checkPair(char val1,char val2){
    return (( val1=='(' && val2==')' )||( val1=='[' && val2==']' )||( val1=='{' && val2=='}' ));
}
int checkBalanced(char expr[], int len){
    int i;
    for (i = 0; i < len; i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
          push(expr[i]);
        }
        else
        {
        if (s.top == -1)
            return 0;
        else if(checkPair(s.stck[s.top],expr[i]))
        {
            pop();
            continue;
        }
        return 0;
        }
    }
    return 1;
}
int main() {
    while(1)
    {
        char exp[MAX];
        printf("\n\nExpression: ");
  scanf("%s", exp);
  int i = 0;
  s.top = -1;
  int len = strlen(exp);
  checkBalanced(exp, len)?printf("Balanced"): printf("Not Balanced");

    }
   return 0;
}
