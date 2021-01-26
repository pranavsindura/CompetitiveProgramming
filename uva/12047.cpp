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
const int MAXN = 1e6 + 5;
const ll inf = 1e12;

void cp()
{
    int n, m, src, dest;
    ll p;
    cin >> n >> m >> src >> dest >> p;
    vector<vector<pi>> adj(n + 1), invadj(n + 1);
    vector<pair<pi, int>> edges;
    for(int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].pb({v, c});
        invadj[v].pb({u, c});
        edges.pb({{u, v}, c});
    }
    vector<ll> dist_from_src(n + 1, inf), dist_from_dest(n + 1, inf);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist_from_src[src] = 0;
    pq.push({0, src});
    while(!pq.empty())
    {
        pair<ll, int> node = pq.top();
        pq.pop();
        int u = node.ss;
        ll d = node.ff;
        if(d > dist_from_src[u])
            continue;
        for(pi node2 : adj[u])
        {
            int v = node2.ff;
            int c = node2.ss;
            if(dist_from_src[u] + c < dist_from_src[v])
            {
                dist_from_src[v] = dist_from_src[u] + c;
                pq.push({dist_from_src[v], v});
            }
        }
    }

    dist_from_dest[dest] = 0;
    pq.push({0, dest});
    while(!pq.empty())
    {
        pair<ll, int> node = pq.top();
        pq.pop();
        int u = node.ss;
        ll d = node.ff;
        if(d > dist_from_dest[u])
            continue;
        for(pi node2 : invadj[u])
        {
            int v = node2.ff;
            int c = node2.ss;
            if(dist_from_dest[u] + c < dist_from_dest[v])
            {
                dist_from_dest[v] = dist_from_dest[u] + c;
                pq.push({dist_from_dest[v], v});
            }
        }
    }
    ll ans = -1;
    for(auto e : edges)
    {
        ll total = dist_from_src[e.ff.ff] + e.ss + dist_from_dest[e.ff.ss];
        if(total <= p)
            ans = max(ans, 1LL*e.ss);
    }
    cout << ans << endl;
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