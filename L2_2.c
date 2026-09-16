#include<stdio.h>
#define size 100
int non_zero(int n,int mat[size][size]){
    int freq=0;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(mat[i][j]!=0)
            freq++;
        }
    }
    return freq;
}
void upper_triangle(int n,int mat[size][size]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i<j)
            printf("%d",mat[i][j]);
            else
            printf(" ");
        }
        printf("\n");
    }
}
void no_diagonal(int n,int mat[size][size]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j)
            printf(" ");
            else
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n,i,j,freq;
    int mat[size][size];
    printf("Enter size of 2D matrix");
    scanf("%d",&n);
    if(n>100 && n<1){
    printf("Invalid input");
    return 1;
}
    printf("Enter element");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&mat[i][j]);
        }
    }  
    freq=non_zero(n,mat);
    printf("Number of non zero element %d\n",freq);
    printf("Upper triangle\n");
    upper_triangle( n, mat);
    printf("Without diagonal\n");
    no_diagonal( n, mat);
    return 0;
}

