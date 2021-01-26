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
void solve(int u, int n, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &dist, vector<int> &ans)
{

    dist[u] = 0;
    set<pair<int, int>> q;
    q.insert(make_pair(0, u));
    while(!q.empty())
    {
        int v = q.begin()->second;
        q.erase(q.begin());
        vis[v] = true;
        for(int x : adj[v])
        {
            if(!vis[x] && dist[v] + 1 < dist[x])
            {
                ans[x] = v;
                q.erase(make_pair(dist[x], x));
                dist[x] = dist[v] + 1;
                q.insert(make_pair(dist[x], x));
            }
        }
    }

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
    vector<int> dist(n + 1, INT_MAX), ans(n + 1, -1);
    vector<bool> vis(n + 1, false);
    solve(1, n, adj, vis, dist, ans);
    for(int i = 2; i < sz(dist); i++)
    {
        if(dist[i] == INT_MAX)
        {
            cout << "No";
            return;
        }
    }
    cout << "Yes\n";
    for(int i = 2; i <= n; i++)
        cout << ans[i] << endl;
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