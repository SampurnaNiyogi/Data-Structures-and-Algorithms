#include<stdio.h>
#include<stdlib.h>
int *countingSort(int *A, int n){
    //k : largest value of  input array
    int k = -1;
    int i;
    for (i = 0; i<n;i++){
        if (A[i] > k){
            k = A[i];
        }
    }

    // C : Array storing the count of each element(initially initialised to 0)
    int *C = (int *)malloc((k+1)* sizeof(int));
    for (i = 0; i <= k; i++){
        C[i] = 0;
    }

    // Counting the no. of occurences of each element of A, the value of element of A is the index of C
    for (i = 0; i < n; i++){
        C[A[i]] += 1;
    }

    // Calculating the cummulative sum to get the index of each element for the new array which will store the sorted array
    for ( i = 0; i < k; i++)
    {
        C[i + 1] = C[i+1] + C[i];
    }

    // B : Array storing the sorted result
    int *B = (int *)malloc(n * sizeof(int));

    // Placing the element of A following the cummulative count of C in B
    // To maintain the stability the array is beng traversed from the end as the count stored is cumulative
    for (i = n-1; i>=0; i--){
        B[C[A[i]]-1] = A[i];
        C[A[i]] -= 1;
    }
    return B;
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
    A = countingSort(A, n);
    printArray(A, n);
    free(A);
}