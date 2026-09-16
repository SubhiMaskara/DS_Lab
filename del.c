#include<stdio.h>
#define size 100
void deletion(int a[],int n,int pos);
int maximum(int a[],int n,int k);

int maximum(int a[],int n,int k){
    int max=a[0],i=0,j=0,pos=0;
    for(i=0;i<k;i++){
        max=a[0];
        pos=0;
       for(j=0;j<n;j++){
        if(max<a[j])
        {
            max=a[j];
            pos=j;
        }
       }
       deletion (a,n,pos);
       n--;
    }
    return max;
}

void deletion(int a[],int n,int pos){
    int i=0;
    for(i=pos;i<n-1;i++){
        a[i]=a[i+1];
    }
}

int main(){
    int n,k,max,i;
    int a[size];
    printf("enter number of element");
    scanf("%d",&n);
    printf("Enter elements-");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter k");
    scanf("%d",&k);
    if(k>n || k<1){
        printf("not valid input");
        return 1;
    }
    max=maximum(a,n,k);
    printf("%dth maximum = %d",k,max);
    return 0;
}