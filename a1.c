#include<stdio.h>
void splitting_point(char st[], int inp){
    int i=0,j=0,k=0,temp=0;
    char sub1[50],sub2[50];
    while(st[i] != '\0' ){
        if(temp==0 && st[i]!='.'){
           sub1[i]=st[i];
           k++;
        }
        else if(st[i] == '.'){
            temp=1;
        }
        else if(temp==1){
          sub2[j]=st[i];
          j++;
        }
        i++;
      }
      sub1[k]='\0';
      sub2[j]='\0';
      if(temp==1){
      if(inp==0){
        printf("%s",sub1);
      }
      else{
        printf("%s",sub2);
      }}
      else{
        printf("not found character");
      }
    }
int main(){
    char s[50];
    int inp;
    printf("Enter a string");
    scanf("%s",s);
    printf("Either 1 or 0");
    scanf("%d",&inp);
    splitting_point(s,inp);
    return 0;
}