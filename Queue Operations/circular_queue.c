#include<stdio.h>
#include<stdlib.h>
#define size 20
typedef struct cirque
{
    int arr[size];
    int rear,front;
}queue;
void enqueue(queue *ptr)
{
    if(ptr->rear==-1)
    {
        ptr->front=ptr->rear=0;
        printf("\nEnter the number:");
        scanf("%d",&(ptr->arr[ptr->rear]));
    }
    else
    {
        if(((ptr->rear==size-1) && ptr->front==0)||(ptr->rear==ptr->front-1))
            printf("\nCircular Queue full.\n\n");
        else if(ptr->rear==size-1)
        {
            ptr->rear=0;
            printf("\nEnter the number:");
            scanf("%d",&(ptr->arr[ptr->rear]));
        }else
        {
            (ptr->rear)++;
            printf("\nEnter the number:");
            scanf("%d",&(ptr->arr[ptr->rear]));
        }
    }
}
void dequeue(queue *ptr)
{
    if(ptr->front==-1)
        printf("\nQueue Empty.\n\n");
    else if(ptr->front==ptr->rear)
    {
        printf("%d\n",ptr->arr[ptr->front]);
        ptr->front=ptr->rear=-1;
    }
    else if(ptr->front==size-1)
    {
        printf("%d\n",ptr->arr[ptr->front]);
        ptr->front=0;
    }
    else
    {
        printf("%d\n",ptr->arr[ptr->front++]);
    }
}
void display(queue *ptr)
{
    for(int i=ptr->front;(i-1)!=ptr->rear;i++)
    {
        if(i==size)
            i=0;
        printf("\nElement :%d",ptr->arr[i]);
    }
    printf("\n\n");
}

int main()
{
    int i,n;
    queue obj;
    obj.front=obj.rear=-1;
    do
    {
        printf("\nEnter the option of operation to be performed\n%d.Enqueue\n%d.Dequeue\n%d.Display\n",1,2,3);
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
                printf("3\n\nDisplaying elements of stack:");
                display(&obj);
                break;
            default:
                exit (0);
        }
    }while(i!='e'||i!='E');
    return (0);
}



