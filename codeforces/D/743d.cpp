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
ll arr[MAXN];
ll subtree[MAXN];
vector<vector<int>> adj(MAXN);
ll mxsum = LLONG_MIN;

pair<ll, ll> mxsubtree(int u, int par)
{
    ll ans = LLONG_MIN;
    ll mxatme = arr[u];
    ll extra = 0;
    for(int v : adj[u])
    {
        if(v == par)
            continue;
        pair<ll, ll> child = mxsubtree(v, u);
        ans = max(ans, child.ff);
        extra += child.ss;
    }
    mxatme += extra;
    ans = max(ans, mxatme);
    subtree[u] = ans;
    return {ans, mxatme};
}

void dfs(int u, int par)
{
    vector<ll> child;
    for(int v : adj[u])
    {
        if(v == par)
            continue;
        dfs(v, u);
        child.pb(subtree[v]);
    }
    sort(allr(child));
    if(sz(child) > 1)
        mxsum = max(mxsum, child[0] + child[1]);
}

void cp()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    mxsubtree(1, 0);
    dfs(1, 0);
    if(mxsum == LLONG_MIN)
        cout << "Impossible\n";
    else
        cout << mxsum << endl;
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