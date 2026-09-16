#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void push(int n,char st[n],int *top,char ch){
    if((*top)==n-1)
    printf("stack overflow");
    else{
        (*top)++;
        st[*top]=ch;
    }
}
char pop(int n,char st[n],int *top){
    char ch;
    if(*top==-1){
        printf("stack underflow");
    }
    else
    {
        ch=st[*top];
        (*top)--;
        return ch;

    }
}
void palindrone(int n,char st[n],int *top){
    char ch1[n];
    char ch2[n];
    char ch;
    int i=0;
    for(i=0;i<n;i++){
        ch1[i]=st[i];
    }
    for(i=0;i<n;i++){
        ch2[i]=pop(n,st,top);
    }
    int temp=0;
    for(i=0;i<n;i++){
        if(ch2[i]!=ch1[i])
        {
            temp=1;
            break;
        }
    }
    if(temp==1){
        printf("not palindrone");
    }
    else{
        printf("palindrone");
    }
}
#define size 50;
int main(){
   int n,i,len=0;
   n=size;
   char ch[n];
   printf("enter string");
   scanf("%s",ch);
    len = strlen(ch);
   char st[len];
    i=0;
   int top=-1;
   while(i<len){
    push(len,st,&top,ch[i]);
    i++;
   }
   palindrone(len,st,&top);
   return 0;
}