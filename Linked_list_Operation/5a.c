#include<stdio.h>
#include<stdlib.h>
typedef struct linked_list
{
    int val;
    struct linked_list *next;
}node;
void insertend(node **temp)
{
    node *ptr1,*trace=*temp;
    if(trace=='\0')
    {
        return;
    }
    while(1)
    {
        if(trace->next=='\0')
        {
            break;
        }
        trace = trace->next;
    }
    trace->next=(node *)malloc(sizeof(node));
    printf("\nEnter number of linked list:");
    scanf("%d",&(trace->next->val));
    trace->next->next='\0';
    //*temp=ptr1;assigning the address of new node
}
void insertbegin(node **temp)
{
    node *ptr1;
    ptr1=(node *)malloc(sizeof(node));
    printf("\nEnter number of linked list:");
    scanf("%d",&(ptr1->val));
    ptr1->next=*temp;
    *temp=ptr1;
}
void deletebegin(node **temp)
{
    *temp = ((*temp)->next);
}
void deleteend(node **temp)
{
    node *pt = *temp;
    while(1)
    {
        if(pt->next->next=='\0')
        {
            pt->next='\0';
            break;
        }
        else
        {
            pt=pt->next->next;
        }
    }
}
void delbetween(node **temp,int num)
{
    if(*temp=='\0')
    {
        return;
    }
    else if((*temp)->val==num)
    {
        *temp = '\0';
    }
    else
    {
        node *ptr = *temp;
        while(1)
        {
            if(ptr->next->val==num)
            {
                ((*temp)->next) = ((*temp)->next->next);
                break;
            }
            if(ptr->next=='\0')
            {
                printf("\nEntered value not Found.");
                break;
            }
            ptr->next=ptr->next->next;
        }
    }
}
void display(node *temp)
{
    if(temp!='\0')
    {
        while(1)
        {
            printf("\nElement :%d",temp->val);
            if(temp->next!='\0')
            {
               temp = temp->next;
            }
            else
            {
                break;
            }
        }
    }

}
int main()
{
    int n,num;
    char ch,ch1;
    node *start,*ptr;
    //ptr used for moving to new node while insertion
    printf("\nTo start the linked list Enter 'Y' else Enter 'N':");
    do
    {
        ch=getch();
    }while(!(ch=='y'||ch=='Y'||ch=='N'||ch=='n'));
    if(ch=='n'||ch=='N')
    {
        printf("\nExiting program......");
        exit(0);
    }
    printf("\nEnter Element of linked list:");
    start = ptr = (node *)malloc(sizeof(node));
    scanf("%d",&(start->val));
    (ptr->next)='\0';
    while(1)
    {
        printf("\nEnter Operation to be performed\n1.Insert\n2.Delete\n3.Display\n4.Exit");
        printf("\nEnter Operation Number:");
       do
       {
           ch=getch();
       }
       while(ch<'1'||ch>'4');
       putchar(ch);
       printf("\n");
       switch(ch)
       {
            case '1':
               printf("\n1.From Begining\n2.From End");
               printf("\nEnter Operation Number:");
               do
               {
                   ch1=getch();
               }while(ch1<'1'||ch1>'2');
               putchar(ch1);
               if(ch1=='1')
                   insertbegin(&start);
               else
                   insertend(&start);
            break;
            case '2':
                printf("\n1.Begin\n2.End\n3.Between");
                printf("\nEnter Operation Number:");
                do
               {
                   ch1=getch();
               }while(ch1<'1'||ch1>'3');
               putchar(ch1);
               if(ch1=='1')
                    deletebegin(&start);
               else if(ch1=='2')
                    deleteend(&start);
               else
               {
                    printf("\nEnter value to be deleted:");
                    scanf("%d",&num);
                    delbetween(&start,num);
               }
                break;
            case '3':
                display(start);
                break;
            case '4':
                printf("\n\n\n");
                exit (0);
       }
    }
    /*printf("\nElements of Linked List are......");
    (ptr)=(start);
    while((ptr)!='\0')
    {
        printf("\n%d",ptr->val);
        ptr=ptr->next;
    }
    printf("\n\n\n");*/
    return 0;
}
