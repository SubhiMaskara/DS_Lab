#include<stdio.h>
#define size 100
int main(){
    int a[100];
    int n,i,pos,del;
    printf("Enter number of elements-");
    scanf("%d",&n);
    if(n>size){
        printf("Array size exceeds maximum limit.\n");
        return 1;
    }
    printf("Enter elements-");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
   for(i=0;i<n-1;i++){
    a[i]=a[i+1];
   }
   for(i=0;i<n-1;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}