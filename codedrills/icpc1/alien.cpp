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

int ans[MAXN], best[MAXN], depth[MAXN];
vector<int> val[105];
int G[105][105];

void dfs(int u, int p, int d, vector<int> &A, vector<vector<int>> &adj)
{
    int me = -2, best = -1;
    for(int i = 1; i <= 100; i++)
        if(G[i][A[u]] == 1 && !val[i].empty())
        {
            if(depth[val[i].back()] > best)
                best = depth[val[i].back()], me = val[i].back();
        }
    ans[u] = me;
    depth[u] = d;
    val[A[u]].push_back(u);
    for(int v : adj[u])
        if(v != p)
            dfs(v, u, d + 1, A, adj);
    val[A[u]].pop_back();
}

void cp()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for(int &x : A)
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

    dfs(0, -1, 0, A, adj);

    for(int i = 0; i < n; i++)
        cout << ans[i] + 1 << " ";
    cout << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    for(int i = 1; i <= 100; i++)
        for(int j = 1; j <= 100; j++)
            G[i][j] = __gcd(i, j);
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}
