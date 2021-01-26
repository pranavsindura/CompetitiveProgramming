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
const int MAXN = 5e2 + 5;

map<string, int> comp;
int get_idx(string s)
{
    if(!comp.count(s))
        comp[s] = sz(comp);
    return comp[s];
}

// Ford-Fulkerson Algorithm
// Edmonds-Karp variant
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
    comp.clear();
    clr(flow, 0);
    int n, m, k, u, v;
    string S = "_src", T = "_sink";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        u = get_idx(a), v = get_idx(T);
        flow[u][v] += 1;
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        string a, b;
        cin >> a >> b;
        u = get_idx(a), v = get_idx(b);
        flow[u][v] += 1;
        u = get_idx(S), v = get_idx(a);
        flow[u][v] += 1;
    }
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        string a, b;
        cin >> a >> b;
        u = get_idx(a), v = get_idx(b);
        flow[u][v] = inf;
    }
    get_idx(S), get_idx(T);
    N = min(MAXN, sz(comp) + 5);
    int f = max_flow(get_idx(S), get_idx(T));
    cout << m - f << endl;
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
        if(t) cout << endl;
    }
    return 0;
}

