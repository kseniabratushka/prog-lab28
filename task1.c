#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct 
{
    int data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) 
{
    s->top = -1;
}

bool isFull(Stack *s) 
{
    return s->top == MAX_SIZE - 1;
}

bool isEmpty(Stack *s) 
{
    return s->top == -1;
}

void push(Stack *s, int value) 
{
    if (isFull(s)) 
    {
        printf("Стек переповнений!\n");
        exit(1);
    }
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) 
    {
        printf("Стек порожній!\n");
        exit(1);
    }
    return s->data[s->top--];
}

void printStack(Stack *s, const char *name) 
{
    printf("%s: ", name);
    for (int i = 0; i <= s->top; i += 1) 
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

Stack sumStacks(Stack *s1, Stack *s2) 
{
    Stack temp, result;
    initialize(&temp);
    initialize(&result);

    while (!isEmpty(s1)) 
    {
        push(&temp, pop(s1));
    }

    while (!isEmpty(&temp)) 
    {
        int val1 = pop(&temp);
        int val2 = pop(s2);
        push(&result, val1 + val2);
        push(s1, val1);
    }

    return result;
}

int main() 
{
    system("chcp 65001");
    Stack s1, s2, result;
    initialize(&s1);
    initialize(&s2);

    push(&s1, 1);
    push(&s1, 2);
    push(&s1, 3);

    push(&s2, 4);
    push(&s2, 5);
    push(&s2, 6);

    printf("Вхідні стеки:\n");
    printStack(&s1, "Стек 1");
    printStack(&s2, "Стек 2");

    result = sumStacks(&s1, &s2);

    printf("\nРезультуючий стек (суми елементів):\n");
    printStack(&result, "Результат");

    printf("\nВідновлені вхідні стеки:\n");
    printStack(&s1, "Стек 1");
    printStack(&s2, "Стек 2");

    return 0;
}