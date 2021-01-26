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
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double PI = acos(-1.0);

vector<int> bfs(int n, vector<vector<int>> &adj)
{
    vector<bool> vis(n + 1, false);
    vector<int> ans(n + 1, -1);
    vis[1] = false;
    queue<pii> q;
    q.push({1, 1});
    while(!q.empty())
    {
        pii u = q.front();
        q.pop();
        vis[u.ff] = true;
        ans[u.ff] = u.ss;
        for(int v : adj[u.ff])
        {
            if(!vis[v])
            {
                q.push({v, u.ff});
                vis[v] = true;
            }
        }
    }
    return ans;
}

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<int> ans = bfs(n, adj);
    for(int i = 2; i <= n; i++)
    {
        if(ans[i] == -1)
        {
            cout << "No";
            return;
        }
    }
    cout << "Yes\n";
    for(int i = 2; i <= n; i++)
    {
        cout << ans[i] << endl;
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