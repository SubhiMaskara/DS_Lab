#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void create(struct node **head,int num){
    struct node *new_node;
    struct node *temp;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    if(*head==NULL){
        *head=new_node;
        new_node->next=*head;
    }
    else{
        temp=*head;
        for(temp=*head;temp->next!=*head;temp=temp->next);
        temp->next=new_node;
        new_node->next=*head;
    }
}
void display(struct node **head){
    struct node *temp=*head;
    do{
       printf("%d ->",temp->data);
       temp=temp->next;
    }
    while(temp!=*head);
}
int main(){
    struct node *head;
    int n,i=0,num;
    printf("Enter number of nodes");
    scanf("%d",&n);
    while(i<n){
        printf("Enter element ");
        scanf("%d",&num);
        create(&head,num);
        i++;
    }
    display(&head);
    return 0;
}