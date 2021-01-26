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
const int MAXN = 60 + 5;

int parent[MAXN], sz[MAXN];

void make_set()
{
    iota(parent, parent + MAXN, 0);
    fill(sz, sz + MAXN, 1);
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
    int n, m;
    while(cin >> n >> m)
    {
        vector<pair<char, char>> temp;
        vector<pi> edges;
        map<char, int> comp;
        for(int i = 0; i < m; i++)
        {
            char u, v;
            cin >> u >> v;
            comp[u], comp[v];
            temp.pb({u, v});
        }
        int idx = 0;
        for(auto &x : comp)
            x.ss = idx++;
        for(auto e : temp)
            edges.pb({comp[e.ff], comp[e.ss]});
        make_set();
        int count = 1;
        for(pi e : edges)
            if(!union_set(e.ff, e.ss))
                count++;
        cout << count << endl;
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