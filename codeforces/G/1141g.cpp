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

vector<int> color;
vector<vector<pi>> adj;

void dfs(int u, int p, int c, int d)
{
    for(auto e : adj[u])
    {
        int v = e.ff, idx = e.ss;
        if(v == p) continue;
        c = (c + 1) % d;
        color[idx] = c;
        dfs(v, u, c, d);
    }
}

void cp()
{
    int n, k;
    cin >> n >> k;
    adj.resize(n);
    vector<int> deg(n);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        deg[u]++, deg[v]++;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    sort(all(deg));
    while(k > 0) deg.pop_back(), k--;

    color.assign(n - 1, -1);

    dfs(0, -1, -1, deg.back());

    cout << deg.back() << endl;
    for(int x : color)
        cout << x + 1 << " ";
    cout << endl;
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
