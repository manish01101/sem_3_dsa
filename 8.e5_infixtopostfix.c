#include<stdio.h>
#include<ctype.h>

#define maxsize 40
int tos = -1;
char stk[maxsize];
void push(char n){
    if (tos == (maxsize - 1))
        printf("stack overflow");
    else
        stk[++tos] = n;   
    return;
}
char pop(){
    if (tos == -1){
        printf("stack underflow! value not entered\n");
        return '\0';
    }
    else
        return stk[tos--];
}
int preced(char ch) {
    int x;
    if(ch == '(') x=1;
    if(ch == '^') x=5;
    if(ch == '*' || ch == '/' || ch == '%') x=4;
    if(ch == '+' || ch == '-') x=3;
    return x;
}


int main() {
    char inf[100], post[100];
    int j = 0, i=0;
    printf("enter infix: ");
    gets(inf);
    push('(');
    while(inf[i] != '\0'){
        if(isalpha(inf[i]))
            post[j++] = inf[i];
        else if(inf[i] == '(')
            push(inf[i]);
        else if(inf[i] == ')') {
            char ch = pop();
            while (ch != '(') {
                post[j++] = ch;
                ch = pop();
            }            
        }
        else { // operator
            while(preced(stk[tos]) >= preced(inf[i])) {
                char scanned = pop();
                post[j++] = scanned;
            }
            push(inf[i]);
        }
        i++;
    }
    post[j]='\0';
    printf("postfix expr: %s", post);
}