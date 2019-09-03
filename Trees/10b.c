#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int len;
typedef struct tree
{
    struct tree *left;
    int val;
    struct tree *right;
}node;
int isoperator(char st)
{
    if(st=='+'||st=='-'||st=='*'||st=='/'||st=='%')
        return 1;
    else
        return 0;
}
node * insertnewnode(char *str)
{
    if(len<0)
        return '\0';
    node *ptr1;
    if(len>=0 && isoperator(*(str+len)))
    {
        ptr1 = (node *)malloc(sizeof(node));
        ptr1->val = *(str+len);
        len--;
        ptr1->right = insertnewnode(str);
        len--;
        ptr1->left = insertnewnode(str);
        return(ptr1);
    }
    else
    {
        ptr1 = (node *)malloc(sizeof(node));
        ptr1->right = ptr1->left = '\0';
        ptr1->val = *(str+len);
        return (ptr1);
    }
}
void display(node *ptr)
{
    if(ptr=='\0')
    {
        return;
    }
    //printf("%c\t",ptr->val);
    display(ptr->left);
    printf("  %c",ptr->val);
    display(ptr->right);
    //printf("%c\t",ptr->val);
}
int main()
{
    char str[25];
    int length;
    node *root;
    printf("\nEnter postfix Expression : ");
    gets(str);
    length = strlen(str);
    len = length-1;
    root = insertnewnode(str);
    printf("\nExpression in Binary Tree in Inorder format is....\n");
    display(root);
    printf("\n\n");
    return 0;
}
