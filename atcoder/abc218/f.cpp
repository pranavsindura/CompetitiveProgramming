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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

vector<int> bfs(vector<vector<int>> &edges, vector<vector<int>> &adj, int ignore)
{
    vector<bool> vis(sz(adj));
    vector<int> path(sz(adj), -1);
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = true;
        for(int e : adj[u])
        {
            if(e == ignore) continue;
            int v = edges[e][1];
            if(!vis[v])
                vis[v] = true, q.push(v), path[v] = e;
        }
    }
    vector<int> retrace;
    int u = sz(adj) - 1;
    while(~path[u]) retrace.push_back(path[u]), u = edges[path[u]][0];
    reverse(all(retrace));
    return retrace;
}

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges, adj(n);
    for(int i = 0, u, v; i < m; i++)
        cin >> u >> v, u--, v--, edges.push_back({u, v}), adj[u].push_back(i);

    vector<int> shortest = bfs(edges, adj, -1);
    vector<int> ans(m, sz(shortest));
    for(int e : shortest)
        ans[e] = sz(bfs(edges, adj, e));
    for(int &x : ans)
        if(x == 0) x = -1;
    for(int x : ans)
        cout << x << endl;
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
