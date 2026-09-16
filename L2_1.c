#include<stdio.h>
#include<stdlib.h>
void insert(int arr[],int n,int pos,int num){
     int i;
     pos=pos-1;
     for(i=n-1;i>=pos+1;i--){
        arr[i]=arr[i-1];
     }
     arr[pos]=num;
}
void delete(int arr[],int n,int pos){
pos=pos-1;
int i;
for(i=pos;i<n-1;i++){
    arr[i]=arr[i+1];
}
}
int linear(int arr[],int n,int num){
    int i;
    for(i=0;i<n;i++){
        if(arr[i]==num)
        return i;
    }
    return -1;
}
void traversal(int arr[],int n,char ope,int num){
    int i;
     if(ope=='+'){
    for(i=0;i<n;i++){
        arr[i]=arr[i]+num;
    }}
     else if(ope=='-'){
    for(i=0;i<n;i++){
        arr[i]=arr[i]-num;
    }}
     else if(ope=='*'){
    for(i=0;i<n;i++){
        arr[i]=arr[i]/num;
    }}
    else if(ope=='/'){
    for(i=0;i<n;i++){
        arr[i]=arr[i]/num;
    }}
}

int main(){
    int *arr;char opera;
    int n,i,op,num,pos,index;
    printf("Enter number of element");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter elements-");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("MENU \n 1.insert \n 2.delete \n 3.linear search \n 4.traverse \n 5.Exit");
    printf("Enter option-");
    scanf("%d",&op);
    if(op==1){
        n=n+1;
      arr=(int*)realloc(arr,n*sizeof(int));
      printf("enter element to be inserted and pos-");
      scanf("%d %d",&num,&pos);
      insert(arr,n+1,pos,num);
    }
    else if(op==2){
        printf("Enter pos for element to be deleted");
        scanf("%d",&pos);
        delete(arr,n,pos);
        n=n-1;
    }
    else if(op==3){
        printf("Enter element to be search");
        scanf("%d",&num);
        index=linear(arr,n,num);
        if(index!=-1){
        printf("position=%d",index+1);}
        else{
            printf("Element not found");
        }
        return 0;
    }
    else if(op==4){
        printf("Enter operation to be done on each element-");
        scanf(" %c",&opera);
        printf("Enter a number-");
        scanf("%d",&num);
        traversal(arr, n, opera, num);
    }
    else{
        return 1;
    }
    printf("New array-");
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    free (arr);
    return 0;

}