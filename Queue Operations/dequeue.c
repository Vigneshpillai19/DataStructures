#include<stdio.h>
#include<stdlib.h>
#define size 20
typedef struct q
{
    int arr[size];
    int front,rear;
}queue;
int isfull(queue *ptr)
{
    if(ptr->rear==0 && ptr->front==size-1)
    {
        return 1;
    }
    else if(ptr->rear+1==ptr->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty(queue *ptr)
{
    if(ptr->front==0 && ptr->rear!=size-1)
    {
        return 1;
    }
    else if(ptr->front!=0 && ptr->rear!=ptr->front-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(queue *ptr)
{
    int num;
    char ch;
    if(!isfull(ptr))
    {
        //if(ptr->rear==-1)
          //  ptr->rear=ptr->front=0;
        printf("\nEnter the number:");
        scanf("%d",&num);
        printf("Insert Number from...\n1.Front\n2.Rear\n");
        printf("Enter option:");
        do
        {
            ch=getch();
        }while(ch<'1'||ch>'2');
        putchar(ch);
        if(ch=='1')
        {
            if(ptr->front==0)
            {
                ptr->front=size-1;
                ptr->arr[ptr->front]=num;
            }else if(ptr->front==-1)
            {
                ptr->front=ptr->rear=size-1;
                ptr->arr[ptr->rear]=num;
            }
            else
            {
                ptr->front--;
                ptr->arr[ptr->front]=num;
            }
        }
        else
        {
            if(ptr->rear==size-1)
            {
                ptr->rear=0;
                ptr->arr[ptr->rear]=num;
            }
            else if(ptr->rear==-1)
            {
                ptr->front=ptr->rear=0;
                ptr->arr[ptr->rear]=num;
            }
            else
            {
                ptr->rear++;
                ptr->arr[ptr->rear]=num;
            }
        }
    }
}
void dequeue(queue *ptr)
{
    if(ptr->rear==-1)
    {
        printf("\nQueue Empty....");
    }
    else
    {
        if(ptr->rear==ptr->front)
        {
            printf("%d\n",ptr->arr[ptr->front]);
            ptr->front=ptr->rear=-1;
        }
        else
            printf("%d\n",ptr->arr[ptr->front++]);
    }
}
void display(queue *ptr)
{
    int i;
    printf("%d\n",ptr->front);
    for(i=ptr->front;i!=(ptr->rear+1);i++)
    {
        printf("\nElement :%d",ptr->arr[i]);
        if(i==size-1)
        {
            i=-1;
        }
    }
}
int main()
{
    int n;
    char i;
    queue obj;
    obj.front=obj.rear=-1;
    printf("\n\t\tOutput Restricted Queue");
    do
    {
        printf("\n\nEnter the option of operation to be performed\n%d.Enqueue\n%d.Dequeue\n%d.Display\n",1,2,3);
        printf("Enter operation number and to exit enter e:");
        i=getch();
        switch(i)
        {
            case '1':
                printf("1\n\nEnqueue:");
                enqueue(&obj);
                break;
            case '2':
                printf("2\n\nDequeue:");
                dequeue(&obj);
                break;
            case '3':
                printf("3\n\nDisplaying elements of queue:");
                display(&obj);
                break;
            default:
                printf("\n\n");
                exit (0);
        }
    }while(1);
    return 0;
}
