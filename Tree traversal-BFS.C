AIM:
To write a C program to perform Breadth-First Search (BFS) traversal (also called Level-Order Traversal) on a binary tree using a queue.

🧠 ALGORITHM
1. Start
2. Create a binary tree
Each node contains data, left child, and right child pointers.
3. BFS Traversal (Level-Order
Create an empty queue
Insert (enqueue) the root node
While queue is not empty:
Dequeue a node
Process (print) the node
Enqueue the left child (if exists)
Enqueue the right child (if exists)
4. End

PROGRAM — BFS / Level-Order Traversal Using Queue:
#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue structure for BFS
struct Node* queue[100];
int front = -1, rear = -1;

// Function to enqueue a node
void enqueue(struct Node* node) {
    if (rear == 99) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;

    queue[++rear] = node;
}

// Function to dequeue a node
struct Node* dequeue() {
    if (front == -1 || front > rear) {
        return NULL;
    }
    return queue[front++];
}

// Create a new tree node
struct Node* createNode(int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// BFS Traversal (Level Order Traversal)
void bfs(struct Node* root) {
    if (root == NULL)
        return;

    enqueue(root);

    while (front <= rear) {
        struct Node* current = dequeue();
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(current->left);

        if (current->right != NULL)
            enqueue(current->right);
    }
}

int main() {

    // Creating a sample tree
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("BFS (Level Order) Traversal: ");
    bfs(root);

    printf("\n");

    return 0;
}

OUTPUT:
BFS (Level Order) Traversal: 1 2 3 4 5

    RESULT:
    For the binary tree:
        1
      /   \
     2     3
    / \
   4   5
   BFS Traversal (Level-Order) output is:
   1 2 3 4 5
