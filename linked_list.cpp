#include <iostream>

using namespace std;

/*
    -> A Linked List is a collection of elements called Node.
        - 0 -> 1 -> 2 -> 3 -> NULL
    -> A node is an object which stores two values,
       the actual data and reference to the next node.
        - Node() { data, nextNode}
        - the nextNode property of last node is set to NULL to signify the end of the linked list.
    -> Linked Lists are used to store dynamic data, or the data whose population is unknown.
    -> A new node can be added to the linked list as per required.
*/

class Node {
    public:
        int data;
        Node *next;

        Node() {
            data = 0;
            next = nullptr;
        }

        Node(int data) {
            this -> data = data;
            this -> next = nullptr;
        }

};

class LinkedList {
    public:
        Node *head;

        LinkedList() {
            head = nullptr;
        }

        void traverse() {
            Node *temp = head;
            cout << "List: ";
            while (temp != nullptr) {
                cout << temp -> data << " - ";
                temp = temp -> next;
            }
            cout << "\n";
        }

        void insertNode(int data) {
            Node *newNode = new Node(data);
            if (head == nullptr) {
                head = newNode;
                return;
            }

            Node *temp = head;

            while (temp -> next != nullptr) {
                temp = temp -> next;
            }

            temp -> next = newNode;
        }

        void insertNode(int data, int pos) {
            Node *temp = head;
            int i = 0;
            while (i < pos - 1) {
                if (temp == nullptr) {
                    cout << "size exceeded\n";
                    return;
                }
                // cout << temp -> data << " - ";
                temp = temp -> next;
                i++;
            }

            Node *nextNode = temp -> next;
            Node *newNode = new Node(data);
            temp -> next = newNode;
            newNode -> next = nextNode;
        }

        void deleteNode(int pos) {

            if (pos == 0) {
                head = head -> next;
                return;
            }

            Node *temp = head;
            int i = 0; 
            while (i < pos - 1) {
                if (temp == nullptr) {
                    cout << "Position exceeded\n";
                    return;
                }

                temp = temp -> next;
                i++;
            }
            Node *nextNode = temp -> next;
            temp -> next = nextNode -> next;
            delete(nextNode);
        }

        void reverse() {
            Node *current = head,
                 *prev = nullptr,
                 *next = nullptr;

            while (current != nullptr) {
                next = current -> next;
                current -> next = prev;
                prev = current;
                current = next;
            }
            head = prev;
        }
};

int main() {

    // LinkedList list;

    printf("/");

    return 0;
}