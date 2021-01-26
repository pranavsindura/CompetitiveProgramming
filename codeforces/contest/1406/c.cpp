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
const int MAXN = 1e6 + 5;
int n;

vector<int> Centroid(vector<vector<int>> &adj)
{
    vector<int> centroid;
    vector<int> subtree(n);
    function<void (int, int)> dfs = [&](int u, int prev)
    {
        subtree[u] = 1;
        bool is_centroid = true;
        for (auto v : adj[u]) if (v != prev)
            {
                dfs(v, u);
                subtree[u] += subtree[v];
                if (subtree[v] > n / 2) is_centroid = false;
            }
        if (n - subtree[u] > n / 2) is_centroid = false;
        if (is_centroid) centroid.push_back(u);
    };
    dfs(0, -1);
    return centroid;
}

void cp()
{
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<int> cent = Centroid(adj);
    if(sz(cent) == 1)
    {
        cout << 0 + 1 << " " << adj[0][0] + 1 << endl;
        cout << 0 + 1 << " " << adj[0][0] + 1 << endl;
        return;
    }
    int a = cent[0], b = cent[1];
    int other = -1;
    for(int v : adj[a])
        if(v != b)
            other = v;
    cout << a + 1 << " " << other + 1 << endl;
    cout << b + 1 << " " << other + 1 << endl;
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