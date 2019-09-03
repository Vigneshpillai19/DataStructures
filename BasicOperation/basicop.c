#include<stdio.h>
int top=-1;
int stack[20];
void push(int num)
{
    stack[++top]=num;
}
void pop()
{
    top--;
}
void display()
{
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
}
void peek()
{
    printf("%d\n",stack[top]);
}
int main()
{
    int n,i,temp;
    printf("\nEnter the number of elements to be entered:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the %d element:",i+1);
        scanf("%d",&temp);
        push(temp);
    }
    printf("\nEnter the option of operation to be performed\n%d.push\n%d.pop\n%d.peek\n%d.display\n",1,2,3,4);
    do
    {
        printf("Enter operation number and to exit enter e:");
        i=getch();
        switch(i)
        {
            case '1':
                printf("\nPUSH:\nEnter the number:");
                scanf("%d",&temp);
                push(temp);
                break;
            case '2':
                printf("\nPOP:\n");
                pop();
                break;
            case '3':
                printf("\nPEEK:\n");
                peek();
                break;
            case '4':
                printf("\nDisplaying elements of stack:\n");
                display();
                break;
            default:
                exit(1);
        }
    }while(i!='e'||i!='E');
    return 0;
}
