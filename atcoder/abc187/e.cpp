#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 4e5 + 5;

vector<vector<int>> adj, edges;
vector<bool> vis, sw;
vector<int> enter, ex;
int TIMER;

void dfs(int u)
{
    vis[u] = 1;
    enter[u] = TIMER++;
    for(int e : adj[u])
    {
        int v = edges[e][0] == u ? edges[e][1] : edges[e][0];
        if(vis[v]) continue;
        dfs(v);
    }
    ex[u] = TIMER++;
}

ll t[4 * MAXN], lazy[4 * MAXN];

void push(int v, int tl, int tr)
{
    int tm = (tl + tr) >> 1;
    t[v << 1] += (tm - tl + 1) * lazy[v];
    t[v << 1 | 1] += (tr - tm) * lazy[v];
    lazy[v << 1] += lazy[v];
    lazy[v << 1 | 1] += lazy[v];
    lazy[v] = 0;
}

void upd(int v, int tl, int tr, int l, int r, int val)
{
    if(l > r) return;
    if(tl == l && tr == r)
        t[v] += (tr - tl + 1) * 1LL * val, lazy[v] += val;
    else
    {
        int tm = (tl + tr) >> 1;
        push(v, tl, tr);
        upd(v << 1, tl, tm, l, min(r, tm), val);
        upd(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val);
        t[v] = t[v << 1] + t[v << 1 | 1];
    }
}

ll query(int v, int tl, int tr, int l, int r)
{
    if(l > r) return 0;
    if(tl == l && tr == r) return t[v];
    else
    {
        push(v, tl, tr);
        int tm = (tl + tr) >> 1;
        return query(v << 1, tl, tm, l, min(r, tm)) + query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
    }
}

vector<ll> val;
ll dfs2(int u)
{
    vis[u] = 1;
    val[u] = query(1, 0, TIMER - 1, enter[u], ex[u]);
    ll sub = val[u];
    for(int e : adj[u])
    {
        int v = edges[e][1];
        if(vis[v]) continue;
        ll dv = dfs2(v);
        val[u] -= dv;
    }
    return sub;
}

void cp()
{
    int n;
    cin >> n;
    adj.resize(n);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(i);
        adj[v].pb(i);
        edges.pb({u, v});
    }

    vis.assign(n, false);
    sw.assign(n, false);
    enter.assign(n, 0);
    ex.assign(n, 0);

    TIMER = 0;
    dfs(0);

    for(int i = 0; i < n - 1; i++)
        if(enter[edges[i][0]] > enter[edges[i][1]])
            swap(edges[i][0], edges[i][1]), sw[i] = 1;

    int q;
    cin >> q;
    while(q--)
    {
        int t, e, x;
        cin >> t >> e >> x;
        t--;
        e--;
        if(sw[e]) t ^= 1;
        if(t == 0)
        {
            int u = edges[e][0], v = edges[e][1];
            upd(1, 0, TIMER - 1, 0, TIMER - 1, x);
            upd(1, 0, TIMER - 1, enter[v], ex[v], -x);

        }
        else
        {
            int u = edges[e][0], v = edges[e][1];
            upd(1, 0, TIMER - 1, enter[v], ex[v], x);
        }
    }

    vis.assign(n, false);
    val.assign(n, 0);
    dfs2(0);

    for(int i = 0; i < n; i++)
        cout << val[i] / 2 << endl;
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

