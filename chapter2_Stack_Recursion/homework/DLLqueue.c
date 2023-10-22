#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    struct Node* next;
    int val;
} Node;

typedef struct DLLQueue {
    Node* rear;
} DLLQueue;
void DLLQueueInit(DLLQueue *dq) {
    Node* head = (Node*) malloc(sizeof(Node));
    head->next = head;
    dq->rear = head;
}
void enQueue(DLLQueue *dq, int val) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = dq->rear->next;
    dq->rear->next = newNode;
    dq->rear = newNode;
}
int deQueue(DLLQueue *dq) {
    if (dq->rear->next == dq->rear) {
        return -1;
    }
    Node* head = dq->rear->next;
    Node* firstNode = head->next;
    int temp = firstNode->val;
    head->next = firstNode->next;
    // if only one element
    if (head->next == head) {
        dq->rear = head;
    }
    free(firstNode);
    return temp;
}

int main() {
    DLLQueue dq;
    DLLQueueInit(&dq);
    enQueue(&dq, 10);
    enQueue(&dq, 20);
    enQueue(&dq, 30);
    enQueue(&dq, 40);
    printf("Dequeued: %d\n", deQueue(&dq));
    printf("Dequeued: %d\n", deQueue(&dq));
    printf("Dequeued: %d\n", deQueue(&dq));
    printf("Dequeued: %d\n", deQueue(&dq));
    enQueue(&dq, 50);
    enQueue(&dq, 60);

    printf("Dequeued: %d\n", deQueue(&dq));
    printf("Dequeued: %d\n", deQueue(&dq));
    return 0;
}
