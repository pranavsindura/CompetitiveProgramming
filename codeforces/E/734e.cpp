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
vector<vector<int>> adj;

pi dfs(int u, int p)
{
    vector<vector<int>> best(2);
    int longest = 1, ans = 1;
    for(int v : adj[u])
        if(v != p)
        {
            pi child = dfs(v, u);

            ans = max(ans, child.ss);
            longest = max(longest, child.ff + (color[v] != color[u]));

            best[color[v]].push_back(child.ff);
            sort(allr(best[color[v]]));
            if(sz(best[color[v]]) > 2)
                best[color[v]].pop_back();
        }

    ans = max(ans, longest);
    if(sz(best[0]) > 1)
        ans = max(ans, best[0][0] + best[0][1] + (color[u] != 0 ? 1 : -1));
    if(sz(best[1]) > 1)
        ans = max(ans, best[1][0] + best[1][1] + (color[u] != 1 ? 1 : -1));
    if(!best[0].empty() && !best[1].empty())
        ans = max(ans, best[0][0] + best[1][0]);

    return {longest, ans};
}

void cp()
{
    int n;
    cin >> n;
    color.resize(n), adj.resize(n);
    for(int &x : color)
        cin >> x;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int root = -1;
    for(int i = 0; i < n; i++)
        if(sz(adj[i]) <= 1)
            root = i;
    int ans = dfs(root, -1).ss;
    cout << ans / 2 << endl;
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
