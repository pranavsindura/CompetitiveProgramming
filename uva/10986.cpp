#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
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
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;
map<pi, int> cost;

void dijkstra(vector<vector<int>> &adj, int n, vector<int> &dist, int s)
{
    dist[s] = 0;
    set<pi> q;
    q.insert({0, s});
    vector<bool> vis(n, false);
    while(!q.empty())
    {
        int u = q.begin()->second;
        q.erase(q.begin());
        vis[u] = true;
        for(int v : adj[u])
        {
            if(!vis[v] && dist[v] > dist[u] + cost[mp(u, v)])
            {
                q.erase({dist[v], v});
                dist[v] = dist[u] + cost[mp(u, v)];
                q.insert({dist[v], v});
            }
        }
    }
}

void cp()
{
    int n, m, src, dest;
    cin >> n >> m >> src >> dest;
    cost.clear();
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        if(cost.find(mp(u, v)) != cost.end())
        {
            cost[mp(u, v)] = min(c, cost[mp(u, v)]);
            cost[mp(v, u)] = min(c, cost[mp(v, u)]);
        }
        else
        {
            cost[mp(u, v)] = c;
            cost[mp(v, u)] = c;
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }
    vector<int> dist(n, INT_MAX);
    dijkstra(adj, n, dist, src);
    if(dist[dest] == INT_MAX)
        cout << "unreachable";
    else
        cout << dist[dest];
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int test_case = 1; test_case <= t; test_case++)
    {
        cout << "Case #" << test_case << ": ";
        cp();
        cout << endl;
    }
    return 0;
}
/*
	Priority Queue Implementation
	#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
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
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

void dijkstra(vector<vector<pi>> &adj, int n, vector<int> &dist, int s)
{
    dist[s] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, s});
    while(!pq.empty())
    {
        pi u_node = pq.top();
        pq.pop();
        int c = u_node.first;
        int u = u_node.second;
        // if dist[u] is already smaller than the accumulated distance, it has been visited, no need to process
        // dropped visited array
        if(dist[u] < c)
            continue;

        for(pi v_node : adj[u])
        {
            int w = v_node.second;
            int v = v_node.first;
            // Relax node v
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void cp()
{
    int n, m, src, dest;
    cin >> n >> m >> src >> dest;
    vector<vector<pi>> adj(n + 1);
    for(int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
    }
    vector<int> dist(n, INT_MAX);
    dijkstra(adj, n, dist, src);
    if(dist[dest] == INT_MAX)
        cout << "unreachable";
    else
        cout << dist[dest];
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int test_case = 1; test_case <= t; test_case++)
    {
        cout << "Case #" << test_case << ": ";
        cp();
        cout << endl;
    }
    return 0;
}
*/