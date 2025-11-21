AIM:
To write a C program to implement Depth First Search (DFS) traversals on a binary tree, including:
Preorder Traversal (Root–Left–Right)
Inorder Traversal (Left–Root–Right)
Postorder Traversal (Left–Right–Root)

ALGORITHM:
1. Start
2. Create a Binary Tree Node
Each node contains:
data
left child pointer
right child pointer
3. Preorder Traversal (DFS)
Visit root
Traverse left subtree
Traverse right subtree
4. Inorder Traversal (DFS)
Traverse left subtree
Visit root
Traverse right subtree
5. Postorder Traversal (DFS)
Traverse left subtree
Traverse right subtree
Visit root
6. End

PROGRAM — DFS TREE TRAVERSAL (Preorder, Inorder, Postorder):
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Preorder Traversal: Root -> Left -> Right
void preorder(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Inorder Traversal: Left -> Root -> Right
void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Postorder Traversal: Left -> Right -> Root
void postorder(struct Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {

    // Creating a sample binary tree
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

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n");

    return 0;
}

OUTPUT:
Preorder Traversal: 1 2 4 5 3
Inorder Traversal: 4 2 5 1 3
Postorder Traversal: 4 5 2 3 1

   RESULT:
   For the given binary tree:

        1
      /   \
     2     3
    / \
   4   5
DFS Traversals produce:
Preorder: 1 2 4 5 3
Inorder: 4 2 5 1 3
Postorder: 4 5 2 3 1
