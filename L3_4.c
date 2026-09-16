#include<stdio.h>
#define size 50
int main(){
    int poly1[size];
    int poly2[size];
    int poly3[size];
    int i=0,j=0;
    int n1,n2,n3;
    printf("Enter maximum degree poly ");
    scanf("%d",&n1);
    printf("Enter polynomial1 from lowest to highest");
    for(i=0;i<=n1;i++){
      scanf("%d",&poly1[i]);
    }
    printf("Enter maximum degree poly ");
    scanf("%d",&n2);
    printf("Enter polynomial2 from lowest to highest");
    for(i=0;i<=n2;i++){
      scanf("%d",&poly2[i]);
    }
    n3=n1+n2;
    for(i=0;i<=n3;i++){
        poly3[i]=0;
    }
    for(i=0;i<=n1;i++){
        for(j=0;j<=n2;j++){
           poly3[i+j]+=poly1[i]*poly2[j];
        }
    }
    for(i=0;i<=n3;i++){
        printf("%d x^%d  ",poly3[i],i);
    }
    return 0;
}