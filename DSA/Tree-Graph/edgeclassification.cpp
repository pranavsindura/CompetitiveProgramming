#include <bits/stdc++.h>
using namespace std;

void dfs(int);

vector<int> adj[10];
bool vis[10];
int timer = 0;
bool any_cycle = false;
vector<int> start(10, -1), finish(10, -1);
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
    for(int i=1;i<=nodes;i++)
        dfs_edgeclassification(i);
    return 0;
}

void dfs_edgeclassification(int s)
{
    start[s] = timer++;
    for (int i = 0; i < adj[s].size(); i++)
    {
        if (start[adj[s][i]] == -1)
            dfs(adj[s][i]);
        else
        {
            if(finish[s] == -1) // this is the ancestor that called us and is waiting to finish, causes cycle,
            {
                any_cycle = true;
                //BACK EDGE
            }
            else if(start[s] < start[adj[s][i]]){}// FORWARD EDGE
            else{}                                // CROSS EDGE

        }
    }
    finish[s] = timer++;
}
