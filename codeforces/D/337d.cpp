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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

/*
Find order by Rooting the tree
We have some sus nodes
Reinterpret the problem as, find the nodes whose maximum distance to a sus node is <= d
Since we rooted the tree, we can reduce the problem into 2 parts, Subtree and not subtree
for each node v, we can find the deepest sus node in its subtree using the children
and find the farthest sus node not in subtree, using the parent
The answer will then be the count of nodes whose farthest node and deepest node are at distance <= d

down[u] = max down[v] + 1
up[u] = max up[par] + 1, max down[sibling] + 2
For max down[sibling] we can store max and second max because max except me will be either of the two
*/
bool sus[MAXN];
vector<vector<int>> adj;

int down[MAXN], up[MAXN], max_child_down[MAXN], max2_child_down[MAXN];

void dfs_down(int u, int par)
{
    for(int v : adj[u])
        if(par != v)
            dfs_down(v, u), down[u] = max(down[u], down[v] + 1);

    if(sus[u])
        down[u] = max(down[u], 0);

    int was = -1, best = -1e7;
    for(int v : adj[u])
        if(par != v)
            if(down[v] > best)
                best = down[v], was = v;
    max_child_down[u] = was;

    was = -1, best = -1e7;
    for(int v : adj[u])
        if(par != v)
            if(v != max_child_down[u])
                if(down[v] > best)
                    best = down[v], was = v;
    max2_child_down[u] = was;
}

void dfs_up(int u, int par)
{
    up[u] = max(up[u], up[par] + 1);

    if(sus[u])
        up[u] = max(up[u], 0);

    if(max_child_down[par] != u && ~max_child_down[par])
        up[u] = max(up[u], down[max_child_down[par]] + 2);
    else if(~max2_child_down[par])
        up[u] = max(up[u], down[max2_child_down[par]] + 2);

    for(int v : adj[u])
        if(par != v)
            dfs_up(v, u);
}

void cp()
{
    int n, m, d;
    cin >> n >> m >> d;

    for(int i = 0, x; i < m; i++)
        cin >> x, sus[x] = 1;

    adj.resize(n + 1);
    for(int i = 0, u, v; i < n - 1; i++)
        cin >> u >> v, adj[u].pb(v), adj[v].pb(u);

    int root = -1;
    for(int i = 1; i <= n; i++)
        if(sz(adj[i]) <= 1)
            root = i;

    fill(down, down + n + 1, -1e7);
    fill(up, up + n + 1, -1e7);
    fill(max_child_down, max_child_down + n + 1, -1);
    fill(max2_child_down, max2_child_down + n + 1, -1);
    
    dfs_down(root, 0);
    dfs_up(root, 0);

    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans += (down[i] <= d && up[i] <= d);
    cout << ans << endl;
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