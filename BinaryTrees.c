#include <stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct queueNode {
    struct node *treeNode;
    struct queueNode *next;
};

struct queueList{
    struct queueNode *front;
    struct queueNode *rear;
};

void *enqueue(struct queueList *myqueue, struct node *mynode){
    struct queueNode *newQueueNode = (struct queueNode *)malloc(sizeof(struct queueNode));
    newQueueNode->treeNode = mynode;
    newQueueNode->next = NULL;
    if ((myqueue->front == NULL) && (myqueue->rear == NULL)){
        myqueue->front = newQueueNode;
        myqueue->rear = newQueueNode;
        return NULL;
    }
    myqueue->rear->next = newQueueNode;
    myqueue->rear = newQueueNode;
    return NULL;
}

struct node *dequeue(struct queueList *myqueue){
    if ((myqueue->front == NULL) && (myqueue->rear == NULL)){
        printf("Queue Underflow");
        return NULL;
    }
    if (myqueue->front == myqueue->rear){
        struct node *tempNode = myqueue->front->treeNode;
        myqueue->front = NULL;
        myqueue->rear = NULL;
        return tempNode;
    }
    struct node *tempNode = myqueue->front->treeNode;
    myqueue->front = myqueue->front->next;
    return tempNode;
}

int arr[13] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
int idx = -1;
struct node *buildBinaryTreePreorder(){
    idx++;
    if (arr[idx] == -1){
        return NULL;
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = arr[idx];
    newnode->left = buildBinaryTreePreorder();
    newnode->right = buildBinaryTreePreorder();
    return newnode;
}

void preorderTraversal(struct node *root){
    if (root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(struct node *root){
    if (root == NULL){
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void postorderTraversal(struct node *root){
    if (root == NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

void levelorderTraversal(struct node *root){
    if (root == NULL) {
        return;
    }
    struct queueList *myqueue = (struct queueList *)malloc(sizeof(struct queueList));
    myqueue->front = NULL;
    myqueue->rear = NULL; 
    enqueue(myqueue, root);
    enqueue(myqueue, NULL);
    struct node *dequeuedValue;
    while ((myqueue->front != NULL) && (myqueue->rear != NULL)){
        dequeuedValue = dequeue(myqueue);
        if (dequeuedValue == NULL){
            printf("\n");
            if ((myqueue->front == NULL) && (myqueue->rear == NULL)){
                break;
            }
            else{
                enqueue(myqueue, NULL);
            }
        }
        else {
            printf("%d ", dequeuedValue->data);
            if (dequeuedValue->left != NULL){
                enqueue(myqueue, dequeuedValue->left);
            }
            if (dequeuedValue->right != NULL){
                enqueue(myqueue, dequeuedValue->right);
            }
        }
    }
}

int main(){
    struct node *root = buildBinaryTreePreorder();
    printf("%d", root->data);
    printf("\n--------PreOrder Traversal------------\n");
    preorderTraversal(root);
    printf("\n--------InOrder Traversal------------\n");
    inorderTraversal(root);
    printf("\n--------PostOrder Traversal------------\n");
    postorderTraversal(root);
    printf("\n--------LevelOrder Traversal------------\n");
    levelorderTraversal(root);
}