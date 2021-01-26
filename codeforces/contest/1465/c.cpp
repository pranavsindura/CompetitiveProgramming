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

void cp()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> row(n, -1), col(n, -1);
    vector<vector<int>> rook(m);

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        row[x] = i, col[y] = i;
        rook[i] = {x, y};
    }

    vector<bool> vis(m), instack(m);
    vector<vector<int>> adj(m);
    for(int i = 0; i < m; i++)
    {
        int x = rook[i][0], y = rook[i][1];
        if(x == y) vis[i] = 1;
        if(~col[x])
            adj[i].pb(col[x]);
        if(~row[y])
            adj[i].pb(row[y]);
    }

    int sub = 0;
    function<bool(int)> dfs = [&](int u)
    {
        vis[u] = 1;
        instack[u] = 1;
        sub++;
        bool cycle = sz(adj[u]) > 1;
        for(int v : adj[u])
        {
            if(!vis[v])
                cycle &= dfs(v);
            else if(instack[v])
            	cycle &= 1;
        }
        instack[u] = 0;
        return cycle;
    };

    int ans = 0;
    for(int i = 0; i < m; i++)
    {
        if(vis[i]) continue;
        sub = 0;
        bool cycle = dfs(i);
        if(cycle) ans += sub + 1;
        else ans += sub;
    }

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

