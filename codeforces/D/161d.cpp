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
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 5e4 + 5;
int n, k;
vector<vector<int>> adj(MAXN);
ll dp[MAXN][502];
ll ans[MAXN];

void dfs(int u, int par)
{
    for(int v : adj[u])
    {
        if(v != par)
        {
            dfs(v, u);
            // Finding order and avoiding overcounting by processing only first j children
            // with full k
            for(int i = 0; i < k; i++)
                ans[u] += dp[u][i] * dp[v][k - i - 1];
            // Then adding them to the parent for further children to be processed with
            for(int i = 1; i <= k; i++)
                dp[u][i] += dp[v][i - 1];
        }
    }
}

void cp()
{
    cin >> n >> k;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }
    for(int i = 1; i <= n; i++)
        dp[i][0] = 1;

    dfs(1, 0);
    
    ll res = 0;
    for(int i = 1; i <= n; i++)
        res += ans[i];
    cout << res;
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