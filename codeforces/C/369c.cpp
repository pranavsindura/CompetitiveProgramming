#include<bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e5 + 5;
map<pi, bool> broken_road;
vector<vector<int>> adj(MAXN);
vector<int> need_repair;
bool vis[MAXN];
vector<int> tour;
bool dfs(int u, int par)
{
    vis[u] = true;
    bool children_repair = false;
    for(int v : adj[u])
    {
        if(!vis[v])
        {
            bool did_my_child = dfs(v, u);
            children_repair = children_repair | did_my_child;
        }
    }
    tour.pb(u);
    if(children_repair)
        return children_repair;
    if(broken_road[ {u, par} ])
    {
        need_repair.pb(u);
        return true;
    }
    else
        return false;
}

void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        adj[a].pb(b);
        adj[b].pb(a);
        if(t == 2)
            broken_road[ {a, b} ] = true, broken_road[ {b, a} ] = true;
    }
    dfs(1, 0);
    cout << sz(need_repair) << endl;
    for(int x : need_repair)
        cout << x << " ";
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