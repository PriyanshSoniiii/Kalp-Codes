#include<stdio.h>
#include<stdlib.h>
void display(int *arr,int row,int col){
    printf("\n");
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            printf("%d ",*(arr + i*col +j));
        }
        printf("\n");
    }
}
void transformMatrix(int *arr,int row,int col){
    for(int i=0,j=0;i<row && j<col;++i,++j){
            int temp = (*(arr+i*col+j));
            (*(arr+i*col+j)) = (*(arr+i*col+(col-j-1)));
            (*(arr+i*col+(col-j-1))) = temp;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int row;
    scanf("%d",&row);
    int *arr = (int*)malloc(row*row*sizeof(int));
    for(int i=0;i<row;++i){
        for(int j=0;j<row;++j){
            int temp;
            scanf("%d",&temp);
            *   (arr + i*row +j) = temp;
        }
    }
    transformMatrix(arr,row,row);
    display(arr,row,row);
    return 0;
}

/*5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25*/