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

void dijkstra(int src, vector<ll> &dist, vector<vector<pi>> &adj)
{
    fill(all(dist), LLONG_MAX);
    dist[src] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, src});

    while(!pq.empty())
    {
        pair<ll, int> node = pq.top();
        int u = node.ss;
        ll d = node.ff;
        pq.pop();
        if(dist[u] < d)
            continue;
        for(auto &e : adj[u])
        {
            int v = e.ff;
            ll w = e.ss;
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
    src--, dest--;
    vector<vector<pi>> adj(n);
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    vector<ll> dist(n), cost(n, LLONG_MAX);
    cost[src] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, src});
    while(!pq.empty())
    {
        pair<ll, int> node = pq.top();
        int u = node.ss;
        ll c = node.ff;
        pq.pop();
        if(cost[u] < c)
            continue;
        dijkstra(u, dist, adj);
        for(int i = 0; i < n; i++)
        {
            if(dist[i] <= a[u] && i != u)
            {
                if(cost[i] > cost[u] + b[u])
                {
                    cost[i] = cost[u] + b[u];
                    pq.push({cost[i], i});
                }
            }
        }

    }

    if(cost[dest] == LLONG_MAX)
        cout << -1 << endl;
    else
        cout << cost[dest] << endl;
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