#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;
vector<bool> vis(1500, false);
vector<int> adj[55];
ll ans = 1;
void bfs(int u)
{
    vis[u] = true;
    queue<int> q;
    q.push(u);
    ll a = 0;
    while(!q.empty())
    {
        int x = q.front();
        vis[x] = true;
        q.pop();
        a++;
        for(int v : adj[x])
        {
            if(!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    for(int i = 0; i < a - 1; i++)
        ans *= 2;
}

int main()
{
    FASTIO;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
            bfs(i);
    }
    cout << ans;
    return 0;
}