#include<stdio.h>
#define size 50
#define size2 3
int main(){
    int i,j,k,nz1,nz2;
    int sp1[size][size2];
    int sp2[size][size2];
    int sp3[size][size2];
    printf("Enter number of sero in sparse matrix 1");
    scanf("%d",&nz1);
    printf("Enter elements of sparse matrix1:");
    for(i=0;i<=nz1;i++){
        for( j=0;j<3;j++)
        {
            scanf("%d",&sp1[i][j]);
        }
    }
    printf("Enter number of zero in sparse matrix 2");
    scanf("%d",&nz2);
    printf("Enter elements of sparse matrix2:");
    for(i=0;i<=nz2;i++){
        for( j=0;j<3;j++)
        {
            scanf("%d",&sp2[i][j]);
        }
    }
    if(sp1[0][0] != sp2[0][0] || sp1[0][1] != sp2[0][1]){
        printf("Addition not possible");
        return 1;
    }
    sp3[0][0]=sp1[0][0];
    sp3[0][1]=sp1[0][1];
    i=1,j=1,k=1;
    while(i<=nz1 && j<=nz2){
        if(sp1[i][0]==sp2[j][0]){
            if(sp1[i][1]==sp2[j][1]){
                sp3[k][0]=sp1[i][0];
                sp3[k][1]=sp1[i][1];
                sp3[k][2]=sp1[i][2]+sp2[j][2];
                k++;
                i++;
                j++;
            }
            else if(sp1[i][1]<sp2[j][1]){
                sp3[k][0]=sp1[i][0];
                sp3[k][1]=sp1[i][1];
                sp3[k][2]=sp1[i][2];
                k++;
                i++;
            }
            else{
                sp3[k][0]=sp2[j][0];
                sp3[k][1]=sp2[j][1];
                sp3[k][2]=sp2[j][2];
                k++;
                j++;
            }
        }
        else if(sp1[i][0]<sp2[j][0]){
            sp3[k][0]=sp1[i][0];
                sp3[k][1]=sp1[i][1];
                sp3[k][2]=sp1[i][2];
                k++;
                i++;
        }
        else{
            sp3[k][0]=sp2[j][0];
                sp3[k][1]=sp2[j][1];
                sp3[k][2]=sp2[j][2];
                k++;
                j++;
        }
    }
    if(i<=nz1){
       while(i<=nz1){
        sp3[k][0]=sp1[i][0];
        sp3[k][1]=sp1[i][1];
        sp3[k][2]=sp1[i][2];
        k++;
        i++;
       }
    }
    else if(j<=nz2){
        while(j<=nz2){
        sp3[k][0]=sp2[j][0];
        sp3[k][1]=sp2[j][1];
        sp3[k][2]=sp2[j][2];
        k++;
         j++;   
        }
    }
    sp3[0][2]=k-1;
    printf("Resultant matrix in 3 tuple format\n");
        for(i=0;i<=k-1;i++){
            for(j=0;j<3;j++){
        printf("%d\t",sp3[i][j]);
    }
    printf("\n");
}
return 0;
}