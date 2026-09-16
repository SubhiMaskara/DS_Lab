#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;
struct node *tail;
void create(int n){
    struct node *temp;
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=n;
    new_node->next=NULL;
    new_node->prev=NULL;
    if(head==NULL){
        head=new_node;
    }
    else{
            for(temp=head;temp->next!=NULL;temp=temp->next);
            temp->next=new_node;
            new_node->prev=temp;
    }
}
void deletebyValue(){
    int val;
    struct node *temp,*temp1;
    printf("Enter value to be deleted");
    scanf("%d",&val);
    if(head->data==val){
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            if(temp->next->data==val){
                break;
            }
            temp=temp->next;
        }
        if(temp->next==NULL){
            printf("Value not found");
        }
        else{
            if(temp->next->next!=NULL){
                temp1=temp->next;
                temp->next=temp->next->next;
                temp->next->prev=temp;
                free(temp1);
            }
            else{
                temp1=temp->next;
                tail=tail->prev;
                temp->next=NULL;
                free(temp1);
            }
        }
    }
}
int main(){
int n,i=1,op=0,num;
    printf("Enter number of nodes");
    scanf("%d",&n);
    while(i<=n){
        printf("Enter a number ");
        scanf("%d",&num);
        create(num);
        i++;
    }
    deletebyValue();
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}