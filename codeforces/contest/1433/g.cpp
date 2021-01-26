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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e3 + 5;

/*
    Generate the all pair shortest path table with Dijkstra
    Floyd Warshall has small constant it will also work but risky TL too tight
    then store the queries, for each edges try to make its cost 0 and find the shortest path for all queries
    If you are making the cost of edge (u, v) -> 0
    then for queries (a, b), the shortest path will now be
    min of dist(a, u) + dist(v, b), dist(a, v) + dist(u, b), dist(a, b)
    Sum these over all queries and minimise total.

    Similar to UVa 10342
*/

int n, m, k;
int dist[MAXN][MAXN];
int path[MAXN][MAXN];

vector<vector<int>> edges, adj;

void dijkstra(int src)
{
    for(int i = 0; i < n; i++)
        dist[src][i] = INT_MAX;

    dist[src][src] = 0;
    path[src][src] = -1;
    // dist, u
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, src});

    while(!pq.empty())
    {
        pi node = pq.top();
        pq.pop();
        int u = node.ss, d = node.ff;

        if(dist[src][u] < d)
            continue;

        for(int i : adj[u])
        {
            int v = (edges[i][0] == u ? edges[i][1] : edges[i][0]);

            if(dist[src][v] > dist[src][u] + edges[i][2])
            {
                dist[src][v] = dist[src][u] + edges[i][2];
                pq.push({dist[src][v], v});
                path[src][v] = i;
            }
        }
    }
}

void cp()
{
    cin >> n >> m >> k;
    adj.resize(n);

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.pb({u, v, w, i});
        adj[u].pb(i);
        adj[v].pb(i);
    }

    for(int i = 0; i < n; i++)
        dijkstra(i);

    vector<pi> query;
    for(int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        query.pb({a, b});
    }

    // Remove some edge? convert to floyd warshall

    ll ans = INT_MAX;

    for(int i = 0; i < m; i++)
    {
        // dont include the ith edge and find min cost
        int u = edges[i][0], v = edges[i][1];
        ll me = 0;
        for(int j = 0; j < k; j++)
        {
            int a = query[j].ff, b = query[j].ss;
            me += min({dist[a][u] + dist[v][b], dist[b][u] + dist[v][a], dist[a][b]});
        }
        ans = min(ans, me);
    }

    cout << ans << endl;
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