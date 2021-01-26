#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 9e-3;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

const double inf = 1e9 + 1;

double adj[55][55];
double dp[55][1 << 12];
bool vis[55][1 << 12];

vector<pair<int, double>> path;

double solve(int u, int mask)
{
    if(mask == 0)
        return -adj[u][0];

    if(vis[u][mask])
        return dp[u][mask];

    vis[u][mask] = 1;

    double ans = -inf;
    for(int i = 0; i < sz(path); i++)
    {
        if((mask >> i) & 1) // this node is not visited, try to visit it
        {
            // go to it
            ans = max(ans, -adj[u][path[i].ff] + path[i].ss + solve(path[i].ff, mask ^ (1 << i)));
            // skip it
            ans = max(ans, solve(u, mask ^ (1 << i)));
        }
    }

    return dp[u][mask] = ans;
}

void cp()
{
    int n, m;
    cin >> n >> m;

    path.clear();
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            adj[i][j] = (i == j ? 0 : inf);

    for(int i = 0; i < m; i++)
    {
        int u, v;
        double w;
        cin >> u >> v >> w;
        adj[u][v] = min(adj[u][v], w);
        adj[v][u] = min(adj[v][u], w);
    }

    for(int k = 0; k <= n; k++)
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                if(adj[i][k] < inf && adj[k][j] < inf)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
    int p;
    cin >> p;
    for(int i = 0; i < p; i++)
    {
        int u;
        double w;
        cin >> u >> w;
        path.pb({u, w});
    }

    clr(vis, 0);
    clr(dp, 0);

    double ans = solve(0, (1 << p) - 1);

    if(ans > eps)
        cout << "Daniel can save $" << ans << endl;
    else
        cout << "Don\'t leave the house" << endl;
}

int main()
{
    FASTIO;
    dblout(2);
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}