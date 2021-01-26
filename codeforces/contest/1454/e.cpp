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
const int MAXN = 2e5 + 5;

int at;
int vis[MAXN], instack[MAXN], cycle[MAXN];
// Find cyclic node
void dfs(int u, int par, vector<vector<int>> &adj)
{
    vis[u] = 1;
    instack[u] = 1;
    for(int v : adj[u])
        if(v != par)
        {
            if(!vis[v])
                dfs(v, u, adj);
            else if(instack[v])
            {
                if(at == -1)
                    at = v;
            }
        }
    instack[u] = 0;
}
// Mark the cycle
bool dfs2(int u, int par, vector<vector<int>> &adj)
{
    bool child = false;
    for(int v : adj[u])
    {
        if(v != par)
        {
            if(v == at)
                child = 1;
            else
                child |= dfs2(v, u, adj);
        }
    }
    if(child) cycle[u] = 1;
    return child;
}
// Subtree size
int dfs3(int u, int par, vector<vector<int>> &adj)
{
    int child = 0;
    for(int v : adj[u])
        if(v != par && !cycle[v])
            child += dfs3(v, u, adj);
    return 1 + child;
}

void cp()
{
    int n;
    cin >> n;
    fill(vis, vis + n, 0);
    fill(cycle, cycle + n, 0);
    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }

    at = -1;
    dfs(0, -1, adj);
    dfs2(at, -1, adj);

    // Let all pairs go through the cycle edge
    ll ans = n * 1LL * (n - 1);

    for(int i = 0; i < n; i++)
    {
    	// All pairs that are from the subtree of cycle node cannot go through the cycle edge as
    	// that will not be the simple path (repeated nodes)
    	// remove them
        if(cycle[i])
        {
            ll subtree = dfs3(i, -1, adj);
            ans -= subtree * (subtree - 1) / 2;
        }
    }
    cout << ans << endl;
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