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
const int MAXN = 1e4 + 5;
const int inf = 1e8;


// DP didn't work, not sure why
// Greedy attempt Dijkstra + BFS
vector<vector<pi>> adj;
int hotel[MAXN];
int n,h,m;
/*
	Intermediate nodes are irrelevant as we only need to go from one
	hotel to another, lets make 1 and n hotels as well
	Now we need to find shortest paths from one hotel to another
	That path must be <= 600 in length, If we can visit hotel u from hotel v with path length <= 600
	then that becomes 1 day and we can make a new graph in which we can BFS(path length 1)
	from hotel 1 to hotel n

	Dijkstra
	node, path weight. sorted by path weight

	BFS
	queue, start from 1, path length to n - 1 is the answer
*/

int dist[105][MAXN];

void dijkstra(int src_idx)
{
    for(int i = 1; i <= n; i++)
        dist[src_idx][i] = inf;
    dist[src_idx][hotel[src_idx]] = 0;
    
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, hotel[src_idx]});

    while(!pq.empty())
    {
        pi node = pq.top();
        pq.pop();
        int u = node.ss, d = node.ff;

        if(dist[src_idx][u] < d)
            continue;

        for(auto nx : adj[u])
        {
            int v = nx.ff, w = nx.ss;
            if(d + w <= 600 && dist[src_idx][v] > dist[src_idx][u] + w)
                dist[src_idx][v] = dist[src_idx][u] + w, pq.push({dist[src_idx][v], v});
        }
    }
}

int bfs()
{
    queue<pi> q;
    q.push({0, 0});
    vector<bool> vis(h);
    while(!q.empty())
    {
        int u = q.front().ff, d = q.front().ss;
        q.pop();
        vis[u] = 1;

        if(hotel[u] == n)
            return d - 1;

        for(int i = 0; i < h; i++)
            if(dist[u][hotel[i]] < inf && !vis[i])
                q.push({i, d + 1}), vis[i] = 1;
    }

    return -1;
}

void cp()
{
    while(cin >> n && n)
    {
        adj.clear(), adj.resize(n + 1);

        cin >> h;
        hotel[0] = 1, hotel[h + 1] = n;
        for(int i = 1, x; i <= h; i++)
            cin >> x, hotel[i] = x;
        h += 2;

        cin >> m;
        for(int i = 0, u, v, w; i < m; i++)
            cin >> u >> v >> w, adj[u].pb({v, w}), adj[v].pb({u, w});

        for(int i = 0; i < h; i++)
            dijkstra(i);

        int ans = bfs();

        cout << ans << endl;
    }
}

int main()
{
    // FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}