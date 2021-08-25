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

int n, k;
vector<vector<int>> adj;

int dfs(int u, int p, int d, int lim)
{
    if(d > lim) return 0;
    int sub = 1;
    for(int v : adj[u])
        if(v != p)
            sub += dfs(v, u, d + 1, lim);
    return sub;
}

void cp()
{
    cin >> n >> k;
    adj.resize(n);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = inf;

    for(int i = 0; i < n; i++)
    {
        vector<int> up, down;
        for(int v : adj[i])
            down.push_back(dfs(v, i, 1, k / 2));
        for(int v : adj[i])
            up.push_back(dfs(v, i, 1, (k + 1) / 2));

        int down_sum = accumulate(all(down), 0);

        for(int j = 0; j < sz(adj[i]); j++)
            ans = min(ans, n - (down_sum - down[j] + up[j] + 1));
    }

    cout << ans << endl;
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
