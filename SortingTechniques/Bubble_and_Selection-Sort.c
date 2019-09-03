#include<stdio.h>
#include<stdlib.h>
void bubblesort(int * arr,int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void selectionsort(int *arr,int n)
{
    int min,pos,temp;
    for(int i=0;i<n;i++)
    {
        min = *(arr+i);
        pos = i;
        for(int j=i+1;j<n;j++)
        {
            if(min>arr[j])
            {
                min = arr[j];
                pos = j;
            }
        }
        if(i!=pos)
        {
            temp = arr[i];
            arr[i] = min;
            arr[pos] = temp;
        }
    }
}
void display(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",*(arr+i));
    }
}
int main()
{
    int n,i;
    char ch;
    printf("\nEnter the number of elements of array:");
    scanf("%d",&n);
    int arr[n];
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("Enter element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\nElements of array before sorting is......\n");
    display(arr,n);
    printf("\n\nOperation list....\n1.Bubble Sort\n2.Selection Sort\n3.Exit\nEnter operation number to be performed:");
    do
    {
        ch=getch();
    }while(ch<'0' || ch>'2');
    putch(ch);
    switch(ch)
    {
        case '1':
            bubblesort(arr,n);
            break;
        case '2':
            selectionsort(arr,n);
            break;
        case '3':
            printf("\n\n");
            exit(1);
            break;
    }
    printf("\n\nElements of array after sorting is......\n");
    display(arr,n);
    printf("\n\n");
    return 0;
}
