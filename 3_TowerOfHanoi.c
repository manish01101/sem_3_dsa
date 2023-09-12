#include<stdio.h>
void tower(int n, char s, char a, char d) {
    //base case
    if(n==1){
        printf("\nmove disk %d from %c to %c", n, s, d);
        return;
    }
    tower(n-1, s, d, a); //step 1
    //step 2
    printf("\nmove disk %d from %c to %c", n, s, d);
    //step 3
    tower(n-1, a, s, d);
}

int main() {
    int n;
    char src='A', aux='B', des='C';
    printf("enter no. of disks");
    scanf("%d", &n);
    tower(n, src, aux, des);
}