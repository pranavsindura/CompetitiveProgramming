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

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<set<int>> adj(n);

    int ans = n;
    vector<int> done(n);
    auto add = [&](int u, int v)
    {
        if(u > v) swap(u, v);
        if(!done[u]) ans--, done[u] = 1;
        adj[u].insert(v);
        adj[v].insert(u);
    };

    auto rem = [&](int u, int v)
    {
        if(u > v) swap(u, v);
        adj[u].erase(v);
        adj[v].erase(u);
        if(adj[u].empty() || *adj[u].rbegin() < u) ans++, done[u] = 0;
    };

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        add(u, v);
    }

    int q;
    cin >> q;
    while(q--)
    {
        int t, x, y;
        cin >> t;
        if(t <= 2) cin >> x >> y, x--, y--;
        if(t == 1)
            add(x, y);
        else if(t == 2)
            rem(x, y);
        else
            cout << ans << endl;
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
