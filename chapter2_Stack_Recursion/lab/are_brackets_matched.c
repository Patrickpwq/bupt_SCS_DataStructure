// Using dynamic array-based stack to implement
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char *arr;
    int capacity;
    int top;
} Stack;
void initStack(Stack *s) {
    s->capacity = 1;
    s->arr = (char *)malloc(s->capacity * sizeof(char));
    s->top = -1;
}
void resize(Stack *s) {
    s->capacity *= 2;
    s->arr = (char *)realloc(s->arr, s->capacity * sizeof(char));
}
void push(Stack *s, char ch) {
    if (s->top == s->capacity - 1) {
        resize(s);
    }
    s->arr[++s->top] = ch;
}
char pop(Stack *s) {
    if (s->top == -1) {
        return '\0';
    }
    return s->arr[s->top--];
}
int isEmpty(Stack *s) {
    return s->top == -1 ? 1 : 0;
}
void freeStack(Stack *s) {
    free(s->arr);
}
int areBracketsMatched(char expr[]) {
    Stack s;
    initStack(&s);
    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == '(' || expr[i] == '[') {
            push(&s, expr[i]);
        } else if (expr[i] == ')') {
            if (isEmpty(&s) || pop(&s) != '(') {
                freeStack(&s);
                return 0;
            }
        } else if (expr[i] == ']') {
            if (isEmpty(&s) || pop(&s) != '[') {
                freeStack(&s);
                return 0;
            }
    }
    }
    freeStack(&s);
    return isEmpty(&s) ? 1 : 0;
}
int main() {
    char expr1[] = "data[(a+12)*(x-y)-5] * (a/(ba->num+66*sin(x-1.7)) - 48)";
    char expr2[] = "task[a+b * (c +99)) / 34 *(x - 78";
    areBracketsMatched(expr1) == 0 ? printf("%s not matched\n", expr1) : printf("%s matched\n", expr1);
    areBracketsMatched(expr2) == 0 ? printf("%s not matched\n", expr2) : printf("%s matched\n", expr2);
    return 0;
}
