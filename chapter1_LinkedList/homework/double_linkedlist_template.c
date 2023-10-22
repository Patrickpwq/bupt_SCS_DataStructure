//双向循环带头节点

#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

// 初始化链表
DNode* initList() {
    DNode* head = (DNode*)malloc(sizeof(DNode));
    if (!head) {
        exit(1);
    }
    head->prev = head;
    head->next = head;
    return head;
}

// 创建新节点
DNode* createNode(int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    if (!newNode) {
        exit(1);
    }
    newNode->data = data;
    newNode->prev = newNode;
    newNode->next = newNode;
    return newNode;
}

// 插入到给定节点之后
void insertAfter(DNode* node, int data) {
    DNode* newNode = createNode(data);
    newNode->next = node->next;
    newNode->prev = node;
    node->next->prev = newNode;
    node->next = newNode;
}

// 删除节点
void deleteNode(DNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
}

// 打印链表
void printList(DNode* head) {
    DNode* temp = head->next;
    while (temp != head) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("HEAD\n");
}
void f1(){
    //insert S after P
    S->next = P->next;
    S->prev = P;
    P->next->prev = S;
    P->next = S;
}
void f2() {
    S->next = P;
    S->prev = P->prev;
    P->prev->next = S;
    P->prev = S;

}
void f3() {
    //题干说明P是中间节点，默认P后的元素不是头指针
    Node* tmp = P->next;
    P->next = P->next->next;
    P->next->pre = P;
    free(tmp);
}
void f4() {
    Node* tmp = P->prev;
    P->prev = P->prev->prev;
    tmp->prev->next = P;
    free(tmp);
}
void f5() {
    P->prev->next = P->next;
    P->next->prev = P->prev;
    free(P);
}
void deletextoy(int *L) {
    int i = 0, j = 0;   //i: 扫描指针，j: 新数组指针
    while (i < len) {
        if (L[i] < x || L[i] > y) {
            L[j] = L[i];
            j++;
        }
        i++;
    }
}
void shiftk(int *L) {
    revert(0, k);
    revert(k, len);
    revert(0, len);
}

Node* lastk(Node* head, int k) {
    //默认k小于等于链表总长度
    Node* slow = head, *fast = head;
    for (int i = 0; i < k; i++) {
        fast = fast->next;
    }
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    } 
    return slow;
}
void removeDuplicates(Node* head) {
    Node* current = head->next;
    while (current) {
        Node* prev = current;
        Node* temp = current->next;
        while (temp) {
            if (current->data == temp->data) {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
}
int isCycle(Node *head) {
    Node* slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        if (fast == slow) {
            return 1;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return 0;
}
int main() {
    DNode* head = initList();
    insertAfter(head, 10);
    insertAfter(head, 20);
    insertAfter(head->next, 30);
    printList(head);

    deleteNode(head->next->next);
    printList(head);

    // TODO: Remember to free the entire list when done

    return 0;
}
