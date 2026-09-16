#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node *next;
};
struct node *head=NULL;
void create(int num){
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->info=num;
    if(head==NULL){
      head=new_node;
      new_node->next=NULL;
   }
   else{
    struct node *temp=head;
    for(temp=head;temp->next!=NULL;temp=temp->next);
       temp->next=new_node;
       new_node->next=NULL;
   }
   
}
void insert(){
    int num,pos,i;
    printf("Enter info of node to be inserted");
    scanf("%d",&num);
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node*));
    new_node->info=num;
    printf("Enter position");
    scanf("%d",&pos);
    if(head==NULL){
        head=new_node;
        new_node->next=NULL;
    }
    else{
    struct node *temp=head;
    for(temp=head,i=1;temp!=NULL && i<pos-1;i++,temp=temp->next);
    new_node->next=temp->next;
    temp->next=new_node;
    }
}
void delete(){
    int pos,i;
    printf("Enter position to be deleted");
    scanf("%d",&pos);
    if(head==NULL){
        printf("NO deletion");
    }
    else if(head->next==NULL){
        head=NULL;
    }
    else{
        struct node *temp;
        struct node *temp1;
        for(temp=head,temp1=head,i=1;temp->next!=NULL && i<pos;temp1=temp,temp=temp->next,i++);
        temp1->next=temp->next;
        free(temp);
    }
}
void count(){
    int count=0;
    struct node *temp=head;
    for(temp=head;temp->next!=NULL;temp=temp->next){
        count++;
    }
    count++;
    printf("Number of nodes=%d",count);
}
void transverse(){
    struct node *temp=head;
    for(temp=head;temp->next!=NULL;temp=temp->next){
        printf("%d->",temp->info);
    }
    printf("%d->",temp->info);
}
void search(){
    int num;
    printf("Enter number to be search");
    scanf("%d",&num);
    struct node *temp=head;
    int i=1,t=0;
    for(temp=head;temp!=NULL;temp=temp->next,i++){
        if(temp->info == num){
            printf("Number found at position =%d",i);
            t=1;
        }
    }
    if(t==0)
    printf("Number not found");
}
void sort(){
    struct node *temp=head;
    struct node *temp1=head;
    int t;
    for(temp=head;temp!=NULL;temp=temp->next){
        for(temp1=temp->next;temp1!=NULL;temp1=temp1->next){
            if(temp->info > temp1->info){
               t=temp->info;
               temp->info=temp1->info;
               temp1->info=t;
            }
        }
    }
}
void reverse(){
    if(head==NULL && head->next==NULL){
        printf("no need to reverse");
        return;
    }
    else{
        struct node *prev=NULL;
        struct node *curr=head;
        struct node *next=head;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }
}
int main(){
    int n,i=1,num,op=0;
    printf("Enter number of nodes");
    scanf("%d",&n);
    printf("Enter elements ");
    while(i<=n){
        scanf("%d",&num);
        create(num);
        i++;
    }
    printf("MENU \n 1.Insertion \n 2.Deletion \n 3.Count \n 4.Transverse \n 5.Search \n 6.Sort \n 7. Reverse \n 8.Exit");
    while(op!=8){

    printf("Enter choice-");
    scanf("%d",&op);
    if(op==1){
        insert();
        printf("New linked list");
        transverse();
    }
    else if(op==2){
        delete();
        printf("New linked list");
        transverse();
    }
    else if(op==3){
        count();
    }
    else if(op==4){
        transverse();
    }
    else if(op==5){
        search();
    }
    else if(op==6){
        sort();
        transverse();
    }
    else if(op==7){
        reverse();
    }
    else{
        printf("bye byee");
    }
}
    return 0;
}