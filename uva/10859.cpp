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
const int MAXN = 1e3 + 5;

vector<bool> vis;
void dfs(int u, vector<vector<int>> &adj)
{
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v, adj);
}

int dp_min_lights[MAXN][2];
bool vis_min_lights[MAXN][2];

int solve_min_lights(int u, int p, int parent_lit, vector<vector<int>> &adj)
{
    if(vis_min_lights[u][parent_lit]) return dp_min_lights[u][parent_lit];
    vis_min_lights[u][parent_lit] = true;

    int ans = inf;

    int light = 1;
    for(int v : adj[u])
    {
        if(v == p) continue;
        light += solve_min_lights(v, u, 1, adj);
    }
    ans = min(ans, light);

    if(parent_lit)
    {
        int no_light = 0;
        for(int v : adj[u])
        {
            if(v == p) continue;
            no_light += solve_min_lights(v, u, 0, adj);
        }
        ans = min(ans, no_light);
    }

    return dp_min_lights[u][parent_lit] = ans;
}

int dp_max_two_lights[MAXN][2];
bool vis_max_two_lights[MAXN][2];

int solve_max_two_lights(int u, int p, int parent_lit, vector<vector<int>> &adj)
{
    if(vis_max_two_lights[u][parent_lit]) return dp_max_two_lights[u][parent_lit];
    vis_max_two_lights[u][parent_lit] = true;

    int min_lights = solve_min_lights(u, p, parent_lit, adj);

    int ans = 0;

    int light = 1;
    for(int v : adj[u])
    {
        if(v == p) continue;
        light += solve_min_lights(v, u, 1, adj);
    }
    if(light == min_lights)
    {
        int A = parent_lit && p != -1;
        for(int v : adj[u])
        {
            if(v == p) continue;
            A += solve_max_two_lights(v, u, 1, adj);
        }
        ans = max(ans, A);
    }

    if(parent_lit)
    {
        int no_light = 0;
        for(int v : adj[u])
        {
            if(v == p) continue;
            no_light += solve_min_lights(v, u, 0, adj);
        }
        if(no_light == min_lights)
        {
            int A = 0;
            for(int v : adj[u])
            {
                if(v == p) continue;
                A += solve_max_two_lights(v, u, 0, adj);
            }
            ans = max(ans, A);
        }
    }

    return dp_max_two_lights[u][parent_lit] = ans;
}

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vis.assign(n, false);
    int min_lights = 0;
    for(int i = 0; i < n; i++)
        if(sz(adj[i]) <= 1 && !vis[i])
        {
            dfs(i, adj);
            clr(vis_min_lights, false);
            int me = solve_min_lights(i, -1, 1, adj);
            min_lights += me;
        }

    vis.assign(n, false);
    int max_two_lights = 0;
    for(int i = 0; i < n; i++)
        if(sz(adj[i]) <= 1 && !vis[i])
        {
            dfs(i, adj);
            clr(vis_max_two_lights, false);
            int me = solve_max_two_lights(i, -1, 1, adj);
            max_two_lights += me;
        }

    cout << min_lights << " " << max_two_lights << " " << m - max_two_lights << endl;
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
