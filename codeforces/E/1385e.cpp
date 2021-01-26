#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 2e5 + 5;

vector<int> topsort;
bool vis[MAXN], instack[MAXN];
bool ok;
void topological_order(int u, vector<vector<int>> &adj)
{
    vis[u] = true;
    instack[u] = true;
    for(auto v : adj[u])
        if(!vis[v])
            topological_order(v, adj);
        else if(instack[v])
            ok = false;
    topsort.pb(u);
    instack[u] = false;
}

void cp()
{
    topsort.clear();
    ok = true;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1), rev_adj(n + 1);
    map<pi, bool> bi;
    vector<pi> orig;
    for(int i = 1; i <= m; i++)
    {
        int ty, u, v;
        cin >> ty >> u >> v;
        if(ty)
            orig.pb({u, v}), adj[u].pb(v), rev_adj[v].pb(u);
        if(!ty)
            bi[ {u, v}] = true;
    }
    // Find topological Order
    fill(vis + 1, vis + n + 1, false);
    fill(instack + 1, instack + n + 1, false);
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            topological_order(i, adj);
    reverse(all(topsort));

    vector<int> pos(n + 1);
    for(int i = 0; i < sz(topsort); i++)
        pos[topsort[i]] = i;


    if(!ok)
    {
        cout << "NO\n"  ;
        return;
    }

    cout << "YES\n";
    for(auto x : orig)
        cout << x.ff << " " << x.ss << endl;
    for(auto x : bi)
    {
        int u = x.ff.ff, v = x.ff.ss;
        if(pos[u] > pos[v])
            swap(u, v);
        cout << u << " " << v << endl;
    }
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