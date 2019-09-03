#include<stdio.h>
#include<stdlib.h>
#define size 20
typedef struct queue
{
    int arr[size];
    int front,rear;
}prqueue;
void enqueue(prqueue *ptr)
{
    int num,i,j;
    if(ptr->rear==size-1)
        printf("\nQueue Full....");
    else if(ptr->rear==-1)
    {
        ptr->rear=ptr->front=0;
        printf("\nEnter the number:");
        scanf("%d",&num);
        ptr->arr[ptr->rear]=num;
    }
    else
    {
        printf("\nEnter the number:");
        scanf("%d",&num);
        for(j=ptr->front;j<=ptr->rear;j++)
        {
            if(ptr->arr[j]>num)
            {
                j++;
                break;
            }
        }
        j--;
        ptr->rear++;
        for(i=ptr->rear-1;i>=j;i--)
        {
            ptr->arr[i+1]=ptr->arr[i];
        }
        ptr->arr[j]=num;
    }
}
void dequeue(prqueue *ptr)
{
    if(ptr->rear==-1)
        printf("\nQueue Empty....");
    else if(ptr->rear==ptr->front)
    {
        printf("%d",ptr->arr[ptr->front]);
        ptr->rear=ptr->front=-1;
    }else
        printf("%d",ptr->arr[ptr->front++]);
}
void display(prqueue *ptr)
{
    int i;
    if(ptr->rear!=-1)
    {
        for(i=ptr->front;i<=ptr->rear;i++)
            printf("\nElement:%d\n",ptr->arr[i]);
    }
    else
        printf("\nQueue Empty....");
}
int main()
{
    int n;
    char i;
    prqueue obj;
    obj.front=obj.rear=-1;
    do
    {
        printf("\nEnter the option of operation to be    performed\n%d.Enqueue\n%d.Dequeue\n%d.Display\n",1,2,3);
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
    printf("\n\n");
    return 0;
}
