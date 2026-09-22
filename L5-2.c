#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
void create(int num){
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    struct node *temp;
    new_node->next=NULL;
    new_node->data=num;
    if(head==NULL){
        head=new_node;
        new_node->next=head;
    }
    else{
        for(temp=head;temp->next!=head;temp=temp->next);
        temp->next=new_node;
        new_node->next=head;
    }
}
void insertAtFirst(){
    int num;
    printf("Enter number to be inserted");
    scanf("%d",&num);
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    struct node *temp;
    new_node->next=NULL;
    new_node->data=num;
    if(head==NULL){
        head=new_node;
        new_node->next=head;
    }
    else{
        for(temp=head; temp->next!=head; temp=temp->next);
        new_node->next = head;
        temp->next = new_node;
        head = new_node;
    }
}
void insertAtLast(){
    int num;
    printf("Enter number to be inserted");
    scanf("%d",&num);
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    struct node *temp;
    if(head==NULL){
        head=new_node;
    }
    else{
        for(temp=head;temp->next!=head;temp=temp->next);
        temp->next=new_node;
        new_node->next=head;
    }
}
void insertAtPosition(){
    int num,pos,i=1;
    struct node *temp;
    printf("Enter position to be inserted");
    scanf("%d",&pos);
    if(pos==1){
        insertAtFirst();
    }
    else{
        printf("Enter number to be inserted");
    scanf("%d",&num);
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    new_node->next=NULL;
    struct node *temp;
        
            for(temp=head,i=1;temp->next!=head && i<pos-1;temp=temp->next,i++);
            if(i==pos-1){
            new_node->next=temp->next;
            temp->next=new_node;}
            else{
               printf("out of range");
            }
        
    }
}
void deleteAtFirst(){
    struct node*temp1,*temp;
    if(head==NULL){
        printf("Empty list");
    }
    else if(head->next==head){
        head=NULL;
    }
    else{
        for(temp=head;temp->next!=head;temp=temp->next);
        temp1=head;
        head=head->next;
        temp->next=head;
        free(temp1);

    }
}
void deleteAtLast(){
    struct node*temp;
    struct node *temp1;
    if(head==NULL){
        printf("Empty list");
    }
    else if(head->next==head){
        head=NULL;
    }
    else{
        for(temp=head;temp->next->next!=head;temp=temp->next);
        temp1=temp->next;
        temp->next=head;
        free(temp1);
    }
}
void deletebyPosition(){
    int pos;
    printf("enter position for element to be deleted");
    scanf("%d",&pos);
    if(pos==1){
        deleteAtFirst();
    }
    else{
        int i=1;
        struct node *temp;
        struct node *temp1;
        for(temp=head,temp1=head,i=1;i<pos && temp1->next!=head;temp=temp1,temp1=temp1->next,i++);
        if(temp1->next==head && i==pos){
            deleteAtLast();
        }
        else if(i==pos && i>1){
           temp->next=temp1->next;
           free(temp1);
        }
        else{
            printf("invalid input");
        }
    }
}
void deletebyValue(){
    int val;
    printf("enter value to be deleted");
    scanf("%d",&val);
    struct node *temp;
    struct node *temp1;
    if(head->data==val){
        for(temp=head;temp->next!=head;temp=temp->next);
        temp1=head;
        head=head->next;
        temp->next=head;
        insertAtLast(temp1);
    }
    else{
        temp=head;
        while(temp->next!=head){
             if(temp->next->data==val){
                break;
             }
             temp=temp->next;
        }
        if(temp->next==head){
            printf("value not found");
            return;
        }
        else{
                temp1=temp->next;
                temp->next=temp->next->next;
                free(temp1);
        }
    }
}
void transverse(){
    struct node *temp=head;
    while(temp->next!=head){
        printf("%d \t",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
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
         insertAtFirst();
         else if(op==2)
         insertAtLast();
         else if(op==3)
         insertAtPosition();
         else if(op==4)
         deleteAtFirst();
         else if(op==5){
         deleteAtLast();}
         else if(op==6){
            deletebyPosition();
         }
         else if(op==7)
         deletebyValue();
         else if(op==8)
         transverse();
         else
         break;
        
    }
    return 0;
}
