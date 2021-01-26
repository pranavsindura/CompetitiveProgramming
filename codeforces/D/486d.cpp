#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define mt make_tuple
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
const int MAXN = 1e6 + 5;

int d, n;
vector<vector<int>> adj;
vector<int> a;
vector<ll> ans;

void dfs2(int u, int p, int root)
{
    ans[u] = 1;
    for(int v : adj[u])
    {
        if(v != p)
        {
            if(a[root] <= a[v] && a[v] <= a[root] + d)
            {
                if(a[v] == a[root] && v < root)
                    continue;
                dfs2(v, u, root);
            }
            ans[u] = (ans[u] * (ans[v] + 1)) % mod;

        }
    }
}

void cp()
{
    cin >> d >> n;
    a.resize(n), adj.resize(n), ans.resize(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    ll res = 0;
    for(int i = 0; i < n; i++)
    {
        fill(all(ans), 0);
        dfs2(i, -1, i);
        res = (res + ans[i]) % mod;
    }
    cout << res << endl;
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