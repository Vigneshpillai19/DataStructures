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
void copy(node *ptr,node **st)
{
    if(ptr=='\0')
    {
        printf("\nEmpty Linked List.....");
        return;
    }
    node *pt = *st = (node *)malloc(sizeof(node));
    pt->val = ptr->val;
    pt->next = '\0';
    ptr = ptr->next;
    while(ptr!='\0')
    {
        pt->next = (node *)malloc(sizeof(node));
        pt = pt->next;
        pt->val = ptr->val;
        pt->next = '\0';
        ptr = ptr->next;
    }
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
    printf("\nEnter Elements of  Linked List to be copied:");
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
    copy(start1,&start2);
    printf("\nAfter copying Elements of linked list are .....\n");
    display(start2);
    return 0;
}
