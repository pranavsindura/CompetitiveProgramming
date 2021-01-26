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

const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

/*
	Since each node is connected to atleast k nodes
	Any node that is a part of a cycle, will have a cycle of length at least k + 1 associated with it
	Find any node with a cycle
	Then find ONE path of length at least k + 1 that ends back to the starting node
*/

int root, k;
vector<vector<int>> adj;
vector<bool> vis, in_stack;

void check_cycle(int u)
{
    vis[u] = 1;
    in_stack[u] = 1;
    for(int v : adj[u])
        if(!vis[v])
            check_cycle(v);
        else if(in_stack[v])
            root = v;
    in_stack[u] = 0;
}

vector<int> cycle;

bool dfs(int u, int depth, int start)
{
    vis[u] = 1;
    bool found = false;

    if(depth >= k && binary_search(all(adj[u]), start))
        found = true;

    for(int v : adj[u])
        if(!vis[v] && !found)
            found |= dfs(v, depth + 1, start);

    if(found)
        cycle.pb(u);

    return found;
}

void cp()
{
    int n, m;
    cin >> n >> m >> k;
    adj.resize(n + 1);
    for(int i = 0, u, v; i < m; i++)
        cin >> u >> v, adj[u].pb(v), adj[v].pb(u);

    for(int i = 1; i <= n; i++)
        sort(all(adj[i]));

    vis.resize(n + 1), in_stack.resize(n + 1);
    fill(all(vis), false), fill(all(in_stack), false);

    check_cycle(1);

    fill(all(vis), false);

    dfs(root, 0, root);

    cout << sz(cycle) << endl;
    for(int x : cycle)
        cout << x << " ";
    cout << endl;
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