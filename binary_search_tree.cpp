#include <iostream>
#include <queue>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data): data(data), left(nullptr), right(nullptr) {}
};

void insertNode(Node**, int);
void printTree(Node*);
void levelOrder(Node*);
bool searchNode(Node*, int);
int min(Node*);
int max(Node*);

int main() {

    Node *root = new Node(15);

    int arr[6] = {10, 20, 7, 13, 17, 25};

    for (int i : arr) {
        insertNode(&root, i);
    }

    cout << "Preorder Traversal: \n";
    printTree(root);
    cout << "\n\n";

    cout << "Level Order Traversal: \n";
    levelOrder(root);

    cout << "Max: " << max(root) << ", Min: " << min(root) << "\n";

    return 0;
}

void insertNode(Node **root, int data) {
    if ((*root) == nullptr) {
        (*root) = new Node(data);
        return;
    }

    if (data < (*root) -> data) {
        insertNode(&((*root) -> left), data);
    }
    else {
        insertNode(&((*root) -> right), data);
    }
}

void printTree(Node *root) {
    if (root != nullptr) {
        cout << root -> data << " ";
        printTree(root -> left);
        printTree(root -> right);
    }
}

bool searchNode(Node *root, int data) {

    if (root == nullptr) {
        return false;
    }

    if (root -> data == data) {
        return true;
    }

    if (data < root -> data) {
        return searchNode(root -> left, data);
    }
    
    return searchNode(root -> right, data);
}

int min(Node *root) {
    if (root == nullptr) {
        return -1;
    }

    while (root -> left != nullptr) {
        root = root -> left;
    }

    return root -> data;
}

int max(Node *root) {
    if (root == nullptr) {
        return -1;
    }

    while (root -> right != nullptr) {
        root = root -> right;
    }
    return root -> data;
}

void levelOrder(Node *root) {
    if (root == nullptr) return;

    queue<Node*> Q;
    Node *current = nullptr;
    Q.push(root);

    while (!Q.empty()) {
        current = Q.front();
        cout << current -> data << " ";
        if (current -> left != nullptr) Q.push(current -> left);
        if (current -> right != nullptr) Q.push(current -> right);
        Q.pop();
    }
    cout << "\n"; 
}