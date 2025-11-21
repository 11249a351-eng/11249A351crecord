✅ Aim:
To implement a stack using an array and perform basic stack operations:
Push (insert element)
Pop (delete element)
Peek / Top (display top element)
Display (show all elements)

✅ Algorithm: Stack Using Array
1. PUSH (Insert Element)
1. If top == size - 1
→ Stack Overflow
2. Else
→ top = top + 1
→ stack[top] = value
2. POP (Delete Element)
1. If top == -1
→ Stack Underflow
2. Else
→ value = stack[top]
3. PEEK (top Element)
1. If top == -1
→ Stack is empty
2. Else
→ Print stack[top]
3. DISPLAY

Program: Stack Operations Using Array:
#include <stdio.h>
#define SIZE 50
int stack[SIZE];
int top = -1;

// Function to push an element
void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed into stack\n", value);
    }
}

// Function to pop an element
void pop() {
    if (top == -1) {
        printf("Stack Underflow! No element to pop\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

// Function to display the top element
void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

// Function to display stack elements
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
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
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}

OUTPUT:
--- STACK MENU ---
Enter your choice: 1
Enter value to push: 10
10 pushed to stack

Enter your choice: 1
Enter value to push: 20
20 pushed to stack

Enter your choice: 1
Enter value to push: 30
30 pushed to stack

Enter your choice: 4
Stack elements: 30 20 10

Enter your choice: 2
30 popped from stack

Enter your choice: 3
Top element is 20
    
        RESULT :
        After performing push → push → push → pop:
        Final stack is:20 10
        Top = 20 and hence we found the stack using array.
