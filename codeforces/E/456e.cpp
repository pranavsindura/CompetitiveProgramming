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
const int MAXN = 3e5 + 5;

// DSU by Size
int parent[MAXN], sz[MAXN], dia[MAXN];
void make_set(int n)
{
    iota(parent, parent + n, 0);
    fill(sz, sz + n, 1);
    fill(dia, dia + n, 1);
}
int find_set(int v)
{
    if(v == parent[v])
        return v;
    else
        return parent[v] = find_set(parent[v]);
}
bool is_connected(int a, int b)
{
    return find_set(a) == find_set(b);
}
bool union_set(int a, int b)
{
    a = find_set(a), b = find_set(b);
    if(sz[a] < sz[b])
        swap(a, b);
    if(a != b)
    {
        parent[b] = a, sz[a] += sz[b];
        dia[a] = max({dia[a], dia[b], (dia[a] / 2 + 1) + (dia[b] / 2 + 1)});
    }
    return a != b;
}

int get_dia(vector<vector<int>> &adj, int S)
{
    int n = sz(adj);
    map<int, bool> vis;
    queue<pi> q;
    q.push({S, 1}); // random node
    pi farthest = {S, 1};
    // BFS 1
    while(!q.empty())
    {
        pi u = q.front();
        q.pop();
        vis[u.ff] = true;
        if(u.ss > farthest.ss)
            farthest = u;
        for(int v : adj[u.ff])
        {
            if(!vis[v])
                q.push({v, u.ss + 1}), vis[v] = true;
        }
    }

    vis.clear();
    q.push({farthest.ff, 1});
    farthest.ss = 1;
    // BFS 2
    while(!q.empty())
    {
        pi u = q.front();
        q.pop();
        vis[u.ff] = true;
        if(u.ss > farthest.ss)
            farthest = u;
        for(int v : adj[u.ff])
        {
            if(!vis[v])
                q.push({v, u.ss + 1}), vis[v] = true;
        }
    }
    return farthest.ss;
}

void cp()
{
    int n, m, q;
    cin >> n >> m >> q;
    make_set(n);

    vector<vector<int>> adj(n);

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        union_set(u, v);
    }

    for(int i = 0; i < n; i++)
        if(i == find_set(i))
            dia[i] = get_dia(adj, i);

    while(q--)
    {
        int t, x, y;
        cin >> t;
        if(t == 1)
        {
            cin >> x, x--;
            cout << dia[find_set(x)] - 1 << endl;
        }
        else
        {
            cin >> x >> y, x--, y--;
            union_set(x, y);
        }
    }
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
