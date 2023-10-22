#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* create() {
    Node* head = malloc(sizeof(Node));
    if (head == NULL) {
        exit(1);
    }
    head->next = NULL;
    return head;
}
void insert(Node* head, int data) {
    Node* new = malloc(sizeof(Node)), *preNode, *nextNode;
    new->data = data;

    Node* current = head;
    while (current->next != NULL) {
        if (data <= current->next->data) {
            break;
        }
        current = current->next;
    }
    preNode = current;
    nextNode = current->next;

    preNode->next = new;
    new->next = nextNode;
}
void verify(Node* head) {
    int f = 1, last;
    Node* current = head;
    while (current->next != NULL) {
        if (current != head && current->data > current->next->data) {
            f = 0;
        }
        current = current->next;
    }
    if (f == 1)
        printf("Verification success!\n");
    else
        printf("Verification failed!\n");
}
void dump(Node* head) {
    Node* current = head->next;
    printf("Current list contains: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void revert(Node* head) {
    Node* pre = NULL, *next, *current = head->next;
    while (current) {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    head->next = pre;
}
void delete(Node* head, int data) {
    Node *current = head -> next, *pre = head;
    while (current) {
        if (current->data == data) {
            pre->next = current->next;
        }
        else
            pre = current;
        current = current->next;
    }
}
void sum(Node* head) {
    int sum = 0;
    Node* current = head->next;
    while (current) {
        sum += current->data;
        current = current->next;
    }
    printf("The sum of list is %d\n", sum);
}
void count(Node* head) {
    Node* current = head->next;
    int c = 0;
    while (current) {
        c++;
        current = current->next;
    }
    printf("The count of list is %d\n", c);
}
void destroy(Node* head) {
    Node* current = head;
    while (current->next) {
        Node* temp = current->next;
        free(current);
        current = temp;
    }
    printf("Successfully destory the list!\n"); 
}
int main()
{
    Node* head = create();
    insert(head, 20);
    insert(head, 90);
    insert(head, 70);

    verify(head);
    dump(head);

    revert(head);
    dump(head);
    
    insert(head, 95);
    delete(head, 90);
    dump(head);
    sum(head);
    
    delete(head, 10);
    insert(head, 98);
    count(head);
    sum(head);
    destroy(head);
}