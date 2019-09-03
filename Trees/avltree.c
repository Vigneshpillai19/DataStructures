#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    struct tree * left;
    int val;
    int height;
    int bf;
    struct tree * right;
}node;
node * create_node()
{
    node * temp = (node *)malloc(sizeof(node));
    printf("\nEnter Elememt :");
    scanf("%d",&temp->val);
    temp->right = temp->left = '\0';
    temp->height = 1;
    temp->bf = 0;
    return temp;
}
void insert(node **ptr)
{
    if(*ptr=='\0')
    {
        *ptr = (node *)malloc(sizeof(node));
        (*ptr)->right = (*ptr)->left = '\0';
        (*ptr)->height = 1;
        (*ptr)->bf = 0;
        printf("\nEnter First Element of Tree : ");
        scanf("%d",&(*ptr)->val);
        return;
    }
    node *pt,*temp;
    pt = *ptr;
    temp = create_node();
    while(!(pt->left=='\0' && pt->right=='\0'))
    {
        if(pt->val>=temp->val)
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
    if(pt->val>=temp->val)
        pt->left = temp;
    else
        pt->right = temp;
}
int update_height(node *ptr)
{
    if(ptr=='\0')
    {
        return 0;
    }
    int h1,h2;
    h1 = update_height(ptr->left);
    h2 = update_height(ptr->right);
    ptr->bf = (h1-h2);
    if(h1>=h2)
    {
        ptr->height = h1+1;
        return(h1+1);
    }
    else
    {
        ptr->height = h2+1;
        return(h2+1);
    }
}
node * make_AVL(node *ptr)
{
    int h;
    if(ptr->bf>-2 && ptr->bf<2)
    {
        ptr->height = update_height(ptr);
        h = update_height(ptr);
        return(ptr);
    }
    if(ptr->left!='\0' && (ptr->left->bf<-1 || ptr->left->bf>1))
    {
        //printf("\nHIII\n");
        ptr->left = make_AVL(ptr->left);
        ptr->left->height = update_height(ptr->left);
        while(ptr->left->bf>1 || ptr->left->bf<-1)
        {
            ptr->left = make_AVL(ptr->left);
            //ptr->left->height = update_height(ptr->left);
            h = update_height(ptr->left);
        }
    }
    if(ptr->right!='\0' && (ptr->right->bf<-1 || ptr->right->bf>1))
    {
        ptr->right = make_AVL(ptr->right);
        //ptr->right->height = update_height(ptr->right);
        h = update_height(ptr->left);
        while(ptr->right->bf>1 || ptr->right->bf<-1)
        {
            ptr->right = make_AVL(ptr->right);
            ptr->right->height = update_height(ptr->right);
        }
    }
    if(ptr->bf>0)
    {
        node * temp = ptr->left;//storing address of left subtree
        ptr->left = temp->right;//assigning left with left subtree's right subtree
        temp->right = ptr;//assigning left subtree's right with this(current) node's tree
        return (temp);
    }
    else
    {
        node * temp = ptr->right;//storing address of right subtree
        ptr->right = ptr->right->left;//ptr->right = temp->left;
        //assigning right with right subtree's left subtree
        temp->left = ptr;//assigning right subtrees's left with this(current) node's tree
        return(temp);
    }
}
int main()
{
    int n,h1;
    char ch;
    node *root='\0';
    insert(&root);
    h1 = update_height(root);
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
        {
            insert(&root);
            h1 = update_height(root);
            /*root = make_AVL(root);
            while(root->bf>1 || root->bf<-1)
            {
                h1 = update_height(root);
                root = make_AVL(root);
            }*/
            printf("\n%d\n",root->bf);
            printf("\n%d\n",root->height);
        }
    }
    while(1);
    printf("\n%d\n",root->bf);
    printf("\n%d\n",root->height);

    h1 = update_height(root);
    root = make_AVL(root);
            while(root->bf>1 || root->bf<-1)
            {
                h1 = update_height(root);
                root = make_AVL(root);
            }

    printf("\n%d\n",root->bf);
    printf("\n%d\n",root->height);
    return 0;
}

