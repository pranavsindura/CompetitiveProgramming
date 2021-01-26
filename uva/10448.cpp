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
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
const int inf = 1e7;

int dp[52][100005];

int adj[52][52], last[52][52];

void build_path(int i, int j, vector<int> &path)
{
    if(last[i][j] == -1)
    {
        if(path.empty())
            path.pb(i);
        path.pb(j);
    }
    else
        build_path(i, last[i][j], path), build_path(last[i][j], j, path);
}

int solve(int i, int rem, vector<int> &path)
{
    if(i == sz(path) - 1)
        return (rem == 0 ? 0 : inf);

    int &ret = dp[i][rem];
    if(~ret)
        return ret;

    int ans = inf;
    // try going back
    if(i - 1 >= 0 && rem >= adj[path[i]][path[i - 1]])
        ans = min(ans, 1 + solve(i - 1, rem - adj[path[i]][path[i - 1]], path));
    // try going front
    if(rem >= adj[path[i]][path[i + 1]])
        ans = min(ans, 1 + solve(i + 1, rem - adj[path[i]][path[i + 1]], path));

    return ret = ans;
}

void cp()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            adj[i][j] = (i == j ? 0 : inf), last[i][j] = -1;

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = min(adj[u][v], w);
        adj[v][u] = min(adj[v][u], w);
    }

    // Floyd Warshall
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(adj[i][k] < inf && adj[k][j] < inf && adj[i][j] > adj[i][k] + adj[k][j])
                    adj[i][j] = adj[i][k] + adj[k][j], last[i][j] = k;
    int q;
    cin >> q;
    while(q--)
    {
        int src, dest, cost;
        cin >> src >> dest >> cost;

        vector<int> path;
        build_path(src, dest, path);

        // for(int i = 0; i <= sz(path); i++)
        //     for(int j = 0; j <= cost; j++)
        //         dp[i][j] = -1;

        // int ans = solve(0, cost, path);

        for(int i = 0; i <= sz(path); i++)
            for(int j = 0; j <= cost; j++)
                dp[i][j] = inf;

        dp[sz(path) - 1][0] = 0;

        for(int i = 0; i <= cost; i++)
        {
            for(int j = 0; j < sz(path) - 1; j++)
            {
                if(j - 1 >= 0 && i >= adj[path[j]][path[j - 1]])
                    dp[j][i] = min(dp[j][i], 1 + dp[j - 1][i - adj[path[j]][path[j - 1]]]);
                if(i >= adj[path[j]][path[j + 1]])
                    dp[j][i] = min(dp[j][i], 1 + dp[j + 1][i - adj[path[j]][path[j + 1]]]);
            }
        }
        int ans = dp[0][cost];

        if(ans < inf)
            cout << "Yes " << ans << endl;
        else
            cout << "No" << endl;
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
        if(t)
            cout << endl;
    }
    return 0;
}