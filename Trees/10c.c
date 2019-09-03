#include<stdio.h>
#include<stdlib.h>
int j=0;
int height = 0;
int heights[6]={0};
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
/*void delet(node **ptr,int num)
{
    node *parent,*temp,*temp1;
    temp = *ptr;
    if(temp=='\0')
    {
        printf("\nEmpty Tree....\n\n");
    }
    else
    {
        while(temp!='\0')
        {
            if(temp->val!=num && temp->left=='\0' && temp->right=='\0')
            {
                printf("\nValue not found....\n\n");
                return;
            }
            if(temp->val==num)
            {
                break;
            }
            if(temp->val>num)
            {
                //parent = temp;
                temp = temp->left;
            }
            else
            {
                //parent = temp;
                temp = temp->right;
            }
        }
        //printf("\n%d",temp->val);
        if(temp==*ptr)
            *ptr = '\0';
        else
        {
            temp1=temp->left;
            if(temp1!='\0')
            {
                while(temp1->right!='\0')
                {
                    parent = temp1;
                    temp1 = temp1->right;
                }
                printf("\n%d",parent->val);
                temp->val = parent->val;
                parent->right = '\0';
            }
            else //if((temp1=temp->right)!='\0')
            {
                temp1=temp->right;
                while(temp1->left!='\0')
                {
                    parent = temp1;
                    temp1 = temp1->left;
                }
                printf("\n%d",parent->val);
                temp->val = parent->val;
                parent->left = '\0';
            }
        }

    }
}*/
void display(node *ptr)
{
    height++;
    if(ptr=='\0')
    {
        return;
    }
    if(ptr->left=='\0' && ptr->right=='\0')
    {
        printf("%d\t",ptr->val);
        heights[j++]=height;
        return;
    }
    display(ptr->left);
    height--;
    printf("%d\t",ptr->val);
    display(ptr->right);
    height--;
}
/*void display(node *ptr)
{
    height++;
    if(ptr=='\0')
    {
        heights[j++]=height-1;
        return;
    }
    //printf("%c\t",ptr->val);
    display(ptr->left);
    printf("  %c",ptr->val);
    display(ptr->right);
    height--;
    //printf("%c\t",ptr->val);
}*/
int main()
{
    int n=0;
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
    //scanf("%d",&n);
    //delet(&root,n);
    //display(root);
    for(int i=0;i<j;i++)
    {
        if(n<heights[i])
            n = heights[i];
        //printf("\nHeight %d : %d\n",i+1,heights[i]);
    }
    printf("\n\nHeight of a Tree is %d.\n\n",n);
    printf("\n\n");
    return 0;
}
