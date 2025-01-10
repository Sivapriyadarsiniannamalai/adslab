#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // Maximum size of the stack

int stack[MAX];
int top = -1; // Initialize the stack as empty

// Function to push an element into the stack
void push() {
    int val;
    if (top == MAX - 1) { // Check if the stack is full
        printf("\nStack Overflow! Cannot push more elements.\n");
    } else {
        printf("\nEnter the element to push: ");
        scanf("%d", &val);
        top++;
        stack[top] = val;
        printf("%d pushed into the stack.\n", val);
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) { // Check if the stack is empty
        printf("\nStack Underflow! No elements to pop.\n");
    } else {
        int popped = stack[top];
        top--;
        printf("%d popped from the stack.\n", popped);
    }
}

// Function to view the top element of the stack
void peek() {
    if (top == -1) { // Check if the stack is empty
        printf("\nThe stack is empty. No top element.\n");
    } else {
        printf("\nThe top element is: %d\n", stack[top]);
    }
}

// Function to display all elements of the stack
void display() {
    if (top == -1) { // Check if the stack is empty
        printf("\nThe stack is empty.\n");
    } else {
        printf("\nStack elements are:\n");
        for (int i = 0; i <= top; i++) { // Loop through the stack
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) { // Infinite loop for the menu
        printf("\n--- Stack Operations Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
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
                printf("\nExiting the program.\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
