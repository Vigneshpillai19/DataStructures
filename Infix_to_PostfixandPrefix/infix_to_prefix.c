#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top=0;
void push(char *stck,char ch)
{
    *(stck + (++top))=ch;
}
char pop(char *stck)
{
    return (*(stck + (top--)));
}
void swap(int *ptr,int start,int end)
{
    for(int i=start;i<=end;i++)
    {
        *(ptr+i-2)=*(ptr+i);
    }
}
void print(int *ptr,int start, int end)
{
    printf("\n");
    for(int i=start;i<=end;i++)
    {
        printf("%d",*(ptr+i));
    }
}
int main()
{
    char str[30],str1[30];
    char stack[20];
    int calc[30];
    int i,len,lent,j=0;
    int start=0,end=0;
    stack[0]=')';
    printf("\nEnter the expression:");
    gets(str);
    len=strlen(str);
    for(i=len-1;i>=0;i--)
    {
        switch(str[i])
        {
            case ')':
                push(stack,')');
                break;
            case '(':
               while(stack[top]!=')')
               {
                   str1[j++]=pop(stack);
                   //putchar(str1[j-1]);//for printing characters
               }
               break;
            case '%':
                push(stack,'%');
                break;
            case '*':
                while(stack[top]=='%')
                {
                    str1[j++]=pop(stack);
                    //putchar(str1[j-1]);//for printing characters
                }
                push(stack,'*');
                break;
            case '/':
                while(stack[top]=='%')
                {
                    str1[j++]=pop(stack);
                    //putchar(str1[j-1]);//for printing characters
                }
                push(stack,'/');
                break;
            case '+':
                while(stack[top]=='%'||stack[top]=='*'||stack[top]=='/')
                {
                    str1[j++]=pop(stack);
                    //putchar(str1[j-1]);//for printing characters
                }
                push(stack,'+');
                break;
            case '-':
                while(stack[top]=='%'||stack[top]=='*'||stack[top]=='/')
                {
                    str1[j++]=pop(stack);
                    //putchar(str1[j-1]);//for printing characters
                }
                push(stack,'-');
                break;
            default:
                if(str[i]>=48&&str[i]<58)
                {
                    str1[j++]=str[i];
                    //printf("%d",str1[j-1]);
                    break;
                }
        }
    }
    while(top!=0)
    {
        if(stack[top]!='('&&stack[top]!=')')
        {
            str1[j++]=pop(stack);
            //putchar(str1[j-1]);
        }
        else
        {
            top--;
        }
    }
    printf("\nThe infix to postfix to expression is :");
    lent=j--;
    for(i=j;i>=0;i--)
    {
        if(str1[i]>=48 && str1[i]<=57)
        {
            calc[j-i]=str1[i]-48;
            printf("%d",calc[j-i]);
        }
        else
        {
            calc[j-i]=str1[i];
            printf("%c",calc[j-i]);
        }
        //putchar(str1[i]);
    }
    printf("\n");
    for(i=0;i<=j;i++)
    {
        //printf("%d",calc[i]);
    }
    lent=j;
    for(i=j;i>=0;i--)
    {
        switch(calc[i])
        {
            case '*':
                calc[i]=(calc[i+1])*(calc[i+2]);
                //printf("\n%d",calc[i]);
                start=i+3;
                swap(calc,start,lent);
                lent-=2;
                //print(calc,0,lent);
                break;
            case '/':
                calc[i]=(calc[i+1])/(calc[i+2]);
                //printf("\n%d",calc[i]);
                start=i+3;
                swap(calc,start,lent);
                lent-=2;
                //print(calc,0,lent);
                break;
            case '+':
                calc[i]=(calc[i+1])+(calc[i+2]);
                //printf("\n%d",calc[i]);
                start=i+3;
                swap(calc,start,lent);
                lent-=2;
                //print(calc,0,lent);
                break;
            case '-':
                calc[i]=(calc[i+1])-(calc[i+2]);
                //printf("\n%d",calc[i]);
                start=i+3;
                swap(calc,start,lent);
                lent-=2;
                //print(calc,0,lent);
                break;
            case '/%':
                calc[i]=(calc[i+1])%(calc[i+2]);
                //printf("\n%d",calc[i]);
                start=i+3;
                swap(calc,start,lent);
                lent-=2;
                //print(calc,0,lent);
                break;

        }
    }
    printf("\n\nValue of given Expression is %d.\n\n",calc[0]);
    return 0;
}
