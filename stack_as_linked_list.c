#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int);
int isEmpty(struct Node*);
void push(struct Node**, int);
int pop(struct Node**);
int peak(struct Node*);
void printStack(struct Node*);

int main() {

    struct Node *stack = NULL;
    
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 4);
    push(&stack, 8);
    pop(&stack);

    printf("%i\n", peak(stack));

    printStack(stack);

    return 0;
}

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

int isEmpty(struct Node *head) {
    return (head == NULL);
}

void push(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    newNode -> next = *head;
    *head = newNode;
}

int pop(struct Node **head) {
    if (*head == NULL) {
        return -1;
    }

    struct Node *temp = *head;
    *head = (*head) -> next;
    int data = temp -> data;
    free(temp);
    return data;
}

int peak(struct Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return -1;
    }
    return head -> data;
}

void printStack(struct Node *head) {
    struct Node *temp = head;
    printf("Top -> ");
    while (temp != NULL) {
        printf("%i\n", temp -> data);
        temp = temp -> next;
    }
}
