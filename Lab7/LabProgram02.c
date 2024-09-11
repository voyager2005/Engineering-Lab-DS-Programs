#include <stdio.h>
#include <stdlib.h>

#define N 10 // Size of the array
#define MID (N / 2)

typedef struct {
    int arr[N];
    int front1, rear1;
    int front2, rear2;
} DoubleCircularQueue;

void initQueue(DoubleCircularQueue *q) {
    q->front1 = q->rear1 = -1;
    q->front2 = q->rear2 = MID;
}

int isFull1(DoubleCircularQueue *q) {
    return (q->rear1 + 1) % MID == q->front1;
}

int isFull2(DoubleCircularQueue *q) {
    return (q->rear2 + 1) % N == q->front2;
}

int isEmpty1(DoubleCircularQueue *q) {
    return q->front1 == -1;
}

int isEmpty2(DoubleCircularQueue *q) {
    return q->front2 == MID;
}

void insertcq1(DoubleCircularQueue *q, int value) {
    if (isFull1(q)) {
        printf("Queue 1 is full\n");
        return;
    }
    if (q->front1 == -1) {
        q->front1 = 0;
    }
    q->rear1 = (q->rear1 + 1) % MID;
    q->arr[q->rear1] = value;
    printf("Inserted %d into Queue 1\n", value);
}

void insertcq2(DoubleCircularQueue *q, int value) {
    if (isFull2(q)) {
        printf("Queue 2 is full\n");
        return;
    }
    if (q->front2 == MID) {
        q->front2 = MID + 1;
    }
    q->rear2 = (q->rear2 + 1) % N;
    q->arr[q->rear2] = value;
    printf("Inserted %d into Queue 2\n", value);
}

void deletecq1(DoubleCircularQueue *q) {
    if (isEmpty1(q)) {
        printf("Queue 1 is empty\n");
        return;
    }
    printf("Deleted %d from Queue 1\n", q->arr[q->front1]);
    if (q->front1 == q->rear1) {
        q->front1 = q->rear1 = -1;
    } else {
        q->front1 = (q->front1 + 1) % MID;
    }
}

void deletecq2(DoubleCircularQueue *q) {
    if (isEmpty2(q)) {
        printf("Queue 2 is empty\n");
        return;
    }
    printf("Deleted %d from Queue 2\n", q->arr[q->front2]);
    if (q->front2 == q->rear2) {
        q->front2 = q->rear2 = MID;
    } else {
        q->front2 = (q->front2 + 1) % N;
    }
}

void displaycq1(DoubleCircularQueue *q) {
    if (isEmpty1(q)) {
        printf("Queue 1 is empty\n");
        return;
    }
    printf("Queue 1 elements: ");
    int i = q->front1;
    while (i != q->rear1) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MID;
    }
    printf("%d\n", q->arr[q->rear1]);
}

void displaycq2(DoubleCircularQueue *q) {
    if (isEmpty2(q)) {
        printf("Queue 2 is empty\n");
        return;
    }
    printf("Queue 2 elements: ");
    int i = q->front2;
    while (i != q->rear2) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % N;
    }
    printf("%d\n", q->arr[q->rear2]);
}

int main() {
    DoubleCircularQueue q;
    initQueue(&q);
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert into Queue 1 \t 2. Insert into Queue 2 \t 3. Delete from Queue 1 \t 4. Delete from Queue 2\n");
        printf("5. Display Queue 1\n");
        printf("6. Display Queue 2\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert into Queue 1: ");
                scanf("%d", &value);
                insertcq1(&q, value);
                break;
            case 2:
                printf("Enter value to insert into Queue 2: ");
                scanf("%d", &value);
                insertcq2(&q, value);
                break;
            case 3:
                deletecq1(&q);
                break;
            case 4:
                deletecq2(&q);
                break;
            case 5:
                displaycq1(&q);
                break;
            case 6:
                displaycq2(&q);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
