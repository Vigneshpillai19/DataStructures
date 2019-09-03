#include<stdio.h>
#include<stdlib.h>
void binsearch(int *arr,int beg,int end,int n)
{
    int m;
    m=(beg+end)/2;
    if(n==*(arr+m))
    {
        printf("\nElement found at %d position.",m+1);
    }else if(beg>=end)
    {
        printf("\nElement not found.");
    }else if(n>*(arr+m))
    {
        binsearch(arr,m+1,end,n);
    }else
    {
        binsearch(arr,beg,m-1,n);
    }
}
int main()
{
    int arr[100],n,i,j,num;
    printf("\nEnter the number of elements in array:");
    scanf("%d",&n);
    printf("\nEnter the number of elements in ascending order....\n");
    for(i=0;i<n;i++)
    {
        printf("\nEnter element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\nElements in array are .....\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    printf("\nEnter elements to be searched:");
    scanf("%d",&num);
    binsearch(arr,0,n,num);
    printf("\n\n\n");
    return 0;
}
