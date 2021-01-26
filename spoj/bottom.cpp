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
    TIMER = 0;
    entry.assign(n + 1, -1), low_link.assign(n + 1, -1), comp.assign(n + 1, -1);
    instack.assign(n + 1, false);
    while(!st.empty()) st.pop();
    scc.clear();

    for(int i = 1; i <= n; i++)
        if(entry[i] == -1)
            dfs(i, adj);
}

void comp_graph(int n, vector<vector<int>> &adj)
{
    is_sink.assign(sz(scc), true);
    for(int u = 1; u <= n; u++)
        for(int v : adj[u])
            if(comp[u] != comp[v])
                is_sink[comp[u]] = false; // outgoing means no more sink
}

void cp()
{
    int n, m;
    while(cin >> n && n)
    {
        cin >> m;
        vector<vector<int>> adj(n + 1);
        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
        }

        tarjan(n, adj);
        comp_graph(n, adj);

        vector<int> res;
        for(int i = 0; i < sz(scc); i++)
            if(is_sink[i])
                for(int x : scc[i])
                    res.pb(x);
        sort(all(res));
        for(int x : res)
            cout << x << " ";
        cout << endl;
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

