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

void cp()
{
    int n;
    cin >> n;
    vector<vector<int>> edges(n - 1);
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[i] = {u, v};
        adj[u].pb(i);
        adj[v].pb(i);
    }
    vector<vector<int>> edges2;
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < sz(adj[i]); j++)
            edges2.push_back({adj[i][0], adj[i][j]});
    }
    cout << n - 1 << endl;
    for(auto v : edges)
        cout << 2 << " " << v[0] + 1 << " " << v[1] + 1 << endl;
    for(auto v : edges2)
        cout << v[0] + 1 << " " << v[1] + 1 << endl;
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

