✅ Aim
To convert a given infix expression (e.g., A + B * C) into a postfix expression (e.g., ABC*+) using a stack, based on operator precedence and associativity.

✅ Algorithm: Infix to Postfix (Using Stack)

Let S be the stack and P be the postfix string.

1. Scan the infix expression from left to right.

2. For each character x:

If x is an operand → Add it to postfix (P).

If x is ‘(’ → Push it onto stack.

If x is ‘)’ →
Pop and add to postfix until ‘(’ is encountered.
Pop ‘(’ from stack but don’t add it to postfix.

If x is an operator ( +, -, *, /, ^ ):

While stack is not empty AND
precedence(top of stack) ≥ precedence(x),
pop and add to postfix

Push x to stack



3. After scanning the expression:

Pop all remaining operators from the stack and add to postfix.

4. Output postfix expression.


Operator	Precedence	Associativity

^	Highest	Right to Left
* /	Medium	Left to Right
+ -	Lowest	Left to Right


✅ C Program: Infix to Postfix Conversion Using Stack

#include <stdio.h>
#include <ctype.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

// Stack operations
void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

// Function to return precedence
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

int main() {
    char infix[50], postfix[50];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        
        // If operand, add to postfix
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        // If opening bracket, push
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        // If closing bracket, pop until '('
        else if (infix[i] == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop();  // remove '('
        }
        // If operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
SAMPLE OUTPUT
Enter Infix Expression: A+(B*C-(D/E^F)*G)*H
Postfix Expression: ABC*DEF^/G*-H*+
    For the input:
A+(B*C-(D/E^F)*G)*H
The postfix expression is:
ABC*DEF^/G*-H*+
    result:
This is the correct postfix conversion, following operator precedence and associativity.
