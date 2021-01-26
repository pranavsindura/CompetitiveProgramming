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
const int MAXN = 2e2 + 5;

/*
	Find max flow from 1 to n
	Edges outgoing from 1 and incoming to n have cap = 1
	remaining have inf cap
*/
int n;
int flow[MAXN][MAXN], path[MAXN];
bool vis[MAXN];

int find_path(int src, int sink)
{
    clr(vis, 0);
    bool found = false;

    queue<pi> q;
    q.push({src, -1});
    while(!q.empty() && !found)
    {
        int u = q.front().ff, par = q.front().ss;
        q.pop();
        found = (u == sink);
        vis[u] = 1, path[u] = par;
        for(int v = 0; v < n; v++)
            if(!vis[v] && flow[u][v] > 0)
                q.push({v, u}), vis[v] = 1;
    }
    return found;
}

int max_flow(int src, int sink)
{
    int ans = 0;
    while(find_path(src, sink))
    {
        ans++;
        int u = sink;
        while(~path[u])
        {
            int par = path[u];
            flow[par][u] -= 1;
            flow[u][par] += 1;
            u = par;
        }
    }
    return ans;
}

void cp()
{
    cin >> n;
    clr(flow, 0);
    for(int i = 0; i < n - 1; i++)
    {
        int m;
        cin >> m;
        for(int j = 0; j < m; j++)
        {
            int v;
            cin >> v;
            if(i == 0 || v == n)
                flow[i][v - 1] = 1;
            else
                flow[i][v - 1] = 1e6;
        }
    }
    cout << max_flow(0, n - 1) << endl;
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

