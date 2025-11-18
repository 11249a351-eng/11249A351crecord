

✅ Aim

To implement a Circular Queue using a linked list and perform basic queue operations such as insertion, deletion, and display using dynamic memory allocation.


---

✅ Algorithm

1. Insert (Enqueue)

1. Create a new node


2. If queue is empty:

front = rear = newNode

rear->next = front



3. Else

rear->next = newNode

rear = newNode

rear->next = front





---

2. Delete (Dequeue)

1. If queue is empty → print "Queue Underflow"


2. If only one node (front == rear):

Store the value

free the node

front = rear = NULL



3. Else

temp = front

front = front->next

rear->next = front

free(temp)





---

3. Display

1. If queue is empty → print "Queue Empty"


2. Start from front and traverse until you reach front again


3. Print each node’s data




---

✅ C Program: Circular Queue Using Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Insert element
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL) {   // Queue empty
        front = rear = newNode;
        rear->next = front;  // Circular link
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;  // Maintain circular structure
    }

    printf("%d inserted into circular queue.\n", value);
}

// Delete element
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow! Nothing to delete.\n");
        return;
    }

    int value;

    // Only one node
    if (front == rear) {
        value = front->data;
        free(front);
        front = rear = NULL;
    } else {
        struct Node* temp = front;
        value = temp->data;
        front = front->next;
        rear->next = front;  // Maintain circular link
        free(temp);
    }

    printf("Deleted element: %d\n", value);
}

// Display queue
void display() {
    if (front == NULL) {
        printf("Circular Queue is Empty.\n");
        return;
    }

    struct Node* temp = front;

    printf("Circular Queue elements:\n");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("(back to front)\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Using Linked List ---\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
