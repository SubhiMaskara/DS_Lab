#include<stdio.h>
#include<stdlib.h>
struct node {
     int coefi;
     int expo;
     struct node *next;
};
void insert(struct node **head,int pow,int num){
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->next=NULL;
    new_node->coefi=num;
    new_node->expo=pow;
    if(num!=0){
      if(*head==NULL){
        *head=new_node;
      }
      else{
        new_node->next=*head;
        *head=new_node;
      }
    }
}
int check(struct node **head,int pow){
struct node *temp=*head;
    while(temp!=NULL){
        if(temp->expo==pow)
          return 1;
        temp=temp->next;
    }
    return 0;
}
void display(struct node **head){
    struct node *temp=*head;
    while(temp!=NULL){
        printf("%dx^%d\t",temp->coefi,temp->expo);
        temp=temp->next;
    }
    
}
int main(){
    struct node *head1=NULL;
    struct node *head2=NULL;
    struct node *temp1=NULL;
    struct node *temp2=NULL;
    struct node *head3=NULL;
    int p1,p2,p3;
    int i=0;
    int coef,max,ch1,ch2;
    printf("Enter highest power of polynomial 1");
    scanf("%d",&p1);
    while(i<=p1){
        printf("Enter coefficient of power %d",i);
        scanf("%d",&coef);
        insert(&head1,i,coef);
        i++;
    }
    i=0;
    printf("Enter highest power of polynomial 2");
    scanf("%d",&p2);
    while(i<=p2){
        printf("Enter coefficient of power %d",i);
        scanf("%d",&coef);
        insert(&head2,i,coef);
        i++;
    }
    if(p1>=p2){
        max=p1;}
    else{
        max=p2;}
    i=0;
    while(i<=max){
        temp1=head1;
    temp2=head2;
      ch1=check(&head1,i);
      ch2=check(&head2,i);
      if(ch1==1 && ch2==1){
        while(temp1->expo!=i){
            temp1=temp1->next;
        }
         while(temp2->expo!=i){
            temp2=temp2->next;
        }
        coef=temp1->coefi+temp2->coefi;
        insert(&head3,i,coef);
      }
      else if(ch1==1 && ch2==0){
        while(temp1->expo!=i){
            temp1=temp1->next;
        }
        coef=temp1->coefi;
        insert(&head3,i,coef);
      }
      else if(ch1==0 && ch2==1){
         while(temp2->expo!=i){
            temp2=temp2->next;
        }
        coef=temp2->coefi;
        insert(&head3,i,coef);
      }
      i++;
    }
    display(&head3);
    return 0;
}