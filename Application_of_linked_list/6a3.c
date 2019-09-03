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
int reverse(node **st)
{
    int c = 0;
    node *ptr1,*ptr2,*temp;
    ptr1 = *st;
    ptr2 = '\0';
    while(ptr1!='\0')
    {
        temp = ptr1->next;
        ptr1->next = ptr2;
        ptr2 = ptr1;
        ptr1 = temp;
        c++;
    }
    *st = ptr2;
    return c;
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
    node *start1;
    start1='\0';
    char ch;
    int count;
    printf("\nEnter Elements of  Linked List to be reversed:");
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
    count = reverse(&start1);
    printf("\nElements of linked list after reversing are.....\n");
    display(start1);
    printf("\nTotal number of Elements in Linked List are : %d\n\n",count);
    return 0;
}
