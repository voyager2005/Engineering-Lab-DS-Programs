/**
Implement a queue of integers. Inclde functions insertq,deleteq and display1
*/

#include <stdio.h>
#define MAX 2

typedef struct{
    int x[MAX];
    int front;
    int rear;
}queue;

void insertq(queue *, int);
void displayq(queue);
int deleteq(queue *);

void insertq(queue *q, int value){
    if(q->rear == MAX-1){
        printf("\nOverflow\n");
    }
    else{
        q->x[++q->rear] = value;
        if(q->front==-1){
            q->front = 0;
        }
    }
}

int deleteq(queue * q){
    int x;
    if(q->front==-1){
        printf("\nUnderflow!!!\n");
    }
    else if(q->front==q->rear){
        x=q->x[q->front];
        q->front=q->rear=-1;
        return x;
    }
    else{
        return q->x[q->front++];
    }
}

void displayq(queue q){
    int i;
    if(q.front == -1 && q.rear == -1){
        printf("\nQueue is Empty\n");
    }
    else{
        printf("\nQueue is: \n");
        for(i = q.front; i <= q.rear; i++){
            printf("%d\n", q.x[i]);
        }
    }
}

int main()
{
    queue q;
    q.front=-1;
    q.rear=-1;
    int ch,x,flag=1;
    while(flag)
    {
        printf("-   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -");
        printf("\n\n1. Insert Queue \t 2. Delete Queue \t 3. Display Queue \t 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the Element:");
                scanf("%d",&x);
                insertq(&q,x);
                break;
            case 2:
                x=deleteq(&q);
                printf("\nRemoved %d from the Queue\n",x);
                break;
            case 3:
                displayq(q);
                break;
            case 4:
                flag=0;
            break;
            default:
            printf("\nWrong choice!!! Try Again.\n");
        }
    }
    return 0;
}

