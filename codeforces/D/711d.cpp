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
const int MAXN = 2e5 + 5;
vector<int> adj, cycle;
int vis[MAXN];

void dfs2(int u)
{
    // find cycle
    cycle.back()++;
    vis[u] = 3;
    if(vis[adj[u]] == 3)
        return;
    else
        dfs2(adj[u]);
}

void dfs(int u)
{
    vis[u] = 1;
    if(vis[adj[u]] == 0)
        dfs(adj[u]);
    else if(vis[adj[u]] == 1)
    {
        //it is in stack
        cycle.pb(0);
        dfs2(u);
    }
    vis[u] = 2;
}

ll fpow(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (res % mod * x % mod) % mod;
        x = (x % mod * x % mod) % mod;
        y >>= 1;
    }
    return res;
}

void cp()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> adj[i];
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
            dfs(i);
    }
    ll ans = 1;
    ll total = n;
    for(int x : cycle)
    {
        total -= x;
        ll me = (fpow(2, x) - 2 + mod) % mod;
        ans = (ans * me) % mod;
    }
    ans = (ans * fpow(2, total)) % mod;
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