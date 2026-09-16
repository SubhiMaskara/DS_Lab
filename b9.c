#include<stdio.h>
#define size 100
#define size2 200
int main(){
    int a1[size],a2[size],a3[size2];
    int n1,n2,i=0,j=0;
    printf("Enter size of array one and two");
    scanf("%d %d",&n1,&n2);
    if(n1>size && n2>size && n1+n2>size2){
        printf("Array size exceeds maximum limit.\n");
        return 1;
    }
    printf("Enter elements-");
    for(i=0;i<n1;i++){
        scanf("%d",&a1[i]);
    }
    printf("Enter elements-");
    for(i=0;i<n2;i++){
        scanf("%d",&a2[i]);
    }
    for(i=0;i<n1+n2;i++){
        if(i<n1){
            a3[i]=a1[i];
        }
        else{
            a3[i]=a2[j];
            j++;
        }
    }
    for(i=0;i<n1+n2;i++){
        printf("%d\t",a3[i]);
    }
    return 0;
}