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
const int MAXN = 1e6 + 5;

void dfs(int u, int par, vector<bool> &vis, vector<vector<int>> &adj)
{
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v, u, vis, adj);
}

void cp()
{
    int n, m;
    while(cin >> n >> m)
    {
        vector<vector<int>> adj(n + 1);
        vector<bool> vis(n + 1);
        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
        }
        vector<int> ans;
        for(int i = 1; i <= n; i++)
        {
            fill(all(vis), false);
            vis[i] = true;
            if(!vis[1])
                dfs(1, 1, vis, adj);
            bool any = false;
            for(int j = 1; j <= n; j++)
                any |= !vis[j];
            if(any)
                ans.pb(i);
        }
        cout << sz(ans) << endl;
        for(int x : ans)
            cout << x << " ";
        cout << endl;
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