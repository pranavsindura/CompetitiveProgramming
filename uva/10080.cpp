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
const int inf = 1LL << 30;
const int MAXN = 2e2 + 5;

struct coord
{
    double x, y;
};

double dist2(coord p, coord q)
{
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

// KUHN's ALGORITHM
vector<int> mt;
vector<bool> vis, picked;

bool kuhn(int u, vector<vector<int>> &adj)
{
    if(vis[u]) return false;
    vis[u] = true;
    for(int v : adj[u])
    {
        if(mt[v] == -1 || kuhn(mt[v], adj)) // can find an augmenting path?
        {
            mt[v] = u;
            return true;
        }
    }
    return false;
}

void cp()
{
    int n, m, s, v;
    while(cin >> n >> m >> s >> v)
    {
        int N = n + m;
        vector<vector<int>> adj(n);
        vector<coord> a(n), b(m);
        for(auto &p : a)
            cin >> p.x >> p.y;
        for(auto &p : b)
            cin >> p.x >> p.y;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(dist2(a[i], b[j]) <= 1.0 * s * s * v * v)
                    adj[i].pb(j);

        mt.assign(m, -1); // which node in left half is the i-th right half node matched to?
        picked.assign(N, false); // greedy picking
        // Simple heuristic to speed things up, find any matching greedily
        for(int u = 0; u < n; u++)
        {
            for(int x : adj[u])
            {
                if(mt[x] == -1) // match it
                {
                    mt[x] = u;
                    picked[u] = 1;
                    break;
                }
            }
        }

        for(int u = 0; u < n; u++)
        {
        	if(picked[u]) continue;
            vis.assign(n, false);
            kuhn(u, adj);
        }

        // for all v such that mt[v] != -1, mt[v] and v belong to the maximum matching
        int matched = 0;
        for(int i = 0; i < m; i++)
            if(mt[i] != -1)
                matched++;
        cout << n - matched << endl;
    }
}


// MAX FLOW
// int N;
// int flow[MAXN][MAXN];
// int vis[MAXN], path[MAXN];

// int find_path(int S, int T)
// {
//     fill(vis, vis + N, 0);
//     queue<pi> q;
//     q.push({S, inf});
//     path[S] = -1;
//     while(!q.empty())
//     {
//         pi node = q.front();
//         q.pop();
//         int u = node.ff, mx = node.ss;
//         vis[u] = 1;
//         if(u == T) return mx;
//         for(int v = 0; v < N; v++)
//             if(!vis[v] && flow[u][v] > 0)
//                 vis[v] = 1, path[v] = u, q.push({v, min(mx, flow[u][v])});
//     }
//     return 0;
// }

// int max_flow(int S, int T)
// {
//     int ans = 0, d, u;
//     while(true)
//     {
//         d = find_path(S, T);
//         if(d == 0) break;
//         ans += d;
//         u = T;
//         while(~path[u])
//             flow[path[u]][u] -= d, flow[u][path[u]] += d, u = path[u];
//     }
//     return ans;
// }

// void cp()
// {
//     int n, m, s, v;
//     while(cin >> n >> m >> s >> v)
//     {
//         int S = n + m, T = n + m + 1;
//         N = n + m + 2;
//         clr(flow, 0);
//         vector<coord> a(n), b(m);
//         for(auto &p : a)
//             cin >> p.x >> p.y;
//         for(auto &p : b)
//             cin >> p.x >> p.y;
//         for(int i = 0; i < n; i++)
//             for(int j = 0; j < m; j++)
//                 if(dist2(a[i], b[j]) <= 1.0 * s * s * v * v)
//                     flow[i][n + j] = 1;
//         for(int i = 0; i < n; i++)
//             flow[S][i] = 1;
//         for(int i = 0; i < m; i++)
//             flow[n + i][T] = 1;

//         int match = max_flow(S, T);
//         cout << n - match << endl;
//     }
// }

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

