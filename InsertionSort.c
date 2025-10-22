#include<stdio.h>
#include<stdlib.h>
void insertionSort(int *A, int size){
    int i, j, key;
    for (j = 1; j < size; j++){
        key = A[j];
        i = j-1;
        while ((i >= 0) && (A[i]>key)){
            A[i+1] = A[i];
            i = i - 1;
        }
        A[++i] = key;
    }
}

void printArray(int *arr,int n){
    int i;
    for (i = 0; i < n ; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int n;
    printf("Enter size of Array: ");
    scanf("%d", &n);
    int *A = (int *)malloc(n*sizeof(int));
    int i;
    for (i = 0; i<n; i++){
        scanf("%d", &A[i]);
    }
    insertionSort(A, n);
    printArray(A, n);
    free(A);
}