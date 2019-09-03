#include<stdio.h>
#include<stdlib.h>
void quicksort(int *arr,int st,int end)
{
    if(st>=end)
    {
        return;
    }
    int low,high,temp;
    low = st;
    high = end-1;
    int pv = *(arr+end);
    while(low!=high)
    {
        if(*(arr+low)>pv && *(arr+high)<=pv)
        {
            temp = *(arr+low);
            *(arr+low) = *(arr+high);
            *(arr+high) = temp;
            low++;
            //display(arr,5);
        }
        else
        {
            if(*(arr+low)<=pv)
            {
                low++;
            }
            else if(*(arr+high)>pv)
            {
                high--;
            }
        }

    }
    if(high!=end-1 || *(arr+high)>*(arr+end))
    {
        temp = *(arr+high);
        *(arr+high) = *(arr+end);
        *(arr+end) = temp;
        //display(arr,5);
        quicksort(arr,st,high-1);
        quicksort(arr,high+1,end);
    }
    else
    {
        //display(arr,5);
        quicksort(arr,st,high);
    }
}
void display(int * arr,int n)
{
    for(int i=0;i<n;i++)
        printf("%d\t",*(arr+i));
    printf("\n");
}
int main()
{
    int n;
    printf("\nEnter the size of array : ");
    scanf("%d",&n);
    int i,arr[n];
    for(i=0;i<n;i++)
    {
        printf("\nEnter number %d:",i+1);
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    display(arr,n);
    return 0;
}
