#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Heap Overflow! Cannot add element.\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack.\n", value);
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return -1;
    }
    struct Node* temp = top;
    int poppedValue = temp->data;
    top = top->next;
    free(temp);
    return poppedValue;
}

int peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}

void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* ptr = top;
    printf("Stack elements (from top to bottom): ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;
    printf("\n--- Stack Implementation using Linked List ---\n");
    while (1) {
        printf("\n---------- MENU ----------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (View Top)\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("--------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped value is: %d\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("The top element is: %d\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}