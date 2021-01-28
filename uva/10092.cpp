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
const int inf = 1e7;
const int MAXN = 1e5 + 5;

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
        for(auto v : flow[u])
            if(!vis[v.first] && v.second > 0)
                vis[v.first] = 1, path[v.first] = u, q.push({v.first, min(mx, v.second)});
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
    int n, m;
    while(cin >> n >> m && n + m)
    {
        N = n + m + 2;
        int S = n + m, T = n + m + 1;
        for(int i = 0; i < N; i++)
            flow[i].clear();

        int total = 0;

        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            flow[S][i] = x;
            total += x;
        }

        for(int i = 0; i < m; i++)
        {
            int k;
            cin >> k;
            for(int j = 0; j < k; j++)
            {
                int c;
                cin >> c;
                c--;
                flow[c][n + i] = 1;
            }
            flow[n + i][T] = 1;
        }

        int F = max_flow(S, T);
        if(F == total)
        {
            cout << 1 << endl;
            vector<vector<int>> match(n);
            for(int i = 0; i < n; i++)
                for(int j = n; j < n + m; j++)
                    if(flow[j][i] > 0)
                        match[i].push_back(j - n);

            for(auto v : match)
                for(int x : v)
                    cout << x + 1 << " \n"[x == v.back()];
        }
        else
            cout << 0 << endl;
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

