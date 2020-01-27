#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2
stack <int> s;
int counts;
int G[100][100],G2[100][100];
int color[100], d[100], f[100], prev[100],scc[100];
int times=0;
int maxfunc(int n)
{
    int m=0;
    for(int i=0; i<n; i++)
    {
        if(m<f[i])
        {
            m=i;
        }
    }
    return m;
}
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
void DFS_visit1(int u, int n)
{
    //times++;
    u=maxfunc(n);
    //d[u]=times;
    color[u]=GRAY;
    for(int v=0; v<n; v++)
    {
        if(G2[u][v]==1)
        {
            if(color[v]==WHITE)
            {
                //prev[v]=u;
                DFS_visit1(v,n);
            }
        }
    }


    color[u]=BLACK;
    scc[u]=counts;
    //s.push(u);
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
            if(color[v]==WHITE)
            {
                prev[v]=u;
                DFS_visit(v,n);
            }
        }
    }
    times++;
    f[u]=times;
    color[u]=BLACK;

    //s.push(u);
}
void DFS1(int n)
{
    for(int i=0; i<n; i++)
    {
        color[i]=WHITE;
        prev[i]=-1;

    }

    for(int u=0; u<n; u++)
    {
        if(color[u]==WHITE)
            counts++;
        DFS_visit1(u,n);
    }
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
            G2[i][j]=0;
        }
    }

    for(int i=0; i<e; i++)
    {
        printf("Enter edges:");
        scanf("%d %d",&u,&v);
        G[u][v]=1;
        G2[v][u]=1;
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
    DFS1(n);
    while(counts--)
    {
        for(int i=0; i<n; i++)
        {
            if(scc[i]==counts)
            {
                cout << i << " ";
            }
        }
    }

    //while(!s.empty())
    //{
    //cout<<s.top() << " ";
    //s.pop();
//}
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
