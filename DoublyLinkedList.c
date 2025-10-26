#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};

void insertAtBeginning(struct node **pointerToHead, int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->prev = NULL;
    if (*pointerToHead == NULL){
        newNode->next = NULL;
        *pointerToHead = newNode;
        return;
    }
    newNode->next = *pointerToHead;
    *pointerToHead = newNode;
    return;
}

void insertAtEnd(struct node **pointerToHead, int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    if (*pointerToHead == NULL){
        newNode->prev = NULL;
        *pointerToHead = newNode;
        return;
    }
    struct node *curr = *pointerToHead;
    while (curr->next != NULL){
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->prev = curr;
}

void deleteAtBeginning(struct node **pointerTohead){
    if (*pointerTohead == NULL){
        return;
    }
    struct node *deletedNode = *pointerTohead;
    *pointerTohead = (*pointerTohead)->next;
    (*pointerTohead)->prev = NULL;
    free(deletedNode);
    return;
}

void deleteAtEnd(struct node **pointerTohead){
    if (*pointerTohead == NULL){
        return;
    }
    struct node *curr = *pointerTohead;
    while (curr->next != NULL){
        curr = curr->next;
    }
    struct node *deletedNode = curr;
    curr->prev->next = NULL;
    free(deletedNode);
}

void traverseList(struct node *head){
    if (head == NULL){
        printf("Linked List is empty : ");
        return;
    }
    struct node *ptr = head;
    printf("Linked List : ");
    while (ptr != NULL){
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

int main(){
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head = NULL;
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
            insertAtBeginning(&head, val);
            traverseList(head);
            break;
        case 2:
            printf("Enter the value to be inserted: ");
            scanf("%d",&val);
            insertAtEnd(&head, val);
            traverseList(head);
            break;
        case 3:
            deleteAtBeginning(&head);
            traverseList(head);
            break;
        case 4:
            deleteAtEnd(&head);
            traverseList(head);
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }
    }
    
}