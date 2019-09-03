#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
       int val;
       struct link *next;
}node;
void push(node **st)
{
    int num;
    node *ptr = (node *)malloc(sizeof(node));
    printf("\nEnter Element to be Inserted:");
    scanf("%d",&num);
    ptr->val = num;
    if(*st == '\0')
        ptr->next = '\0';
    else
        ptr->next = *st;
    *st = ptr;
}
void pop(node **st)
{
    if(*st == '\0')
    {
        printf("\nEmpty linked list......\n");
        return;
    }
    printf("\npopped Element is : %d\n",(*st)->val);
    *st = (*st)->next;
}
void peek(node *st)
{
    if(st == '\0')
    {
        printf("\nEmpty linked list......\n");
        return;
    }
    printf("\nTopmot Element of Linked List is : %d\n",st->val);
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
        printf("\nElement : %d",ptr->val);
        ptr = ptr->next;
    }
}

int main()
{
    node *top;
    top ='\0';
    char i;
    do
    {
        printf("\nEnter the option of operation to be performed\n%d.push\n%d.pop\n%d.peek\n%d.display\n",1,2,3,4);
        printf("Enter operation number and to exit enter e:");
        i=getch();
        switch(i)
        {
            case '1':
                putch(i);
                printf("\n\nPUSH:");
                push(&top);
                break;
            case '2':
                putch(i);
                printf("\n\nPOP:");
                pop(&top);
                break;
            case '3':
                putch(i);
                printf("\nPEEK:");
                peek(top);
                break;
            case '4':
                putch(i);
                printf("\n\nDisplaying elements of stack:");
                display(top);
                break;
            default:
                putch(i);
                printf("\n\n\n");
                exit(1);
        }
    }while(i!='e'||i!='E');
    return 0;
}
