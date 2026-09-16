#include<stdio.h>
#define size 50
int main(){
    int poly1[size];
    int poly2[size];
    int i=0;
    int n;
    printf("Enter maximum degree poly ");
    scanf("%d",&n);
    printf("Enter polynomial1 from lowest to highest");
    for(i=0;i<=n;i++){
      scanf("%d",&poly1[i]);
    }
    printf("Enter polynomial2 from lowest to highest");
    for(i=0;i<=n;i++){
      scanf("%d",&poly2[i]);
    }
    
       for(i=0;i<=n;i++){
        poly1[i]=poly1[i]+poly2[i];
       }
       for(i=n;i>=0;i--){
        printf("%dx^%d\t",poly1[i],i);
       }
    
   
    return 0;
}