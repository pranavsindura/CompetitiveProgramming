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
const int MAXN = 2e5 + 5;
struct edge
{
    int v, status;
    edge(): v(0), status(0) {}
    edge(int v, int status): v(v), status(status) {}
};

vector<int> ans;
vector<edge> edges;
vector<vector<int>> adj(MAXN);

int dfs(int u, int len)
{
    int my_req = (len + 1) / 2;

    for(int x : adj[u])
    {
        int v = edges[x].v;
        int req = dfs(v, len + 1);
        req -= edges[x].status;
        if(req > len)
            ans.pb(x), req--;
        my_req = max(my_req, req);
    }
    return my_req;
}

void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        string type;
        int u, v, status;
        cin >> v >> u >> type;
        if(type == "almost")
            status = 0, cin >> type;
        else
            status = 1;
        adj[u].pb(i);
        edges.pb(edge(v, status));
    }
    dfs(1, 0);
    cout << sz(ans) << endl;
    for(int x : ans)
        cout << x + 1 << " ";

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