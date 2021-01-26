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
const int MAXN = 100 + 5;

vector<vector<int>> adj(MAXN), rev_adj(MAXN);
vector<int> topsort;
bool vis[MAXN];
int in[MAXN], out[MAXN];
void topological_order(int u)
{
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v])
            topological_order(v);
    topsort.pb(u);
}

void dfs(int u, vector<int> &scc)
{
    vis[u] = true;
    scc.pb(u);
    for(int v : rev_adj[u])
        if(!vis[v])
            dfs(v, scc);
}

ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void cp()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        int u;
        cin >> u;
        adj[i].pb(u);
        in[u]++;
        rev_adj[u].pb(i);
    }
    // Find topological Order
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            topological_order(i);
    reverse(all(topsort));

    clr(vis, false);
    bool ok = true;
    vector<int> len;
    for(int u : topsort)
    {
        // Find SCC
        if(!vis[u])
        {
            vector<int> scc;
            dfs(u, scc);

            if(sz(scc) > 1)
            {
                int me = sz(scc);
                if(me % 2 == 0)
                    me /= 2;
                len.pb(me);
            }
            else
            {
                // if u has incoming edge, then there is self loop, which is okay, will be solvable in t=1
                // else ans is -1
                if(!in[u])
                    ok = false;
            }
        }
    }
    ll ans = 1;
    for(int x : len)
        ans = ans * x / gcd(ans, x);
    cout << (ok ? ans : -1);
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