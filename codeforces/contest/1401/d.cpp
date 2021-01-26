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

int n, m;
int dfs(int u, int par_idx, vector<vector<int>> &adj, vector<bool> &vis, vector<pi> &edges, vector<ll> &freq)
{
    vis[u] = true;
    int subtree = 0;
    for(int e : adj[u])
    {
        int v = (u == edges[e].ff ? edges[e].ss : edges[e].ff);
        if(!vis[v])
            subtree += dfs(v, e, adj, vis, edges, freq);
    }
    ll below = subtree + 1;
    ll above = n - below;
    ll total = above * below;
    freq[par_idx] = total;

    return subtree + 1;
}

void cp()
{
    cin >> n;
    vector<pi> edges;
    edges.pb({0, 0});
    vector<vector<int>> adj(n + 1);
    int root = -1;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(i + 1);
        adj[v].pb(i + 1);
        edges.pb({u, v});
    }
    cin >> m;
    vector<ll> arr(m);
    for(ll &x : arr)
        cin >> x;

    sort(allr(arr));

    for(int i = 1; i <= n; i++)
        if(sz(adj[i]) <= 1)
            root = i;

    vector<bool> vis(n + 1);
    vector<ll> freq(n + 1);
    dfs(root, 0, adj, vis, edges, freq);

    vector<int> order;
    for(int i = 1; i <= n - 1; i++)
        order.pb(i);
    sort(all(order), [&](int a, int b)
    {
        return freq[a] > freq[b];
    });

    ll ans = 0;

    if(sz(order) >= sz(arr))
    {
        for(int i = 0; i < sz(order); i++)
        {
            ll val;
            if(i < sz(arr))
                val = (freq[order[i]] % mod * arr[i] % mod) % mod;
            else
                val = freq[order[i]] % mod;
            ans = (ans % mod + val % mod) % mod;
        }
    }
    else
    {
        int off = sz(arr) - sz(order);
        ll extra = 1;
        for(int i = 0; i < off; i++)
            extra = (extra % mod * arr[i] % mod) % mod;

        for(int i = 0; i < sz(order); i++)
        {
            ll val = (freq[order[i]] % mod * arr[i + off] % mod) % mod;
            val = (val % mod * extra % mod) % mod;
            extra = 1;
            ans = (ans % mod + val % mod) % mod;
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