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
    int u, v, times, c;
    ll w;
    edge(): u(0), v(0), w(0), times(0), c(0) {}
    edge(int u, int v, ll w, int c): u(u), v(v), w(w), c(c) {}
};

struct cmp
{
    bool operator()(edge &a, edge &b)
    {
        ll reda = a.w * a.times - (a.w / 2) * a.times;
        ll redb = b.w * b.times - (b.w / 2) * b.times;
        return reda < redb;
    }
};

int dfs(int u, int par, vector<vector<int>> &adj, vector<edge> &edges)
{
    bool any = false;
    int total = 0;
    for(int x : adj[u])
    {
        int v;
        if(edges[x].u == u)
            v = edges[x].v;
        else
            v = edges[x].u;
        if(v != par)
        {
            int leaf = dfs(v, u, adj, edges);
            edges[x].times = leaf;
            total += leaf;
            any = true;
        }
    }

    if(!any)
        return 1;
    else
        return total;
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
        int u, v, c;
        ll w;
        cin >> u >> v >> w >> c;
        edges.push_back(edge(u, v, w, c));
        adj[u].pb(i);
        adj[v].pb(i);
    }
    dfs(1, 0, adj, edges);
    priority_queue<edge, vector<edge>, cmp> pq;
    for(edge e : edges)
        if(e.c == 1)
            pq.push(e);
    vector<ll> op1, op2;
    while(!pq.empty())
    {
        edge big = pq.top();
        pq.pop();
        ll red = big.w * big.times - (big.w / 2) * big.times;
        op1.pb(red);
        big.w /= 2;
        if(big.w)
            pq.push(big);
    }
    for(edge e : edges)
        if(e.c == 2)
            pq.push(e);
    while(!pq.empty())
    {
        edge big = pq.top();
        pq.pop();
        ll red = big.w * big.times - (big.w / 2) * big.times;
        op2.pb(red);
        big.w /= 2;
        if(big.w)
            pq.push(big);
    }
    ll total = 0;
    for(edge e : edges)
        total += e.w * e.times;

    for(int i = 1; i < sz(op1); i++)
        op1[i] += op1[i - 1];
    for(int i = 1; i < sz(op2); i++)
        op2[i] += op2[i - 1];

    int op = INT_MAX;
    if(total <= s)
        op = 0;
    // only 1s
    int lo = 0, hi = sz(op1) - 1;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(total - op1[mid] <= s)
            op = min(op, mid + 1), hi = mid - 1;
        else
            lo = mid + 1;
    }
    // only 2s
    lo = 0, hi = sz(op2) - 1;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(total - op2[mid] <= s)
            op = min(op, (mid + 1) * 2), hi = mid - 1;
        else
            lo = mid + 1;
    }

    for(int i = 0; i < sz(op1); i++)
    {
        lo = 0, hi = sz(op2) - 1;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(total - (op1[i] + op2[mid]) <= s)
                op = min(op, i + 1 + (mid + 1) * 2), hi = mid - 1;
            else
                lo = mid + 1;
        }
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