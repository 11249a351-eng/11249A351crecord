
✅ Aim

To implement a Doubly Linked List in C and perform all major operations using a menu-driven switch-case program:

Insert at beginning

Insert at end

Insert at specific position

Delete from beginning

Delete from end

Delete from specific position

Forward display

Reverse display

Search an element



---

✅ Node Structure

Each node has:

prev → Pointer to previous node

data → Value

next → Pointer to next node



---

🚀 C Program: Doubly Linked List (All Operations – Switch Case)

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next, *prev;
};

struct Node* head = NULL;

// Create new node
struct Node* createNode(int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

// Insert at beginning
void insertBeginning(int value) {
    struct Node* newnode = createNode(value);

    if (head != NULL) {
        newnode->next = head;
        head->prev = newnode;
    }

    head = newnode;
    printf("%d inserted at beginning\n", value);
}

// Insert at end
void insertEnd(int value) {
    struct Node* newnode = createNode(value);

    if (head == NULL) {
        head = newnode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }
    printf("%d inserted at end\n", value);
}

// Insert at specific position
void insertPosition(int value, int pos) {
    struct Node* newnode = createNode(value);

    if (pos == 1) {
        insertBeginning(value);
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;

    printf("%d inserted at position %d\n", value, pos);
}

// Delete from beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    printf("Deleted %d from beginning\n", temp->data);
    free(temp);
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev == NULL) {
        head = NULL;
    } else {
        temp->prev->next = NULL;
    }

    printf("Deleted %d from end\n", temp->data);
    free(temp);
}

// Delete from specific position
void deletePosition(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    if (pos == 1) {
        deleteBeginning();
        return;
    }

    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("Deleted %d from position %d\n", temp->data, pos);
    free(temp);
}

// Search an element
void search(int key) {
    struct Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Element %d not found\n", key);
}

// Display forward
void displayForward() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Doubly Linked List (Forward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Display reverse
void displayReverse() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Doubly Linked List (Reverse): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Search Element\n");
        printf("8. Display Forward\n");
        printf("9. Display Reverse\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertPosition(value, pos);
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deletePosition(pos);
                break;

            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 8:
                displayForward();
                break;

            case 9:
                displayReverse();
                break;

            case 10:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
