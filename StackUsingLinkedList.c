#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* push(struct Node *head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL){
        head = newNode;
        return head;
    }
    newNode->next = head;
    head = newNode;
    return head;
}

int pop(struct Node *head) {
    if (head == NULL){
        printf("Underflow condition");
        return -1;
    }
    struct Node *temp = head;
    head = head->next;
    return temp->data;
}

int peek(struct Node *head) {
    if (head == NULL){
        printf("Stack is empty");
        return -1;
    }
    struct Node *temp = head;
    return temp->data;
}

void display(struct Node *head) {
    if (head == NULL){
        printf("Stack is empty");
        return;
    }
    struct Node *curr = head;
    while (curr->next != NULL){
        printf("%d -> ", curr->data);
        curr = curr->next;        
    }
    printf("%d", curr->data);
}

int main() {
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head = NULL;
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
                head = push(head, value);
                break;
            case 2:
                value = pop(head);
                if (value != -1) {
                    printf("Popped value is: %d\n", value);
                }
                break;
            case 3:
                value = peek(head);
                if (value != -1) {
                    printf("The top element is: %d\n", value);
                }
                break;
            case 4:
                display(head);
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