#include<stdio.h>
#define size 100
int main(){
    char ch[100];
    int i=0,j=0,n,off;
    printf("Enter number of elements-");
    scanf("%d",&n);
    if(n>size){
        printf("Character Array size exceeds maximum limit.\n");
        return 1;
    }
    printf("Enter elements-");
    for(i=0;i< n;i++){
        scanf(" %c",&ch[i]);
    }
    printf("Enter offset-");
    scanf("%d",&off);
    if(off < 0){
        for(i=0;i<-off;i++){
            for(j=0;j<n;j++){
            if(ch[j]=='A'){
               ch[j]='Z';
            }
            else
            ch[j]=ch[j]-1;
        }
    }}
    else{
        for(i=0;i<off;i++){
            for(j=0;j<n;j++){
            if(ch[j]=='Z'){
               ch[j]='A';
            }
            else
            ch[j]=ch[j]+1;
        }
    }
}
for(i=0;i<n;i++){
    printf("%c\n",ch[i]);
}
return 0;
}