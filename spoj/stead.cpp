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
const int MAXN = 2e3 + 5;

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
    int N, B;
    cin >> N >> B;
    vector<vector<int>> cow(N, vector<int>(B));
    for(auto &v : cow)
        for(int &x : v)
            cin >> x, x--;
    vector<int> cap(B);
    for(int &x : cap)
        cin >> x;

    int best = B;
    for(int a = 0; a < B; a++)
    {
        :: N = N + B + 2;
        int S = N + B, T = N + B + 1;
        for(int j = 0; j < N + B + 2; j++)
            flow[j].clear();
        for(int j = 0; j < B; j++)
            flow[N + j][T] = cap[j];
        for(int j = 0; j < N; j++)
            flow[S][j] = 1;
        bool ok = false;
        int F = 0;
        for(int i = a; i < B; i++)
        {
            for(int j = 0; j < N; j++)
                flow[j][N + cow[j][i]] = 1;
            F += max_flow(S, T);
            if(F >= N)
            {
                best = min(best, i - a + 1);
                break;
            }
        }
    }

    cout << best << endl;
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
