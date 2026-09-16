#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
struct node *tail=NULL;
void create(int num){
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    new_node->next=NULL;
    new_node->prev=NULL;
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
void insertAtFront(){
    int num;
    struct node *new_node;
    printf("Enter number to be inserted");
    scanf("%d",&num);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    new_node->next=NULL;
    new_node->prev=NULL;
    if(head==NULL){
    head=new_node;
    tail=new_node;
   }
   else{
     new_node->next=head;
     head->prev=new_node;
     head=new_node;
   }
}
void insertAtLast(){
    int num;
    struct node *new_node;
    printf("Enter number to be inserted");
    scanf("%d",&num);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    new_node->next=NULL;
    new_node->prev=NULL;
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
void insertAtposition(){
    int num,p,i=1;
    struct node *new_node;
    printf("Enter position");
    scanf("%d",&p);
    if(p==1){
      insertAtFront();
    }
    printf("Enter number to be inserted");
    scanf("%d",&num);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    new_node->next=NULL;
    new_node->prev=NULL;
    struct node *temp;
    for(temp=head,i=1;temp!=NULL && i<p-1;i++,temp=temp->next);
    if( temp->next==NULL && temp!=NULL){
    new_node->next=temp->next;
    new_node->prev=temp;
    temp->next->prev=new_node;
    temp->next=new_node;
    }
    else if(temp->next==NULL)
    insertAtLast();
    else
    printf("Invalid position");
}
void DeleteAtFront(){
    struct node *temp;
    if(head==NULL){
        printf("Empty list");
    }
    else if(head->next==NULL){
        head=NULL;
        tail=NULL;
    }
    else{
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
}
void DeleteAtLast(){
    struct node *temp;
    if(head==NULL){
        printf("Empty list");
    }
    else if(head->next==NULL){
        head=NULL;
        tail=NULL;
    }
    else{
       temp=tail;
       tail=tail->prev;
       tail->next=NULL;
       free(temp);
    }
}
void deleteAtPosition(){
    int p,i=1;
    printf("Enter position");
    scanf("%d",&p);
    if(p==1){
      DeleteAtFront();
    }
    struct node *temp;
    struct node *temp1;
    for(temp1=head,temp=head,i=1;temp!=NULL && i<p;i++,temp1=temp,temp=temp->next);
    if( temp->next!=NULL && temp!=NULL){
     temp1->next=temp->next;
     temp->next->prev=temp1;
     free(temp);
    }
    else if(temp->next==NULL)
    DeleteAtLast();
    else
    printf("Invalid position");
}
void deleteByValue(){
    int val,i=1;
    struct node *temp1;
    printf("Enter value");
    scanf("%d",&val);
    struct node *temp;
    if(head->data==val){
        DeleteAtFront();
    }
    temp=head;
    while(temp->next!=NULL){
        if(temp->next->data==val){
            break;
        }
    }
    if(temp->next==NULL)
      printf("value not found");
    else{
        if(temp->next->next==NULL){
        DeleteAtLast();}
        else{
           temp1=temp->next;
           temp1->next->prev=temp;
           temp->next=temp1->next;
           free(temp1);
        }
    }
}
void transverse(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d \t",temp->data);
        temp=temp->next;
    }
}
int main(){
    int n,i=0,val,op=0;
    printf("enter number of elements");
    scanf("%d",&n);
    printf("Enter elements");
    while(i<n){
        printf("Enter value");
        scanf("%d",&val);
        create(val);
        i++;
    }
    printf("MENU \n 1.insert at front \n 2.Insert at last \n 3.insert at position \n 4.delete at first \n 5.9delete at last \n 6.delete at position \n 7.delete by value \n 8.transverse \n 9.exit");
    while(op!=9)
    { printf("Enter operation");
        scanf("%d",&op);
         if(op==1)
         insertAtFront();
         else if(op==2)
         insertAtLast();
         else if(op==3)
         insertAtposition();
         else if(op==4)
         DeleteAtFront();
         else if(op==5){
         DeleteAtLast();}
         else if(op==6)
         deleteAtPosition();
         else if(op==7)
         deleteByValue();
         else if(op==8)
         transverse();
         else
         break;
        
    }
    return 0;
}
