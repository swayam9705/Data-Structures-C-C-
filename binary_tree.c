#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int);
void printTree(struct Node*);

int main() {

    struct Node *root = createNode(0);
    root -> left = createNode(1);
    root -> right = createNode(2);
    root -> left -> left = createNode(3);
    root -> left -> right = createNode(4);
    root -> right -> left = createNode(5);
    root -> right -> right = createNode(6);

    /* 
        Rough structure of the tree
        
                     0   <- root
                  /    \
                 1      2
               /  \   /  \
              3   4  5    6
    */

    printTree(root);

    return 0;
}

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;

    return newNode;
}

void printTree(struct Node *root) {
    if (root != NULL) {
        printTree(root -> left);
        printf("%i\n", root -> data);
        printTree(root -> right);
    }
}