#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top=0;
char stack[100];
int opt[20];
void push(char p)
{
    stack[top]=p;
}
void swap(int num,int l,int len)
{
    opt[l-2]=num;
    l++;
    while(l-1!=len)
    {
        opt[l-2]=opt[l++];
    }
    //printf("\n%d",num);
}
int main()
{
    int len,lent,i,j=0;
    char str[100];
    printf("\nEnter the expression:");
    gets(str);
    len=strlen(str);
    lent=0;
    //int stack[len+2];
    stack[0]='(';
    stack[len+1]=')';
    printf("\n\nThe postfix expression is:");
    for(i=0;i<len;i++)
    {
        switch (str[i])
        {
            case '(':
                ++top;
                push('(');
                break;
            case '%':
                ++top;
                push('%');
                break;
            case '*':
            case '/':
                if(stack[top]=='%'||stack[top]=='*'||stack[top]=='/')
                {
                    while(stack[top]!='('&&(stack[top]!='+'&&stack[top]!='-'))
                    {
                        opt[j++]=stack[top];
                        putchar(stack[top--]);
                        lent++;
                    }
                    ++top;
                    push(str[i]);
                }
                else
                {
                    ++top;
                    push(str[i]);
                }
                break;
            case '+':
            case '-':
                if(stack[top]=='*'||stack[top]=='/'||stack[top]=='%'||stack[top]=='+'||stack[top]=='-')
                {
                    while(stack[top]!='(')
                    {
                        opt[j++]=stack[top];
                        putchar(stack[top--]);
                        lent++;
                    }
                    ++top;
                    push(str[i]);
                }
                else
                {
                    ++top;
                    push(str[i]);
                }
                break;
            case ')':
                while(stack[top]!='(')
                {
                    opt[j++]=stack[top];
                    putchar(stack[top--]);
                    lent++;
                }
                top--;
                break;
            default:
                    opt[j++]=str[i]-48;
                    putchar(str[i]);
                    lent++;
                    break;
        }
    }
    while(top!=0)
    {
        opt[j++]=stack[top];
        putchar(stack[top--]);
        lent++;
    }
    /*printf("\n%d",j);
    for(j=0;j<lent;j++)
    {
        printf("\n%c",opt[j]);
    }*/
    while(lent!=1)
    {
        j=0;
        while(j<lent)
        {
            if(lent==1)
            {
                break;
            }
            if(opt[j]=='+'||opt[j]=='-'||opt[j]=='*'||opt[j]=='/'||opt[j]=='%')
            {
                switch(opt[j])
                {
                    case '+':
                        swap(opt[j-2]+(int)opt[j-1],j,lent);
                        break;
                    case '-':
                        swap(opt[j-2]-opt[j-1],j,lent);
                        break;
                    case '*':
                        swap(opt[j-2]*opt[j-1],j,lent);
                        break;
                    case '/':
                        swap(opt[j-2]/opt[j-1],j,lent);
                        break;
                    case '%':
                        swap(opt[j-2]%opt[j-1],j,lent);
                        break;
                }
                lent-=2;
                break;
            }
            j++;
        }
    }
    printf("\n\nThe value of given expresion is %d.\n\n\n",opt[0]);




    return 0;
}
