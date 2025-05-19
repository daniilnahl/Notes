#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int top;
    int items[MAX];
} Stack;

void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[s->top--];
}

int main() {
    Stack s;
    s.top = -1;

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Popped: %d\n", pop(&s)); // 30
    printf("Popped: %d\n", pop(&s)); // 20
}
