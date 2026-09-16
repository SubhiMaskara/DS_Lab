#include<stdio.h>
# define size 100 
int main(){
    int n,i,max,min;
    int a[size];
    printf("Enter a number");
    scanf("%d",&n);
    if(n>size){
        printf("Array size exceeds maximum limit.\n");
        return 1;
    }
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    max=a[0];
    min=a[0];
    for(i=0;i<n;i++){
        if(a[i]>max)
        max=a[i];
        if(a[i]<min)
        min=a[i];
    }
    printf("Maximum integer =%d\n",max);
    printf("Minimum integer=%d",min);
    return 0;
}