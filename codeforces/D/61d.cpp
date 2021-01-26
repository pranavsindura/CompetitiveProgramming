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
const int MAXN = 1e5 + 5;

ll dp1[MAXN], dp2[MAXN];
// dp1[u] -> cost if i return back to node u, to end path in some node not in u's subtree
// dp2[u] -> cost if i dont return to node u, to end path in u's subtree
void dfs(int u, int par, vector<vector<pi>> &adj)
{
    bool leaf = true;
    for(pi e : adj[u])
    {
        int v = e.ff, w = e.ss;
        if(v == par)
        	continue;

        dfs(v, u, adj);
        // Since we come back to u, edge weight is added twice, and also cost of coming back to v.
        dp1[u] += 2LL * w + dp1[v];
        leaf = false;
    }

    dp2[u] = LLONG_MAX;
    for(pi e : adj[u])
    {
        int v = e.ff, w = e.ss;
        if(v == par)
        	continue;
        // Since we dont come back to u, we can choose to end path in some child v
        // remove the edge weight once(coming back) and remove cost of coming back to v
        // now for the child v we have 2 choices, come back to v or dont come back to v
        // pick whichever is minimum
        dp2[u] = min(dp2[u], dp1[u] - w - dp1[v] + min(dp1[v], dp2[v]));
    }
    // If u is a leaf, dp1[u] = dp2[u] = 0
    if(leaf)
        dp2[u] = 0;
}

void cp()
{
    int n;
    cin >> n;
    vector<vector<pi>> adj(n + 1);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    dfs(1, 0, adj);
    cout << dp2[1];
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