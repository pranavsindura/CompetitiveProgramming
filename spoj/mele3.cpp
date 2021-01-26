#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int, int>
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

int go_up(int u, int v, int d)
{
    // go up from u to v
    int len = v - u, mul = d / len, rem = d % len, wt = 0, pos;
    if(mul & 1) // going down
        pos = v - rem, wt = pos - u + len;
    else // going up
        pos = u + rem, wt = len + (pos > u) * (v - pos + len);
    return wt;
}

int go_down(int u, int v, int d)
{
    // go down from u to v
    int len = u - v, mul = d / len, rem = d % len, wt = 0, pos;
    if(mul & 1) // going down
        pos = u - rem, wt = len + (pos < u) * (pos - v + len);
    else // going up
        pos = v + rem, wt = len + (u - pos);
    return wt;
}

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0, u, v; i < m; i++)
        cin >> u >> v, adj[u].pb(v), adj[v].pb(u);

    vector<int> dist(n + 1, INT_MAX);
    dist[1] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 1});
    while(!pq.empty())
    {
        pi node = pq.top();
        pq.pop();
        int u = node.ss;
        ll d = node.ff;
        if(d > dist[u])
            continue;

        for(int v : adj[u])
        {
            int wt = v > u ? go_up(u, v, d) : go_down(u, v, d);
            if(dist[v] > dist[u] + wt)
            {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    cout << dist[n] * 5 << endl;

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