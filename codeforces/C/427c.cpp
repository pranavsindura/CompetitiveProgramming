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

int junc_cost[MAXN];
vector<vector<int>> adj(MAXN), rev_adj(MAXN);
vector<int> topsort;
bool vis[MAXN];
void topological_order(int u)
{
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v])
            topological_order(v);
    topsort.pb(u);
}

void dfs(int u, map<int, int> &m)
{
    vis[u] = true;
    m[junc_cost[u]]++;
    for(int v : rev_adj[u])
        if(!vis[v])
            dfs(v, m);
}

void cp()
{
    int n, m;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> junc_cost[i];
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        rev_adj[v].pb(u);
    }
    // Find topological Order
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            topological_order(i);
    reverse(all(topsort));

    clr(vis, false);

    ll total = 0, ways = 1;
    for(int u : topsort)
    {
        // Find SCC
        if(!vis[u])
        {
            map<int, int> cnt;
            dfs(u, cnt);
            pi x = *cnt.begin();
            total += x.ff;
            ways = (ways % mod * x.ss % mod) % mod;
        }
    }
    cout << total << " " << ways;
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