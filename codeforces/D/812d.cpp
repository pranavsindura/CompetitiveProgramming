#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

bool vis[MAXN];
int subtree[MAXN];
int tin[MAXN], tout[MAXN];
int TIMER;
void topsort(int u, vector<vector<int>> &adj, vector<int> &top)
{
    vis[u] = 1;
    for(int v : adj[u])
        if(!vis[v])
            topsort(v, adj, top);
    top.push_back(u);
}

int dfs(int u, vector<vector<int>> &adj)
{
    vis[u] = 1;
    subtree[u] = 1;
    tin[u] = TIMER++;
    for(int v : adj[u])
        if(!vis[v])
            subtree[u] += dfs(v, adj);
    tout[u] = TIMER++;
   	return subtree[u];
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

void cp()
{
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<vector<int>> adj(n);
    vector<int> have(m, -1);
    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if(~have[y]) adj[have[y]].push_back(x);
        have[y] = x;
    }

    vector<int> top;
    for(int i = 0; i < n; i++)
        if(!vis[i])
            topsort(i, adj, top);

    clr(vis, false);
    while(!top.empty())
    {
        if(!vis[top.back()])
            dfs(top.back(), adj);
        top.pop_back();
    }

    while(q--)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        int ans = 0;
        if(~have[y] && is_ancestor(x, have[y]))
            ans = subtree[x];
        cout << ans << endl;
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
