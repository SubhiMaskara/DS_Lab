#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;
struct node *tail;
void create(int num){
   struct node *new_node;
   new_node=(struct node*)malloc(sizeof(struct node));
   new_node->next=NULL;
   new_node->prev=NULL;
   new_node->data=num;
   if(head==NULL){
    head=new_node;
    tail=new_node;
   }
   else{
    tail->next=new_node;
    new_node->prev=tail;
    tail=new_node;
   }
}
void insert(int n){
    int num,pos,i;
    printf("Enter number to be inserted");
    scanf("%d",&num);
    printf("Enter position for number  be inserted");
    scanf("%d",&pos);
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->next=NULL;
    new_node->prev=NULL;
    new_node->data=num;
    struct node *temp=head;
    if(pos==1){
        new_node->next=head;
        head=new_node;
    }
    else if(pos==n){
        new_node->prev=tail;
        tail=new_node;
    }
    else{
        for(temp=head,i=1;i<pos-1;i++,temp=temp->next);
        new_node->next=temp->next;
        temp->next->prev=new_node;
        temp->next=new_node;
        new_node->prev=temp;
    }
}
void delete(int n){
    int pos,i;
    struct node *temp;
    struct node *temp1;
    printf("Enter position for element to be deleted-");
    scanf("%d",&pos);
    if(pos==1){
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
    else if(pos==n){
        temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        free(temp);
    }
    else{
        for(temp=head,temp1=head,i=1;i<pos;i++,temp1=temp,temp=temp->next);
        temp1->next=temp->next;
        temp->next->prev=temp1;
        free(temp);
    }
}
void transverse(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
int main(){
    int n,i=0,num,op=0;
    printf("Enter number of nodes");
    scanf("%d",&n);
    while(i<n){
      printf("Enter number-");
      scanf("%d",&num);
      create(num);
      i++;
    }
    printf("MENU \n 1.INSERT \n 2.DELETE \n 3.TRANSVERSE \n 4.EXIT");
    while(op!=4){
        printf("Enter choice");
        scanf("%d",&op);
        if(op==1){
            insert(n);
        }
        else if(op==2){
            delete(n);
        }
        else if(op==3){
           transverse();
        }
        else{
            printf("EXIT");
        }
    }
    return 0;
}