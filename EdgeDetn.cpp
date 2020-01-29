#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2

int G[100][100];
int color[100], d[100], f[100], prev[100],treeEdge[100][100],backEdge[100][100];
int forwardEdge[100][100],crossEdge[100][100];
int times=0;
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
    times++;
    d[u]=times;
    color[u]=GRAY;
    for(int v=0; v<n; v++)
    {
        if(G[u][v]==1)
        {
            if(color[v]==BLACK && d[u]>d[v])
            {
                cout << u << "---" << v << "Cross Edge \n";
            }
            else if(color[v]==BLACK && d[u]<d[v])
            {
                cout << u << "---" << v << "Forward Edge \n";
            }
            else if(color[v]==GRAY)
            {
                cout << u << "---" << v << "Back Edge \n";
            }
            else if(color[v]==WHITE)
            {
                cout << u << "---" << v << "Tree Edge \n";
                prev[v]=u;
                DFS_visit(v,n);
            }

        }
    }
    times++;
    f[u]=times;
    color[u]=BLACK;
}

void DFS(int n)
{
    for(int i=0; i<n; i++)
    {
        color[i]=WHITE;
        prev[i]=-1;
    }

    for(int u=0; u<n; u++)
    {
        if(color[u]==WHITE)
            DFS_visit(u,n);
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
            G[i][j]=0;
        }
    }

    for(int i=0; i<e; i++)
    {
        printf("Enter edges:");
        scanf("%d %d",&u,&v);
        G[u][v]=1;
        //G[v][u]=1;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%-4d",G[i][j]);
        }
        printf("\n");
    }

    DFS(n);

    /*for(int i=0;i<n;i++)
    {
        printf("%d ",color[i]);
    }
    printf("\n");

    for(int i=0;i<n;i++)
    {
        printf("%d ",d[i]);
    }

    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",f[i]);
    }

    printf("\n");

    for(int i=0;i<n;i++)
    {
        printf("%d ",prev[i]);
    }

    printf("\n");
    print_path(0,5);*/
    return 0;
}
