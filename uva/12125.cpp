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
const int inf = 300;
const int MAXN = 2e2 + 5;

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

double dist(array<int, 4> &a, array<int, 4> &b)
{
    return sqrt((a[0] - b[0]) * 1.0 * (a[0] - b[0]) + (a[1] - b[1]) * 1.0 * (a[1] - b[1]));
}

#define in(v) v
#define out(v) v + n

void cp()
{
    int n;
    double d;
    cin >> n >> d;
    vector<array<int, 4>> p(n);
    for(auto &v : p)
        for(int &x : v)
            cin >> x;

    int P = 0;
    for(int i = 0; i < n; i++)
        P += p[i][2];

    vector<int> res;
    for(int i = 0; i < n; i++)
    {
        N = 2 * n + 1;
        int S = 2 * n;
        clr(flow, 0);
        for(int j = 0; j < n; j++)
            flow[in(j)][out(j)] = p[j][3], flow[S][in(j)] = p[j][2];

        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                if(j != k && (dist(p[j], p[k]) < d || fabs(dist(p[j], p[k]) - d) < eps))
                    flow[out(j)][in(k)] = inf;

        int F = max_flow(S, in(i));
        if(F >= P) res.push_back(i);
    }
    for(int x : res)
        cout << x << " \n"[x == res.back()];
    if(res.empty()) cout << -1 << endl;
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
