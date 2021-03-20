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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1800 + 5;

const vector<int> dx = {0, 0, 1, -1};
const vector<int> dy = {1, -1, 0, 0};

#define get(x, y) ((x) * m + (y))
#define in(v) (v)
#define out(v) (v) + n * m

// Ford-Fulkerson Algorithm
// Edmonds-Karp variant
// flow can be map<int, int>[]
int N; // Total number of nodes, < MAXN
map<int, int> flow[MAXN]; // Dont forget to clear the flow in case of multiple TC
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
        for(auto &v : flow[u])
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
    int n, m, p;
    while(cin >> n >> m >> p)
    {
        vector<string> arr(n);
        for(auto &x : arr)
            cin >> x;

        auto valid = [&](int x, int y)
        {
            return x >= 0 && x < n && y >= 0 && y < m;
        };

        N = 2 * n * m + 2;
        for(int i = 0; i < N; i++)
            flow[i].clear();
        int S = 2 * n * m, T = 2 * n * m + 1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(arr[i][j] == '.' || arr[i][j] == '*')
                {
                    for(int k = 0; k < 4; k++)
                        if(valid(i + dx[k], j + dy[k]))
                            flow[out(get(i, j))][in(get(i + dx[k], j + dy[k]))] = 1;
                    flow[in(get(i, j))][out(get(i, j))] = 1;
                }
                else if(arr[i][j] == '@')
                {
                    for(int k = 0; k < 4; k++)
                        if(valid(i + dx[k], j + dy[k]))
                            flow[out(get(i, j))][in(get(i + dx[k], j + dy[k]))] = inf;
                    flow[in(get(i, j))][out(get(i, j))] = inf;
                }
                else if(arr[i][j] == '#')
                {
                    for(int k = 0; k < 4; k++)
                        if(valid(i + dx[k], j + dy[k]))
                            flow[out(get(i, j))][in(get(i + dx[k], j + dy[k]))] = inf;
                    flow[in(get(i, j))][out(get(i, j))] = inf;
                }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(arr[i][j] == '*')
                    flow[S][in(get(i, j))] = 1;
                else if(arr[i][j] == '#')
                    flow[out(get(i, j))][T] = p;

        int F = max_flow(S, T);
        cout << F << endl;
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
