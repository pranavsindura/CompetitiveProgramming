#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 2e3 + 5;

struct edge
{
    int u, v, cost;
    edge() {}
    edge(int u, int v, int cost): u(u), v(v), cost(cost) {}
    const bool operator<(const edge &e) const
    {
        return cost < e.cost;
    }
};

vector<edge> edges;
ll mat[MAXN][MAXN];
ll res[MAXN][MAXN];

int parent[MAXN];
void make_set()
{
    iota(parent, parent + MAXN, 0);
}

int find_set(int v)
{
    if(v == parent[v])
        return v;
    else
        return parent[v] = find_set(parent[v]);
}

bool union_set(int a, int b)
{
    a = find_set(a), b = find_set(b);
    if(a != b)
        parent[b] = a;
    return a != b;
}

void dfs(int start, int u, ll sofar, vector<vector<pi>> &adj, vector<bool> &vis)
{
    vis[u] = true;
    res[start][u] = sofar;
    for(pi v : adj[u])
        if(!vis[v.ff])
            dfs(start, v.ff, sofar + v.ss, adj, vis);
}

void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int w;
            cin >> w;
            edges.pb(edge(i, j, w));
            mat[i][j] = w;
        }
    }
    make_set();
    vector<edge> mst;
    sort(all(edges));
    for(edge e : edges)
    {
        if(union_set(e.u, e.v))
            mst.pb(e);
    }

    vector<vector<pi>> adj(n);
    for(edge e : mst)
        adj[e.u].pb({e.v, e.cost}), adj[e.v].pb({e.u, e.cost});

    vector<bool> vis(n);
    for(int i = 0; i < n; i++)
    {
        fill(all(vis), false);
        dfs(i, i, 0, adj, vis);
    }

    bool ok = true;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(res[i][j] != mat[i][j] || (i != j && (res[i][j] == 0 || mat[i][j] == 0)))
                ok = false;
    cout << (ok ? "YES" : "NO");
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