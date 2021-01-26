#include <bits/stdc++.h>
using namespace std;

void dfs(int);

vector<int> adj[10];
bool vis[10];
vector<int> topsort;
int connected()
{
    int c = 0;
    for (int i = 0; i < nodes; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            c++;
        }
    }
    return c;
}
int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    int root;
    cin >> root;
    memset(vis, false, sizeof(vis));
    int connectedcomp = connected(nodes);
    cout<<connectedcomp<<endl;
    return 0;
}

void dfs(int s) //s is basically root
{
    vis[s] = true; // set root to visited
    // cout << s << " ";                       // print root
    for (int i = 0; i < adj[s].size(); i++) // for every child of root
    {
        if (vis[adj[s][i]] == false) //if child not visited
            dfs(adj[s][i]);          //dfs(child)
    }
    topsort.push_back(s);
}
