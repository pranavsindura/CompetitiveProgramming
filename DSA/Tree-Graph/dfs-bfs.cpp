#include <bits/stdc++.h>
using namespace std;

void bfs(int);
void bfs2(int);
void dfs(int);

vector<int> adj[10];
bool vis[10];
queue<int> q;
int level[10];

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
    // bfs(root);
    bfs2(root);
    // dfs(root);
    return 0;
}

void dfs(int s) //s is basically root
{
    vis[s] = true;                          // set root to visited
    cout << s << " ";                       // print root
    for (int i = 0; i < adj[s].size(); i++) // for every child of root
    {
        if (vis[adj[s][i]] == false) //if child not visited
            dfs(adj[s][i]);          //dfs(child)
    }
}
void bfs2(int s)
{
    q.push(s);
    vis[s] = true;
    while (q.size())
    {
        int n = q.front();
        q.pop();
        cout << n << " ";
        for (int i = 0; i < adj[n].size(); i++)
        {
            if (!vis[adj[n][i]])
            {
                q.push(adj[n][i]);
                vis[adj[n][i]] = true;
            }
        }
    }
}
void bfs(int s)
{
    q.push(s);
    level[s] = 0;
    vis[s] = true;
    cout << s << " ";

    while (!q.empty())
    {
        int p = q.front();
        cout << p << " ";
        q.pop();

        for (int i = 0; i < adj[p].size(); i++)
        {
            if (vis[adj[p][i]] == false)
            {
                level[adj[p][i]] = level[p] + 1;
                q.push(adj[p][i]);
                vis[adj[p][i]] == true;
            }
        }
    }
    // cout<<level[5];
}