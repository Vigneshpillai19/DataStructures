#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    struct tree *left;
    int val;
    int status;
    struct tree *right;
}node;
node * insert_element()
{
    node *temp = (node *)malloc(sizeof(node));
    printf("\nEnter Element to be Inserted : ");
    scanf("%d",&temp->val);
    temp->left = temp->right = '\0';
    temp->status = 0;
    return(temp);
}

void insert_1threadedtree(node **ptr)
{
    if(*ptr=='\0')
    {
        printf("\nEnter First Element of Tree....\n");
        *ptr = insert_element();
        return;
    }
    node *temp = *ptr;
    node *newnode = insert_element();
    while(1)
    {
        if(temp->val>=newnode->val)
        {
            printf("%d\n",temp->val);
            if(temp->left=='\0')
            {
                temp->left = newnode;
                newnode->right = temp;
                newnode->status = 1;
                return;
            }
            else
                temp = temp->left;
        }
        else
        {
            printf("%d\n",temp->val);
            if(temp->right=='\0')
            {
                temp->right = newnode;
                return;
            }
            else if(temp->status==1)
            {
                temp->status=0;
                newnode->right = temp->right;
                temp->right = newnode;
                newnode->status = 1;
                return;
            }
            else
                temp = temp->right;
        }
    }
}
void display(node *temp)
{
    if(temp == '\0')
    {
        //printf("\nEmpty Tree.....\n\n");
        return;
    }
    if(temp->left=='\0')
    {
        printf("%d\t",temp->val);
        display(temp->right);
    }
    else if(temp->status == 0)
    {
        temp->status = 10;
        display(temp->left);
    }
    else if(temp->status == 10)
    {
        temp->status = 0;
        printf("%d\t",temp->val);
        display(temp->right);
    }
    else if(temp->status == 1)
    {
        temp->status = 2;
        display(temp->left);
    }
    else if(temp->status == 2)
    {
        temp->status = 1;
        printf("%d\t",temp->val);
        display(temp->right);
    }
}
int main()
{
    int n;
    char ch;
    node *root='\0';
    insert_1threadedtree(&root);
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
            insert_1threadedtree(&root);
    }
    while(1);
    printf("\nElements inserted Successfully......\n");
    printf("\nElements of Tree are.....\n");
    display(root);
    printf("\n\n\n");
    return 0;
}
