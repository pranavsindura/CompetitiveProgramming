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
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 2e3 + 5;

vector<vector<int>> adj(MAXN);
bool ok;
int colour[MAXN];

void dfs(int u, int par_colour)
{
    colour[u] = par_colour % 2 + 1;
    for(int v : adj[u])
    {
        if(!colour[v])
            dfs(v, colour[u]);
        else if(colour[u] == colour[v])
            ok = false;
    }
}

void cp()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        adj[i].clear();

    for(int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        adj[u - 1].pb(v - 1);
        adj[v - 1].pb(u - 1);
    }
    fill(colour, colour + n, 0);
    ok = true;
    for(int i = 0; i < n; i++)
        if(!colour[i])
            dfs(i, 0);
    cout << (ok ? "No suspicious bugs found!\n" : "Suspicious bugs found!\n");
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Scenario #" << i << ":\n";
        cp();
    }
    return 0;
}