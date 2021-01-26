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
const int inf = 1e7;
const int MAXN = 1e5 + 5;

map<string, int> compress;
int get_idx(string &s)
{
    if(compress.count(s))
        return compress[s];
    else
        return compress[s] = sz(compress) - 1;
}

int TIMER;
vector<int> entry, low_link, comp;
vector<bool> instack;
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
    int N = n;
    TIMER = 0;
    entry.assign(N, -1), low_link.assign(N, -1), comp.assign(N, -1);
    instack.assign(N, false);
    while(!st.empty()) st.pop();
    scc.clear();

    for(int i = 0; i < n; i++)
        if(entry[i] == -1)
            dfs(i, adj);
}

vector<bool> is_source;
vector<vector<int>> component_graph(vector<vector<int>> &adj)
{
    // Find SCC
    is_source.assign(sz(scc), true);
    vector<vector<int>> G(sz(scc));
    for(int u = 0; u < sz(adj); u++)
        for(int v : adj[u])
            if(comp[u] != comp[v])
            {
                G[comp[u]].pb(comp[v]);
                is_source[comp[v]] = false;
            }
    return G;
}

vector<int> freq, len;
vector<pair<ll, ll>> val;

vector<bool> vis;
void dfs2(int u, vector<vector<int>> &adj)
{
    vis[u] = 1;
    for(int v : adj[u])
    {
        if(!vis[v])
            dfs2(v, adj);
        val[u] = min(val[u], val[v]);
    }
}

vector<string> arr;
vector<vector<int>> adj;
void cp()
{
    int n, m;
    cin >> n;
    arr.resize(n);
    for(string &x : arr)
        cin >> x, transform(all(x), begin(x), ::tolower), get_idx(x);
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        string u, v;
        cin >> u >> v;
        transform(all(u), begin(u), ::tolower);
        transform(all(v), begin(v), ::tolower);
        val.pb({get_idx(u), get_idx(v)});
    }

    int N = sz(compress);

    adj.resize(N);
    for(auto x : val)
        adj[x.ff].pb(x.ss);

    val.clear();
    freq.assign(N, 0);
    len.assign(N, 0);
    for(auto &x : compress)
    {
        for(char y : x.ff)
            freq[x.ss] += y == 'r';
        len[x.ss] = ln(x.ff);
    }

    tarjan(N, adj);

    vector<vector<int>> C = component_graph(adj);
    val.assign(sz(scc), {inf, inf});
    for(int i = 0; i < sz(scc); i++)
        for(int x : scc[i])
            val[i] = min(val[i], {freq[x], len[x]});

    vis.assign(sz(scc), false);
    for(int i = 0; i < sz(scc); i++)
        if(is_source[i] && !vis[i])
            dfs2(i, C);

    ll a = 0, b = 0;
    for(string &x : arr)
        a += val[comp[get_idx(x)]].ff, b += val[comp[get_idx(x)]].ss;
    cout << a << " " << b << endl;
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

