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

int mx;
vector<bool> vis;
void dfs(int u, vector<vector<int>> &adj)
{
    vis[u] = 1;
    mx = max(mx, u);
    for(int v : adj[u])
        if(!vis[v])
            dfs(v, adj);
}
void cp()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vis.assign(n + 1, false);
    ll ans = 0;
    int l = 1;
    while(true)
    {
        while(l <= n && vis[l]) l++;
        if(l > n) break;
        mx = l;
        dfs(l, adj);
        while(l < mx)
        {
            if(!vis[l]) dfs(l, adj), ans++;
            l++;
        }
        if(l > n) break;
    }
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

