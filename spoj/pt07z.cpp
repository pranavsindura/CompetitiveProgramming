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
// dia, height pair
pi diameter(int u, vector<vector<int>> &adj, int par = -1)
{
    int mx_height[3] = {-1, -1, -1};
    int dia = 0;
    for(int v : adj[u])
    {
    	if(v == par)
    		continue;
        pi child = diameter(v, adj, u);
        dia = max(dia, child.ff);

        mx_height[0] = child.ss + 1;
        sort(mx_height, mx_height + 3);
    }
    for(int i = 0; i < 3; i++)
        if(mx_height[i] == -1)
            mx_height[i] = 0;

    dia = max(dia, mx_height[1] + mx_height[2]);

    return {dia, mx_height[2]};
}

void cp()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cout << diameter(1, adj).ff;
    // vector<bool> vis(n + 1, false);
    // queue<pi> q;
    // q.push({1, 0});
    // pi farthest = {1, 0};
    // while(!q.empty())
    // {
    //     pi u = q.front();
    //     q.pop();
    //     vis[u.ff] = true;
    //     if(u.ss > farthest.ss)
    //         farthest = u;
    //     for(int v : adj[u.ff])
    //     {
    //         if(!vis[v])
    //             q.push({v, u.ss + 1}), vis[v] = true;
    //     }
    // }
    // fill(all(vis), false);
    // q.push({farthest.ff, 0});
    // farthest.ss = 0;
    // while(!q.empty())
    // {
    //     pi u = q.front();
    //     q.pop();
    //     vis[u.ff] = true;
    //     if(u.ss > farthest.ss)
    //         farthest = u;
    //     for(int v : adj[u.ff])
    //     {
    //         if(!vis[v])
    //             q.push({v, u.ss + 1}), vis[v] = true;
    //     }
    // }
    // cout << farthest.ss;
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