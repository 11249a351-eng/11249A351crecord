AIM:
To write a C program to reverse a given string using stack operations.

ALGORITHM:
1. Start
2. Read the input string
3. Push each character of the string into a stack
4. Pop characters from stack and store them back into the string
Since stack uses LIFO, the string becomes reversed.
5. Display reversed string
6. End

PROGRAM — String Reversal Using Stack:
#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ch;
}

// Pop operation
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

int main() {
    char str[MAX];
    int i;

    printf("Enter a string: ");
    scanf("%s", str);

    // Push all characters
    for (i = 0; i < strlen(str); i++) {
        push(str[i]);
    }

    // Pop all characters to reverse
    for (i = 0; i < strlen(str); i++) {
        str[i] = pop();
    }

    printf("Reversed string: %s\n", str);

    return 0;
}

OUTPUT:
Enter a string: HELLO
Reversed string: OLLEH
       RESULT:
       Input string HELLO becomes:
       OLLEH
       The string is successfully reversed using stack operations (push/pop).
