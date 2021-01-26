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
const int MAXN = 1e5 + 5;



vector<vector<int>> adj;
bool vis[MAXN];
void topsort(int u, vector<int> &top)
{
    vis[u] = 1;
    for(int v : adj[u])
        if(!vis[v])
            topsort(v, top);
    top.pb(u);
}


/*
Assuming DAG
BS on k
there should be a unique topological order
find topological order using first k edges
every adjacent pair must have an edge between them
*/
void cp()
{
    int n, m;
    cin >> n >> m;

    adj.resize(n);

    vector<pi> edges(m);
    for(pi &e : edges)
        cin >> e.ff >> e.ss, e.ff--, e.ss--;

    int ans = -1, lo = 0, hi = m - 1;

    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;

        for(int i = 0; i < n; i++)
            adj[i].clear();
        map<pi, bool> present;

        for(int i = 0; i <= mid; i++)
            adj[edges[i].ff].pb(edges[i].ss), present[edges[i]] = 1;

        fill(vis, vis + n, false);

        vector<int> top;
        for(int i = 0; i < n; i++)
            if(!vis[i])
                topsort(i, top);
        reverse(all(top));

        bool can = true;
        for(int i = 0; i < n - 1; i++)
            if(!present.count(mp(top[i], top[i + 1])))
                can = false;

        if(can)
            ans = mid + 1, hi = mid - 1;
        else
            lo = mid + 1;
    }
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