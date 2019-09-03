#include<stdio.h>
#include<stdlib.h>
void sort(int *arr,int st,int en)
{
    int end1,end2,i,j,len;
    i = st;
    end1 = (st+en)/2;
    j = (st+en)/2+1;
    end2 = en;
    int temp[en-st+1];
    len = 0;
    while(i<=end1 || j<=end2)
    {
        if(i>end1)
        {
            temp[len++] = *(arr+j);
            j++;
        }
        else if(j>end2)
        {
            temp[len++] = *(arr+i);
            i++;
        }
        else if(*(arr+i)>=*(arr+j))
        {
            temp[len++] = *(arr+j);
            j++;
        }
        else
        {
            temp[len++] = *(arr+i);
            i++;
        }
    }
    len = 0;
    for(i=st;i<=en;i++)
    {
        *(arr+i) = temp[len++];
    }
}
void mergesort(int *arr,int st,int en)
{
    if(st==en)
        return;
    mergesort(arr,st,(st+en)/2);
    mergesort(arr,(st+en)/2+1,en);
    sort(arr,st,en);
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
    int n;
    printf("\nEnter number of elements of array : ");
    scanf("%d",&n);
    int i,arr[n];
    for(i=0;i<n;i++)
    {
        printf("\nEnter number %d:",i+1);
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1);
    printf("\nElements of array after sorting is.......\n");
    display(arr,n);
    printf("\n\n");
    return 0;
}
