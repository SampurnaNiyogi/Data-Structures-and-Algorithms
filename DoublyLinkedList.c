#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};

void insertAtBeginning(struct node **pointerToHead, struct node **pointerToTail, int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->prev = NULL;
    if (*pointerToHead == NULL){
        newNode->next = NULL;
        *pointerToHead = newNode;
        *pointerToTail = newNode;
        return;
    }
    newNode->next = *pointerToHead;
    (*pointerToHead)->prev = newNode;
    *pointerToHead = newNode;
    return;
}

void insertAtEnd(struct node **pointerToHead, struct node **pointerToTail, int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    if (*pointerToHead == NULL){
        newNode->prev = NULL;
        *pointerToHead = newNode;
        *pointerToTail = newNode;
        return;
    }
    (*pointerToTail)->next = newNode;
    newNode->prev = *pointerToTail;
    *pointerToTail = newNode;
}

void deleteAtBeginning(struct node **pointerTohead, struct node **pointerToTail){
    if (*pointerTohead == NULL){
        return;
    }
    struct node *deletedNode = *pointerTohead;
    if (*pointerTohead == *pointerToTail){
        *pointerTohead = NULL;
        *pointerToTail = NULL;
        free(deletedNode);
        return;
    }
    *pointerTohead = (*pointerTohead)->next;
    (*pointerTohead)->prev = NULL;
    free(deletedNode);
    return;
}

void deleteAtEnd(struct node **pointerTohead, struct node **pointerToTail){
    if (*pointerTohead == NULL){
        return;
    }
    struct node *deletedNode = *pointerTohead;
    if (*pointerTohead == *pointerToTail){
        *pointerTohead = NULL;
        *pointerToTail = NULL;
        free(deletedNode);
        return;
    }
    *pointerToTail = (*pointerToTail)->prev;
    (*pointerToTail)->next = NULL;
    free(deletedNode);
    return;
}

void traverseList(struct node *head, struct node *tail){
    if (head == NULL){
        printf("Linked List is empty : ");
        return;
    }
    struct node *ptr = head;
    printf("Linked List : ");
    while (ptr != tail->next){
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

int main(){
    struct node *head = NULL;
    struct node *tail = NULL;
    int ch, val;
    while (1)
    {
        printf("\n1: Insert at begin\n2: Insert at end\n3:Delete at first\n4: Delete at last\n5: Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d",&val);
            insertAtBeginning(&head, &tail, val);
            traverseList(head, tail);
            break;
        case 2:
            printf("Enter the value to be inserted: ");
            scanf("%d",&val);
            insertAtEnd(&head, &tail, val);
            traverseList(head, tail);
            break;
        case 3:
            deleteAtBeginning(&head, &tail);
            traverseList(head, tail);
            break;
        case 4:
            deleteAtEnd(&head, &tail);
            traverseList(head, tail);
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }
    }
    
}