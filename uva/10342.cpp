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
const int inf = 1e6 + 5;

int dist[105][105];

int n, m;
vector<vector<pi>> adj(105);
vector<tuple<int, int, int>> edges;

void dijkstra(int src)
{
    dist[src][src] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, src});
    while(!pq.empty())
    {
        pi node = pq.top();
        pq.pop();
        int u = node.ss;
        int d = node.ff;
        if(dist[src][u] < d)
            continue;
        for(auto e : adj[u])
        {
            int v = e.ff;
            int w = e.ss;
            if(dist[src][u] + w < dist[src][v])
            {
                dist[src][v] = dist[src][u] + w;
                pq.push({dist[src][v], v});
            }
        }
    }
}

int solve(int a, int b)
{
    int shortest = dist[a][b];
    int ans = dist[a][b];
    int mn = inf;
    for(auto e : adj[b])
        mn = min(mn, e.ss);
    ans += 2 * mn;
    for(int i = 0; i < m; i++)
    {
        // try to include this edge
        int u, v, w;
        tie(u, v, w) = edges[i];
        int me = dist[a][u] + w + dist[v][b];
        if(me > shortest)
            ans = min(me, ans);
        me = dist[a][v] + w + dist[u][b];
        if(me > shortest)
            ans = min(me, ans);
    }

    return ans;
}

void cp()
{
    for(int i = 0; i < n; i++)
        adj[i].clear();
    edges.clear();
    for(int i = 0; i < n; i++)
        fill(dist[i], dist[i] + n, inf);
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(make_tuple(u, v, w));
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    for(int i = 0; i < n; i++)
        dijkstra(i);
    int q;
    cin >> q;
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        int ans = solve(a, b);
        if(ans >= inf)
            cout << "?\n";
        else
            cout << ans << endl;
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(cin >> n >> m)
    {
        cout << "Set #" << t++ << endl;
        cp();
    }
    return 0;
}