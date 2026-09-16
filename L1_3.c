#include<stdio.h>
#define size 100
struct Employee{
    char name[size];
    char degn[size];
    int emp_id;
    float basic_salary;
    float hra;
    float da;
    float gross_sal;
    float da_amount;
    float hra_amount;
};
int main(){
    int n,i;
    printf("Enter number of employee");
    scanf("%d",&n);
    struct Employee emp[n];
    for(i=0;i<n;i++){
       printf("Enter employee %d information",i+1);
       scanf("%s",emp[i].name);
       scanf("%s",emp[i].degn);
       scanf("%d",&emp[i].emp_id);
       scanf("%f",&emp[i].basic_salary);
       scanf("%f",&emp[i].hra);
       scanf("%f",&emp[i].da);
    }
    for(i=0;i<n;i++){
        emp[i].hra_amount=emp[i].basic_salary*(emp[i].hra/100);
        emp[i].da_amount=emp[i].basic_salary*(emp[i].da/100);
        emp[i].gross_sal=emp[i].basic_salary+emp[i].hra_amount+emp[i].da_amount;
    }
    for(i=0;i<n;i++){
        printf("Employee %d information \n ",i+1);
        printf("Name-%s\n",emp[i].name);
        printf("Designation-%s\n",emp[i].degn);
        printf("Employee id -%d\n",emp[i].emp_id);
        printf("Basic salary-%f\n",emp[i].basic_salary);
        printf("HRA-%f\n",emp[i].hra);
        printf("DA-%f\n",emp[i].da);
        printf("Gross Salary-%f\n",emp[i].gross_sal);
    }
    return 0;
}