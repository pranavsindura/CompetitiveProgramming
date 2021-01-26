#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

// Kosaraju's Algorithm
vector<int> comp, idx;
vector<bool> vis;
vector<vector<int>> scc;
void topsort(int u, vector<vector<int>> &adj, vector<int> &top)
{
    vis[u] = 1;
    for(int v : adj[u])
        if(!vis[v])
            topsort(v, adj, top);
    top.pb(u);
    idx[u] = sz(top) - 1;
}
void dfs(int u, vector<vector<int>> &adj)
{
    vis[u] = 1;
    scc.back().pb(u);
    comp[u] = sz(scc) - 1;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v, adj);
}
void kosaraju(int n, vector<vector<int>> &adj, vector<vector<int>> &rev_adj)
{
    comp.assign(n, -1), idx.assign(n, -1);
    vis.assign(n, false);
    scc.clear();
    vector<int> top;
    for(int i = 0; i < n; i++)
        if(!vis[i])
            topsort(i, adj, top);
    vis.assign(n, false);
    while(!top.empty())
    {
        int u = top.back();
        top.pop_back();
        if(vis[u]) continue;
        scc.pb(vector<int>());
        dfs(u, rev_adj);
    }
}

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n), rev_adj(n), dag(n);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        dag[u].pb(v);
        rev_adj[v].pb(u);
    }
    set<int> dis;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        adj[i].pb(x);
        rev_adj[x].pb(i);
        dis.insert(x);
    }
    kosaraju(n, adj, rev_adj);
    vector<int> cand(all(dis));

    idx.assign(n, -1);
    vector<int> top;
    vis.assign(n, false);
    for(int i = 0; i < n; i++)
        if(!vis[i])
            topsort(i, dag, top);

    if(sz(scc) != sz(cand))
        cout << -1 << endl;
    else
    {
        sort(all(cand), [&](int a, int b)
        {
            return idx[a] < idx[b];
        });
        cout << sz(cand) << endl;
        for(int x : cand)
            cout << x + 1 << endl;
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

