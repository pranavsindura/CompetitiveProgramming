#include <bits/stdc++.h>
#define  ll        long long int
#define  ld        long double
#define  pi        pair<int,int>
#define  all(x)    x.begin(), x.end()
#define  allr(x)   x.rbegin(), x.rend()
#define  sz(x)     ((int)x.size())
#define  ln(x)     ((int)x.length())
#define  mp        make_pair
#define  pb        push_back
#define  ff        first
#define  ss        second
#define  endl      '\n'
#define  dbg(x)    cout << #x << ": " << x << endl
#define  clr(x,v)  memset(x, v, sizeof(x))
#define  dblout(x) cout << setprecision(x) << fixed;
#define  FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const ll inf = 1 << 30;
const int MAXN = 1e6 + 5;

vector<vector<int>> min_flip;
vector<vector<vector<int>>> adj;
int flipped;

void get_flipped(int u, int par)
{
    for(auto &e : adj[u])
    {
        int v = e[0], stat = e[1];
        if(v != par)
            get_flipped(v, u), flipped += stat;
    }
}

void dfs(int u, int par, int sum)
{
    min_flip[flipped - sum].pb(u);
    for(auto e : adj[u])
    {
        int v = e[0], stat = e[1];
        if(v != par)
            dfs(v, u, sum + (stat ? 1 : -1));
    }
}

void cp()
{
    int n;
    cin >> n;

    adj.resize(n + 1), min_flip.resize(n + 1);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb({v, 0});
        adj[v].pb({u, 1});
    }

    int root = -1;
    for(int i = 1; i <= n; i++)
        if(sz(adj[i]) <= 1)
            root = i;

    get_flipped(root, 0);
    dfs(root, 0, 0);

    int idx = -1;
    for(int i = 0; i < n && idx == -1; i++)
        if(!min_flip[i].empty())
            idx = i;

    sort(all(min_flip[idx]));
    cout << idx << endl;
    for(int x : min_flip[idx])
        cout << x << " ";
    cout << endl;
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