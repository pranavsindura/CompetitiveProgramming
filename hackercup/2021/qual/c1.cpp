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

vector<int> C;
vector<ll> subtree;

ll dfs(int u, int p, vector<vector<int>> &adj)
{
    for(int v : adj[u])
        if(v != p)
            subtree[u] = max(subtree[u], dfs(v, u, adj));
    subtree[u] += C[u];
    return subtree[u];
}

void cp()
{
    int n;
    cin >> n;
    C.resize(n);
    for(int &x : C)
        cin >> x;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    subtree.assign(n, 0LL);
    dfs(0, -1, adj);

    ll ans = C[0];
    vector<ll> child;
    for(int v : adj[0])
        child.push_back(subtree[v]);
    sort(allr(child));

    if(sz(child) >= 2) ans += child[0] + child[1];
    else if(sz(child) >= 1) ans += child[0];

    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        cp();
    }
    return 0;
}
