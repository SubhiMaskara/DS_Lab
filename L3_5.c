#include<stdio.h>
#define size 30
int search(int sp[size][3],int nz, int r,int c){
int i=0,j=0;
for(i=0;i<nz;i++){
    for(j=0;j<3;j++){
        if(sp[i][0]==r && sp[i][1]==c){
            return 0;
        }
    }}
    return 1;

}
int findindex(int sp[size][3],int nz, int r,int c){
    int i=0,j=0,ind=0;
    for(i=0;i<nz;i++){
       for(j=0;j<3;j++){
        if(sp[i][0]==r && sp[i][1]==c){
            ind=i;
            break;
        }
    }}
    return ind;

}
int main()
{
int i,j,k,nz=0,test,ind,nz1=0;
 int s1[size][3];
 int s2[size][3];
 int s3[size][3];
 int s3_final[size][3];
 int n1,n2;
 printf("Enter number of zeros in matrix 1");
 scanf("%d",&n1);
 printf("Enter elemets in sparse matrix 1");
 for(i=0;i<=n1;i++){
    for(j=0;j<3;j++){
        scanf("%d",&s1[i][j]);
    }
 }
 printf("Enter number of zeros in matrix 2");
 scanf("%d",&n2);
 printf("Enter elements in sparse matrix 2");
 for(i=0;i<=n2;i++){
    for(j=0;j<3;j++){
        scanf("%d",&s2[i][j]);
    }
 }
 if( s1[0][1]!=s2[0][0]){
   printf("Multiplication not possible");
   return 1;
 }
 for(i=0;i<size;i++){
    for(j=0;j<3;j++){
        s3[i][j]=0;
    }
 }
nz=1;
s3[0][0]=s1[0][0];
s3[0][1]=s2[0][1];
for(i=1;i<=n1;i++){
    for(j=1;j<=n2;j++){
      if(s1[i][1]==s2[j][0]){
        test= search(s3,nz,s1[i][0],s2[j][1]);
        if(test==1){
        s3[nz][0]=s1[i][0];
        s3[nz][1]=s2[j][1];
        s3[nz][2]+=s1[i][2]*s2[j][2];
        nz++;
      }}
      else{
        ind=findindex(s3,nz,s1[i][0],s2[j][1]);
        s3[ind][2]+=s1[i][2]*s2[j][2];
      }
      nz1++;
    }
}
s3[0][2]=nz1-1;
for(i=0;i<=nz-1;i++){
   for(j=0;j<3;j++){
    printf("%d ",s3[i][j]);
   }
   printf("\n");
}
return 0;
}