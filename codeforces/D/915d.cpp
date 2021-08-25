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
const int MAXN = 1e5 + 5;

vector<bool> vis, instack;
bool check_cycle(int u, vector<vector<int>> &adj, int U, int V)
{
    bool cycle = false;
    vis[u] = instack[u] = true;
    for(int v : adj[u])
    {
        if(u == U && v == V) continue;
        if(!vis[v])
            cycle |= check_cycle(v, adj, U, V);
        else if(instack[v])
            cycle = true;
    }
    instack[u] = false;
    return cycle;
}

bool done = false;
vector<int> st;
int at = -1;
void dfs(int u, vector<vector<int>> &adj)
{
    if(done) return;
    st.push_back(u);
    vis[u] = instack[u] = true;
    for(int v : adj[u])
    {
        if(!vis[v])
            dfs(v, adj);
        else if(instack[v])
            done = true, at = v;
    	if(done) return;
    }
    st.pop_back();
    instack[u] = false;
}

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
    }

    vis.resize(n);
    instack.assign(n, false);

    for(int i = 0; i < n; i++)
        dfs(i, adj);

    bool ok = false;

    if(at == -1) ok = true;

    vector<int> cycle_path;
    int pos;
    for(pos = 0; pos < sz(st); pos++)
        if(st[pos] == at) break;
    for(; pos < sz(st); pos++)
        cycle_path.push_back(st[pos]);

    // for(int x : cycle_path)
    //     cout << x + 1 << " ";
    // cout << endl;

    for(int i = 0; i < sz(cycle_path); i++)
    {
        bool cycle = false;
        fill(all(vis), false);
        fill(all(instack), false);
        for(int j = 0; j < n; j++)
            if(!vis[j])
                cycle |= check_cycle(j, adj, cycle_path[i], cycle_path[(i + 1) % sz(cycle_path)]);
        if(!cycle) ok = true;
    }

    cout << (ok ? "YES\n" : "NO\n");
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
