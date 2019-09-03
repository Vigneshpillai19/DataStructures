#include<stdio.h>
#include<stdlib.h>
typedef struct linked_list
{
    int val;
    struct linked_list *ptr;
}node;
void insertend(node *ptr)
{
    node *ptr1;
    (ptr->ptr)=ptr1=(node *)malloc(sizeof(node));
    printf("\nEnter number of linked list:");
    scanf("%d",&(ptr1->val));
    (ptr1->ptr)='\0';
    //(ptr)=(ptr1);
}
int main()
{
    int n,i=0;
    char ch;
    node *start,*ptr,*ptr1;
    printf("\nEnter number %d of linked list:",++i);
    start = ptr = (node *)malloc(sizeof(node));
    scanf("%d",&(start->val));
    (ptr->ptr)='\0';
    while(1)
    {
        printf("\nDo you want to insert more element in linked list:(Y/N):");
       do
       {
           ch=getch();
       }
       while(!(ch=='y'||ch=='Y'||ch=='n'||ch=='N'));
       putchar(ch);
       printf("\n");
       if(ch=='y'||ch=='Y')
       {
           /*(ptr->ptr)=ptr1=(node *)malloc(sizeof(node));
           printf("\nEnter number %d of linked list:",++i);
           scanf("%d",&(ptr1->val));
           //(ptr->ptr->ptr)='\0';
           (ptr1->ptr)='\0';
           //(ptr)=(ptr->ptr);
           (ptr)=(ptr1);
           //printf("\n%p,%p",ptr,ptr->ptr);*/
           insertend(ptr);
       }
       /*if(ch=='y'||ch=='Y')
       {
           (ptr->ptr)=ptr1=(node *)malloc(sizeof(node));
           printf("\nEnter number %d of linked list:",i++);
           scanf("%d",&(ptr1->val));
           //(ptr->ptr->ptr)='\0';
           (ptr1->ptr)='\0';
           //(ptr)=(ptr->ptr);
           (ptr)=(ptr1);
       }*/
       else
       {
           break;
       }
    }
    printf("\nElements of Linked List are......");
    (ptr)=(start);
    while((ptr)!='\0')
    {
        printf("\n%d",ptr->val);
        ptr=ptr->ptr;
    }
    printf("\n\n\n");
    return 0;
}
