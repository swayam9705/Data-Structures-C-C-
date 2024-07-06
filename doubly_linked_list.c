#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

struct Node* createNode(int);
void insertAtHead(int);
void insertAtTail(int);
void printList();
void reversePrint();


int main() {

    for (int i = 0; i < 5; i++) {
        insertAtHead(i);
    }

    insertAtTail(100);
    insertAtTail(101);
    insertAtTail(102);

    printList();
    reversePrint();

    return 0;
}

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    return newNode;
}

void insertAtHead(int data) {
    struct Node *newNode = createNode(data);

    // if list head is NULL, then set the `head = Node`
    if (head == NULL) {
        head = newNode;
        return;
    }

    head -> prev = newNode;
    newNode -> next = head;
    head = newNode;
}

void printList() {
    // curr refers to temporary current node
    struct Node *curr = head;
    printf("List: ");
    while (curr != NULL) {
        printf("%i ", curr -> data);
        curr = curr -> next;
    }
    printf("\n");
}

void reversePrint() {
    printf("Reverse List: ");
    if (head == NULL) {
        return;
    }

    struct Node *curr = head;

    while (curr -> next != NULL) {
        curr = curr -> next;
    }

    while (curr != NULL) {
        printf("%i ", curr -> data);
        curr = curr -> prev;
    }
}

void insertAtTail(int data) {
    struct Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *curr = head;

    while (curr -> next != NULL) {
        curr = curr -> next;
    }

    curr -> next = newNode;
    newNode -> prev = curr;
}