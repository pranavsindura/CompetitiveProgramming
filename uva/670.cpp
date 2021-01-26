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
const double eps = 1e-7;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

double dist(pi a, pi b)
{
    return sqrt((a.ff - b.ff) * 1.0 * (a.ff - b.ff) + (a.ss - b.ss) * 1.0 * (a.ss - b.ss));
}

vector<int> mt;
vector<bool> vis;

bool kuhn(int u, vector<vector<int>> &adj)
{
    if(vis[u]) return false;
    vis[u] = true;
    for(int v : adj[u])
    {
        if(mt[v] == -1 || kuhn(mt[v], adj))
        {
            mt[v] = u;
            return true;
        }
    }
    return false;
}

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<pi> bob(n), ralph(m);
    for(auto &x : bob)
        cin >> x.ff >> x.ss;
    for(auto &x : ralph)
        cin >> x.ff >> x.ss;

    vector<vector<int>> adj(m);
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < m; j++)
        {
            double L = dist(bob[i], ralph[j]) + dist(ralph[j], bob[i + 1]);
            double R = 2 * dist(bob[i], bob[i + 1]);
            if(L < R || fabs(R - L) < eps)
                adj[j].pb(i);
        }
    }

    mt.assign(n, -1);
    for(int i = 0; i < m; i++)
        vis.assign(m, false), kuhn(i, adj);

    vector<pi> path;
    for(int i = 0; i < n - 1; i++)
    {
        path.pb(bob[i]);
        if(mt[i] != -1)
            path.pb(ralph[mt[i]]);
    }
    path.pb(bob.back());

    cout << sz(path) << endl;
    for(int i = 0; i < sz(path); i++)
    {
        if(i)
            cout << " ";
        cout << path[i].ff << " " << path[i].ss;
    }
    cout << endl;
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
        if(t)
            cout << endl;
    }
    return 0;
}

