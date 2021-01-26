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

vector<int> vis;

void dfs(int u, int par, vector<vector<int>> &adj)
{
    for(int v : adj[u])
        if(v != par)
            dfs(v, u, adj);

    vector<int> child;
    int cnt = 0;
    for(int v : adj[u])
        if(v != par)
            child.pb(vis[v]);

    int mx = 0;
    int idx = 0;
    sort(all(child));
    while(!child.empty())
    {
        int p = child.back();
        child.pop_back();
        idx++;
        mx = max(mx, p + idx);
    }

    vis[u] = mx;
}

void cp()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++)
    {
        int x;
        while(cin >> x && x)
            x--, adj[i].pb(x), adj[x].pb(i);
    }
    vis.assign(n, 0);
    int S;
    cin >> S;
    S--;
    dfs(S, S, adj);
    cout << vis[S] << endl;
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

