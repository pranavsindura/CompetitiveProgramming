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
const int MAXN = 1e5 + 5;
vector<vector<int>> adj(MAXN);
bool is_leaf[MAXN];
int odd, even;

void dfs(int u, int par, int depth)
{
    bool leaf = true;
    for(int v : adj[u])
        if(v != par)
            dfs(v, u, depth + 1), leaf = false;
    if(leaf)
    {
        is_leaf[u] = true;
        if(depth & 1)
            odd++;
        else
            even++;
    }
}

void cp()
{
    int n, root;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }

    for(int i = 1; i <= n; i++)
        if(sz(adj[i]) == 1)
            root = i;

    int minf = 3, maxf = n - 1;
    
    dfs(root, 0, 0);
    if(even && !odd)
        minf = 1;

    is_leaf[root] = 1;
    for(int i = 1; i <= n; i++)
    {
        int leaf = 0;
        for(int v : adj[i])
            if(is_leaf[v])
                leaf++;
        if(leaf)
            maxf -= (leaf - 1);
    }
    cout << minf << " " << maxf;
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