#include<stdio.h>
int main()
{
    int i,j,arr[10],min;
    for(i=0;i<10;i++)
    {
        printf("\nEnter number %d:",i+1);
        scanf("%d",&arr[i]);
    }
    for(i=1;i<10;i++)
    {
        min = arr[i];
        for(j=i-1;j>=0;j--)
        {
            if(min<arr[j])
            {
                arr[j+1] = arr[j];
                arr[j] = min;
            }
            else
                break;
        }
    }
    for(i=0;i<10;i++)
    {
        printf("\nNumber %d:%d",i+1,arr[i]);
    }
    return 0;
}
