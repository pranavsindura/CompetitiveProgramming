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
const int MAXN = 1e5 + 5;

vector<vector<int>> adj;
vector<int> depth;

void dfs(int u, int par, int d)
{
    depth[u] = d;
    for(int v : adj[u])
        if(v != par)
            dfs(v, u, d + 1);
}

void cp()
{
    int n;
    cin >> n;
    adj.resize(n + 1), depth.assign(n + 1, 0);
    for(int i = 0, u, v; i < n - 1; i++)
        cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);

    dfs(1, 1, 1);

    double ans = 0;
    for(int i = 1; i <= n; i++) ans += 1.0 / double(depth[i]);

    fix(20);
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
