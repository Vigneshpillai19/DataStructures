#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int counts[10]={0};
int visitedarr[10]={0};
int distance[8][8]={0};
int distancearr[10]={-1};
int dist=0;
int count = 1;
int i=0;
int k=0;
typedef struct ll
{
    int val;
    struct ll *next;
}node;
typedef struct gh
{
    int v;
    node **ptr;
}graph;
graph * creategraph(int n)
{
    graph * g = (graph *)malloc(sizeof(graph));
    g->v = n;
    node ** pt = (node **)malloc(n*sizeof(node *));
    for(int i=0;i<n;i++)
        *((pt)+i)='\0';
    g->ptr = pt;
    return (g);
}
node * newnode(int src)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->val = src;
    temp->next = '\0';
    return (temp);
}
void addedge(graph * gh,int src,int dest,char ch)
{
    node * temp = newnode(dest);
    temp->next = (gh->ptr[src-1]);
    (gh->ptr[src-1]) = temp;
    if(ch=='y' || ch=='Y')
    {
        temp = newnode(src);
        temp->next = (gh->ptr[dest-1]);
        (gh->ptr[dest-1]) = temp;
    }
}
void display(graph *gh)
{
    for(int i=0;i<gh->v;i++)
    {
        printf("\nGraph with vertex %d is \n",i+1);
        node *temp = gh->ptr[i];
        while(temp!='\0')
        {
            printf("->%d",temp->val);
            temp = temp->next;
        }
    }
}

void trace(node **ptr,int loc,int num,int prev)
{
    count++;
    node *temp = (*(ptr+loc));
    if(temp->val==num)
    {
        printf("%d\t",temp->val);
        visitedarr[temp->val]=1;
        counts[i++]=count;
        dist += distance[prev][temp->val];
        distancearr[k++] = dist;
        printf("\n%d\n",dist);
        dist -= distance[prev][temp->val];
        return;
    }
    else if(temp=='\0')
    {
        count--;
        return;
    }
    else
    {
        while(temp!='\0')
        {
            if(temp->val==num)
            {
                printf("%d\t",temp->val);
                counts[i++]=count;
                dist += distance[prev][temp->val];
                distancearr[k++] = dist;
                printf("\n%d\n",dist);
                break;
            }
            if(visitedarr[temp->val]==0)
            {
                printf("%d\t",temp->val);
                visitedarr[temp->val]=1;
                dist += distance[prev][temp->val];
                trace(ptr,temp->val-1,num,temp->val);
                count--;
                dist -= distance[prev][temp->val];
                visitedarr[temp->val]=0;
            }
            temp = temp->next;
        }
    }
}
int main()
{
    int n,n1,n2,num,j=0;
    char ch;
    printf("\nEnter number of vertices of graphs : ");
    scanf("%d",&n);
    graph *g = creategraph(n);
    printf("\nTo stop Entering Edges Enter (-1,-1)\n");
    do
    {
        printf("\nEnter Edges :\n");
        printf("\nEnter source edge :");
        scanf("%d",&n1);
        printf("\nEnter destination edge :");
        scanf("%d",&n2);
        if(n1==-1||n2==-1)
            break;
        printf("\nEnter distance between Source and Destination node : ");
        scanf("%d",&distance[n1][n2]);
        printf("\nIs there a reverse Connection(Y/N): ");
        ch=getch();
        if(ch=='y' || ch=='Y')
        {
            printf("\n\nEnter distance between Destination and Source node : ");
            scanf("%d",&distance[n2][n1]);
        }
        addedge(g,n1,n2,ch);
    }while(1);
    display(g);
    printf("\nEnter the source node from which to be traversed :");
    scanf("%d",&n1);
    printf("\nEnter destination node :");
    scanf("%d",&n2);
    node *temp = g->ptr[n1-1];
    visitedarr[n1] = 1;
    while(temp!='\0')
    {
        if(temp->val==n2)
        {
            counts[i++]=1;
            printf("\n%d\n",distance[n1][n2]);
        }
        else
        {
            printf("%d\t%d\t",n1,temp->val);
            visitedarr[temp->val]=1;
            count = 1;
            dist = distance[n1][temp->val];
            trace(&g->ptr[0],temp->val-1,n2,temp->val);
            for(j=0;j<10;j++)
            {
                if(j!=n1)
                {
                    visitedarr[j] = 0;
                }
            }
            printf("\n\n");
        }
        temp = temp->next;
    }
    int min = distancearr[0];
    for(j=1;j<k;j++)
    {
        if(min>distancearr[j])
        {
            min = distancearr[j];
        }
    }
    if(distancearr[0]==-1)
    {
        printf("\nShortest Distance between Node %d and Node %d is Infinity.\n\n",n1,n2);
    }
    else
    {
        printf("\nShortest Distance between Node %d and Node %d is %d.\n\n",n1,n2,min);
    }

    for(j=0;j<i;j++)
    {
        printf("\nCount %d : %d",j+1,counts[j]);
    }
    return 0;
}
