#include<stdio.h>
#include<stdlib.h>
int visited[10]={0};
int visitedarr[10]={0};
typedef struct adjnode
{
    int val;
    struct adjnode *next;
}node;
typedef struct adjnodelist
{
    node *list;
}nodelist;
typedef struct graphs
{
    int v;
    nodelist *array;//node **array
}graph;

graph * creategraph(int n)
{
    graph *ptr = (graph *)malloc(sizeof(graph));
    ptr->v = n;
    ptr->array = (nodelist *)malloc(n*sizeof(nodelist));//(node **)malloc(n*sizeof(node *));
    for(int i=0;i<n;i++)
        ptr->array[i].list = '\0';
    return ptr;
}
node * newnode(int num)
{
    node *pt = (node *)malloc(sizeof(node));
    pt->val =num;
    pt->next = '\0';
    return (pt);
}
void addedge(graph *g,int src,int dest)
{
    node *temp = newnode(dest);
    temp->next = g->array[src-1].list;
    g->array[src-1].list = temp;

    temp = newnode(src);
    temp->next = g->array[dest-1].list;
    g->array[dest-1].list = temp;
}
void display(graph *gh)
{
    for(int i=0;i<gh->v;i++)
    {
        printf("\nGraph with vertex %d is \n",i+1);
        node *temp = gh->array[i].list;
        while(temp!='\0')
        {
            printf("->%d",temp->val);
            temp = temp->next;
        }
    }
}
void dispDFS(nodelist **ptr,int loc)
{
    if(*ptr=='\0')
        return;
    node *temp = ((*ptr)+loc)->list;//*** are used since lhs is node and rhs is nodelist
    while(temp!='\0')
    {
        if(visited[temp->val]!=1)
        {
            visited[temp->val]=1;
            printf("%d\t",temp->val);
            dispDFS(ptr,temp->val-1);
        }
        temp = temp->next;
    }
}
void dispBFS(nodelist **ptr,int loc)
{
    node *temp = ((*ptr)+loc)->list;
    while(temp!='\0')
    {
        if(visited[temp->val]!=1)
        {
            printf("%d\t",temp->val);
            visited[temp->val] = 1;
        }
        temp = temp->next;
    }
    visitedarr[loc+1]=1;
    temp = ((*ptr)+loc)->list;
    while(temp!='\0')
    {
        if(visited[temp->val]!=1)
        {
            visited[temp->val]=1;
            printf("%d\t",temp->val);
        }
        if(visitedarr[temp->val]!=1)
        {
            visitedarr[temp->val]=1;
            dispBFS(ptr,temp->val-1);
        }
        temp = temp->next;
    }
}
int main()
{
    int n;
    char ch;
    /*printf("\nEnter Number of vertices of Graph :");
    scanf("%d",&n);*/
    graph *g = creategraph(8);
    addedge(g,1,2);
    addedge(g,1,3);
    addedge(g,2,8);
    addedge(g,2,4);
    addedge(g,3,5);
    addedge(g,3,6);
    addedge(g,6,7);
    addedge(g,4,5);
    display(g);
    printf("\n\n");
    do
    {
        printf("\nList of Operations....\n1.DFS\n2.BFS\n3.Exit\nEnter operation Number to be performd : ");
        do
        {
            ch=getch();
        }while(ch<'0'||ch>'3');
        printf("%c\n",ch);
        switch(ch)
        {
            case '1':
                printf("\nEnter Vertex number from which to be traced :");
                scanf("%d",&n);
                visited[n]=1;
                printf("%d\t",n);
                dispDFS(&g->array,n-1);
                break;
            case '2':
                printf("\nEnter Vertex number from which to be traced :");
                scanf("%d",&n);
                visited[n]=1;
                printf("%d\t",n);
                dispBFS(&g->array,n-1);
                break;
            case '3':
                printf("Exiting....\n\n");
                exit(1);
        }
        for(int i=0;i<10;i++)
        {
            visited[i]=0;
            visitedarr[i]=0;
        }
    }while(1);
    return 0;
}
