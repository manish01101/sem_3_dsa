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
    if(ch == '(') x=100;
    if(ch == '^') x=500;
    if(ch == '*' || ch == '/' || ch == '%') x=400;
    if(ch == '+' || ch == '-') x=300;
    return x;
}


int main() {
    char inf[100], pos[100];
    int j = 0, i=0;
    printf("enter infix: ");
    gets(inf);
    push('(');
    while(inf[i] != '\0'){
        if(isalpha(inf[i]))
            pos[j++] = inf[i];
        else if(inf[i] == '(')
            push(inf[i]);
        else if(inf[i] == ')') {
            char ch = pop();
            while (ch != '(') {
                pos[j++] = ch;
                ch = pop();
            }            
        }
        else {
            while(preced(stk[tos]) >= preced(inf[i])) {
                char scanned = pop();
                pos[j++] = scanned;
            }
            push(inf[i]);
        }
        i++;
    }
    pos[j]='\0';
    printf("postfix expr: %s", pos);
}