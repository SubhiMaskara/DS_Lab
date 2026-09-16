#include<stdio.h>
#include<stdlib.h>
int prime(int *p)
{
  int i,fac=0;
  for(i=1;i<=*p;i++){
    if(*p%i==0)
    fac++;
  }
  return fac;
  
}
int main(){
    int n,i,fac=0,sum;
    int *p;
    printf("Enter number of elements-");
    scanf("%d",&n);
    p=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",p+i);
    }
    for(i=0;i<n;i++){
     fac=prime(p+i);
    if(fac==2)
    sum=sum+*(p+i);
    }
    printf("Sum=%d",sum);
    return 0;
}