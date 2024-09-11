#include <stdio.h>
#include <string.h>

#define MAX_SIZE 5

// Define the structure for the circular queue
typedef struct  {
    char queue[MAX_SIZE][100];
    int front;
    int rear;
}queue;

// Function to initialize the queue
void initializeQueue(queue *cq) {
    cq->front = -1;
    cq->rear = -1;
}

// Function to check if the queue is full
int isFull(queue *cq) {
    return (cq->front == (cq->rear + 1) % MAX_SIZE);
}

// Function to check if the queue is empty
int isEmpty(queue *cq) {
    return (cq->front == -1);
}

// Function to insert an element into the queue
void insertcq(queue *cq, char *str) {
    if (isFull(cq)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(cq)) {
        cq->front = 0;
    }
    cq->rear = (cq->rear + 1) % MAX_SIZE;
    strcpy(cq->queue[cq->rear], str);
    printf("Inserted: %s\n", str);
}

// Function to delete an element from the queue
void deletecq(queue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Deleted: %s\n", cq->queue[cq->front]);
    if (cq->front == cq->rear) {
        cq->front = -1;
        cq->rear = -1;
    } else {
        cq->front = (cq->front + 1) % MAX_SIZE;
    }
}

// Function to display the elements of the queue
void displaycq(queue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:\n");
    int i = cq->front;
    while (i != cq->rear) {
        printf("%s ", cq->queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%s\n", cq->queue[cq->rear]);
}

// Main function to test the circular queue
int main()
{
    queue q;
    q.front=-1;
    q.rear=-1;
    int ch, flag=1;
    char str[300];
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
                scanf("%s",str);
                insertcq(&q,str);
                break;
            case 2:
                deletecq(&q);
                break;
            case 3:
                displaycq(&q);
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

