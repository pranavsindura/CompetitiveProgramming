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

int ans;
int dfs(int u, int par, vector<vector<int>> &adj)
{
    int me = 1;
    for(int v : adj[u])
        if(v != par)
        {
            int child = dfs(v, u, adj);
            if(child % 2 == 0)
                ans++;
            else
                me += child;
        }
    return me;
}

void cp()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n), edges;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int root = -1;
    for(int i = 0; i < n; i++)
        if(sz(adj[i]) <= 1)
            root = i;
    dfs(root, root, adj);
    if(n & 1)
        cout << -1 << endl;
    else
    {
        cout << ans << endl;
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

