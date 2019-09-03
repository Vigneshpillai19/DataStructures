#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    int n;
    int order;
    int * arr;
    struct tree **ptr;
}node;
node * create_node(int ord)
{
    node * temp = (node *)malloc(sizeof(node));
    temp->n = -1;
    temp->order = ord;
    temp->arr = (int *)malloc((ord-1)*sizeof(int));
    temp->ptr = (node **)malloc(ord*sizeof(node *));
    for(int i=0;i<ord;i++)
    {
        //temp->(*(ptr+i)) = '\0';
        *(temp->ptr + i) = '\0';
    }
    return (temp);
}
/*node * split_node(node * temp,int num)
{
    node * ext_node = create_node(temp->order);
    node * ext_node1 = create_node(temp->order);
    ext_node->arr[++ext_node->n] = temp->arr[temp->order/2];//assigning mid node's value to new node
    int i = temp->order/2+1;
    while(i<=temp->n)//assigning right part node's value to new node
    {
        ext_node1->arr[++ext_node1->n] = temp->arr[i];
        if(*((temp->ptr)+i)!='\0')
        {
            //ext_node1->arr[ext_node1->n] = *((temp->ptr)+i);
            *(ext_node1->ptr+ext_node1->n) = *((temp->ptr)+i);
            *((temp->ptr)+i) = '\0';
        }
        i++;
    }
    ext_node1->arr[++ext_node1->n] = num;
    if(*(temp->ptr+i)!='\0')
    {
        *((ext_node1->ptr)+(ext_node1->n)) = *(temp->ptr+i);//assigning right node's last addr value to new node pointer
        *((temp->ptr)+i) = '\0';
    }
    else
    {
        //ext_node1->arr[++ext_node1->n] = num;
    }
    temp->n = temp->order/2-1;
    *((ext_node->ptr)+0) = temp;
    *((ext_node->ptr)+1) = ext_node1;
    return (ext_node);
}*/
node * split_node(node *ptr)
{
    int i;
    node * parent = create_node(ptr->order);
    node * rightchild = create_node(ptr->order);
    parent->arr[++parent->n] = ptr->arr[ptr->order/2];
    *(parent->ptr+0) = ptr;
    *(parent->ptr+1) = rightchild;
    for(i=(ptr->order/2+1);i<=ptr->n;i++)
    {
        rightchild->arr[++rightchild->n] = ptr->arr[i];
        if(*(ptr->ptr+i)!='\0')
        {
            *(rightchild->ptr+rightchild->n) = *(ptr->ptr+i);
            *(ptr->ptr+i) = '\0';
        }
    }
    if(*(ptr->ptr+i)!='\0')
    {
        *(rightchild->ptr+rightchild->n+1) = *(ptr->ptr+i);
        *(ptr->ptr+i) = '\0';
    }
    ptr->n = (ptr->order/2)-1;
    return(parent);
}
/*node * insert_value_split(node * temp1,node * temp2,int i)//for inserting node coming from bottom and entering node is full
{
    if(i==temp1->order-1)//inerting new node at last of current node
    {
        *(temp1->ptr+i) = *(temp2->ptr+0);//assigning temp2 node's 1st addr to temp1 node's last addr
        node * splt_node = split_node(temp1,temp2->arr[0]);//passing coming node's value
        node * extra = *(splt_node->ptr+1);
        *(extra->ptr+extra->n+1) = *(temp2->ptr+1);
        return(splt_node);
    }
    node *extra = *(temp1->ptr+temp1->order-1);
    int j = temp1->order-2;
    //node * t = *((temp1->ptr)+temp1->order-1);
    int num = temp1->arr[j--];
    while(j>i)
    {
        temp1->arr[j+1] = temp1->arr[j];
        *((temp1->ptr)+j+2) = *((temp1->ptr)+j+1);//shifting key's right pointer to next right pointer
        j--;
    }
    temp1->arr[j] = temp2->arr[0];
    *((temp1->ptr)+i) = *((temp2->ptr)+0);
    *((temp1->ptr)+i+1) = *((temp2->ptr)+1);
    node * splt_node = split_node(temp1,num);
    node * t = *(splt_node->ptr+1);
    *(t->ptr+t->n+1) = extra;
    return (splt_node);
}
node * insert_value_btwn(node * temp1,node * temp2,int i)//for inserting node coming from bottom and entering node is not full
{
    int j = temp1->n;
    temp1->n++;
    //*(temp1->ptr+j+2) = *(temp1->ptr+j+1);//shifting node's last reference by 1 position towards right
    while(j>i)
    {
        temp1->arr[j+1] = temp1->arr[j];//for shifting key values
        *(temp1->ptr+j+2) = *(temp1->ptr+j+1);//for shifting reference
        j--;
    }
    *(temp1->ptr+j+2) = *(temp1->ptr+j+1);
    *(temp1->ptr+i) = *(temp2->ptr+0);
    *(temp1->ptr+i+1) = *(temp2->ptr+1);
    temp1->arr[i] = temp2->arr[0];
    return (temp1);
}*/
node * insert_node_btwn(node * ptr,node * nx,int i)
{
    int j,num;
    node *tp;
    if((ptr->n+1) == (ptr->order-1))//for entering node into parent node which is full
    {
        if(i==ptr->order-1)
        {
            num = nx->arr[0];
            tp = *(nx->ptr+1);
        }
        else
        {
            num = ptr->arr[ptr->n];
            tp = *(ptr->ptr+ptr->n+1);
            for(j=ptr->n;j>i;j--)
            {
                ptr->arr[j] = ptr->arr[j-1];
                *(ptr->ptr+j+1) = *(ptr->ptr+j);
            }
            ptr->arr[i] = nx->arr[0];
            *(ptr->ptr+i+1) = *(nx->ptr+1);
        }
        node * spl_node = split_node(ptr);
        node * tp1 = *(spl_node->ptr+1);
        tp1->arr[++tp1->n] = num;
        *(tp1->ptr+tp1->n+1) = tp;
        free(nx);
        return(spl_node);
    }
    else
    {
        ptr->n++;
        for(j=ptr->n;j>i;j--)
        {
            *(ptr->ptr+j+1) = *(ptr->ptr+j);
            ptr->arr[j] = ptr->arr[j-1];
        }
        *(ptr->ptr+i+1) = *(nx->ptr+1);
        ptr->arr[i] = nx->arr[0];
        free(nx);
        return(ptr);
    }
}
/*node * insert_value(node *temp,int num)
{
    if(*(temp->ptr+0) != '\0')
    {
        int i = 0;
        while(i<=temp->n)
        {
            if(temp->arr[i]>num)
                break;
            else
                i++;
        }
        node * nxt_node = insert_value(*(temp->ptr+i),num);
        if(nxt_node == *(temp->ptr+i))
            return (temp);
        else
        {
            if(temp->n+1 == temp->order-1)//split current node to add coming new node stored in nxt_node
            {
                //node * nxt_node1 = insert_value_split(temp,nxt_node,i);
                return (insert_value_split(temp,nxt_node,i));
            }
            else
            {
                //node * nxt_node1 = insert_value(temp,nxt_node,i);
                return (insert_value_btwn(temp,nxt_node,i));
            }
        }
        //return (nxt_node1);
    }
    else
    {
        if(temp->n+1 == temp->order-1)//when root node is full and for insertion
        {
            //for swapping value with last node value with entered value(if entered value is less than last value)
            if(num<temp->arr[temp->n])
            {
                int t = num;//temp varialble for swapping value
                num = temp->arr[temp->n];
                temp->arr[temp->n] = t;
                int i = temp->n;
                while(i>0)
                {
                    if(temp->arr[i]<temp->arr[i-1])
                    {
                        int t = temp->arr[i];//temp varialble for swapping value
                        temp->arr[i] = temp->arr[i-1];
                        temp->arr[i-1]= t;
                        i--;
                    }
                    else
                        break;
                }
            }
            node * ext_node = split_node(temp,num);//num holds max value and it should be in splitted nodes last value
            return(ext_node);
        }
        else
        {
            temp->arr[++temp->n] = num;
            int i = temp->n;
            while(i>0)
            {
                if(temp->arr[i]<temp->arr[i-1])
                {
                    int t = temp->arr[i];
                    temp->arr[i] = temp->arr[i-1];
                    temp->arr[i-1] = t;
                    i--;
                }
                else
                    break;
            }
            return(temp);
        }
    }
}*/
node * insert_val(node * ptr,int val)
{
    int num,j,i=0;
    node * temp = *(ptr->ptr+0);
    if(temp == '\0')
    {
        while(i<=ptr->n)
        {
            if(val>ptr->arr[i])
                i++;
            else
                break;
        }
        if(ptr->n+1 == ptr->order-1)
        {
            if(i==ptr->n+1)
            {
                num = val;
            }
            else
            {
                num = ptr->arr[ptr->n];
                for(j=ptr->n;j>i;j--)
                {
                    ptr->arr[j] = ptr->arr[j-1];
                }
                ptr->arr[i] = val;
            }
            node * spl_node = split_node(ptr);
            node * tp = *(spl_node->ptr+1);
            tp->arr[++tp->n] = num;
            return(spl_node);
        }
        else
        {
            ptr->n++;
            for(j=ptr->n;j>i;j--)
            {
                ptr->arr[j] = ptr->arr[j-1];
            }
            ptr->arr[i] = val;
            return(ptr);
        }
    }
    else
    {
        while(i<=ptr->n)
        {
            if(val>ptr->arr[i])
                i++;
            else
                break;
        }
        node * nxt = insert_val(*(ptr->ptr+i),val);
        if(nxt == (*(ptr->ptr+i)))
            return(ptr);
        else
        {
            node * tp = insert_node_btwn(ptr,nxt,i);
            return(tp);
        }
    }
}
/***********************************************************************************************************************************************/

void display(node *ptr)
{
    int i=0;
    if(*(ptr->ptr+0)=='\0')
    {
        while(i<=ptr->n)
        {
            printf("\t%d",ptr->arr[i++]);
        }
    }
    else
    {
        while(i<=ptr->n)
        {
            display(*(ptr->ptr+i));
            printf("\t%d",ptr->arr[i++]);
        }
        display(*(ptr->ptr+i));
    }
}
node * root_merge(node *ptr)
{
    int j,temp = ptr->arr[0];
    ptr->n--;
    node *temp1,*temp2;
    temp1 = *(ptr->ptr+0);
    temp2 = *(ptr->ptr+1);
    for(j=0;j<=temp1->n;j++)
    {
        ptr->arr[++ptr->n] = temp1->arr[j];
        *(ptr->ptr+ptr->n) = *(temp1->ptr+j);
    }
    ptr->arr[++ptr->n] = temp;
    *(ptr->ptr+ptr->n) = *(temp1->ptr+j);
    for(j=0;j<=temp2->n;j++)
    {
        ptr->arr[++ptr->n] = temp2->arr[j];
        *(ptr->ptr+ptr->n) = *(temp2->ptr+j);
    }
    *(ptr->ptr+ptr->n+1) = *(temp1->ptr+j);
    free(temp1);
    free(temp2);
    return(ptr);
}
node * merge_child_node(node *ptr,node *temp_var1,node *temp_var2,int i)
{
    /*if(ptr->n==0)
    {
        return(root_merge(ptr));
    }*/
    int j;
    temp_var1->arr[++temp_var1->n] = ptr->arr[i];
    for(j=0;j<=temp_var2->n;j++)
    {
        temp_var1->arr[++temp_var1->n] = temp_var2->arr[j];
        *(temp_var1->ptr+temp_var1->n) = *(temp_var2->ptr+j);
    }
    *(temp_var1->ptr+temp_var1->n+1) = *(temp_var2->ptr+j);

    for(j=i;j<ptr->n;j++)
    {
        ptr->arr[j] = ptr->arr[j+1];
        *(ptr->ptr+j+1) = *(ptr->ptr+j+2);
    }
    *(ptr->ptr+ptr->n+1) = '\0';
    ptr->n--;
    free(temp_var2);
    return(ptr);
}
node * balance_node(node *ptr,int i)
{
    int j;
    node *temp1,*temp2,*temp3;
    temp1=temp3='\0';
    temp2 = *(ptr->ptr+i);
    if(i>0)
        temp1 = *(ptr->ptr+i-1);
    if(i<=ptr->n)
        temp3 = *(ptr->ptr+i+1);

    if(temp1!='\0' && ((temp1->n+1+temp2->n+1)==(temp2->order-2)))
    {
        ptr = merge_child_node(ptr,temp1,temp2,i-1);
    }
    else if(temp3!='\0' && ((temp2->n+1+temp3->n+1)==(temp2->order-2)))
    {
        //temp2->arr[++temp2->n] = ptr->arr[i];
        ptr = merge_child_node(ptr,temp2,temp3,i);
    }
    else
    {
        if(i>0)
        {
            for(j=temp2->n;j>=0;j--)
            {
                temp2->arr[j+1] = temp2->arr[j];
                *(temp2->ptr+j+2) = *(temp2->ptr+j+1);
            }
            *(temp2->ptr+j+2) = *(temp2->ptr+j+1);
            temp2->arr[0] = ptr->arr[i-1];
            *(temp2->ptr+0) = *(temp1->ptr+temp1->n+1);
            ptr->arr[i-1] = temp1->arr[temp1->n];
            *(temp1->ptr+temp1->n+1) = '\0';
            temp1->n--;
            temp2->n++;
        }
        else
        {
            temp2->arr[++temp2->n] = ptr->arr[i];
            ptr->arr[i] = temp3->arr[0];
            *(temp2->ptr+temp2->n+1) = *(temp3->ptr+0);
            for(j=0;j<temp3->n;j++)
            {
                temp3->arr[j] = temp3->arr[j+1];
                *(temp3->ptr+j) = *(temp3->ptr+j+1);
            }
            *(temp3->ptr+j) = *(temp3->ptr+j+1);
            *(temp3->ptr+j+1) = '\0';
            temp3->n--;
        }
    }
    return(ptr);
}
int copy_val_check(node *ptr,int i)
{
    int status;
    node *temp = *(ptr->ptr+i+1);
    if(temp == '\0')
    {
        for(int j=i;j<ptr->n;j++)
        {
            ptr->arr[j] = ptr->arr[j+1];
        }
        ptr->n--;
    }
    else
    {
        ptr->arr[i] = temp->arr[0];
        status = copy_val_check(temp,0);
        if(status == 0)
        {
            ptr = balance_node(ptr,i+1);
        }
    }
    if(ptr->n+1 >= (ptr->order/2))
        return(1);
    else
        return(0);
}
int delete_val(node *ptr,int val)
{
    if(ptr=='\0')
    {
        printf("\nValue not Found....\n\n");
        return (1);
    }
    node *temp;
    int status,i = 0;
    while(i<=ptr->n)
    {
        if(val>ptr->arr[i])
        {
            i++;
        }
        else if(val<ptr->arr[i])
        {
            break;
        }
        else
        {
            temp = *(ptr->ptr+i+1);
            status = copy_val_check(ptr,i);
            return(status);
        }
    }
    temp = *(ptr->ptr+i);
    status = delete_val(temp,val);
    if(status == 0)
    {
        ptr = balance_node(ptr,i);
    }
    if(ptr->n+1 >= ptr->order/2)
        return(1);
    else
        return (0);
}

/*******************************************************************************************************************************************/

int main()
{
    int order,num,val,status;
    char ch;
    printf("\nEnter Order of B Tree (Order>3) : ");
    do
    {
       scanf("%d",&order);
    }while(order<3);
    node * root = create_node(order);
    do
    {
        printf("\n\nEnter the element to be added :");
        scanf("%d",&num);
        root = insert_val(root,num);
        printf("\nRoot : %d \n",root);
        printf("\nDo you want to add more element in B Tree (Y/N): ");
        do
        {
            ch = getch();
        }
        while(!(ch=='y' || ch=='Y' || ch=='N' || ch=='n'));
        if(ch=='n' || ch=='N')
        {
            display(root);
            break;
        }
        display(root);
    }
    while(1);
    printf("\n\nRoot : %d,%d,%d\n",root,root->n,root->arr[0]);
    display(root);
    do
    {
        display(root);
        printf("\n\nEnter Element to be deleted :");
        scanf("%d",&val);
        status = delete_val(root,val);
        printf("\n\nRoot : %d,%d,%d\n",root,root->n,root->arr[0]);
        if(root->n==-1)
        {
            if(*(root->ptr+0)!='\0')
            {
                node *tp = root;
                root = *(root->ptr+0);
                free(tp);
            }
            else if(*(root->ptr+1)!='\0')
            {
                node *tp = root;
                root = *(root->ptr+1);
                free(tp);
            }
            else
                root = '\0';
        }
        //printf("Root : %d,%d\n\n",root,root->n);
        printf("\nDo you want to delete more element in B Tree (Y/N): ");
        do
        {
            ch = getch();
        }
        while(!(ch=='y' || ch=='Y' || ch=='N' || ch=='n'));
        if(ch=='n' || ch=='N')
            break;
    }while(1);
    printf("\n\n\n");
    return 0;
}
