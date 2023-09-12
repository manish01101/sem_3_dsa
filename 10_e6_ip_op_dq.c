#include<stdio.h>
#define maxsize 3
int dq[maxsize];
int f = -1, r = -1;
int choice, ele, i;

void print() {
    printf("queue element: \n");
    if(f<=r) {
        for(i = f; i<=r; i++)
            printf("%d ", dq[i]);
        printf("\n");
    }
    else {
        for(i = f; i<maxsize; i++)
            printf("%d ", dq[i]);
        for(i = 0; i<=r; i++)
            printf("%d ", dq[i]);
        printf("\n");
    }
}

void insert_front(int val) {
    if((f==0 && r==(maxsize-1)) || (f == r+1))
        printf("queue full\n");
    else {
        if(f == -1) {
            f = 0; r = 0;
        } 
        else if (f==0)
            f = maxsize-1;
        else
            f--;
        dq[f] = val;
    }  
}

void insert_rear(int val) {
    if((f==0 && r==maxsize-1) || (r+1==f))
        printf("queue is full!\n");
    else {
        if(r == -1) {
            f=0; r=0;
        }
        else if(r == maxsize-1)
            r=0;
        else
            r++;
        dq[r] = ele;    
    }
}

int delete_front() {
    if(f == -1){
        printf("queue is empty!\n");
        return -99;
    }
    else {
        int n = dq[f];
        if(f == r) {
            f=-1; r=-1;
        } 
        else if(f==maxsize-1)
            f=0;
        else
            f++;
        return n;
    }
}

int delete_rear() {
    if(r == -1){
        printf("queue is empty\n");
        return -99;
    }
    else {
        int n = dq[r];
        if(f == r) {
            f=-1; r=-1;
        }
        else if(r==0)
            r = maxsize-1;
        else
            r--;
        return n;
    }
}

void inputRestricted() {
    int inputRestChoice;
    printf("\nyou choose i/p restricted q;\n");
    // first choice
    printf("enter choice: 0-exit, 1-insert_rear_restr, 2-insert_front_restr, : ");
    scanf("%d", &inputRestChoice);
    

    while(inputRestChoice) {
        switch (inputRestChoice) {
            case 1://insert front
                int insFrChoice;
                printf("\nyou choose insert-rear-restr:\n");
                printf("enter choice 0:exit, 1:insert_front, 2:delete_front, 3:delete_rear:\n");
                scanf("%d", &insFrChoice);

                while(insFrChoice) {
                    switch (insFrChoice) {
                        case 1: //insert front
                            printf("\nenter ele to insert: ");
                            scanf("%d", &ele);
                            insert_front(ele);
                            break;
                        case 2: //delete front
                            ele = delete_front();
                            printf("deleted ele: %d\n", ele);
                            break;
                        case 3: //delete rear
                            ele = delete_rear();
                            printf("deleted ele: %d\n", ele);
                            break;
                        default:
                            printf("enter valid choice\n");
                            break;
                    }
                    printf("enter choice 0:exit, 1:insert_front, 2:delete_front, 3:delete_rear:\n");
                    scanf("%d", &insFrChoice);
                }
                break;
            case 2://insert rear
                int insRrChoice;
                printf("\nyou choose insert-front-restr:\n");
                printf("enter choice 0:exit, 1:insert_rear, 2:delete_front, 3:delete_rear:\n");
                scanf("%d", &insRrChoice);
                while(insRrChoice) {
                    switch (insRrChoice) {
                        case 1: //insert rear
                            printf("enter ele to insert: ");
                            scanf("%d", &ele);
                            insert_rear(ele);
                            break;
                        case 2: //delete front
                            ele = delete_front();
                            printf("deleted ele: %d\n", ele);
                            break;
                        case 3: //delete rear
                            ele = delete_rear();
                            printf("deleted ele: %d\n", ele);
                            break;
                        default:
                            printf("enter valid choice\n");
                            break;
                    }
                    printf("enter choice 0:exit, 1:insert_rear, 2:delete_front, 3:delete_rear:\n");
                    scanf("%d", &insRrChoice);
                }
                break;
        default:
            printf("enter valid choice\n");
            break;
        }
        printf("enter choice: 0-exit, 1-insert_rear_restr, 2-insert_front_restr, : ");
        scanf("%d", &inputRestChoice);
    }
}

void outputRestricted() {
    int ouputRestChoice;
    printf("\nyou choose o/p restricted q;\n");
    printf("enter choice: 0-exit, 1-delete_rear_restr, 2-delete_front_restr: ");
    scanf("%d", &ouputRestChoice);
    // first time choice
    while(ouputRestChoice) {
        switch (ouputRestChoice) {
            case 1://delete front
                int delFrChoice;
                printf("\nyou choose delete-rear-restr:\n");
                printf("enter choice 0: exit, 1:delete_front, 2:insert_front, 3:insert_rear:\n");
                scanf("%d", &delFrChoice);

                while (delFrChoice) {
                    switch (delFrChoice) {
                        case 1: // delete front
                            ele = delete_front();
                            printf("deleted ele: %d\n", ele);
                            break;
                        case 2: // insert front
                            printf("enter ele to insert: ");
                            scanf("%d", &ele);
                            insert_front(ele);
                            break;
                        case 3: // insert rear
                            printf("enter ele to insert: ");
                            scanf("%d", &ele);
                            insert_rear(ele);
                            break;
                        default:
                            printf("enter valid choice\n");
                            break;
                    }
                    printf("enter choice 0: exit, 1:delete_front, 2:insert_front, 3:insert_rear:\n");
                    scanf("%d", &delFrChoice);
                }
                break;
            case 2://delete rear
                int delRrChoice;
                printf("\nyou choose delete-front-restr:\n");
                printf("choice choice 0:exit, 1:delete_rear, 2:insert_front, 3:insert_rear:\n");
                scanf("%d", &delRrChoice);

                while (delRrChoice) {
                    switch (delRrChoice) {
                        case 1: // delete rear
                            ele = delete_rear();
                            printf("deleted ele: %d\n", ele);
                            break;
                        case 2: //insert front
                            printf("enter ele to insert: ");
                            scanf("%d", &ele);
                            insert_front(ele);
                            break;
                        case 3: //insert rear
                            printf("enter ele to insert: ");
                            scanf("%d", &ele);
                            insert_rear(ele);
                            break;
                        default:
                            printf("enter valid choice\n");
                            break;
                    }
                    printf("choice choice 0:exit, 1:delete_rear, 2:insert_front, 3:insert_rear:\n");
                    scanf("%d", &delRrChoice);
                }
                break;
            default:
                printf("enter valid choice\n");
                break;
        }
        printf("enter choice: 0-exit, 1-delete_rear_restr, 2-delete_front_restr: ");
        scanf("%d", &ouputRestChoice);
    }
}

int main() {
    printf("enter choice 0-exit, 1-i/p, 2-o/p restricted, 3-print q: ");
    scanf("%d", &choice);
    while(choice) {
        switch (choice) {
            case 1://input restricted
                inputRestricted();
                break;
            case 2: //output restricted
                outputRestricted();
                break;
            case 3:
                print();
                break;
            default:
                printf("enter valid choice\n");
                break;
        }
        printf("enter choice 0-exit, 1-i/p, 2-o/p restricted, 3-print q: ");
        scanf("%d", &choice);
    }
    return 0;
}
