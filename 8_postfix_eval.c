#include<stdio.h>
#include<ctype.h>

#define maxsize 5
int tos = -1;
int stk[maxsize];

void push(int n){
    if (tos == (maxsize - 1))
        printf("stack overflow");
    else
        stk[++tos] = n;
}
int pop(){
    if (tos == -1){
        printf("stack underflow! value not entered\n");
        return -1;
    }
    else
        return stk[tos--];
}

int eval(char ch, int x, int y) {
    switch (ch){
    case '+':
        return x+y;
    case '-':
        return x-y;
    case '*':
        return x*y;
    case '/':
        return x/y;
    case '%':
        return x%y;
    case '^':
        return x^y;
    default:
        break;
    }
}

int solve(char str[]){
    int x, y, i=0;
    //scanning
    while(str[i] != '\0') {
        //operand - push
        char ch = str[i];
        if(ch == ')') {
            return stk[tos];
        }
        if(isalpha(ch)) {
            int n;
            printf("enter value of %c :", ch);
            scanf("%d", &n);
            push(n);
        }
        // operator - 2-pop
        else {
            x = pop();
            y = pop();
            int res = eval(ch, x, y);
            push(res);
        }
        i++;
    }
}

int main() {
    //string expr
    char str[100];

    printf("enter postfix expr: ");
    gets(str);
    int i = 0;
    while(str[i] != '\0')
        i++;
    str[i++] = ')';
    str[i] == '\0';

    //solve
    int ans = solve(str);
    printf("ans is: %d \n", ans);
}