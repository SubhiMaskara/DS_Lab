#include<stdio.h>
#include<stdlib.h>
struct node
{
   int row;
   int colm;
   int num;
   struct node *next;
};
void create(struct node **head,int r,int c,int n){
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->next=NULL;
    new_node->row=r;
    new_node->colm=c;
    new_node->num=n;
 if(*head==NULL){
    *head=new_node;
 }
 else{
    struct node *temp=*head;
    for(temp=*head;temp->next!=NULL;temp=temp->next);
    temp->next=new_node;
    new_node->next=NULL;
 }
}
void display(struct node **head){
    struct node *temp=*head;
    for(temp=*head;temp!=NULL;temp=temp->next){
     printf("%d %d %d",temp->row,temp->colm,temp->num);
     printf("\n");
    }
}
#define size 30
int main(){
    struct node *head=NULL;
    int a[size][size];
    int n,m,nz=0,i,j;
    printf("Enter row and col number ");
    scanf("%d %d",&n,&m);
    printf("Enter element-");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]==0)
            nz++;
        }
    }
    create(&head,n,m,nz);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
          if(a[i][j]!=0){
            create(&head,i,j,a[i][j]);
          }
        }
    }
    printf("sparce matrix in 3 tuple format ");
    display(&head);
    return 0;
}
