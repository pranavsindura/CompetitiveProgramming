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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

int colour[MAXN];

void dfs(int u, int par, vector<vector<int>> &adj)
{
    colour[u] = colour[par] % 2 + 1;
    for(int v : adj[u])
        if(!colour[v])
            dfs(v, u, adj);
}

void cp()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 0, u, v; i < n - 1; i++)
        cin >> u >> v, adj[u].pb(v), adj[v].pb(u);

    dfs(1, 0, adj);

    vector<int> cnt(3);
    for(int i = 1; i <= n; i++)
        cnt[colour[i]]++;
    ll ans = cnt[1] * 1LL * cnt[2] - n + 1;
    cout << ans << endl;
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