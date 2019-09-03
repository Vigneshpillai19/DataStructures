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
void split(node *ptr,node **st,int val)
{
    if(ptr=='\0')
    {
        printf("\nEmpty Linked list.....");
        return;
    }
    if(ptr->next=='\0')
    {
        printf("\nLinked List cannot be Splitted....");
        return;
    }
    while(ptr->next!='\0')
    {
        if(ptr->next->val==val)
        {
            *st = ptr->next;
            ptr->next = '\0';
            return;
        }
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
    int num;
    node *start1,*start2;
    start1=start2='\0';
    char ch;
    printf("\nEnter Elements of  Linked List to be Splited:");
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
    printf("\nElements of linked list are.....\n");
    display(start1);
    printf("\nEnter value from which Linked List is to be Splitted:");
    scanf("%d",&num);
    split(start1,&start2,num);
    printf("\nAfter Splitting Elements of Linked List are ........\n");
    printf("\nElements of linked list 1 are.....\n");
    display(start1);
    printf("\nElements of linked list 2 are.....\n");
    display(start2);
    return 0;
}

