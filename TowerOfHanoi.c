#include<stdio.h>
int move(int, char, char, char);

int main(){
    int n;
    printf("Enter the number of rings: ");
    scanf("%d", &n);
    int moves = move(n, 'A', 'B', 'C');
    printf("\nTotal no. of moves: %d", moves);
    return 0;
}

int move(int n, char source, char dest, char spare){
    static int count = 0;
    if (n == 1){
        count++;
        printf("\nMove from %c to %c", source, dest);
    }
    else{
        move(n-1, source, spare, dest);
        move(1, source, dest, spare);
        move(n-1,spare, dest, source);
    }
    return count;
}