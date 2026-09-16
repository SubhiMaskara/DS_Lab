#include<stdio.h>
#define size 100
int main(){
    int a[size];
    int n,i,pos,inser;
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
    printf("Enter element to be inserted-");
    scanf("%d",&inser);
    printf("Enter position ");
    scanf("%d",&pos);
    pos--;
    for(i=n;i>pos-1;i--){
        a[i]=a[i-1];
    }
    a[pos]=inser;
    for(i=0;i<=n;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}