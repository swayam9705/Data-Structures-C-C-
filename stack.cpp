#include <iostream>

#define MAX_SIZE 101

class Stack {
    private:
        int arr[MAX_SIZE]; // Array to store stack elements
        int top; // Index of the top most element in the stack.

    public:
        Stack() {
            top = -1;
        }

        void print() {
            printf("STACK\n");
            for (int i = top; i >= 0; i--) {
                printf("%i\n", arr[i]);
            }
        }

        bool isEmpty() {
            return top == -1;
        }

        bool isFull() {
            return top == MAX_SIZE - 1; 
        }

        void push(int data) {
            if (isFull()) {
                printf("Erro: Stack is full.\n");
                return;
            }
            top++;
            arr[top] = data;
        }

        void pop(int data) {
            if (isEmpty()) {
                printf("Error: Stack is Empty.\n");
                return;
            }
            top--;
        }

        int peak() {
            if (isEmpty()) {
                printf("Error: Stack is empty");
                return -1;
            }
            printf("Peak: %i\n", arr[top]);
            return arr[top];
        }
};

int main() {
    
    Stack stack;

    stack.push(5);
    stack.push(8);
    stack.push(0);

    stack.peak();
    return 0;
}
