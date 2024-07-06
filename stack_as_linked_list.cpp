#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int newData) {
            this -> data = newData;
            this -> next = nullptr;
        }
};

class Stack {
    public:
        Node *head;

        Stack() {
            head = NULL;
        }

        void printStack() {
            Node *temp = head;
            cout << "Top -> ";
            while (temp != NULL) {
                cout << temp -> data << "\n";
                temp = temp -> next;
            }
        }

        void push(int newData) {
            Node *newNode = new Node(newData);
            newNode -> next = head;
            head = newNode;
        }

        int pop() {
            Node *temp = head;
            head = head -> next;
            int data = temp -> data;
            free(temp);
            return data;
        }

        int peak() {
            if (head == NULL) {
                cout << "Stack is Empty.";
                return -1;
            }
            return head -> data;
        }
};

int main() {

    Stack *stack = new Stack();

    // Implementing stack of characters to reverse the string.
    
    string str = "Hello, world";
    int l = 12, i = 0;

    while (i < l) {
        stack -> push((int)str[i]);
        i++;
    }

    i = 0;
    while (i < l) {
        str[i] = (char)(stack -> pop());
        i++;
    }

    cout << str << "\n";

    return 0;
}