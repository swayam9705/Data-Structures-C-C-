#include <stdio.h>
#include <stdlib.h>

/*
    -> A Linked List is a collection of elements called Node.
        - 0 -> 1 -> 2 -> 3 -> NULL
    -> A node is an object which stores two values (the actual data and reference to the next node.)
        - Node() { data, nextNode}
        - the nextNode property of last node is set to NULL to signify the end of the linked list.
    -> Linked Lists are used to store dynamic data, or the data whose population is unknown.
    -> A new node can be added to the linked list as per needed.


*/ 
struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int);
int isEmpty(struct Node*);
void print(struct Node*);
void reverse(struct Node*);
void insertAtBeginning(struct Node**, int);
void insertAtEnd(struct Node**, int);
void delete(struct Node**, int);
void insert(struct Node**, int, int);

int main() {
    
    struct Node *head = createNode(0);
    int i, j, k;

    for (int i = 1; i <= 5; i++) {
        insertAtBeginning(&head, i);
    }

    print(head);

    printf("Enter data and index: ");
    scanf("%i %i", &i, &j);
    insert(&head, i, j);

    print(head);

    return 0;
}

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

int isEmpty(struct Node *head) {
    if (head == NULL) {
        return 1;
    }

    return 0;
}

void print(struct Node *head) {
    // check if the list is empty
    if (isEmpty(head)) {
        printf("Error: The linked list is empty.\n");
        return;
    }

    // declare a temporary node pointer
    struct Node *current = head;
    while (current != NULL) {
        printf("%i - ", current -> data);
        current = current -> next;
    } 
    printf("\n");
}

void reverse(struct Node *head) {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current -> next;
        current -> next = prev;
        current = next;
    }
}

void insertAtBeginning(struct Node **head, int newData) {
    // create a new node
    struct Node *newNode = createNode(newData);

    // insert it at the beginning of the list
    newNode -> next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node **head, int newData) {
    // create a node object
    struct Node *newNode = createNode(newData); 

    // declare a temporary node variable
    struct Node *current = *head; 

    while (current -> next != NULL) {
        current = current -> next;
    }

    // append the new node to the end of the list
    current -> next = newNode;
}

void delete(struct Node **head, int index) {

    // check if the index is pointing to the head node,
    // if so the set it's next node as the head. 
    if (index == 0) {
        struct Node *temp = *head;
        *head = temp -> next;
        free(temp);
    }

    int i;
    struct Node *current = *head;

    for (i = 0; i < index - 1; i++) {
        if (current == NULL) {
            printf("Error: Index succeeded the size of the linked list.\n");
            return;
        }
        current = current -> next;
    }

    struct Node *nextNode = current -> next;
    current -> next = nextNode -> next;
    free(nextNode);
}

void insert(struct Node **head, int newData, int index) {
    struct Node *newNode = createNode(newData);

    if (index == 0) {
        newNode -> next = *head;
        *head = newNode;
    }

    int i;
    struct Node *current = *head;

    for (i = 0; i < index - 1; i++) {
        current = current -> next;

        if (current == NULL) {
            printf("Error: Given index exceeded the size of the linked list.\n");
            return;
        }
    }

    struct Node *nextNode = current -> next;
    current -> next = newNode;
    newNode -> next = nextNode;
}