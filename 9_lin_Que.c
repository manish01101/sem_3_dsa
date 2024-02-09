#include<stdio.h>
#define maxsize 3
int q[maxsize];
int f = -1, r = -1;

int main() {
    int choice, ele, i;
    // first choice
    printf("enter choice 1-insert,2-del, 3-display: ");
    scanf("%d", &choice);

    while(choice) {
        switch (choice) {
            case 1: //insert
                printf("enter element to insert: ");
                scanf("%d", &ele);
                if(r == maxsize-1)
                    printf("queue is full!\n");
                else {
                    if(r == -1) {
                        f=0; r=0;
                        q[r] = ele;
                    }
                    else
                        q[++r] = ele;
                }
                break;
            case 2: //delete
                if(r == -1)
                    printf("queue is empty!\n");
                else {
                    if(f == r) {
                        f=-1; r=-1;
                    }
                    else
                        printf("\ndeleted ele: %d\n", q[f++]);
                }
                break;
            case 3:
                if(f==-1) {
                    printf("queue empty\n");
                    break;
                }
                printf("queue element: \n");
                for(i = f; i<=r; i++) {
                    printf("%d ", q[i]);
                }printf("\n");
                break;
            default:
                printf("enter valid choice!\n");
                break;
        }
        printf("enter choice 1-insert,2-del, 3-display: ");
        scanf("%d", &choice);
    }
    if(!choice) printf("program exited:)\n");
    return 0;
}
