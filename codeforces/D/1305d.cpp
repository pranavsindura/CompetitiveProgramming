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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

int query(int u, int v)
{
    cout << "? " << u + 1 << " " << v + 1 << endl;
    cout.flush();
    int x;
    cin >> x;
    if(x == -1) exit(0);
    return x - 1;
}

vector<int> get_dia(map<int, set<int>> &adj)
{
    map<int, int> path;
    int mxd = -1, last = -1;
    queue<vector<int>> q;
    q.push({adj.begin()->ff, 0, -1});
    while(!q.empty())
    {
        vector<int> nd = q.front();
        q.pop();
        int u = nd[0], d = nd[1], par = nd[2];
        if(d > mxd) mxd = d, last = u;
        path[u] = par;
        for(int v : adj[u])
            if(v != par)
                q.push({v, d + 1, u});
    }

    path.clear();
    q.push({last, 0, -1});
    mxd = -1, last = -1;
    while(!q.empty())
    {
        vector<int> nd = q.front();
        q.pop();
        int u = nd[0], d = nd[1], par = nd[2];
        if(d > mxd) mxd = d, last = u;
        path[u] = par;
        for(int v : adj[u])
            if(v != par)
                q.push({v, d + 1, u});
    }
    vector<int> route;
    while(~last) route.push_back(last), last = path[last];
    return route;
}

void cp()
{
    int n;
    cin >> n;
    map<int, set<int>> adj;
    for(int i = 0, u, v; i < n - 1; i++)
        cin >> u >> v, u--, v--, adj[u].insert(v), adj[v].insert(u);
    while(n > 3)
    {
        vector<int> dia = get_dia(adj);
        int lca = query(dia.front(), dia.back());
        map<int, bool> vis;
        for(int x : dia)
            vis[x] = x != lca;
        queue<pi> q;
        q.push({lca, lca});
        map<int, set<int>> nadj;
        nadj[lca];
        while(!q.empty())
        {
            pi nd = q.front();
            q.pop();
            int u = nd.first, par = nd.second;
            vis[u] = 1;
            for(int v : adj[u])
                if(!vis[v])
                    nadj[u].insert(v), nadj[v].insert(u), q.push({v, u}), vis[v] = 1;
        }
        adj = nadj;
        n  = sz(adj);
    }
    vector<int> dia = get_dia(adj);
    int lca = query(dia.front(), dia.back());
    cout << "! " << lca + 1 << endl;
    cout.flush();
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
