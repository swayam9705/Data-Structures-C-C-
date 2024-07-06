#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int);
void printTree(struct Node*);
void insertNode(struct Node**, int);
int search(struct Node*, int);
int min(struct Node*);
int max(struct Node*);
int height(struct Node*);

int main() {

    int arr[6] = {5, 4, 7, 9, 3, 0};
    
    struct Node *root = NULL;

    for (int i = 0; i < 6; i++) {
        insertNode(&root, arr[i]);
    }

    printTree(root);

    printf("The height of the tree is %i\n", height(root));

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
        printf("%i\n", root -> data);
        printTree(root -> left);
        printTree(root -> right);
    }
}

void insertNode(struct Node **root, int data) {

    if (*root == NULL) {
        (*root) = createNode(data);
    }

    else if ((*root) -> data > data) {
        insertNode(&((*root) -> left), data);
    }
    else {
        insertNode(&((*root) -> right), data);
    }

}

int search(struct Node *root, int data) {
    if (root == NULL) return 0;
    if (root -> data == data) return 1;

    if (data < root -> data) {
        return search(root -> left, data);
    }
    else {
        return search(root -> right, data);
    }
}

int min(struct Node *root) {
    if (root == NULL) {
        return -1;
    }

    while (root -> left != NULL) {
        root = root -> left;
    }
    
    return root -> data;
}

int max(struct Node *root) {
    if (root == NULL) {
        return -1;
    }

    while (root -> right != NULL) {
        root = root -> right;
    }

    return root -> data;
}

int height(struct Node *root) {
    if (root == NULL) {
        return -1;
    }

    int left_height = height(root -> left);
    int right_height = height(root -> right);
    int max_height = (left_height > right_height) ? left_height : right_height;

    return max_height + 1;
}