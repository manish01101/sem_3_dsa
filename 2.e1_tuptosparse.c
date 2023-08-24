#include<stdio.h>

int main() {
    int arr[30][30];
    int tuple[100][3];
    int row, col, nonzeroele, k=0, zeroele=0;

    printf("enter no of nonzero ele: ");
    scanf("%d", &nonzeroele);
    printf("enter tuple : ");
    for(int i=0; i<=nonzeroele; i++){
        for(int j=0; j<3; j++)
            scanf("%d", &tuple[i][j]);
    }
    row = tuple[0][0];
    col = tuple[0][1];
    //initialize all ele with zero
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            arr[i][j]=0;
        }
    }
    //reassigning nonzero ele
    for(int i=1; i<=nonzeroele; i++){
        int rowindex = tuple[i][0];
        int colindex = tuple[i][1];
        int newval = tuple[i][2];

        arr[rowindex][colindex] = newval;
    }
    printf("\nprinting new origninal matrix: \n");
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ", arr[i][j]);
        }printf("\n");
    }
    return 0;
}