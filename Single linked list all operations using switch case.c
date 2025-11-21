Aim:
To implement a Singly Linked List in C and perform all major operations using a menu-driven program:
Insert at beginning
Insert at end
Insert at specific position
Delete from beginning
Delete from end
Delete from specific position
Search an element
Display the list

Algorithm (Major Operations):
1. Insert at Beginning
1. Create a new node
2. Set newnode->next = head
3. Set head = newnode

2. Insert at End
1. Create a new node
2. Traverse to last node
3. Set last->next = newnode
    
3. Insert at Position
1. Traverse to node before desired position
2. Set newnode->next = temp->next
3. Set temp->next = newnode


4. Delete from Beginning
1. Store head in temp
2. Set head = head->next
3. Free temp

5. Delete from End
1. Traverse to second last node
2. Set temp->next = NULL
3. Free last node

6. Delete from Position
1. Traverse to previous node
2. Adjust links
3. Free the node

7. Search
Traverse list and compare each element.
    
8. Display
Traverse and print each node.

Program: Singly Linked List (All Operations – Switch Case)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create new node
struct Node* createNode(int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

// Insert at beginning
void insertBeginning(int value) {
    struct Node* newnode = createNode(value);
    newnode->next = head;
    head = newnode;
    printf("Inserted %d at beginning\n", value);
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
    }
    printf("Inserted %d at end\n", value);
}

// Insert at specific position
void insertPosition(int value, int pos) {
    struct Node* newnode = createNode(value);

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
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
    temp->next = newnode;
    printf("Inserted %d at position %d\n", value, pos);
}

// Delete from beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Deleted %d from beginning\n", temp->data);
    free(temp);
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        printf("Deleted %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    printf("Deleted %d from end\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

// Delete from a position
void deletePosition(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 1) {
        deleteBeginning();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node* del = temp->next;
    temp->next = del->next;

    printf("Deleted %d from position %d\n", del->data, pos);
    free(del);
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

// Display list
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Search Element\n");
        printf("8. Display\n");
        printf("9. Exit\n");
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
                display();
                break;

            case 9:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}

OUTPUT:
--- Singly Linked List Menu ---
Enter choice: 1
Enter value: 10
Inserted 10 at beginning

Enter choice: 2
Enter value: 20
Inserted 20 at end

Enter choice: 2
Enter value: 30
Inserted 30 at end

Enter choice: 3
Enter value and position: 25 3
Inserted 25 at position 3

Enter choice: 7
Linked List: 10 20 25 30

Enter choice: 5
Deleted 30 from end

Enter choice: 4
Deleted 10 from beginning

Enter choice: 7
Linked List: 20 25
    
         RESULT:
         After performing all operations, the linked list contains:20 → 25
         Head = 20
         Last node = 25.
