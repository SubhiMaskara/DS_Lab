#include<stdio.h>
#define size 4
#define size2 3
int main()
{ int i,j,temp;
    int sp[size][size2];
    printf("Enter elements of sparse matrix:");
    for(i=0;i<=size;i++){
        for( j=0;j<3;j++)
        {
            scanf("%d",&sp[i][j]);
        }
    }
    for( i=0;i<=size;i++){

            if(sp[i][0]!=sp[i][1]){
                temp=sp[i][0];
                sp[i][0]=sp[i][1];
                sp[i][1]=temp;
        }
    }
    printf("Elements of transpose:");
    for( i=0;i<=size;i++){
        for( j=0;j<3;j++)
        {
            printf("%d ",sp[i][j]);
        }
        printf("\n");
    }
    return 0;
}