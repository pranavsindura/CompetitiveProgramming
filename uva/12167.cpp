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

// Tarjan's Algorithm
int TIMER;
vector<int> entry, low_link, comp;
vector<bool> instack, is_sink;
stack<int> st;
vector<vector<int>> scc;
void dfs(int u, vector<vector<int>> &adj)
{
    entry[u] = low_link[u] = TIMER++;
    instack[u] = 1;
    st.push(u);

    for(int v : adj[u])
        if(entry[v] == -1)
            dfs(v, adj), low_link[u] = min(low_link[u], low_link[v]);
        else if(instack[v])
            low_link[u] = min(low_link[u], entry[v]);

    if(entry[u] == low_link[u])
    {
        scc.pb(vector<int>());
        int x = -1;
        while(x != u)
        {
            x = st.top();
            st.pop();
            instack[x] = 0;
            scc.back().pb(x);
            comp[x] = sz(scc) - 1;
        }
    }
}

void tarjan(int n, vector<vector<int>> &adj)
{
    // RESET
    int N = n + 1;
    TIMER = 0;
    entry.assign(N, -1), low_link.assign(N, -1), comp.assign(N, -1);
    instack.assign(N, false);
    while(!st.empty()) st.pop();
    scc.clear();

    for(int i = 0; i < n; i++)
        if(entry[i] == -1)
            dfs(i, adj);
}

int min_edges(vector<vector<int>> &adj)
{
	if(sz(scc) == 1) return 0;
    int src = sz(scc);
    int sink = sz(scc);
    vector<int> in(src), out(src);
    // Find SCC
    for(int u = 0; u < sz(adj); u++)
        for(int v : adj[u])
            if(comp[u] != comp[v])
            {
                if(out[comp[u]] == 0) src--;
                if(in[comp[v]] == 0) sink--;
                out[comp[u]]++;
                in[comp[v]]++;
            }
    return max(src, sink);
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
        u--, v--;
        adj[u].pb(v);
    }

    tarjan(n, adj);

    cout << min_edges(adj) << endl;
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

