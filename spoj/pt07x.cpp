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
const int MAXN = 1e5 + 5;

int dp[MAXN][2];

int dfs(int u, int par, int have_choice, vector<vector<int>> &adj)
{

    int &ret = dp[u][have_choice];
    if(~ret)
        return ret;

    int ans = 2 * MAXN;
    if(have_choice)
    {
        //choose to include me, have_choice for children
        int c1 = 1;
        for(int v : adj[u])
            if(v != par)
                c1 += dfs(v, u, 1, adj);
        //dont include me, no choice but to include children
        int c2 = 0;
        for(int v : adj[u])
            if(v != par)
                c2 += dfs(v, u, 0, adj);
        ans = min(c1, c2);
    }
    else
    {
        //no choice but to include me, have choice for children
        ans = 1;
        for(int v : adj[u])
            if(v != par)
                ans += dfs(v, u, 1, adj);
    }
    return ret = ans;
}

void cp()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 0, u, v; i < n - 1; i++)
        cin >> u >> v, adj[u].pb(v), adj[v].pb(u);
    int root = -1;
    for(int i = 1; i <= n; i++)
        if(sz(adj[i]) <= 1)
            root = i;
    clr(dp, -1);
    int ans = min(dfs(root, root, 0, adj), dfs(root, root, 1, adj));
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