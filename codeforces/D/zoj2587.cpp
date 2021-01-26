#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e5;
const int MAXN = 8e2 + 5;

/*UNTESTED*/

map<int, int> flow[MAXN];

// Ford-Fulkerson Algorithm
// Edmonds-Karp variant
int N; // Total number of nodes, < MAXN
int vis[MAXN], path[MAXN];

int find_path(int S, int T)
{
    fill(vis, vis + N + 1, 0);
    queue<pi> q;
    q.push({S, inf});
    path[S] = -1;
    while(!q.empty())
    {
        pi node = q.front();
        q.pop();
        int u = node.ff, mx = node.ss;
        vis[u] = 1;
        if(u == T) return mx;
        for(auto v : flow[u])
            if(!vis[v.ff] && v.ss > 0)
                vis[v.ff] = 1, path[v.ff] = u, q.push({v.ff, min(mx, v.ss)});
    }
    return 0;
}

int max_flow(int S, int T)
{
    int ans = 0, d, u;
    while(true)
    {
        d = find_path(S, T);
        if(d == 0) break;
        ans += d;
        u = T;
        while(~path[u])
            flow[path[u]][u] -= d, flow[u][path[u]] += d, u = path[u];
    }
    return ans;
}

void cp()
{
    int n, m, S, T;
    while(cin >> n >> m >> S >> T && n + m + S + T)
    {
        for(int i = 1; i <= n; i++)
            flow[i].clear();
        vector<pi> edges;
        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            flow[u][v] = w;
            flow[v][u] = w;
            edges.pb({u, v});
        }
        N = n;
        int F = max_flow(S, T);
        find_path(S, T);
        int cnt = 0;
        for(pi e : edges)
        {
            bool min_cut = vis[e.ff] ^ vis[e.ss];
            if(!min_cut && (!flow[e.ff][e.ss] || !flow[e.ss][e.ff]))
                cnt++;
        }
        if(cnt)
            cout << "AMBIGUOUS\n";
        else
            cout << "UNIQUE\n";
    }
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

