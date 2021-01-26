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
const ll inf = 1e5;
const int MAXN = 400 + 5;

// MAX FLOW

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};
char arr[45][15];

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
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // Minimum edge cover?
    // Find maximum matching + greedily extend
    // Graph is bipartite, Max matching with max flow
    clr(flow, 0);
    N = n * m + 2;
    int S = n * m, T = n * m + 1;
    int total = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(arr[i][j] == '*')
            {
                total++;
                int u = i * m + j;
                if((i + j) % 2)
                {
                    flow[S][u] = 1;
                    for(int k = 0; k < 4; k++)
                    {
                        int nx = i + dx[k], ny = j + dy[k];
                        int v = nx * m + ny;
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == '*')
                            flow[u][v] = 1;
                    }
                }
                else
                    flow[u][T] = 1;
            }

    int match = max_flow(S, T);
    int ans = total - match;
    cout << ans << endl;
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

