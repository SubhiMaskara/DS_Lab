#include<stdio.h>
#define size 50
int main(){
    int row,col,i,j,non_zero=0,k=0;
    int mat[size][size];
    printf("Enter size of sparce matrix");
    scanf("%d %d",&row,&col);
    printf("Enter element");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&mat[i][j]);
        }
    }  
    
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(mat[i][j]!=0)
            non_zero++;
        }
    }
    int s[non_zero+1][3];
    s[0][0]=row;
    s[0][1]=col;
    s[0][2]=non_zero;
    k=1;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
           if(mat[i][j]!=0){
            s[k][0]=i;
            s[k][1]=j;
            s[k][2]=mat[i][j];
            k++;
           }
        }
    }
    for(i=0;i<non_zero+1;i++){
        for(j=0;j<3;j++){
            printf("%d\t",s[i][j]);
        }
        printf("\n");
    }
    return 0;

}
