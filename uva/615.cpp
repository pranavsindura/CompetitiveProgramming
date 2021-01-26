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
const int MAXN = 1e6 + 5;

int parent[MAXN], sz[MAXN];

void make_set(int n)
{
    iota(parent, parent + n, 0);
    fill(sz, sz + n, 1);
}

int find_set(int v)
{
    if(v == parent[v])
        return v;
    else
        return parent[v] = find_set(parent[v]);
}

bool union_set(int a, int b)
{
    a = find_set(a), b = find_set(b);
    if(sz[a] < sz[b])
        swap(a, b);
    if(a != b)
        parent[b] = a, sz[a] += sz[b];
    return a != b;
}

void cp()
{
    int u, v;
    int tc = 0;
    while(cin >> u >> v && u >= 0 && v >= 0)
    {
        cout << "Case " << ++tc << " is";
        // no root
        if(u == 0 && v == 0)
        {
            cout << " a tree.\n";
            continue;
        }
        vector<pi> edges;
        edges.pb({u, v});
        map<int, int> comp;
        comp[u], comp[v];
        while(cin >> u >> v && u + v)
            comp[u], comp[v], edges.pb({u, v});
        int n = 0;
        for(auto &x : comp)
            x.ss = n++;
        for(pi &x : edges)
            x.ff = comp[x.ff], x.ss = comp[x.ss];
        make_set(n);
        bool ok = true;
        for(pi x : edges)
            ok &= union_set(x.ff, x.ss);
        int cnt = 0;
        for(int i = 0; i < n; i++)
            cnt += (i == find_set(i));
        ok &= (cnt == 1);
        cout << (ok ? "" : " not") << " a tree.\n";
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