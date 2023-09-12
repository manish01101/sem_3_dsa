#include <stdio.h>
#define maxsize 5
int tos = -1;
int stk[maxsize];

void push(int n) {
    if (tos == (maxsize - 1)) {
        printf("stack overflow");
        return;
    }
    else{
        stk[++tos] = n;
        return;
    }
}
int pop(){
    if (tos == -1){
        printf("stack underflow! value not entered\n");
        return -1;
    }
    else
        return stk[tos--];
}
void print(){
    int i = tos;
    while (i >= 0)
        printf("%d ", stk[i--]);
    printf("\n");
}

int main(){
    int choice, n;
    // first choice
    printf("enter choice 1-push,2-pop,3-print : ");
    scanf("%d", &choice);
    while(choice){
        switch (choice){
            case 1:
                printf("enter num : ");
                scanf("%d", &n);
                push(n);
                break;
            case 2:
                printf("\npopped element : %d\n", pop());
                break;
            case 3:
                printf("\nprinting stack : \n");
                print();
                break;
            default:
                printf("enter valid choice !\n");
                break;
        }
        printf("enter choice 1-push,2-pop,3-print : ");
        scanf("%d", &choice);
    }
    if(!choice) printf("exited from loop:)\n");
    return 0;
}