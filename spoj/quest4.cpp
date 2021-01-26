#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 240 + 5;


vector<int> mt;
vector<bool> vis;

bool kuhn(int u, vector<vector<int>> &adj)
{
    if(vis[u]) return false;
    vis[u] = true;
    for(int v : adj[u])
    {
        if(mt[v] == -1 || kuhn(mt[v], adj)) // can find an augmenting path?
        {
            mt[v] = u;
            return true;
        }
    }
    return false;
}

void cp()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(120);
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
    }

    int match = 0;
    mt.assign(120, -1);
    for(int i = 0; i < 120; i++)
    {
        vis.assign(120, false);
        if(kuhn(i, adj))
            match++;
    }

    cout << match << endl;
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

