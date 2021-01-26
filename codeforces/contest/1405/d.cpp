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
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    queue<pi> q;
    vector<bool> vis(n + 1, false);
    vector<int> depth(n + 1);
    q.push({a, 0});
    while(!q.empty())
    {
        pi node = q.front();
        q.pop();
        int u = node.ff;
        int d = node.ss;
        vis[u] = 1;
        depth[u] = d;
        for(int v : adj[u])
            if(!vis[v])
                q.push({v, d + 1}), vis[v] = 1;
    }

    if(depth[b] <= da)
    {
        cout << "Alice\n";
        return;
    }

    if(da * 2 >= db)
    {
        cout << "Alice\n";
        return;
    }

    fill(all(vis), false);
    q.push({1, 0});
    int mxd = 0, last = 1;
    while(!q.empty())
    {
        pi node = q.front();
        q.pop();
        int u = node.ff;
        int d = node.ss;
        vis[u] = 1;
        if(d > mxd)
            mxd = d, last = u;
        for(int v : adj[u])
            if(!vis[v])
                q.push({v, d + 1}), vis[v] = 1;
    }

    mxd = 0;
    fill(all(vis), false);
    q.push({last, 0});
    while(!q.empty())
    {
        pi node = q.front();
        q.pop();
        int u = node.ff;
        int d = node.ss;
        vis[u] = 1;
        if(d > mxd)
            mxd = d, last = u;
        for(int v : adj[u])
            if(!vis[v])
                q.push({v, d + 1}), vis[v] = 1;
    }
    int half = (mxd + 1) / 2;
    cout << (da >= half ? "Alice\n" : "Bob\n");
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
    }
    return 0;
}