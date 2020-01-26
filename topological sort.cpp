#include<bits/stdc++.h>
using namespace std;
int G[100][100],indegree[100];
int main()
{
    int n,e,i,u,v,j;
    stack <int> st;
    cout << " Enter Number of Node and Edges : ";
    cin>>n>>e;
    G[100][100]={0};
    for(i=0;i<e;i++)
    {
        cout << " Enter Edges : ";
        cin>>u>>v;
        G[u][v]=1;
        indegree[v]++;
    }
    for(i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            st.push(i);
            for(j=0;j<n;j++)
            {
                if(G[i][j]==1)
                {
                    indegree[j]--;
                }
            }

        }
    }
    while(!st.empty())
    {
        cout << st.top() << "\t";
        st.pop();
    }
}
