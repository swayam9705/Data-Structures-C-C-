#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

struct Queue* createQueue();
struct Node* createNode(int);
int isEmpty(struct Queue*);
int front(struct Queue*);
int size(struct Queue*);
void printQueue(struct Queue*);
void enqueue(struct Queue*, int);
void dequeue(struct Queue*);

int main() {

    struct Queue *myQueue = createQueue();
    enqueue(myQueue, 0);
    enqueue(myQueue, 1);
    enqueue(myQueue, 2);
    enqueue(myQueue, 3);

    dequeue(myQueue);
    dequeue(myQueue);
    dequeue(myQueue);

    enqueue(myQueue, 100);
    enqueue(myQueue, 101);
    enqueue(myQueue, 102);

    printf("The Size of the queue: %i\n", size(myQueue));
    printf("The front of the queue: %i\n", front(myQueue));

    printQueue(myQueue);
 
    return 0;
}

struct Queue* createQueue() {
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));

    queue -> front = NULL;
    queue -> rear = NULL;

    return queue;
}

struct Node* createNode(int newData) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = newData;
    newNode -> next = NULL;

    return newNode;
}

int isEmpty(struct Queue *queue) {
    if (queue -> front == NULL && queue -> rear == NULL) {
        return true;
    }
    return false;
}

int front(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is Empty.\n");
        return -1;
    }
    return queue -> front -> data;
}

int size(struct Queue *queue) {
    if (isEmpty(queue)) {
        return 0;
    }
    struct Node *curr = queue -> front;
    int size = 0;
    while (curr != NULL) {
        size++;
        curr = curr -> next;
    }

    return size;
}

void printQueue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty.\n");
        return;
    }
    struct Node *curr = queue -> front;
    while (curr != NULL) {
        printf("%i ", curr -> data);
        curr = curr -> next;
    }
    printf("\n");
}

void enqueue(struct Queue *queue, int newData) {

    struct Node *newNode = createNode(newData);

    if (isEmpty(queue)) {
        queue -> front = newNode;
        queue -> rear = queue -> front;
        return;
    }

    queue -> rear -> next = newNode;
    queue -> rear = newNode;
}

void dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty.\n");
        return;
    }
    else if (queue -> front == queue -> rear) {
        struct Node *frontNode = queue -> front;
        queue -> front = NULL;
        queue -> rear = NULL;
        free(frontNode);
        printf("The queue is now empty\n");
        return;
    }
    struct Node *frontNode = queue -> front;
    queue -> front = queue -> front -> next;
    free(frontNode);
}