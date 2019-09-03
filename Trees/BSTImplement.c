#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    struct tree *left;
    int val;
    struct tree *right;
}node;
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
node * call(node *ptr)
{
    if(ptr->left=='\0' && ptr->right=='\0')
        return '\0';
    node * temp = ptr->left;
    if(temp->right=='\0')
    {
        temp->right = ptr->right;
        return (temp);
    }
    else
    {
        while(temp->right->right!='\0')
        {
            temp = temp->right;
        }
        node *temp1 = temp->right;
        temp->right = temp->right->left;
        temp1->left = '\0';
        return (temp1);
    }
}
void deletenode(node *ptr,int val)
{
    if(ptr == '\0')
    {
        printf("\nEntered Element Not Found In the Tree....\n");
        return;
    }
    node *temp;
    if(ptr->left != '\0' && ptr->left->val==val)
    {
        if(ptr->left->right=='\0')
        {
            ptr->left = ptr->left->left;
        }
        else if(ptr->left->left=='\0')
        {
            ptr->left = ptr->left->right;
        }
        else
        {
            temp = call(ptr->left);
            if(temp == '\0')
            {
                //ptr->left = ptr->left->left;
                ptr->left = '\0';
            }
            else if(temp == ptr->left->left)
            {
                ptr->left = temp;
            }
            else
            {
                temp->left = ptr->left->left;
                temp->right = ptr->left->right;
                ptr->left = temp;
            }
        }
    }
    else if(ptr->right != '\0' && ptr->right->val == val)
    {
        if(ptr->right->left == '\0')
        {
            ptr->right = ptr->right->right;
        }
        else if(ptr->right->right == '\0')
        {
            ptr->right = ptr->right->left;
        }
        else
        {
            temp = call(ptr->right);
            if(temp == '\0')
            {
                //ptr->right = ptr->right->left;
                ptr->right = '\0';
            }
            else if(temp == ptr->right->left)
            {
                ptr->right = temp;
            }
            else
            {
                temp->left = ptr->right->left;
                temp->right = ptr->right->right;
                ptr->right = temp;
            }
        }
    }
    else
    {
        if(ptr->val>=val)
            deletenode(ptr->left,val);
        else
            deletenode(ptr->right,val);
    }
}
void delroot_node(node **ptr)
{
    if((*ptr)->left=='\0' && (*ptr)->right=='\0')
    {
        *ptr = '\0';
    }
    else if((*ptr)->left=='\0')
    {
        *ptr = (*ptr)->right;
    }
    else if((*ptr)->right=='\0')
    {
        *ptr = (*ptr)->left;
    }
    //try eliminating above steps
    else
    {
        node *temp = call((*ptr));
        if(temp == (*ptr)->left)
        {
            temp->right = (*ptr)->right;
            *ptr = temp;
        }
        else if(temp == (*ptr)->right)
        {
            temp->left = (*ptr)->left;
            *ptr = temp;
        }
        else
        {
            temp->left = (*ptr)->left;
            temp->right = (*ptr)->right;
            (*ptr) = temp;
        }
    }
}
void display(node *ptr)
{
    if(ptr=='\0')
    {
        return;
    }
    display(ptr->left);
    printf("%d\t",ptr->val);
    display(ptr->right);
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
    printf("\nElements of Tree are.....\n");
    display(root);
    printf("\n\nEnter Element to be Deleted : ");
    scanf("%d",&n);
    if(root->val==n)
        delroot_node(&root);
    else
        deletenode(root,n);
    printf("\n\nAfter Deleting Elements of Tree are....\n");
    display(root);
    printf("\n\n");
    return 0;
}
