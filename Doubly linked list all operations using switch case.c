Aim:
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
    
algorithm:
1. Start
Initialize head = NULL.
2. Insert at Beginning
Create a new node.
If list is empty:
head = newnode
Else:
newnode>next = head
head>prev = newnode
head = newnode
3. Insert at End
Create new node.
If list is empty:
head = newnode
Else:
Traverse to last node.
Update pointers:
last->next = newnode
newnode->prev = last
4. Insert at Position
Get position.
Traverse till pos-1.
Adjust next and prev pointers of surrounding nodes.
Insert node.
5. Delete at Beginning
If list empty → print underflow.
Else:
Move head to head->next
Free old head.
6. Delete at End
If list empty → underflow.
Traverse to last node.
Update prev->next = NULL.
Free last node.
7. Delete at Position
Get position.
Traverse to that node.
Adjust surrounding links.
Free the node.
8. Display (Forward)
Traverse from head and print using next.
9. Display (Reverse)
Go to last node.
Traverse backwards using prev.
10. Stop
    
 Program: Doubly Linked List (All Operations – Switch Case)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

// Create node
struct Node* createNode(int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->prev = newnode->next = NULL;
    return newnode;
}

// Insert at beginning
void insertBeg(int value) {
    struct Node *newnode = createNode(value);

    if (head == NULL) {
        head = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    printf("Inserted %d at beginning\n", value);
}

// Insert at end
void insertEnd(int value) {
    struct Node *newnode = createNode(value);

    if (head == NULL) {
        head = newnode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;

    printf("Inserted %d at end\n", value);
}

// Insert at position
void insertPos(int value, int pos) {
    struct Node *newnode = createNode(value);

    if (pos == 1) {
        insertBeg(value);
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid Position\n");
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;

    printf("Inserted %d at position %d\n", value, pos);
}

// Delete at beginning
void deleteBeg() {
    if (head == NULL) {
        printf("List Empty\n");
        return;
    }

    struct Node *temp = head;
    printf("Deleted %d from beginning\n", temp->data);

    head = head->next;
    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

// Delete at end
void deleteEnd() {
    if (head == NULL) {
        printf("List Empty\n");
        return;
    }

    struct Node *temp = head;

    if (temp->next == NULL) {
        printf("Deleted %d from end\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Deleted %d from end\n", temp->data);

    temp->prev->next = NULL;
    free(temp);
}

// Delete at position
void deletePos(int pos) {
    if (head == NULL) {
        printf("List Empty\n");
        return;
    }

    struct Node *temp = head;

    if (pos == 1) {
        deleteBeg();
        return;
    }

    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid Position\n");
        return;
    }

    printf("Deleted %d from position %d\n", temp->data, pos);

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// Display forward
void displayForward() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List Empty\n");
        return;
    }

    printf("List (Forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Display reverse
void displayReverse() {
    if (head == NULL) {
        printf("List Empty\n");
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    printf("List (Reverse): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Delete at Beginning\n5. Delete at End\n6. Delete at Position\n");
        printf("7. Display Forward\n8. Display Reverse\n9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeg(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter value & position: ");
                scanf("%d %d", &value, &pos);
                insertPos(value, pos);
                break;

            case 4:
                deleteBeg();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePos(pos);
                break;

            case 7:
                displayForward();
                break;

            case 8:
                displayReverse();
                break;

            case 9:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}

OUTPUT:
mathematica
Copy code
--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete at Beginning
5. Delete at End
6. Delete at Position
7. Display Forward
8. Display Reverse
9. Exit
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
Enter value & position: 25 3
Inserted 25 at position 3

Enter choice: 7
List (Forward): 10 20 25 30

Enter choice: 5
Deleted 30 from end

Enter choice: 4
Deleted 10 from beginning

Enter choice: 7
List (Forward): 20 25

Enter choice: 8
List (Reverse): 25 20
    
        RESULT:
        After all operations, the list contains:
                                        20 → 25
                                        Head = 20
                                        Last node = 25
        Doubly linked traversal possible both ways and we found all list in the given menu.
