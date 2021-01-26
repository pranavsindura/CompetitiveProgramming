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
const int MAXN = 1e6 + 5;
int n, m;
int topsort[MAXN];
int pos;
bool vis[MAXN], instack[MAXN];
bool cyc;

void topological_order(int u, vector<vector<int>> &adj)
{
    vis[u] = true;
    instack[u] = true;
    for(int v : adj[u])
        if(!vis[v])
            topological_order(v, adj);
        else if(instack[v])
            cyc = true;
    instack[u] = false;
    topsort[pos++] = u;
}

void cp()
{
    while(cin >> n >> m && n + m)
    {
        vector<vector<int>> adj(n + 1);
        for(int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            // a on top of b
            adj[b].pb(a);
        }
        fill(vis + 1, vis + n + 1, false);
        fill(instack + 1, instack + n + 1, false);
        cyc = false;
        pos = 0;
        for(int i = 1; i <= n; i++)
            if(!vis[i])
                topological_order(i, adj);
        if(cyc)
        {
            cout << "IMPOSSIBLE\n";
        }
        else
        {
            for(int i = 0; i < pos; i++)
                cout << topsort[i] << endl;
        }
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