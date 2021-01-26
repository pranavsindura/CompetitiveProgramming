#include <bits/stdc++.h>
#define ll long long int
#define FASTIO                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
using namespace std;
vector<int> topsort;
void dfs(int v, vector<int> adj[], vector<bool> &vis)
{
    vis[v] = true;
    for (int i = 0; i < adj[v].size(); i++)
    {
        int child = adj[v][i];
        if (!vis[child])
        {
            dfs(child, adj, vis);
        }
    }
    topsort.push_back(v);
}
int main()
{
    FASTIO;
    int n, m, a, b;
    cin >> n >> m;
    while (n)
    {
        vector<int> adj[n + 1];
        vector<bool> vis(n + 1, false);
        for (int i = 1; i <= m; i++)
        {
            cin >> a >> b;
            adj[b].push_back(a);
        }
        topsort.clear();
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
                dfs(i, adj, vis);
        }
        for (auto x : topsort)
        {
            cout << x << " ";
        }
        cout << endl;
        cin >> n >> m;
    }
    return 0;
}