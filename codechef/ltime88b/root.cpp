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
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void topsort(int u, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &top)
{
    vis[u] = 1;
    for(int v : adj[u])
        if(!vis[v])
            topsort(v, adj, vis, top);
    top.pb(u);
}

void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[u] = 1;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v, adj, vis);
}

void cp()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0, u, v; i < n - 1; i++)
        cin >> u >> v, adj[u - 1].pb(v - 1);

    vector<bool> vis(n);
    vector<int> top;
    for(int i = 0; i < n; i++)
        if(!vis[i])
            topsort(i, adj, vis, top);
        
    reverse(all(top));
    fill(all(vis), false);
    int cnt = 0;
    for(int i = 0; i < n; i++)
        if(!vis[top[i]])
            dfs(top[i], adj, vis), cnt++;
    cout << cnt - 1 << endl;
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