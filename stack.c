#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void push(int x) {
    if (top == MAX_SIZE - 1) {
        printf("Error: Stack overflow.");
        return;
    } 
    A[++top] = x;
};

void pop() {
    if (top == -1) {
        printf("Error: No element to pop.");
        return;
    }
    top--;
}

int topElement() {
    if (top == -1) {
        printf("Error: Stack is Empty.");
        return -1;
    }
    return A[top];
}

void print() {
    for (int i = 0; i <= top; i++) {
        printf("%i ", A[i]);
    }
}

int main() {

    push(2);
    push(5);
    push(7);
    pop();
    printf("%i\n", topElement());
    print(); 

    return 0;
}