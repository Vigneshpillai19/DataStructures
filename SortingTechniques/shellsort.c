#include<stdio.h>
int main()
{
    int n=10;
    int i,arr[n];
    for(i=0;i<n;i++)
    {
        printf("\nEnter number %d:",i+1);
        scanf("%d",&arr[i]);
    }
    shellsort(arr,n,n/2);
    //insertionsort(arr,0,n,1);
    for(i=0;i<n;i++)
    {
        printf("\nNumber %d:%d",i+1,arr[i]);
    }
    return 0;
}
void shellsort(int * arr,int n,int incr)
{
    int i;
    if(incr == 0)
    {
        return;
    }
    for(i=0;i<incr;i++)
    {
        insertionsort(arr,i+incr,n,incr);
    }
    display(arr,10);
    shellsort(arr,n,incr/2);
}
void insertionsort(int * arr,int i,int n ,int incr)
{
    int min,j;
    for(;i<n;i+=incr)
    {
        min = arr[i];
        for(j=i-incr;j>=0;j-=incr)
        {
            if(min<arr[j])
            {
                arr[j+incr] = arr[j];
                arr[j] = min;
            }
            else
                break;
        }
    }
}
void display(int * arr,int n)
{
    printf("\nArray Elements:\n");
    for(int i=0;i<n;i++)
        printf("%d\t",*(arr+i));
}
