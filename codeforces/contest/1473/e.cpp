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
const ll inf = 1e16;
const int MAXN = 2e5 + 5;

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pi>> adj(n);
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    vector<vector<vector<ll>>> dist(n, vector<vector<ll>>(2, vector<ll>(2, inf)));
    dist[0][0][0] = 0;

    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    pq.push({0, 0, 0, 0});

    while(!pq.empty())
    {
        vector<ll> node = pq.top();
        pq.pop();
        ll d = node[0];
        int mxd = node[1];
        int mnd = node[2];
        int u = node[3];
        if(dist[u][mxd][mnd] < d) continue;

        for(auto nd : adj[u])
        {
            int v = nd.ff;
            ll w = nd.ss;
            // skip
            if(dist[v][mxd][mnd] >= d + w)
            {
                dist[v][mxd][mnd] = d + w;
                pq.push({dist[v][mxd][mnd], mxd, mnd, v});
            }
            // Make mx
            if(!mxd && dist[v][1][mnd] >= d + w - w)
            {
                dist[v][1][mnd] = d + w - w;
                pq.push({dist[v][1][mnd], 1, mnd, v});
            }
            // Make mn
            if(!mnd && dist[v][mxd][1] >= d + w + w)
            {
                dist[v][mxd][1] = d + w + w;
                pq.push({dist[v][mxd][1], mxd, 1, v});
            }
            // Make mx and mn
            if(!mxd && !mnd && dist[v][1][1] >= d + w + w - w)
            {
                dist[v][1][1] = d + w + w - w;
                pq.push({dist[v][1][1], 1, 1, v});
            }
        }
    }

    for(int i = 1; i < n; i++)
        cout << dist[i][1][1] << " ";
    cout << endl;
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