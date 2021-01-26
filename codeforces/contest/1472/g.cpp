#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

vector<vector<int>> adj, dp;
vector<int> depth;
vector<bool> vis;

void bfs()
{
    queue<pi> q;
    q.push({0, 0});
    while(!q.empty())
    {
        pi node = q.front();
        q.pop();
        int u = node.ff, d = node.ss;
        vis[u] = 1;
        depth[u] = d;
        for(int v : adj[u])
            if(!vis[v])
                q.push({v, d + 1}), vis[v] = 1;
    }
}

int dfs(int u, int stat)
{
    int &ret = dp[u][stat];
    if(~ret) return ret;

    ret = inf;
    int ans = inf;
    // choose to stop
    ans = min(ans, depth[u]);
    for(int v : adj[u])
    {
        if(depth[u] < depth[v]) // move
            ans = min(ans, dfs(v, stat));
        else if(stat == 0) // not used try to move
            ans = min(ans, dfs(v, 1));
    }
    return ret = ans;
}

void cp()
{
    int n, m;
    cin >> n >> m;
    adj.assign(n, vector<int>());
    depth.assign(n, 0);
    vis.assign(n, false);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
    }
    vector ans(n, -1);
    dp.assign(n, vector<int>(2, -1));
    bfs();
    for(int i = 0; i < n; i++)
        dfs(i, 0);
    for(int i = 0; i < n; i++)
        cout << dp[i][0] << " ";
    cout << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}

