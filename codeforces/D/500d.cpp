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

struct edge
{
    int u, v, wt;
    ll freq;
    edge(): u(0), v(0), wt(0), freq(0) {}
    edge(int u, int v, int wt): u(u), v(v), wt(wt), freq(0) {}
};

int n;
vector<edge> edges;
vector<vector<int>> adj;

int dfs(int u, int par)
{
    int subtree = 0;
    for(int e : adj[u])
    {
        int v = (edges[e].u == u ? edges[e].v : edges[e].u);
        if(v != par)
        {
            int child = dfs(v, u);
            int other = n - child;
            edges[e].freq = child * 1LL * other;
            subtree += child;
        }
    }
    return subtree + 1;
}

void cp()
{
    cin >> n;
    adj.resize(n + 1);
    for(int i = 0, u, v, l; i < n - 1; i++)
    {
        cin >> u >> v >> l;
        adj[u].pb(sz(edges));
        adj[v].pb(sz(edges));
        edges.pb(edge(u, v, l));
    }

    dfs(1, 0);
    
    double total = n * 1.0 * (n - 1) / 2.0;
    double ans = 0;
    for(int i = 0; i < n - 1; i++)
    {
        ans += edges[i].wt * double(edges[i].freq) / total;
    }

    dblout(10);
    int q;
    cin >> q;
    while(q--)
    {
        int idx, nwt;
        cin >> idx >> nwt;
        idx--;
        ans -= edges[idx].wt * double(edges[idx].freq) / total;
        edges[idx].wt = nwt;
        ans += edges[idx].wt * double(edges[idx].freq) / total;
        cout << 3.0 * ans << endl;
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