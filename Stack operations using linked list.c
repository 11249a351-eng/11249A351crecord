Aim:
To implement stack operations (Push, Pop, Peek, Display) using a linked list in C and demonstrate the working of stack using dynamic memory allocation.

Algorithm:
1. Push Operation
1. Create a new node
2. Store the given data in the node
3. Make new node → next = top
4. Update top = new node
 Pop Operation
1. If top == NULL → Stack Underflow
2. Else
 Store the value of top
 Move top to top->next
 Free the old top node
  Peek Operation
1. If top == NULL → print “Stack Empty”
2. Else print top->data
  Display Operation
1. If top == NULL → print “Stack Empty”
2. Traverse from top to bottom and print each node.

Program: Stack Operations Using Linked List
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Function to push data into stack
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (!newNode) {
        printf("Memory not allocated!\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed into stack.\n", value);
}

// Function to pop data from stack
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Nothing to pop.\n");
        return;
    }

    struct Node* temp = top;
    printf("Popped element: %d\n", top->data);

    top = top->next;
    free(temp);
}

// Function to see the top element
void peek() {
    if (top == NULL) {
        printf("Stack is Empty.\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

// Function to display stack
void display() {
    if (top == NULL) {
        printf("Stack is Empty.\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack elements:\n");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Using Linked List ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}

OUTPUT:
--- STACK MENU (Linked List) ---
Enter choice: 1
Enter value to push: 10
10 pushed to stack

Enter choice: 1
Enter value to push: 20
20 pushed to stack

Enter choice: 1
Enter value to push: 30
30 pushed to stack

Enter choice: 4
Stack elements: 30 20 10

Enter choice: 2
30 popped from stack

Enter choice: 3
Top element is 20
 
           RESULT:
           After pushing 10, 20, 30 and popping once, the stack becomes:20 10
           Top = 20 and hence we found the stack using linked list.

