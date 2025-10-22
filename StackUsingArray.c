#include<stdio.h>
#define MAX_SIZE 15

int top = -1;

struct stack {
    int top;
    int array[MAX_SIZE];
} mystack;

void push(int val) {
    if (top == MAX_SIZE) {
        printf("Stack overflow\n");
        return;
    }
    top++;
    mystack.array[top] = val;
    return;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow");
    }
    int temp = mystack.array[top];
    top--;
    return temp;
}

int peek() {
    if (top == -1) {
        printf("Stack Empty");
        return -1;
    }
    int temp = mystack.array[top];
    return temp;
}

void display() {
    int i;
    for (i = 0; i <= top; i++) {
        printf("%d\n", mystack.array[i]);
    }
}

int main() {
    int c = 6, val, ch;
    while (c != 0) {
        printf("1: push\n2: pop\n3: peek\n4: display\n");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                printf("%d", pop());
                break;
            case 3:
                printf("%d", peek());
                break;
            case 4:
                display();
                break;
            default:
                printf("Wrong choice");
        }
        printf("\nTo exit enter 0 ");
        scanf("%d", &c);
    }
    return 0;
}