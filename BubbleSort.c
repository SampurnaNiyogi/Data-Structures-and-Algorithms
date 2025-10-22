#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    int i, j, temp, comp=0;
    for (i = 0; i < n-1; i++) {       
        for (j = 0; j < n-i-1; j++) {
            comp++;
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Total comparisons: %d\n", comp);
    
}

void improvedBubbleSort(int arr[], int n) {
    int i, j, temp, comp=0;
    int swapped;
    for (i = 0; i < n-1; i++) {       
        swapped = 0;
        for (j = 0; j < n-i-1; j++) {
            comp++;
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
    printf("Total comparisons: %d\n", comp);
}

void cocktailShakerSort(int arr[], size_t n){
    size_t i, j;
    int tmp,comp=0;

    for (i = 0; i < n / 2; ++i) {
        
        for (j = i; j + 1 < n - i; ++j) {
            comp++;
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }

        for (j = n - i - 1; j > i; --j) {
            comp++;
            if (arr[j - 1] > arr[j]) {
                tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    printf("Total comparisons: %d\n", comp);
}
void cocktailSortImproved(int arr[], int n) {
    int start = 0, end = n-1;
    int swapped = 1, i, temp, comp=0;

    while (swapped) {
        swapped = 0;

        for (i = start; i < end; i++) {
            comp++;
            if (arr[i] > arr[i+1]) {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        end--;

        for (i = end-1; i >= start; i--) {
            comp++;
            if (arr[i] > arr[i+1]) {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swapped = 1;
            }
        }
        start++;
    }
    printf("Total comparisons: %d\n", comp);
}
int main(){
    int *arr = (int *)malloc(16*sizeof(int));
    int i;
    for (i = 0; i < 15; i++) {
        arr[i] = rand() % 100; 
    }
    int *temp1 = (int *)malloc(16*sizeof(int));
    int *temp2 = (int *)malloc(16*sizeof(int));
    int *temp3 = (int *)malloc(16*sizeof(int));
    int *temp4 = (int *)malloc(16*sizeof(int));
    memcpy(temp1, arr, 15*sizeof(int));
    memcpy(temp2, arr, 15*sizeof(int));
    memcpy(temp3, arr, 15*sizeof(int));
    memcpy(temp4, arr, 15*sizeof(int));
    printf("Original array: \n");
    printArray(arr, 15);
    printf("Sorted array using Bubble Sort: \n");
    bubbleSort(temp1, 15);
    printArray(temp1, 15);
    printf("Sorted array using Improved Bubble Sort: \n");
    improvedBubbleSort(temp2, 15);
    printArray(temp2, 15);
    printf("Sorted array using Cocktail Sort: \n");
    cocktailShakerSort(temp3, 15);
    printArray(temp3, 15);
    printf("Sorted array using Improved Cocktail Sort: \n");
    cocktailSortImproved(temp4, 15);
    printArray(temp4, 15);
    free(arr);
    free(temp1);    
    free(temp2);    
    free(temp3);
    free(temp4);
    return 0;
}