#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the tree
Node* insertNode(Node* root, int data) {
    // If the tree is empty, assign a new node address to the root
    if (root == NULL) {
        root = createNode(data);
    }
    // Else, recur down the tree
    else if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to display the tree in pre-order traversal
void displayTree(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        displayTree(root->left);
        displayTree(root->right);
    }
}

// Function to free the memory allocated to the tree
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("Pre-order traversal of the tree is: ");
    displayTree(root);

    freeTree(root);

    return 0;
}
