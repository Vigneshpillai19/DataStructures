#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
       int val;
       struct link *next;
}node;
void enqueue(node **st,node **st1)
{
    node *ptr = *st;
    if((*st)=='\0')
        *st = *st1 =  ptr = (node *)malloc(sizeof(node));
    else
    {
       (*st)->next = ptr = (node *)malloc(sizeof(node));
       *st = ptr;
    }
    ptr->next = '\0';
    printf("\nEnter Number:");
    scanf("%d",&ptr->val);
}
void dequeue(node **st)
{
    if(*st == '\0')
    {
        printf("\nEmpty Linked List.......\n");
        return;
    }
    printf("\nPopped Element is : %d",(*st)->val);
    *st = (*st)->next;
}
void display(node *ptr)
{
    if(ptr == '\0')
    {
        printf("\nEmpty Linked List.......\n");
        return;
    }
    while(ptr!='\0')
    {
        printf("Element :%d\n",(ptr)->val);
        ptr = ptr->next;
    }
}

int main()
{
    node *front,*rear;
    front = rear ='\0';
    char i;
    do
    {
        printf("\nEnter the option of operation to be performed\n%d.Enqueue\n%d.Dequeue\n%d.Display\n",1,2,3);
        printf("Enter operation number and to exit enter e:");
        i=getch();
        switch(i)
        {
            case '1':
                putch(i);
                printf("\n\nEnqueue:");
                enqueue(&rear,&front);
                break;
            case '2':
                putch(i);
                printf("\n\nDequeue:");
                dequeue(&front);
                break;
            case '3':
                putch(i);
                printf("\n\nDisplay:\n");
                display(front);
                break;
            default:
                putch(i);
                printf("\n\n\n");
                exit(1);
        }
    }while(i!='e'||i!='E');
    return 0;
}
