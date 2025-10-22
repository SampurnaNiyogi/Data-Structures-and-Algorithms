#include<stdio.h>
#include<stdlib.h>
void print2DArray(int **A, int n, int m){
    int i, j;
    for ( i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");        
    }
    
}

int main(){
    int n, m;
    printf("Enter no. of rows: ");
    scanf("%d", &n);
    printf("Enter no. of columns: ");
    scanf("%d", &m);
    int **A = (int **)malloc(n * sizeof(int *));
    int i, j, count=0;
    for ( i = 0; i < n; i++){
        A[i] = (int *)malloc(m * sizeof(int));
        for (j = 0; j < m; j++){
           scanf("%d",&A[i][j]) ;
        }   
    }
    for ( i = 0; i < n; i++){
        for (j = 0; j < m; j++){
           if (A[i][j] != 0) count++;      
        }   
    }
    int **B = (int **)malloc((count+1) * sizeof(int *));
    B[0] = (int *)malloc(3 * sizeof(int));
    B[0][0] = n;
    B[0][1] = m;
    B[0][2] = count;
    int si= 1;
    for ( i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            if (A[i][j] != 0){
                B[si] = (int *)malloc(3*sizeof(int));
                B[si][0] = i;
                B[si][1] = j;
                B[si][2] = A[i][j];
                si++;
            }
        }   
    }
    print2DArray(B, count+1, 3);

    printf("==============Transpose of sparse matrix================\n");
    int temp;
    temp = B[0][0];
    B[0][0] = B[0][1];
    B[0][1] = temp;
    for (i = 1; i <= count; i++){
        temp = B[i][0];
        B[i][0] = B[i][1];
        B[i][1] = temp;
    }
    print2DArray(B, count+1, 3);

    printf("============Transposed n*m Matrix from spare representation===========\n");
    A = (int **)realloc(A, B[0][0] * sizeof(int *));
    for ( i = 0; i < B[0][0]; i++){
        A[i] = (int *)realloc(A[i], B[0][1] * sizeof(int));
        for (j = 0; j < B[0][1]; j++){
           A[i][j] = 0;
        }   
    }
    for (i = 1; i <= B[0][2]; i++){
        A[B[i][0]][B[i][1]] = B[i][2];
    }
    print2DArray(A, B[0][0], B[0][1]);
}

