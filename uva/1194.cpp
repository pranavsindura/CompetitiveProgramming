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
const ll inf = 1LL << 30;
const int MAXN = 205;

// Ford-Fulkerson Algorithm
// Edmonds-Karp variant
// flow can be map<int, int>[]
int N; // Total number of nodes, < MAXN
int flow[MAXN][MAXN]; // Dont forget to clear the flow in case of multiple TC
int vis[MAXN], path[MAXN];

int find_path(int S, int T)
{
    fill(vis, vis + N, 0);
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
        for(int v = 0; v < N; v++)
            if(!vis[v] && flow[u][v] > 0)
                vis[v] = 1, path[v] = u, q.push({v, min(mx, flow[u][v])});
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
    int n, m, k;
    while(cin >> n && n)
    {
        cin >> m >> k;
        N = n + m + 2;
        int S = n + m, T = n + m + 1;
        clr(flow, 0);
        clr(path, -1);
        for(int i = 0; i < k; i++)
        {
            int u, x, y;
            cin >> u >> x >> y;
            if(x && y)
                flow[x][n + y] = 1;
        }
        for(int i = 0; i < n; i++)
            flow[S][i] = 1;
        for(int i = 0; i < m; i++)
            flow[n + i][T] = 1;
        int ans = max_flow(S, T);
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

