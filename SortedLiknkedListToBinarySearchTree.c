#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode *getMid(struct ListNode* head){
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode *prev = NULL;
    while ((fast != NULL) && (fast->next != NULL)){
        prev = slow;
        fast = fast->next->next;
        slow = slow->next;
    }
    if (prev != NULL)
        prev->next = NULL;

    return slow;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (head == NULL)
        return NULL;

    struct ListNode* mid = getMid(head);

    // Allocate a new tree node for mid
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = mid->val;
    root->left = NULL;
    root->right = NULL;

    // Base case: if mid is the only node
    if (head == mid)
        return root;

    // Recursively build left and right subtrees
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(mid->next);

    return root;
}
struct ListNode* createNode(int value){
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

void traverseLinkedList(struct ListNode* head){
    if (head == NULL){
        printf("Linked List is empty");
        return;
    }
    struct  ListNode *curr = NULL;
    curr = head;
    while (curr != NULL){
        printf("%d->", curr->val);
        curr = curr->next;
    }
    printf("NULL");
}

struct ListNode* insertAtEnd(struct ListNode *head, int value){
    struct ListNode *newNode = createNode(value);
    if (head == NULL){
        return newNode;
    }
    struct ListNode *curr = head;
    while (curr->next != NULL){
        curr = curr->next;
    }
    curr->next = newNode;
    return head;
}

void inorderTraversal(struct TreeNode *root){
    if (root == NULL){
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

int main() {
    struct ListNode* head = NULL;
    int n, val, i;
    printf("Enter the no. of nodes in LinkedList: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++){
        scanf("%d", &val);
        head = insertAtEnd(head, val);
    }
    traverseLinkedList(head);

    struct TreeNode* root = sortedListToBST(head);

    printf("\nInorder Traversal: ");
    inorderTraversal(root);
    printf("\n");
    return 0;
}