#include<stdio.h>

int main() {
    int arr[30][30];
    int tuple[100][3];
    int row, col, nonzeroele, k=0, zeroele=0;
    printf("enter row & col: ");
    scanf("%d %d", &row, &col);
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
            scanf("%d", &arr[i][j]);
    }
    //counting no of zero and printing original matrix
    printf("\noriginal matrix: \n");
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ", arr[i][j]);
            if(arr[i][j]==0) zeroele++;
        }
        printf("\n");
    }
    
    nonzeroele = (row*col) - zeroele;

    if(zeroele > (row*col)/2) {
        printf("\nsparse matrix");
        tuple[k][0]=row;
        tuple[k][1]=col;
        tuple[k][2]=nonzeroele;
        k++;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(arr[i][j]!=0){
                    tuple[k][0]=i;
                    tuple[k][1]=j;
                    tuple[k][2]=arr[i][j];
                    k++;
                }
            }
            printf("\n");
        }
        for(int i=0; i<=nonzeroele; i++){
            for(int j=0; j<3; j++)
                printf("%d ", tuple[i][j]);
            printf("\n");
        }
        // // transforming tuple to new original matrix
        // printf("\nsparse reverse: \n");
        // int newrow = tuple[0][0];
        // int newcol = tuple[0][1];
        // // int newArr[newrow][newcol];
        // int newArr[3][3];
        // //initialize all ele with zero
        // for(int i=0; i<newrow; i++){
        //     for(int j=0; j<newcol; j++){
        //         newArr[i][j]=0;
        //     }
        // }
        // //reassigning nonzero ele
        // for(int i=1; i<=nonzeroele; i++){
        //     int rowindex = tuple[i][0];
        //     int colindex = tuple[i][1];
        //     int newval = tuple[i][2];

        //     newArr[rowindex][colindex] = newval;
        // }

        // printf("\nprinting new origninal matrix: \n");
        // for(int i=0; i<newrow; i++){
        //     for(int j=0; j<newcol; j++){
        //         printf("%d ", newArr[i][j]);
        //     }printf("\n");
        // }
    }
    else
        printf("not a sparse matrix");
}