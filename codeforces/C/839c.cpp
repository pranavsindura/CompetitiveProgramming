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
vector<vector<int>> adj(MAXN);
vector<bool> vis(MAXN);

ld dfs(int u, int len, ld prob)
{
    vis[u] = true;
    ld me = 0;
    int child = 0;
    for(int v : adj[u])
        if(!vis[v])
            child++;
    if(child)
    {
        for(int v : adj[u])
            if(!vis[v])
                me += dfs(v, len + 1, prob / (child * 1.0));
    }
    else
    {
        me = (len * 1.0) * prob;
    }
    return me;
}

void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    ld ans = dfs(1, 0, 1);
    cout << setprecision(7) << fixed << ans;
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