

✅ Aim

To reverse a given string using stack operations, demonstrating the LIFO (Last In, First Out) property of a stack.


---

✅ Algorithm: String Reversal Using Stack

1. Start


2. Read the input string


3. Create a stack (array of characters)


4. For each character in the string:

Push the character onto the stack



5. Initialize an empty string for the reversed result


6. While the stack is not empty:

Pop each character and append it to the reversed string



7. Display the reversed string


8. Stop




---

✅ C Program: String Reversal Using Stack

#include <stdio.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

// Push function
void push(char c) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = c;
    }
}

// Pop function
char pop() {
    if (top == -1) {
        return '\0';  // stack empty
    } else {
        return stack[top--];
    }
}

int main() {
    char str[SIZE];
    char reversed[SIZE];
    int i;

    printf("Enter a string: ");
    gets(str);  // (For simplicity in small programs)

    // Push characters into stack
    for (i = 0; str[i] != '\0'; i++) {
        push(str[i]);
    }

    // Pop characters to reverse string
    for (i = 0; top != -1; i++) {
        reversed[i] = pop();
    }
    reversed[i] = '\0';  // Null terminate reversed string

    printf("Reversed string: %s\n", reversed);

    return 0;
}



✔ Example

Input: HELLO
Stack pushes: H → E → L → L → O
Pop order: O → L → L → E → H
Output: OLLEH

