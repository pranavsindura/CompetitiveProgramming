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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

int vis[MAXN], prv[MAXN];
int find_center(vector<vector<int>> &adj, int S)
{
    int n = sz(adj);
    queue<tuple<int, int, int>> q;

    int mx_d = 0, last = S;
    q.push(make_tuple(S, S, 0));
    while(!q.empty())
    {
        int u, par, depth;
        tie(u, par, depth) = q.front();
        q.pop();
        if(depth > mx_d)
            last = u, mx_d = depth;
        for(int v : adj[u])
            if(v != par && !vis[v])
                q.push(make_tuple(v, u, depth + 1));
    }

    mx_d = 0;
    q.push(make_tuple(last, last, 0));
    while(!q.empty())
    {
        int u, par, depth;
        tie(u, par, depth) = q.front();
        q.pop();
        prv[u] = par;
        if(depth > mx_d)
            last = u, mx_d = depth;
        for(int v : adj[u])
            if(v != par && !vis[v])
                q.push(make_tuple(v, u, depth + 1));
    }

    vector<int> path;
    while(prv[last] != last)
        path.pb(last), last = prv[last];
    path.pb(last);

    return path[sz(path) / 2];
}

void cp()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0, u, v; i < n - 1; i++)
        cin >> u >> v, adj[u - 1].push_back(v - 1), adj[v - 1].push_back(u - 1);

    vector<int> rank(n);
    queue<vector<int>> q;
    q.push({0, 0});
    bool ok = true;
    while(!q.empty() && ok)
    {
        int u = q.front()[0], p = q.front()[1];
        q.pop();
        int C = find_center(adj, u);
        rank[C] = p;
        vis[C] = 1;
        ok &= p < 26;
        for(int v : adj[C])
            if(!vis[v])
                q.push({v, p + 1});
    }

    if(ok)
    {
        for(int i = 0; i < n; i++)
            cout << char(65 + rank[i]) << " ";
        cout << endl;
    }
    else
        cout << "Impossible!\n";
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
