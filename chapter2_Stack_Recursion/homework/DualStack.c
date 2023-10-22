#include <stdio.h>
#define N 100

typedef struct DualStack {
    int top1, top2;
    int array[N];
} DualStack;
void initDualStack(DualStack *ds) {
    ds->top1 = -1;
    ds->top2 = N;
}
void push(DualStack *ds, int stackNum, int value) {
    if (ds->top1 + 1 == ds->top2) { 
        //stack is full
        printf("Stack is full!\n");
        return;
    }
    if (stackNum == 0) {
        ds->array[++ds->top1] = value;
    } else if (stackNum == 1) {
        ds->array[--ds->top2] = value;
    }
}
int pop(DualStack *ds, int stackNum) {
    if ((stackNum == 0 && ds->top1 == -1) || (stackNum == 1 && ds->top2 == N)){
        //stack is empty
        printf("Stack is empty!\n");
        return -1;
    } 
    if (stackNum == 0) {
        return ds->array[ds->top1--];
    } else if (stackNum == 1) {
        return ds->array[ds->top2++];
    }
}
int main() {
    DualStack ds;
    initDualStack(&ds);

    push(&ds, 0, 1);
    push(&ds, 1, 2);
    push(&ds, 0, 3);
    push(&ds, 1, 4);
    push(&ds, 0, 5);

    printf("Pop from Stack 0: %d\n", pop(&ds, 0));
    printf("Pop from Stack 1: %d\n", pop(&ds, 1));
    printf("Pop from Stack 0: %d\n", pop(&ds, 0));
    printf("Pop from Stack 1: %d\n", pop(&ds, 1));
    printf("Pop from Stack 0: %d\n", pop(&ds, 0));

    return 0;
}
