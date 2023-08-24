#include<stdio.h>
#define maxsize 3
int cq[maxsize];
int f = -1, r = -1;

int main() {
    int choice, ele, i;
    // begining choice
    printf("enter choice 1-insert,2-del, 3-display: ");
    scanf("%d", &choice);

    while(choice) {
        switch (choice) {
            case 1: //insert rear
                printf("enter element to insert: ");
                scanf("%d", &ele);
                if((f==0 && r==maxsize-1) || (r+1==f))
                    printf("queue is full!\n");
                else {
                    if(r == -1) {
                        f=0; r=0;
                        cq[r] = ele;
                    }
                    else if(r == maxsize-1) {
                        r=0;
                        cq[r] = ele;
                    }
                    else
                        cq[++r] = ele;
                }
                break;
            case 2: //delete front
                if(f == -1)
                    printf("queue is empty!\n");
                else {
                    int n = cq[f];
                    if(f == r) {
                        f=-1; r=-1;
                    } 
                    else if(f==maxsize-1)
                        f=0;
                    else
                        f++;
                    printf("\ndeleted ele: %d\n", n);
                }
                break;
            case 3:
                printf("queue element: \n");
                if(f<=r) {
                    for(i = f; i<=r; i++) {
                        printf("%d ", cq[i]);
                    }printf("\n");
                }
                else {
                    for(i = f; i<maxsize; i++) {
                        printf("%d ", cq[i]);
                    }
                    for(i = 0; i<=r; i++) {
                        printf("%d ", cq[i]);
                    }
                    printf("\n");
                }
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
