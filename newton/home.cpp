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
const ll inf = 1e16;
const int MAXN = 3e3 + 5;

ll dist[MAXN][MAXN];

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pi>> adj(n);
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j <= n; j++)
            dist[i][j] = inf;

    dist[0][0] = 0;

    for(int steps = 0; steps < n; steps++)
        for(int u = 0; u < n; u++)
            for(auto e : adj[u])
            {
                int v = e.ff, w = e.ss;
                dist[v][steps + 1] = min(dist[v][steps + 1], dist[u][steps] + w * (steps + 1LL));
            }

    for(int i = 0; i < n; i++)
    {
        ll best = *min_element(dist[i], dist[i] + n + 1);
        if(best == inf) cout << -1 << endl;
        else cout << best << endl;
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
