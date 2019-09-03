#include<stdio.h>
#include<stdlib.h>
void heaplarge(int *arr,int n,int size)
{
    int temp,left,right;
    left = 2*n+1;
    right = 2*n+2;
    if(left<=size && arr[left]>*(arr+n))
    {
        temp = arr[left];
        arr[left] = *(arr+n);
        *(arr+n) = temp;
    }
    if(right<=size && arr[right]>*(arr+n))
    {
        temp = arr[right];
        arr[right] = *(arr+n);
        *(arr+n) = temp;
    }
}
void display(int *arr,int n)
{
    printf("\nElements of Array is.....\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",*(arr+i));
    }
    printf("\n");
}
void swap(int *arr,int n)
{
    int temp;
    temp = *(arr);
    *(arr) = *(arr+n);
    *(arr+n) = temp;
}
int main()
{
    int i,n,size;
    printf("\nEnter Number of Elements of array : ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        printf("\nEnter Element %d :",i+1);
        scanf("%d",&arr[i]);
    }
    size = n;
    while(size>1)
    {
        i = (size-2)/2;
        for(;i>=0;i--)
        {
            heaplarge(arr,i,size-1);
        }
        swap(arr,size-1);
        size--;
    }
    display(arr,n);
    return 0;
}
