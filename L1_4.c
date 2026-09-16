#include<stdio.h>
struct num{
    int real;
    int imag;
};
void addition(struct num s1,struct num s2){
    int add_real;
    int add_imag;
    add_real=s1.real+s2.real;
    add_imag=s1.imag+s2.imag;
    printf("%d + %di",add_real,add_imag);
}
void multiplication(struct num s1,struct num s2){
     int first,outer,inner,last;
     int multi_real,multi_imag;
     first =s1.real*s2.real;
     outer=s1.real*s2.imag;
     inner=s1.imag*s2.real;
     last=s1.imag*s2.imag;
     multi_real=first+(-1)*last;
     multi_imag=outer+inner;
     printf("%d + %d i",multi_real,multi_imag);
}
int main(){
    int choice;
    struct num num1,num2;
    printf("Enter complex number 1\n");
    scanf("%d %d",&num1.real,&num1.imag);
    printf("Enter complex number 2\n");
    scanf("%d %d",&num2.real,&num2.imag);
    printf("MENU\n 1.addition \n 2.multiplication\n");
    printf("Enter your choice ");
    scanf("%d",&choice);
    if(choice == 1)
     addition(num1,num2);
    else
    multiplication(num1,num2);
    return 0;
}