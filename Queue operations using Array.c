✅ Aim:
To implement a queue using an array and perform the following operations:

Enqueue (insert element)

Dequeue (delete element)

Peek/Front (first element)

Display (show all elements)


✅ Algorithm: Queue Using Array

Let

front = 0 (or -1 depending on design)

rear = -1

size = maximum number of elements


1. ENQUEUE (Insert Element)

1. If rear == size - 1
→ Queue Overflow


2. Else
→ rear = rear + 1
→ queue[rear] = value
→ If front == -1, set front = 0

2. DEQUEUE (Delete Element)

1. If front == -1 OR front > rear
→ Queue Underflow


2. Else
→ value = queue[front]
→ front = front + 1



3. PEEK (Front Element)

1. If queue empty
→ Print "Queue is empty"


2. Else
→ Print queue[front]


4. DISPLAY

1. If queue empty
→ Print "Queue is empty"


2. Else display elements from front to rear


✅ C Program: Queue Operations Using Array

#include <stdio.h>
#define SIZE 50

int queue[SIZE];
int front = -1, rear = -1;

// Enqueue function
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("%d inserted into queue\n", value);
    }
}

// Dequeue function
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! No element to delete\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

// Peek function
void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

// Display all elements
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
SAMPLE OUTPUT:
--- Queue Menu ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter value: 10
Inserted 10

Enter your choice: 1
Enter value: 20
Inserted 20

Enter your choice: 1
Enter value: 30
Inserted 30

Enter your choice: 3
Queue Elements: 10 20 30

Enter your choice: 2
Deleted 10

Enter your choice: 3
Queue Elements: 20 30
    result:
        After performing operations:
        Inserted: 10, 20, 30
        Deleted: 10
        Remaining queue:20 30
        Front → 20
        Rear → 30
