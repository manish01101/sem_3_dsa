#include<stdio.h>

int main() {
    int arr[50];
    int size, i;
    int maxi, mini;
    int pos, element, flag, choice;

    printf("enter size : ");
    scanf("%d", &size);
    printf("enter arr ele: ");
    for(i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }

    maxi=arr[0];
    mini=arr[0];
    // for first time - choice
    printf("enter choice 1-Max&Min, 2-insert, 3-remove, 4-display: ");
    scanf("%d", &choice);

    while(choice){
        switch (choice){
            case 1: //max and min
                for(i=0; i<size; i++) {
                    if(arr[i] > maxi) maxi = arr[i];
                    else if(arr[i] < mini) mini = arr[i];
                }
                printf("max element is %d & min is %d\n", maxi, mini);
                break;
            case 2: //insert
                printf("enter position : ");
                scanf("%d", &pos);
                printf("enter element : ");
                scanf("%d", &element);
                
                for(i=size-1; i>=pos; i--){
                    arr[i+1] = arr[i];
                }
                arr[pos] = element;
                break;
            case 3: //remove
                flag=0;
                printf("enter element : ");
                scanf("%d", &element);
                for(i=0; i<size; i++){
                    if(arr[i] == element){
                        pos=i;
                        flag=1;
                    }
                }
                if(flag){
                    for(i=pos; i<size-1; i++)
                        arr[i] = arr[i+1];
                    size--; //arr[i]=0;
                }
                else printf("element not found\n");
                break; 
            case 4: //print
                printf("\narray is : \n");
                for(i=0; i<size; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;
            default:
                printf("enter valid choice!\n");
                break;
        }
        printf("enter choice 1-Max&Min, 2-insert, 3-remove, 4-display: ");
        scanf("%d", &choice);
    }
    return 0;
}