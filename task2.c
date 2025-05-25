#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct 
{
    int data[MAX_SIZE];
    int front, rear;
} Queue;

void initialize(Queue *q) 
{
    q->front = q->rear = -1;
}

int isFull(Queue *q)
{
    return q->rear == MAX_SIZE - 1;
}

int isEmpty(Queue *q) 
{
    return q->front == -1 || q->front > q->rear;
}

void enqueue(Queue *q, int value) 
{
    if (isFull(q)) 
    {
        printf("Черга переповнена!\n");
        return;
    }
    if (isEmpty(q)) 
    {
        q->front = 0;
    }
    q->data[++q->rear] = value;
}

int dequeue(Queue *q) 
{
    if (isEmpty(q)) 
    {
        printf("Черга порожня!\n");
        return -1;
    }
    return q->data[q->front++];
}

Queue mergeQueues(Queue *q1, Queue *q2) 
{
    Queue result;
    initialize(&result);

    while (!isEmpty(q1) && !isEmpty(q2)) 
    {
        if (q1->data[q1->front] <= q2->data[q2->front]) 
        {
            enqueue(&result, dequeue(q1));
        } 
        else 
        {
            enqueue(&result, dequeue(q2));
        }
    }

    while (!isEmpty(q1)) 
    {
        enqueue(&result, dequeue(q1));
    }

    while (!isEmpty(q2)) 
    {
        enqueue(&result, dequeue(q2));
    }

    return result;
}

void printQueue(Queue *q) 
{
    for (int i = q->front; i <= q->rear; i += 1) 
    {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() 
{
    system("chcp 65001");
    Queue q1, q2, merged;
    initialize(&q1);
    initialize(&q2);

    enqueue(&q1, 1);
    enqueue(&q1, 3);
    enqueue(&q1, 5);

    enqueue(&q2, 2);
    enqueue(&q2, 4);
    enqueue(&q2, 6);

    printf("Черга 1: ");
    printQueue(&q1);
    printf("Черга 2: ");
    printQueue(&q2);

    merged = mergeQueues(&q1, &q2);

    printf("Об'єднана черга: ");
    printQueue(&merged);

    return 0;
}