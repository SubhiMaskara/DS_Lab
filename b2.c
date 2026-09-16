#include<stdio.h>
#define size 100
int main(){
    int a[size];
    int n,i,max,min,max2,min2;
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
    max2=min;
    min2=max;
    for(i=0;i<n;i++){
        if(a[i]>max2 && a[i]!=max)
        max2=a[i];
        if(a[i]<min2 && a[i]!=min)
        min2=a[i];
    }
    printf("Second Maximum integer =%d\n",max2);
    printf("Second Minimum integer=%d",min2);
    return 0;
}