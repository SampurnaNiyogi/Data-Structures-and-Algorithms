#define MAX_SIZE 6
#include<stdio.h>
#include<stdlib.h>
struct queue {
    int front;
    int rear;
    int arr[MAX_SIZE];
};

void peek(struct queue *myqueue){
    if (myqueue->front == -1){
        printf("Queue is empty");
        return;
    }
    printf("%d", myqueue->arr[myqueue->front]);
}

void enqueue(struct queue *myqueue, int val){
    if ((myqueue->front == -1) && (myqueue->rear == -1)){
        myqueue->front = 0;
        myqueue->rear = 0;
        myqueue->arr[myqueue->rear] = val;
        return;
    }
    else if (((myqueue->rear + 1)%MAX_SIZE) == myqueue->front){
        printf("Queue Overflow");
        return;
    }
    
    myqueue->rear=(myqueue->rear + 1)%MAX_SIZE;
    myqueue->arr[myqueue->rear] = val;
}

void dequeue(struct queue *myqueue){
    if (myqueue->front == -1){
        printf("Queue Underflow");
        return;
    }
    else if (myqueue->front == myqueue->rear){
        printf("%d", myqueue->arr[myqueue->front]);
        myqueue->front = -1;
        myqueue->rear = -1;
        return;
    }
    printf("%d", myqueue->arr[myqueue->front]);
    myqueue->front=(myqueue->front + 1)%MAX_SIZE;
}

void display(struct queue *myqueue){
    if ((myqueue->front == -1) && (myqueue->rear == -1)){
        printf("Queue Empty");
        return;
    }
    int i = myqueue->front;
    while (i != myqueue->rear){
        printf("%d | ", myqueue->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d", myqueue->arr[i]);
}


int main(){
    int ch;
    struct queue *myqueue = (struct queue *)malloc(sizeof(struct queue));
    myqueue->front = -1;
    myqueue->rear = -1;
    int value;
    while (1){
        printf("Press  1) Enqueue 2) Dequeue 3) Peek 4) Display 5) Exit\n Enter choice: ");
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
}