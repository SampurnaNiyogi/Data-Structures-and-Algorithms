#include <stdlib.h>
#include<stdio.h>
struct queueNode {
    int data;
    struct queueNode *next;
};

struct queueLinkedList {
    struct queueNode *front;
    struct queueNode *rear;
};

void *enqueue(struct queueLinkedList *myqueue, int val){
    struct queueNode *newNode= (struct queueNode *)malloc(sizeof(struct queueNode));
    newNode->data = val;
    newNode->next=NULL;
    if ((myqueue->front == NULL) && (myqueue->rear == NULL)){
        myqueue->front = newNode;
        myqueue->rear = newNode;
        return NULL;
    }
    myqueue->rear->next = newNode;
    myqueue->rear = newNode;
    return NULL;    
}

void *dequeue(struct queueLinkedList *myqueue){
    int temp;
    if ((myqueue->front == NULL) && (myqueue->rear == NULL)){
        printf("Queue Underflow");
        return NULL;
    }
    if (myqueue->front == myqueue->rear){
        temp = myqueue->front->data;
        myqueue->front = NULL;
        myqueue->rear = NULL;
        printf("Dequeued : %d", temp);
        return NULL;
    }
    temp = myqueue->front->data;
    myqueue->front = myqueue->front->next;
    printf("Dequeued : %d", temp);
    return NULL;
}
void peek(struct queueLinkedList *myqueue){
    if ((myqueue->front == NULL) && (myqueue->rear == NULL)){
        printf("Queue Empty");
        return;
    }
    printf("%d", myqueue->front->data);
    return;
}

void display(struct queueLinkedList *myqueue){
    if ((myqueue->front == NULL) && (myqueue->rear == NULL)){
        printf("Queue Empty");
        return;
    }
    struct queueNode *curr = myqueue->front;
    while (curr != myqueue->rear){
        printf("%d | ", curr->data);
        curr = curr->next;
    }
    printf("%d", curr->data);
}

int main(){
    int ch;
    struct queueLinkedList *myqueue = (struct queueLinkedList *)malloc(sizeof(struct queueLinkedList));
    myqueue->front = NULL;
    myqueue->rear = NULL;    
    int value;
    while (1){
        printf("\nPress  1) Enqueue 2) Dequeue 3) Peek 4) Display 5) Exit\n Enter choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter value to be enqueued: ");
            scanf("%d", &value);
            enqueue(myqueue, value);
            break;
        case 2:
            dequeue(myqueue);
            break;

        case 3:
            peek(myqueue);
            break;
        case 4:
            display(myqueue);
            break;
        
        case 5:
            exit(0);

        default:
            printf("Wrong input");
            break;
        }
    }
    free(myqueue);
}