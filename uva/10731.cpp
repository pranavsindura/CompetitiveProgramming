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
const int MAXN = 1e5 + 5;

vector<int> comp;
vector<bool> vis, exist;
vector<vector<int>> scc;
void topsort(int u, vector<vector<int>> &adj, vector<int> &top)
{
    vis[u] = 1;
    for(int v : adj[u])
        if(!vis[v])
            topsort(v, adj, top);
    top.pb(u);
}
void dfs(int u, vector<vector<int>> &adj)
{
    vis[u] = 1;
    scc.back().pb(u);
    comp[u] = sz(scc) - 1;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v, adj);
}
void kosaraju(int n, vector<vector<int>> &adj, vector<vector<int>> &rev_adj)
{
	comp.assign(n, -1);
    vis.assign(n, false);
    scc.clear();
    vector<int> top;
    for(int i = 0; i < n; i++)
        if(!vis[i] && exist[i])
            topsort(i, adj, top);
    vis.assign(n, false);
    while(!top.empty())
    {
        int u = top.back();
        top.pop_back();
        if(vis[u]) continue;
        scc.pb(vector<int>());
        dfs(u, rev_adj);
    }
}

void cp()
{
    int T = 0;
    int n;
    while(cin >> n && n)
    {
        if(T++)
            cout << endl;
        vector<vector<int>> adj(26), rev_adj(26);
        exist.assign(26, false);
        for(int i = 0; i < n; i++)
        {
            vector<char> arr(6);
            for(char &x : arr) cin >> x, exist[x - 'A'] = 1;
            for(char x : arr)
                if(x != arr.back())
                    adj[arr.back() - 'A'].pb(x - 'A'), rev_adj[x - 'A'].pb(arr.back() - 'A');
        }
        kosaraju(26, adj, rev_adj);
        for(auto &v : scc)
            sort(all(v));
        sort(all(scc));
        for(auto &v : scc)
            for(int x : v)
                cout << char(65 + x) << " \n"[x == v.back()];
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

