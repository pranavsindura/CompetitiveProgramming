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
const int inf = 1e6;
const int MAXN = 2e2 + 5;

#define in(v) v
#define out(v) v + n
int n;
int flow[MAXN][MAXN], path[MAXN];
bool vis[MAXN];

int find_path(int src, int sink)
{
    clr(vis, 0);
    queue<pi> q;
    q.push({src, inf});
    path[src] = -1;
    while(!q.empty())
    {
        int u = q.front().ff, mx = q.front().ss;
        q.pop();
        vis[u] = 1;
        if(u == sink) return mx;
        for(int v = 0; v < 2 * n + 2; v++)
            if(!vis[v] && flow[u][v] > 0)
                path[v] = u, vis[v] = 1, q.push({v, min(mx, flow[u][v])});
    }
    return 0;
}

int max_flow(int src, int sink)
{
    int ans = 0;
    while(true)
    {
        int d = find_path(src, sink);
        if(d == 0) break;
        ans += d;

        int u = sink;
        while(~path[u])
        {
            int p = path[u];
            flow[p][u] -= d;
            flow[u][p] += d;
            u = p;
        }
    }
    return ans;
}

void cp()
{
    while(cin >> n)
    {
        clr(flow, 0);
        for(int i = 0; i < n; i++)
        {
            int cap;
            cin >> cap;
            flow[in(i)][out(i)] = cap;
        }
        int m;
        cin >> m;
        for(int i = 0; i < m; i++)
        {
            int u, v, cap;
            cin >> u >> v >> cap;
            u--, v--;
            flow[out(u)][in(v)] = cap;
        }
        int b, d;
        cin >> b >> d;
        // 2*n = super source, 2*n+1 super sink
        for(int i = 0; i < b; i++)
        {
            int u;
            cin >> u;
            u--;
            flow[2 * n][in(u)] = inf;
        }
        for(int i = 0; i < d; i++)
        {
            int u;
            cin >> u;
            u--;
            flow[out(u)][2 * n + 1] = inf;
        }
        // find max flow from super source to super sink
        int ans = max_flow(2 * n, 2 * n + 1);
        cout << ans << endl;
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

