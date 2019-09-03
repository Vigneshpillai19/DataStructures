#include<stdio.h>
#include<stdlib.h>
typedef struct ll
{
    struct ll *prev;
    int val;
    struct ll *next;
}node;
void insertend(node **ptr)
{
    int num;
    node *temp;
    if(ptr=='\0')
    {
        *ptr = (node *)malloc(sizeof(node));
        ((*ptr)->prev) = '\0';
        ((*ptr)->next) = '\0';
        printf("\nEnter Number:");
        scanf("%d",&num);
        ((*ptr)->val) = num;
    }
    else
    {
        temp = *ptr;
        while(temp->next!='\0')
        {
            temp = temp->next;
        }
        temp->next = (node *)malloc(sizeof(node));
        temp->next->prev = temp;
        temp->next->next = '\0';
        printf("\nEnter number:");
        scanf("%d",&num);
        temp->next->val = num;
    }
}
void insertbegin(node **ptr)
{
    node *temp;
    int num;
    if((*ptr)=='\0')
    {
        *ptr = (node *)malloc(sizeof(node));
        ((*ptr)->prev) = '\0';
        ((*ptr)->next) = '\0';
        printf("\nEnter Number:");
        scanf("%d",&num);
        ((*ptr)->val) = num;
    }
    else
    {
        temp = (node *)malloc(sizeof(node));
        temp->next = *ptr;
        temp->next->prev = temp;
        temp->prev = '\0';
        *ptr = temp;
        printf("\nEnter Number:");
        scanf("%d",&num);
        temp->val = num;
    }
}
void insertbetween(node *ptr,int num)
{
    node *temp;
    if(ptr=='\0')
    {
        printf("\nEmpty Linked List....");
        return;
    }
    while(ptr->val!=num)
    {
        if(ptr->next=='\0')
        {
            printf("\nValue Not Found.");
            return;
        }
        ptr = ptr->next;
    }
    temp = (node *)malloc(sizeof(node));
    temp->prev = ptr;
    temp->next = ptr->next;
    ptr->next = temp;
    temp->next->prev=temp;
    printf("\nEnter Number:");
    scanf("%d",&(temp->val));
}
void deletebegin(node **ptr)
{
    if((*ptr)=='\0')
    {
        printf("\nEmpty Linked List....");
        return;
    }
    else
    {
        *ptr = ((*ptr)->next);
        (*ptr)->prev = '\0';
    }
}
void deleteend(node **ptr)
{
    node *temp = *ptr;
    if(*ptr=='\0')
    {
        printf("\nEmpty Linked List....");
        return;
    }
    else if((*ptr)->next=='\0')
    {
        *ptr='\0';
        return;
    }
    while(temp->next->next!='\0')
    {
        temp = temp->next;
    }
    temp->next = '\0';
}
void deletebetween(node **ptr,int val)
{
    node *temp = *ptr;
    if(*ptr=='\0')
    {
        printf("\nEmpty Linked List....");
        return;
    }else if((*ptr)->next=='\0'&&(*ptr)->val==val)
    {
        *ptr='\0';
        return;
    }
    while(temp->next->val!=val)
    {
        temp = temp->next;
        if(temp->next=='\0')
        {
            printf("\nValue not found....");
            return;
        }
    }
    temp->next = temp->next->next;
    temp->next->prev = temp;
}
void display(node *ptr)
{
    if(ptr=='\0')
    {
        printf("\nLinked List Empty....");
        return;
    }
    while(ptr!='\0')
    {
        printf("\nElement:%d",ptr->val);
        ptr = ptr->next;
    }
}
int main()
{
    char ch;
    int num;
    printf("\nDo you want to Create Linked List(Y(Yes)/N(No)):");
    do
    {
        ch=getch();
    }while(!(ch=='Y'||ch=='y'||ch=='N'||ch=='n'));
    putchar(ch);
    if(ch=='N'||ch=='n')
    {
        printf("\nExiting Program....");
        exit (0);
    }
    node *start = (node *)malloc(sizeof(node));
    printf("\nEnter Element:");
    scanf("%d",&(start->val));
    start->prev = start->next = '\0';
    do
    {
        printf("\nEnter Operation number to be performed....\n");
        printf("\n1.InsertBegin\n2.InsertEnd\n3.InsertBetween\n4.DeleteBegin\n5.DeleteEnd\n6.DeleteBetween\n7.Display\n8.Exit\n");
        do
        {
            ch=getch();
        }while(ch<'1'||ch>'8');
        switch(ch)
        {
            case '1':
                printf("\nInsertion at begining....\n");
                insertbegin(&start);
                break;
            case '2':
                printf("\nInsertion at end....\n");
                insertend(&start);
                break;
            case '3':
                printf("\nEnter value after which to be inserted:");
                scanf("%d",&num);
                insertbetween(start,num);
                break;
            case '4':
                printf("\Deletion at begining....\n");
                deletebegin(&start);
                break;
            case '5':
                printf("\Deletion at End....\n");
                deleteend(&start);
                break;
            case '6':
                printf("\nEnter Value to be deleted:");
                scanf("%d",&num);
                deletebetween(&start,num);
                break;
            case '7':
                printf("\nDisplaying Elements of Linked List....\n");
                display(start);
                break;
            case '8':
                printf("\nExiting Program.....\n\n");
                exit (0);
        }
    }while(1);
    return 0;
}
