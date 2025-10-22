#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;


node *createNode(int data){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void traverseList(node *head){
    if (head == NULL){
        printf("Linked List is empty");
        return;
    }
    node *ptr = head;
    while (ptr != NULL){
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

node *insert_at_end(int data, node *head){
    node *newNode = createNode(data);
    if (head == NULL){
        return newNode;
    }
    node *ptr = head;
    while (ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    return head;
}

node *insert_at_begin(int data, node *head){
    node *newNode = createNode(data);
    if (head == NULL){
        return newNode;
    }
    newNode->next = head;
    head = newNode;
    return head;
}

node *delete_at_end(node *head){
    if (head == NULL){
        printf("Nothing to delete");
        return head;
    }
    node *ptr = head;
    while (ptr->next->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = NULL;
    return head;
}

node *delete_at_first(node *head){
    if (head == NULL){
        printf("Nothing to delete");
        return head;
    }
    head = head->next;
    return head;
}

void search(int key, node *head){
    int index = 0;
    if (head == NULL){
        printf("Linked List is empty");
        return;
    }
    node *ptr = head;
    while (ptr != NULL){
        if (ptr->data == key){
            printf("Element found at %d", index);
        }
        ptr = ptr->next;
        index++;
    }
}

node* insertAfterValue(int val, node *head, int key){
    node *newNode = createNode(val);
    int inserted=0;
    if (head == NULL){
        printf("No value found for inserting. First node created with the given value");
        return newNode;
    }
    node *curr = head;
    while (curr != NULL){
        if (curr->data == key){
            newNode->next=curr->next;
            curr->next = newNode;
            inserted=1;
        }
        curr = curr->next;
    }
    if (!inserted) printf("No equal value found after which it is to be inserted.");
    return head;
}

node* deleteAfterValue(node *head, int key){
    int deleted=0;
    if (head == NULL){
        printf("No value found for which next element is to be deleted");
        return head;
    }
    node *curr = head;
    node *temp;
    while (curr->next != NULL){
        if (curr->data == key){
            temp = curr->next->next;
            curr->next = temp;
            deleted=1;
        }
        curr = curr->next;
    }
    if (!deleted) printf("No equal value found after which the element is to be deleted.");
    return head;
}

node* insertBeforeValue(int val, node *head, int key){
    node *newNode = createNode(val);
    int inserted=0;
    if (head == NULL){
        printf("No value found for inserting. First node created with the given value");
        return newNode;
    }
    node *curr = head;
    node *temp;
    while (curr->next != NULL){
        temp = curr->next;
        if (temp->data == key){
            newNode->next=temp;
            curr->next = newNode;
            inserted=1;
            break;
        }
        curr = curr->next;
    }
    if (!inserted) printf("No equal value found after which it is to be inserted.");
    return head;
}

node* deleteBeforeValue(node *head, int key){
    int deleted=0;
    if (head == NULL){
        printf("No value found for which next element is to be deleted");
        return head;
    }
    node *curr = head;
    node *temp;
    while (curr->next->next != NULL){
        if (curr->next->next->data == key){
            temp = curr->next->next;
            curr->next = temp;
            deleted=1;
        }
        curr = curr->next;
    }
    if (!deleted) printf("No equal value found after which the element is to be deleted.");
    return head;
}

node* insertAtPosition(int val, node *head, int key){
    node *newNode = createNode(val);
    int inserted=0;
    if (head == NULL){
        printf("First node created with the given value");
        return newNode;
    }
    node *curr = head;
    int count = 0;
    while (curr != NULL){
        if (key == 0){
            newNode->next=head;
            head=newNode;
            inserted=1;
            break;
        }
        if (count == key-1){
            newNode->next=curr->next;
            curr->next=newNode;
            inserted=1;
        }
        curr=curr->next;
        count++;
        if (!inserted) printf("No equal value found after which it is to be inserted.");
    }

    return head;
}
node* deleteAtPosition(node *head, int key){
    int deleted=0;
    if (head == NULL){
        printf("Nothing to delete");
        return head;
    }

    node *curr = head;
    int count = 0;
    while (curr != NULL){
        if (key == 0){
            head = head->next;
            deleted=1;
            break;
        }

        if (count == key-1){
            curr->next = curr->next->next;
            deleted=1;
        }
        count++;
        curr = curr->next;
    }
    if (!deleted) printf("position not within range");
    return head;
}

node* reverseLinkedList(node *head){
    if (head == NULL){
        printf("Nothing to reverse");
        return head;
    }

    node *curr = head;
    node *next = curr->next;
    node *prev = NULL;
    while (curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    return head;
}

int main(){
    node *head = (node *)malloc(sizeof(node));
    head = NULL;
    int c = 6, data, ch, key;
    while (c>0){
        printf("1: Insert at begin\n2: Insert at end\n3:Delete at first\n4: Delete at last\n5: Search\n6: Insert After a given value\n7: Insert before a given value\n8: Delete after certain value\n9: Delete before a certain value\n10: Insert at a position\n11: Delete at certain position\n12: Reverse a List");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch){
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                head = insert_at_begin(data, head);
                printf("After operation: ");
                traverseList(head);
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                head = insert_at_end(data, head);
                printf("After operation: ");
                traverseList(head);
                break;

            case 3:
                head = delete_at_first(head);
                printf("After operation: ");
                traverseList(head);
                break;

            case 4:
                head = delete_at_end(head);
                printf("After operation: ");
                traverseList(head);
                break;

            case 5:
                printf("Enter element to search: ");
                scanf("%d", &data);
                search(data, head);
                break;

            case 6:
                printf("Enter the value after which: ");
                scanf("%d", &key);
                printf("Enter value to be inserted: ");
                scanf("%d", &data);
                head = insertAfterValue(data, head, key);
                printf("After operation: ");
                traverseList(head);
                break;

            case 7:
                printf("Enter the value before which: ");
                scanf("%d", &key);
                printf("Enter value to be inserted: ");
                scanf("%d", &data);
                head = insertBeforeValue(data, head, key);
                printf("After operation: ");
                traverseList(head);
                break;

            case 8:
                printf("Enter the value after which: ");
                scanf("%d", &key);
                head = deleteAfterValue(head, key);
                printf("After operation: ");
                traverseList(head);
                break;

            case 9:
                printf("Enter the value after which: ");
                scanf("%d", &key);
                head = deleteBeforeValue(head, key);
                printf("After operation: ");
                traverseList(head);
                break;

            case 10:
                printf("Enter position no.: ");
                scanf("%d", &key);
                printf("Enter value to be inserted: ");
                scanf("%d", &data);
                head = insertAtPosition(data, head, key);
                printf("After operation: ");
                traverseList(head);
                break;

            case 11:
                printf("Enter position no.: ");
                scanf("%d", &key);
                head = deleteAtPosition(head, key);
                printf("After operation: ");
                traverseList(head);
                break;

            case 12:
                head = reverseLinkedList(head);
                printf("After Reversing:");
                traverseList(head);
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
