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
const int MAXN = 1e6 + 5;

struct data
{
    int x, y, idx;
    data(): x(0), y(0), idx(-1) {}
    data(int x, int y, int idx): x(x), y(y), idx(idx) {}
};

bool cmp_x(data a, data b)
{
    return mp(a.x, a.y) < mp(b.x, b.y);
};

bool cmp_y(data a, data b)
{
    return mp(a.y, a.x) < mp(b.y, b.x);
};

ll dijkstra(vector<vector<pair<int, ll>>> &adj, int src, int dest)
{
    vector<ll> dist(sz(adj), LLONG_MAX);
    dist[src] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, src});

    while(!pq.empty())
    {
        pair<ll, int> node = pq.top();
        pq.pop();
        ll d = node.ff;
        int u = node.ss;
        if(dist[u] < d)
            continue;
        for(auto e : adj[u])
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
    return dist[dest];
}

void cp()
{
    int n, m, sx, sy, ex, ey;
    cin >> n >> m;
    cin >> sx >> sy >> ex >> ey;

    vector<data> arr(m);

    data st = data(sx, sy, 0);
    for(int i = 0, x, y; i < m; i++)
        cin >> x >> y, arr[i] = data(x, y, i + 1);
    data en = data(ex, ey, m + 1);

    auto manhattan = [&](data a, data b)
    {
        return abs(a.x - b.x) + 0LL + abs(a.y - b.y);
    };

    auto instant = [&](data a, data b)
    {
        return min(abs(a.x - b.x), abs(a.y - b.y));
    };

    vector<vector<pair<int, ll>>> adj(m + 2);

    sort(all(arr), cmp_x);

    for(int i = 0; i < sz(arr); i++)
    {
        // join src with arr[i]
        ll d = instant(st, arr[i]);
        adj[0].pb({arr[i].idx, d});
        adj[arr[i].idx].pb({0, d});

        // join arr[i] with dest
        d = manhattan(en, arr[i]);
        adj[m + 1].pb({arr[i].idx, d});
        adj[arr[i].idx].pb({m + 1, d});

        // join arr[i] with arr[i + 1]
        if(i + 1 < sz(arr))
        {
            d = instant(arr[i], arr[i + 1]);
            adj[arr[i].idx].pb({arr[i + 1].idx, d});
            adj[arr[i + 1].idx].pb({arr[i].idx, d});
        }
    }

    sort(all(arr), cmp_y);
    for(int i = 0; i < sz(arr) - 1; i++)
    {
        // join arr[i] with arr[i + 1]
        ll d = instant(arr[i], arr[i + 1]);
        adj[arr[i].idx].pb({arr[i + 1].idx, d});
        adj[arr[i + 1].idx].pb({arr[i].idx, d});
    }

    // join src and dest
    ll d = manhattan(st, en);
    adj[0].pb({m + 1, d});
    adj[m + 1].pb({0, d});

    ll ans = dijkstra(adj, 0, m + 1);
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