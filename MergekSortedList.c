/*
    Merging K - sorted Linked List
    Approach:
    1) The head of each linked list is inserted into a heap
    2) Use min heap to get the smallest val
    3) Insert the next node of the smallest val and minHeapify again
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void minHeapify(struct ListNode **arr, int i, int size){
    int l = (2*i)+1;
    int r = (2*i)+2;
    int smallestIndex;
    struct ListNode *temp;
    if ((l < size) && (arr[l]->val < arr[i]->val)){
        smallestIndex = l;
    }
    else{
        smallestIndex = i;
    }
    if ((r < size) && (arr[r]->val < arr[smallestIndex]->val)){
        smallestIndex = r;
    }
    if (smallestIndex != i){
        temp = arr[i];
        arr[i] = arr[smallestIndex];
        arr[smallestIndex] = temp;
        minHeapify(arr, smallestIndex, size);
    }
}

void buildMinHeap(struct ListNode **arr, int size){
    int i;
    for (i = (size-1)/2; i >= 0; i--){
        minHeapify(arr, i, size);
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int i, j=0;
    struct ListNode **heap = (struct ListNode **)malloc(listsSize * sizeof(struct ListNode *));
    if (heap == NULL){
        return NULL;
    }
    for (i = 0; i < listsSize; i++){
        if (lists[i] != NULL){
            heap[j] = lists[i];
            j++;
        }
    }
    struct ListNode *head;
    struct ListNode *curr = (struct ListNode *)malloc(sizeof(struct ListNode));
    curr->next = NULL;

    int heapSize = j;
    if (heapSize == 0) {
        free(heap); 
        free(curr); 
        return NULL;
    }
    buildMinHeap(heap, heapSize);
    
    head = curr;

    while (heapSize != 0){
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = heap[0]->val;
        newNode->next = NULL;
        curr->next = newNode;
        curr = curr->next;
        if (heap[0]->next == NULL){
            heap[0] = heap[heapSize - 1];
            heapSize--;
        }
        else heap[0] = heap[0]->next;
        if (heapSize > 0) {
            minHeapify(heap, 0, heapSize);
        }
    }
    curr = NULL;
    
    free(head);
    free(heap);

    return head->next; 
}

int main() {
    int k;
    printf("How many lists do you want to merge? ");
    scanf("%d", &k);

    if (k <= 0) {
        printf("No lists to merge.\n");
        return 0;
    }

    struct ListNode** lists = (struct ListNode**)malloc(k * sizeof(struct ListNode*));
    if (lists == NULL) {
        printf("Failed to allocate memory for lists array.\n");
        return 1;
    }

    
    for (int i = 0; i < k; i++) {
        int listSize;
        printf("\nEnter number of nodes for list%d (0 for empty): ", i + 1);
        scanf("%d", &listSize);

        if (listSize <= 0) {
            printf("Wrong input");
            continue; 
        }

        printf("Enter %d sorted values for list %d (space-separated): ", listSize, i + 1);
        
        struct ListNode* head = NULL;
        struct ListNode* curr = NULL;
        for (int j = 0; j < listSize; j++) {
            int val;
            scanf("%d", &val);
            struct ListNode* newNode = createNode(val);
            
            if (newNode == NULL) {
                printf("Error: Memory allocation failed for a new node.\n");
                freeList(head);
                for(int n = 0; n < i; n++) {
                freeList(lists[n]);
                }
                free(lists);
                return 1;
            }

            if (head == NULL) {
                head = newNode;
                curr = newNode;
            } else {
                curr->next = newNode;
                curr = newNode;
            }
        }
        lists[i] = head; 
    }

    printf("\nOriginal lists:\n");
    for (int i = 0; i < k; i++) {
        printList(lists[i]);
    }

    struct ListNode* mergedHead = mergeKLists(lists, k);

    printf("\nMerged list:\n");
    printList(mergedHead);

    freeList(mergedHead);
    
    
    for (int i = 0; i < k; i++) {
        freeList(lists[i]);
    }
    
    free(lists);

    return 0;
}