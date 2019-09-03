#include<stdio.h>
#include<stdio.h>
struct stack
{
    int elem[20];
    int top;
};
void push(struct stack *ptr)
{
    printf("\nEnter element:");
    (ptr->top)+=1;
    scanf("%d",&(ptr->elem[ptr->top]));
}
int main()
{
    int n,t,i,j,siz=0;
    printf("\nEnter number of stack:");
    scanf("%d",&n);
    struct stack arr1[n];
    int size[n];
    for(i=0;i<n;i++)
    {
        printf("\nEnter number of elements of stack%d:",i+1);
        scanf("%d",&size[i]);
        siz+=size[i];
        arr1[i].top=-1;
        printf("\nEnter elements of stack %d....\n",i+1);
        for(j=0;j<size[i];j++)
        {
            push(arr1+i);
        }
    }
    int arr[siz];
    t=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<size[i];j++)
        {
            arr[t++]=(arr1[i].elem[j]);
        }
    }
    printf("\nArray Elements are.....\n");
    for(i=0;i<t;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n\n\n");
    return 0;
}
