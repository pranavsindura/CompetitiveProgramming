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

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> adj(n);
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> dist(n, LLONG_MAX);
    vector<int> shortest_path(n, -1);
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while(!pq.empty())
    {
        vector<ll> nd = pq.top();
        pq.pop();
        ll d = nd[0];
        int u = nd[1];
        if(d > dist[u]) continue;
        for(auto e : adj[u])
        {
            int v = e[0], w = e[1];
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                shortest_path[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    vector<int> path(n, -1), vis(n);
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 1;
        if(u == 1) break;
        for(auto e : adj[u])
        {
            int v = e[0];
            if(!vis[v] && v != shortest_path[u])
                q.push(v), vis[v] = 1, path[v] = u;
        }
    }

    if(vis[1])
    {
        vector<int> reconstruct;
        int u = 1;
        while(~u) reconstruct.push_back(u), u = path[u];
        reverse(all(reconstruct));
        cout << sz(reconstruct);
        for(int v : reconstruct)
            cout << " " << v;
        cout << endl;
    }
    else
        cout << "impossible\n";
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
