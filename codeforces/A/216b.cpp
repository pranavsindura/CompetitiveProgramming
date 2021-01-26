#include <bits/stdc++.h>
#define ll long long int
#define FASTIO                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
using namespace std;
int count;
void dfs(int v, int p, vector<int> adj[], vector<int> &c)
{
    c[v] = c[p] % 2 + 1;
    for (int i = 0; i < adj[v].size(); i++)
    {
        int child = adj[v][i];
        if (!c[child])
        {
            c[child] = c[v] % 2 + 1;
            dfs(child, v, adj, c);
        }
        else if (c[child] == c[v])
        {
            ::count++;
            c[child] = -1;
        }
    }
}
int main()
{
    FASTIO;
    int n, m, a, b;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!c[i])
            dfs(i, 0, adj, c);
    }
    if ((n - ::count) & 1)
        ::count++;
    cout << ::count;
    return 0;
}