#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int newData) {
            data = newData;
            next = nullptr;
        }
};

class Queue {
    public:
        Node *front;
        Node *rear;

        Queue() {
            front = nullptr;
            rear = nullptr;
        }

        bool isEmpty() {
            return front == nullptr && rear == nullptr;
        }

        int top() {
            if (isEmpty()) {
                cout << "Error: Queue is empty\n";
                return -1;
            }
            return front -> data;
        }

        int size() {
            if (isEmpty()) {
                return 0;
            }

            Node *curr = front;
            int size = 0;

            while (curr != nullptr) {
                size++;
                curr = curr -> next;
            }
            return size;
        }

        void printQueue() {

            if (isEmpty()) {
                cout << "Error: Queue is empty.\n";
                return;
            }
            cout << "QUEUE: \n";         
            Node *curr = front;
            while (curr != nullptr) {
                cout << curr -> data << " ";
                curr = curr -> next;
            }
            cout << "\n";
        }

        void enqueue(int newData) {
            Node *newNode = new Node(newData);

            if (isEmpty()) {
                front = newNode;
                rear = front;
                return;
            }

            rear -> next = newNode;
            rear = newNode;
            
        }

        void dequeue() {
            if (isEmpty()) {
                cout << "The queue is empty.\n";
                return;
            }
            else if (front == rear && front != nullptr) {
                Node *frontNode = front;
                front = nullptr;
                rear = nullptr;
                delete frontNode;
                cout << "Now the queue is empty.\n";
                return;
            }
            Node *frontNode = front;
            front = front -> next;
            delete frontNode;
        }

};

int main() {

    Queue *myQueue = new Queue();

    for (int i = 0; i < 4; i++) {
        myQueue -> enqueue(i); // 0 1 2 3
    }

    myQueue -> dequeue();
    myQueue -> dequeue();
    myQueue -> dequeue();
    myQueue -> dequeue();

    myQueue -> enqueue(1001);
    myQueue -> enqueue(1002);
    myQueue -> enqueue(1003);

    cout << "Top of the queue: " << myQueue -> top() << "\n";
    myQueue -> printQueue();

    return 0;
}
