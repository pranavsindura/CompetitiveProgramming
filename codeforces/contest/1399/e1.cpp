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

struct edge
{
    int u, v, freq;
    ll w;
    edge(): u(0), v(0), w(0), freq(0) {}
    edge(int u, int v, ll w): u(u), v(v), w(w) {}
};

struct cmp
{
    bool operator()(edge &a, edge &b)
    {
        ll reduced_a = a.w * a.freq - (a.w / 2) * a.freq;
        ll reduced_b = b.w * b.freq - (b.w / 2) * b.freq;
        return reduced_a < reduced_b;
    }
};

int dfs(int u, int par, vector<vector<int>> &adj, vector<edge> &edges)
{
    bool any = false;
    int total = 0;

    for(int x : adj[u])
    {
        int v = (edges[x].u == u ? edges[x].v : edges[x].u);
        if(v != par)
        {
            int leaf = dfs(v, u, adj, edges);
            edges[x].freq = leaf, total += leaf, any = true;
        }
    }

    return any ? total : 1;
}

void cp()
{
    int n;
    ll s;
    cin >> n >> s;
    vector<edge> edges;
    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back(edge(u, v, w));
        adj[u].pb(i), adj[v].pb(i);
    }

    dfs(1, 0, adj, edges);

    int op = 0;
    ll total = 0;

    priority_queue<edge, vector<edge>, cmp> pq;
    for(edge e : edges)
        pq.push(e), total += e.w * e.freq;

    while(total > s)
    {
        edge big = pq.top();
        pq.pop();
        total -= (big.w * big.freq - (big.w / 2) * big.freq);
        big.w /= 2;
        pq.push(big);
        op++;
    }
    
    cout << op << endl;
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