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

int dp[17][1 << 17];

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int k;
    cin >> k;
    vector<int> gem(k);
    for(int &x : gem)
        cin >> x, x--;

    bool ok = true;

    vector<vector<int>> dist(k, vector<int>(k, inf));
    for(int i = 0; i < k; i++)
    {
        vector<bool> vis(n);
        vector<int> D(n, inf);
        queue<int> q;
        q.push(gem[i]);
        D[gem[i]] = 0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            vis[u] = 1;

            for(int v : adj[u])
                if(!vis[v])
                    q.push(v), D[v] = D[u] + 1, vis[v] = 1;
        }

        for(int j = 0; j < k; j++)
            dist[i][j] = D[gem[j]];
    }

    function<int(int, int)> solve = [&](int i, int mask)
    {
        if(mask == (1 << k) - 1) return 0;
        int &ret = dp[i][mask];
        if(~ret) return ret;
        int ans = inf;
        for(int j = 0; j < k; j++)
            if(!((mask >> j) & 1))
                ans = min(ans, dist[i][j] + solve(j, mask | (1 << j)));
        return ret = ans;
    };
    clr(dp, -1);
    int ans = inf;
    for(int i = 0; i < k; i++)
        ans = min(ans, 1 + solve(i, 1 << i));

    if(ans == inf) ans = -1;
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

