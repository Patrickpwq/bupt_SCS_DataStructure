#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

ListNode *reverseGroup(ListNode *group[], int len)
{
    for (int i = len - 1; i >= 1; i--)
    {
        group[i]->next = group[i - 1];
    }
    return group[0];
}
struct ListNode *reverseEvenLengthGroups(struct ListNode *head)
{
    ListNode *temp = head->next;
    int groupLength = 1;
    int count = 1;
    int len = 0;
    int f = 0;
    ListNode *beforeGroup = head->next, *nextGroup;
    ListNode *group[100000];
    while (temp)
    {
        group[len++] = temp;
        count++;
        if (count > groupLength || temp->next == NULL)
        {
            count = 1;
            groupLength++;

            if (len % 2 == 0) {
                beforeGroup->next = temp;
                nextGroup = temp->next;
                reverseGroup(group, len)->next = nextGroup;
                beforeGroup = group[0];
                f = -1;
            }
            else
                beforeGroup = temp;
            len = 0;
        }
        if (f == -1)
        {
            temp = nextGroup;
            f = 0;
        }
        else
            temp = temp -> next;
    }
    return head;
}

ListNode *createList()
{
    ListNode *head = malloc(sizeof(ListNode));
    head->next = NULL;
    return head;
}

void insertNode(ListNode *head, int val)
{
    ListNode *newNode = malloc(sizeof(ListNode)), *temp = head;
    newNode->val = val;
    newNode->next = NULL;

    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void printList(ListNode *head)
{
    ListNode *temp = head->next;

    while (temp != NULL)
    {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }

    printf("NULL\n");
}
int main()
{
    ListNode *head = createList();
    insertNode(head, 5);
    insertNode(head, 2);
    insertNode(head, 6);
    insertNode(head, 3);
    insertNode(head, 9);
    insertNode(head, 1);
    insertNode(head, 7);
    insertNode(head, 3);

    printList(reverseEvenLengthGroups(head));
}
