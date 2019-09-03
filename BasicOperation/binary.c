#include<stdio.h>
int top=-1;
int stack[32];
void push(int num)
{
    if(num)
    {
        stack[++top]=num%2;
        push(num/2);
    }
}
void display()
{
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%d",stack[i]);
    }
}
int main()
{
    int n;
    printf("\nEnter the decimal numeber:");
    scanf("%d",&n);
    push(n);
    printf("\nBinary of %d is:",n);
    display();
    return 0;
}
