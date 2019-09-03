#include<stdio.h>
void towhon(int n,char a,char b,char c)
{
    if(n==1)
        printf("\nMove disc from %c to %c",a,c);
    else
    {
        towhon(n-1,a,c,b);
        printf("\nMove disc from %c to %c",a,c);
        towhon(n-1,b,a,c);
    }
}
int main()
{
    int n;
    printf("\nMain Tower be A\nAuxiliary Tower be B\nDestination Tower be C\nEnter the number of disc in Tower A:");
    scanf("%d",&n);
    towhon(n,'A','B','C');
    return 0;
}
