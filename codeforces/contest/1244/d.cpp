#include<bits/stdc++.h>
using namespace std;

void dfs(vector<pair<int,int>> adj[], int c1[], int c2[], int c3[], bool vis[], int v, int parent)
{
    
}

int main()
{
    int n, a, b;
    cin>>n;
    int c1[n+1], c2[n+1], c3[n+1];
    for(int i=1;i<=n;i++)
        cin>>c1[i];
    for(int i=1;i<=n;i++)
        cin>>c2[i];
    for(int i=1;i<=n;i++)
        cin>>c3[i];
    vector<pair<int,int>> adj[n+1];
    bool bt = true;
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        adj[a].push_back(make_pair(b,INT_MIN));
        adj[b].push_back(make_pair(a,INT_MIN));
        if(adj[a].size() > 2 || adj[b].size() > 2)
            bt = false;
    }
    if(!bt)
    {
        cout<<-1;
        return 0;
    }

    bool vis[n+1];
    memset(vis, false, sizeof(vis));
    dfs(adj, c1, c2, c3, vis, 1, 0);
    return 0;
}