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

int n, l;
vector<vector<vector<int>>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];

    for (auto u : adj[v])
    {
        if (u[0] != p)
            dfs(u[0], v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i)
    {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root)
{
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

vector<int> val, depth;
void dfs2(int u, int par, int d, int dp)
{
    depth[u] = dp;
    val[u] = d;
    for(auto v : adj[u])
        if(v[0] != par)
            dfs2(v[0], u, d + v[1], dp + 1);
}

void cp()
{
    int q, k;
    cin >> n >> k;
    adj.resize(n);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb({v, 0});
        adj[v].pb({u, 1});
    }
    cin >> q;

    preprocess(0);
    val.assign(n, 0);
    depth.assign(n, 0);
    dfs2(0, 0, 0, 0);

    while(q--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int x = lca(u, v);
        int A = depth[u] - depth[x] - (val[u] - val[x]);
        ll ans = A + val[v] - val[x];
        cout << ans * k << endl;
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}

