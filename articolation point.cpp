#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

int G1[100][100];
int color[100], d[100], f[100], prev[100],low[100],arra[100];
int time=0;
int top=0;
void print_path(int s, int v)
{
    if(s==v)
    {
        printf("%d->",s);
    }
    else if(prev[v]==-1)
    {
        printf("No Path");
    }
    else
    {
        print_path(s,prev[v]);
        printf("%d->",v);
    }
}

void DFS_visit(int u, int n)
{
    time++;
    d[u]=time;
    low[u]=d[u];
    color[u]=GRAY;
    for(int v=0; v<n; v++)
    {
        if(G1[u][v]==1)
        {
            if(color[v]==WHITE)
            {
                prev[v]=u;
                DFS_visit(v,n);
                if(low[v]>=d[u]){
                    arra[top++]=u;
                }
                if(low[v]<low[u])low[u]=low[v];
            }
            else if(color[v]==GRAY&&prev[u]!=v){
                if(d[v]<low[u])low[u]=low[v];
            }
        }
    }
    time++;
    f[u]=time;
    color[u]=BLACK;
}

void DFS(int n)
{
    for(int i=0; i<n; i++)
    {
        color[i]=WHITE;
        prev[i]=-1;
        low[i]=-1;
        f[i]=0;
    }
    time = 0;
    for(int u=0; u<n; u++)
    {
        if(color[u]==WHITE)
        {
            DFS_visit(u,n);
        }
    }
}

int main()
{
    int n, e, u, v;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&e);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            G1[i][j]=0;
        }
    }

    for(int i=0; i<e; i++)
    {
        printf("Enter edges:");
        scanf("%d %d",&u,&v);
        G1[u][v]=1;
        G1[v][u]=1;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%-4d",G1[i][j]);
        }
        printf("\n");
    }
    DFS(n);
    //top=top-2;
    for(int i=0;i<top;i++){
        printf("%d ",arra[i]);
    }
    return 0;
}
