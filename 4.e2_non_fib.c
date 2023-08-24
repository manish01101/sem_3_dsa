#include<stdio.h>

int fib(int n) {
    //base case
    if(n==0 || n==1) return n;
    return fib(n-1) + fib(n-2);
}

int main() {
    int n;
    printf("enter n: ");
    scanf("%d", &n);
    printf("non series: \n");

    int x = 1;
    int fib1 = fib(x);
    int fib2 = fib(x+1);
    int cnt = 1;
    while(n>=0){
        for(int i=fib1+1; i<fib2; i++) {
            printf("%d ", i);
            n--;
            x++;
            fib1 = fib(x);
            fib2 = fib(x+1);
        }
    }
}