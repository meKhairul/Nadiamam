#include <stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

int G[100][100];
int color[100], d[100], f[100], prev[100];
int time=0;
int treeEdge[100][2], backEdge[100][2], forwardEdge[100][2], crossEdge[100][2];
int te, be, fe, ce;

void print_path(int s, int v) {
    if(s==v) {
        printf("%d->",s);
    }
    else if(prev[v]==-1) {
        printf("No Path");
    }
    else {
        print_path(s,prev[v]);
        printf("%d->",v);
    }
}

void DFS_visit(int u, int n) {
    time++;
    d[u]=time;
    color[u]=GRAY;
    for(int v=0;v<n;v++) {
        if(G[u][v]==1) {
            if(color[v]==WHITE)
            {
                treeEdge[te][0] = u;
                treeEdge[te][1] = v;
                te++;
                prev[v]=u;
                DFS_visit(v,n);
            }
            else if(color[v]==GRAY){
                backEdge[be][0] = u;
                backEdge[be][1] = v;
                be++;
            }
            else if(color[v]==BLACK){
                if(d[u]<d[v]){
                    forwardEdge[fe][0] = u;
                    forwardEdge[fe][1] = v;
                    fe++;
                }
                else if(d[u]>d[v]){
                    crossEdge[ce][0] = u;
                    crossEdge[ce][1] = v;
                    ce++;
                }
            }
        }
    }
    time++;
    f[u]=time;
    color[u]=BLACK;
}

void DFS(int n)
{
    for(int i=0;i<n;i++) {
        color[i]=WHITE;
        prev[i]=-1;
    }

    for(int u=0;u<n;u++) {
        if(color[u]==WHITE){
            //treeEdge[]
            DFS_visit(u,n);
        }
    }
}


int main() {
    int n, e, u, v;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&e);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            G[i][j]=0;
        }
    }

    for(int i=0;i<e;i++)
    {
        printf("Enter edges:");
        scanf("%d %d",&u,&v);
        G[u][v]=1;

    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%-4d",G[i][j]);
        }
        printf("\n");
    }

    DFS(n);

    for(int i=0;i<n;i++)
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
    print_path(0,5);
    return 0;
}
