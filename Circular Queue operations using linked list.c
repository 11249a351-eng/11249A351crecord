✅ Aim:
To implement a Circular Queue using a linked list and perform basic queue operations such as insertion, deletion, and display using dynamic memory allocation.

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
3. Display
1. If queue is empty → print "Queue Empty"
2. Start from front and traverse until you reach front again
3. Print each node’s data

Program: Circular Queue Using Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (front == NULL) {
        front = rear = newNode;
        rear->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    printf("Inserted %d\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is Empty\n");
    } 
    else if (front == rear) {
        printf("Deleted %d\n", front->data);
        free(front);
        front = rear = NULL;
    } 
    else {
        struct Node* temp = front;
        printf("Deleted %d\n", temp->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue Elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    
    display();

    dequeue();
    dequeue();

    display();

    enqueue(40);
    enqueue(50);

    display();

    return 0;
}

OUTPUT:
Inserted 10
Inserted 20
Inserted 30
Queue Elements: 10 20 30
Deleted 10
Deleted 20
Queue Elements: 30
Inserted 40
Inserted 50
Queue Elements: 30 40 50

    Final Circular Queue content
30 → 40 → 50 → (back to 30)

Front = 30
Rear = 50
      
        RESULT:
        hence we found the front and rear using circular queue by linked list.
