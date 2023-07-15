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

vector<bool> vis;
bool dfs(int u, int T, int L, int R, vector<vector<int>> &edges, vector<vector<int>> &adj)
{
    if(u == T) return true;
    bool ok = false;
    for(int e : adj[u])
    {
        int v = edges[e][0] == u ? edges[e][1] : edges[e][0];
        int l = edges[e][2], r = edges[e][3];
        if(l <= L && r >= R && !vis[e])
        {
            vis[e] = true;
            ok |= dfs(v, T, L, R, edges, adj);
        }
    }
    return ok;
}

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges, adj(n);
    for(int i = 0; i < m; i++)
    {
        int u, v, l, r;
        cin >> u >> v >> l >> r, u--, v--;
        edges.push_back({u, v, l, r});
        adj[u].push_back(i);
        adj[v].push_back(i);
    }

    int ans = 0;
    for(int i = 0; i < m; i++)
    {
        int L = edges[i][2];
        int R = -1;
        int lo = L, hi = 1e6;
        while(lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            vis.assign(m, false);
            if(dfs(0, n - 1, L, mid, edges, adj))
                R = mid, lo = mid + 1;
            else
                hi = mid - 1;
        }
        if(~R) ans = max(ans, R - L + 1);
    }

    if(ans) cout << ans << endl;
    else cout << "Nice work, Dima!" << endl;
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
