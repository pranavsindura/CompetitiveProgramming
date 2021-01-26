#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define nl cout<<endl;
const double PI = acos(-1.0);
using namespace std;
int n = 100005;
vector<int> res(n + 1, 0);
vector<bool> vis(n + 1, false);
vector<int> cost(n + 1, 0);
vector<vector<int>> adj(n + 1);

void dfs(int u, int par, int count)
{
    res[u] = max(res[par], count + cost[u]);
    vis[u] = true;
    for(int x : adj[u])
    {
        if(!vis[x])
        {
            if(cost[u])
                dfs(x, u, count + cost[u]);
            else
                dfs(x, u, 0);
        }
    }
}

void cp()
{
    int m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        cin >> cost[i];

    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[b].pb(a);
        adj[a].pb(b);
    }
    dfs(1, 0, 0);
    int count = 0;
    for(int i = 2; i <= n; i++)
    {
        if(sz(adj[i]) == 1 && res[i] <= m)
            count++;
        // cout << i << ": " << res[i] << endl;
    }
    cout << count;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin>>t;
    while(t--)
    {
        cp();
    }
    return 0;
}