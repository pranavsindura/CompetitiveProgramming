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
ll people[MAXN], h[MAXN];
ll acc[MAXN];
bool vis[MAXN];
bool ok;
ll dfs(int u, vector<vector<int>> &adj)
{
    vis[u] = true;
    ll sum = people[u];
    for(int v : adj[u])
    {
        if(!vis[v])
            sum += dfs(v, adj);
    }
    if(h[u] < -sum || h[u] > sum || (sum % 2 != abs(h[u]) % 2) )
        ok = false;
    return acc[u] = sum;
}

pair<ll, ll> dfs2(int u, vector<vector<int>> &adj)
{
    vis[u] = true;

    ll mpos = 0, mneg = 0;
    ll temp = h[u] + acc[u];
    mpos = temp / 2;
    mneg = acc[u] - mpos;

    ll cpos = 0, cneg = 0;

    for(int v : adj[u])
    {
        if(!vis[v])
        {
            pair<ll, ll> c = dfs2(v, adj);
            cpos += c.ff;
            cneg += c.ss;
        }
    }
    if(cpos > mpos)
        ok = false;
    return {mpos, mneg};

}

void cp()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> people[i];
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    ok = true;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    fill(acc + 1, acc + n + 1, 0);
    fill(vis + 1, vis + n + 1, 0);
    dfs(1, adj);
    fill(vis + 1, vis + n + 1, 0);
    dfs2(1, adj);
    if(ok)
        cout << "YES\n";
    else
        cout << "NO\n";
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