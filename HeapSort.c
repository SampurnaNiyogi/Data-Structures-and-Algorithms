#include<stdio.h>
#include<stdlib.h>

/*Max-Heapify
    1) Assign index of left and right child to l and r 
    2) Find the largest of the three l, r and i and assign it to the parent index
    3) Result: The parent has the highest weight
    4) However if its parent is greater than the current parent but smaller than its child the max heap is disturbed
    5) Hence MaxHeapify is again called on the index with maximum weight thus resolving the disturbance in lower branches....
*/
void maxHeapify(int *A, int i, int size){
    int l = (2*i + 1);
    int r = (2*i + 2);
    int largestIndex;
    int temp;
    if (A[l]>A[i] && l<size){
        largestIndex = l;
    }
    else {
        largestIndex = i;
    }
    if (A[r]>A[largestIndex] && r<size){
        largestIndex = r;
    }
    if (i != largestIndex){
        temp = A[i];
        A[i] = A[largestIndex];
        A[largestIndex] = temp;
        maxHeapify(A, largestIndex, size);
    }
    
}

/* Build Max Heap
    1) Find last heap node with children (length[A]/2-1)
    2) call MaxHeapify to each node from last heap with children -> 0
*/
void buildMaxHeap(int *arr, int size){
    int i;
    for (i = (size-2)/2; i >= 0; i--){
        maxHeapify(arr, i, size);
    }
}

/* Heap Sort use max heap array
    1) The parent of the entire heap is always the maximum element hence it is exchanged with the last element
    2) The heap size is reduced by 1 returning the last element in a new array
    3) Calling only max heapify on the top element(the one which was the last element and hence smaller than its children) again puts the maximum element of the entire heap to the top
*/
void heapSort(int *A, int size){
    int i, temp;
    int heap_size = size;
    for (i = size-1; i >= 0; i--){
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        heap_size -= 1;
        maxHeapify(A, 0, heap_size);
    }
}

void printHeap(int *arr,int n){
    int i;
    for (i = 0; i < n ; i++){
        printf("%d ", arr[i]);
    }
}
int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int *A = (int *)malloc(n*sizeof(int));
    // Create heap
    int i;
    for (i = 0; i<n; i++){
        scanf("%d", &A[i]);
    }

    buildMaxHeap(A, n);
    printf("\n");
    heapSort(A, n);
    printHeap(A, n);
    free(A);
    return 0;
}