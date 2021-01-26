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
const int MAXN = 2e5 + 5;

int people[MAXN], leaf[MAXN];
ll subtree[MAXN];

void cp()
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for(int i = 2, x; i <= n; i++)
        cin >> x, adj[x].pb(i);
    for(int i = 1; i <= n; i++)
        cin >> people[i];

    bool ok = true;
    function<ll(int)> dfs = [&](int u)
    {
        bool isLeaf = true;
        ll ans = 0;
        for(int v : adj[u])
        {
            ans = max(ans, dfs(v));
            leaf[u] += leaf[v];
            subtree[u] += subtree[v];
            isLeaf = false;
        }

        leaf[u] += isLeaf;
        subtree[u] += people[u];

        ans = max(ans, (subtree[u] + leaf[u] - 1) / leaf[u]);
        return ans;
    };

    cout << dfs(1) << endl;

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