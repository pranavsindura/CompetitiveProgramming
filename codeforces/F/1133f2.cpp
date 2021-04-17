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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 2e5 + 5;

int vis[MAXN];
void dfs(int u, int comp, vector<vector<int>> &adj)
{
    vis[u] = comp;
    for(int v : adj[u])
        if(!vis[v]) dfs(v, comp, adj);
}

// DSU by Size
int parent[MAXN], sz[MAXN];
void make_set(int n)
{
    iota(parent, parent + n, 0);
    fill(sz, sz + n, 1);
}
int find_set(int v)
{
    if(v == parent[v])
        return v;
    else
        return parent[v] = find_set(parent[v]);
}
bool is_connected(int a, int b)
{
    return find_set(a) == find_set(b);
}
bool union_set(int a, int b)
{
    a = find_set(a), b = find_set(b);
    if(sz[a] < sz[b])
        swap(a, b);
    if(a != b)
        parent[b] = a, sz[a] += sz[b];
    return a != b;
}

void cp()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<vector<int>> adj(n);
    vector<vector<int>> edges(m);
    for(int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {u, v};
    }

    vis[0] = -1;
    int comp = 0;
    for(int v : adj[0])
        if(!vis[v]) ++comp, dfs(v, comp, adj);

    if(d < comp || d > sz(adj[0]))
    {
        cout << "NO\n";
        return;
    }

    make_set(n);
    vector<vector<int>> spanning;

    comp = 1;
    int cnt = 0;
    for(int u : adj[0])
        if(vis[u] == comp)
            comp++, vis[u] = 0, union_set(0, u), spanning.push_back({0, u});
    comp--;
    for(int u : adj[0])
        if(cnt < d - comp && vis[u])
            vis[u] = 0, cnt++, union_set(0, u), spanning.push_back({0, u});

    assert(cnt + comp == d);

    for(auto e : edges)
    {
        int u = e[0], v = e[1];
        if(u > v) swap(u, v);

        if(u == 0 && vis[v])
            continue;

        if(union_set(u, v))
            spanning.push_back({u, v});
    }
    assert(sz(spanning) == n - 1);
    cout << "YES\n";
    for(auto e : spanning)
        cout << e[0] + 1 << " " << e[1] + 1 << endl;
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
