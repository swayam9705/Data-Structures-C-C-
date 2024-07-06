#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *prev;
        Node *next;

        Node(int data_) {
            data = data_;
        }
};

class DLL {
    public:
        Node *head;

        DLL() {
            head = nullptr;
        }

        void print() {
            Node *curr = head;
            
            while (curr != nullptr) {
                cout << curr -> data << " ";
                curr = curr -> next;
            }
            cout << "\n";
        }

        void reversePrint() {
            Node *curr = head;
            while (curr -> next != nullptr) {
                curr = curr -> next;
            }
            
            while (curr != nullptr) {
                cout << curr -> data << " ";
                curr = curr -> prev;
            }
            cout << "\n";
        }

        void insertAtHead(int data) {
            // create a new Node object
            Node *newNode = new Node(data);

            // if list is not initialized, then set the first node as head of the list
            if (head == nullptr) {
                head = newNode;
                return;
            }

            head -> prev = newNode;
            newNode -> next = head;
            head = newNode;
        }

        void insertAtTail(int data) {
            // create a new Node
            Node *newNode = new Node(data);

            if (head == nullptr) {
                head = newNode;
                return;
            }

            Node *curr = head;
            while (curr -> next != nullptr) {
                curr = curr -> next;
            }

            curr -> next = newNode;
            newNode -> prev = curr;
        }

};

int main() {

    DLL *list = new DLL();
    list -> insertAtHead(0);
    list -> insertAtHead(1);
    list -> insertAtTail(100);
    list -> insertAtTail(101);

    list -> print();

    return 0;
}