#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    struct tree *left;
    int val;
    struct tree *right;
}node;
void disp_inorder(node *ptr)
{
    if(ptr=='\0')
        return '\0';
    else
    {
        disp_inorder(ptr->left);
        printf("%d\t",ptr->val);
        disp_inorder(ptr->right);
    }
}
void disp_preorder(node *ptr)
{
    if(ptr=='\0')
        return '\0';
    else
    {
        printf("%d\t",ptr->val);
        disp_preorder(ptr->left);
        disp_preorder(ptr->right);
    }
}
void disp_postorder(node *ptr)
{
    if(ptr=='\0')
        return '\0';
    else
    {
        disp_postorder(ptr->left);
        disp_postorder(ptr->right);
        printf("%d\t",ptr->val);
    }
}
void insert(node **ptr)
{
    if(*ptr=='\0')
    {
        *ptr = (node *)malloc(sizeof(node));
        (*ptr)->right = (*ptr)->left = '\0';
        printf("\nEnter First Element of Tree : ");
        scanf("%d",&(*ptr)->val);
        return;
    }
    int num;
    node *pt,*temp;
    pt = *ptr;
    printf("\nEnter Elememt :");
    scanf("%d",&num);
    temp = (node *)malloc(sizeof(node));
    temp->right = temp->left = '\0';
    temp->val = num;
    while(!(pt->left=='\0' && pt->right=='\0'))
    {
        if(pt->val>=num)
        {
            if(pt->left=='\0')
            {
                pt->left = temp;
                return;
            }
            else
                pt = pt->left;
        }
        else
        {
            if(pt->right=='\0')
            {
                pt->right =temp;
                return;
            }
            else
                pt = pt->right;
        }
    }
    if(pt->val>=num)
        pt->left = temp;
    else
        pt->right = temp;
}
int main()
{
    int n;
    char ch;
    node *root='\0';
    insert(&root);
    do
    {
        printf("\nDo You Want to add more elements to tree (Y/N):");
        do
        {
            ch = getch();
        }
        while(!(ch=='y'||ch=='Y'||ch=='n'||ch=='N'));
        printf("%c\n",ch);
        if(ch=='n'||ch=='N')
            break;
        else
            insert(&root);
    }
    while(1);
    printf("\nElements of Tree in Preorder format is .......\n");
    disp_preorder(root);
    printf("\n\nElements of Tree in Inorder format is .......\n");
    disp_inorder(root);
    printf("\n\nElements of Tree in Postorder format is .......\n");
    disp_postorder(root);
    printf("\n\n");
    return 0;
}
