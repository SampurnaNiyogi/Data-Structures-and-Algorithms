#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node* createNode(int value){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = newNode;
    return newNode;
}


void traverseLinkedList(node* head){
    if (head == NULL){
        printf("Linked List is empty");
        return;
    }
    node *curr = head;
    while (curr->next != head){
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("%d->%d", curr->data, curr->next->data);

}

node* insertAtBeginning(node* head, int value){
    node *newNode = createNode(value);
    if (head == NULL){
        return newNode;
    }
    node *ptr = head;
    while (ptr->next != head){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = head;
    head = newNode;
    return head;
}


node* insertAtEnd(node* head, int value){
    node *newNode = createNode(value);
    if (head == NULL){
        return newNode;
    }
    node *ptr = head;
    while (ptr->next != head){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = head;
    return head;
}

node* deleteAtFirst(node* head){
    if (head == NULL){
        printf("Nothing to delete");
        return head;
    }
    node *ptr = head;
    while (ptr->next != head){
        ptr = ptr->next;
    }
    ptr->next = head->next;
    free(head);
    head = head->next;
    return head;
}

node* deleteAtEnd(node* head){
    if (head == NULL){
        printf("Nothing to delete");
        return head;
    }
    node *ptr = head;
    while (ptr->next->next != head){
        ptr = ptr->next;
    }
    ptr->next = head;
    free(ptr);
    return head;
}


int main(){
    node *head = (node *)malloc(sizeof(node));
    head = NULL;
    int c = 6, data, ch, key;
    traverseLinkedList(head);
    while (c>0){
        printf("1: Insert at begin\n2: Insert at end\n3:Delete at first\n4: Delete at last\n5: Search\n6: Insert After a given value\n7: Insert before a given value\n8: Delete after certain value\n9: Delete before a certain value\n10: Insert at a position\n11: Delete at certain position\n12: Reverse a List");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch){
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                printf("After operation: ");
                traverseLinkedList(head);
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                printf("After operation: ");
                traverseLinkedList(head);
                break;
            case 3:
                head = deleteAtFirst(head);
                printf("After operation: ");
                traverseLinkedList(head);
                break;

            case 4:
                head = deleteAtEnd(head);
                printf("After operation: ");
                traverseLinkedList(head);
                break;
            default:
                printf("Wrong choice");
        }
        printf("\nTo exit enter any non-negative no. (Else enter any positive integer) ");
        scanf("%d", &c);
    }
    free(head);
    return 0;
}