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
const int MAXN = 60040;

map<int, int> flow[MAXN];
int vis[MAXN], path[MAXN];

int find_path(int S, int T)
{
    clr(vis, 0);
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
    int ans = 0, u, d;
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
    int n, m;
    cin >> n >> m;

    for(int i = 0; i <= 2 * n + 1; i++) flow[i].clear();
    for(int i = 1; i <= n; i++)
        flow[i][i + n] = 1;
    flow[2][2 + n] = 2;
    int S = 0, T = 2 * n + 1;
    flow[S][2] = 2, flow[1 + n][T] = 1, flow[3 + n][T] = 1;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if(u >= 1 && u <= n && v >= 1 && v <= n)
            flow[u + n][v] += 1, flow[v + n][u] += 1;
    }
    bool ok = max_flow(S, T) == 2;
    cout << (ok ? "YES\n" : "NO\n");
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

