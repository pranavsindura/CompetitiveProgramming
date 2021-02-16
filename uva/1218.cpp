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
const int MAXN = 1e4 + 5;

int n;
vector<vector<int>> adj;
int dp[MAXN][3][3];

int dfs(int u, int par, int p, int m)
{
    int &ret = dp[u][p][m];
    if(~ret) return ret;

    ret = inf;
    bool leaf = true;
    for(int v : adj[u]) if(v != par) leaf = false;

    if(p == 0 && m == 0)
    {
        vector<int> zero, one, pref;
        for(int v : adj[u]) if(v != par)
                zero.push_back(dfs(v, u, m, 0));
        for(int v : adj[u]) if(v != par)
                one.push_back(1 + dfs(v, u, m, 1));

        int total = accumulate(all(zero), 0);
        for(int i = 0; i < sz(one); i++)
            ret = min(ret, total - zero[i] + one[i]);
    }
    else if(p == 0 && m == 1)
    {
        int total = 0;
        for(int v : adj[u]) if(v != par)
                total += min(dfs(v, u, m, 0), 1 + dfs(v, u, m, 1));
        ret = total;
    }
    else if(p == 1 && m == 0)
    {
        int total = 0;
        for(int v : adj[u]) if(v != par)
                total += dfs(v, u, m, 0);
        ret = total;
    }
    else
    {
        int total = 0;
        for(int v : adj[u]) if(v != par)
                total += min(dfs(v, u, m, 0), 1 + dfs(v, u, m, 1));
        ret = total;
    }

    if(leaf && p + m == 0) ret = inf;

    return ret;
}

void cp()
{
    while(true)
    {
        cin >> n;
        adj.assign(n, vector<int>());
        for(int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >>  u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int S = -1;
        for(int i = 0; i < n; i++) if(sz(adj[i]) <= 1) S = i;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < 3; j++)
                for(int k = 0; k < 3; k++)
                    dp[i][j][k] = -1;

        int ans = inf;
        ans = min(ans, dfs(S, -1, 0, 0));
        ans = min(ans, 1 + dfs(S, -1, 0, 1));
        cout << ans << endl;

        int terminate;
        cin >> terminate;
        if(terminate == -1) break;
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
