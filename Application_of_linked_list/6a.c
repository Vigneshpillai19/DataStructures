#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
       int val;
       struct link *next;
}node;
void enque(node **st)
{
       if((*st)=='\0')
       {
              *st = (node *)malloc(sizeof(node));
              (*st)->next = '\0';
              printf("\nEnter Number:");
              scanf("%d",&(*st)->val);
              return;
       }
       node *ptr = *st;
       while(ptr->next!='\0')
       {
              ptr=ptr->next;
       }
       ptr->next = (node *)malloc(sizeof(node));
       printf("\nEnter Number:");
       scanf("%d",&ptr->next->val);
       ptr->next->next='\0';
}
void concat(node *st1,node *st2)
{
       while(st1->next!='\0')
       {
              st1=st1->next;
       }
       st1->next = st2;
}
void display(node *ptr)
{
       while(ptr!='\0')
       {
              printf("Element :%d\n",(ptr)->val);
              ptr = ptr->next;
       }
}
int main()
{
       node *start1,*start2;
       start1=start2='\0';
       char ch;
       printf("\nEnter Elements of  Linked List 1:");
       do
       {
              enque(&start1);
              printf("Do you want to add Element for linked list (Y/N):");
              do
              {
                            ch=getch();
              }while(!(ch=='Y' || ch=='y' || ch=='n' || ch=='N'));
              putchar(ch);
       }while(ch=='y'  || ch=='Y' );
       printf("\n\nEnter Elements of  Linked List 2:");
       do
       {
              enque(&start2);
              printf("Do you want to add Element for linked list (Y/N):");
              do
              {
                            ch=getch();
              }while(!(ch=='Y'||ch=='y'||ch=='n'||ch=='N'));
              putchar(ch);
       }while(ch=='y'||ch=='Y');
       concat(start1,start2);
       printf("\nAfter concatenating Elements of Linked list are:\n");
       display(start1);
       return 0;
}
