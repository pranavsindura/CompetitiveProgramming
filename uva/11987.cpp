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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

set<int> dsu[MAXN];
int parent[MAXN];
ll sum[MAXN];

void make_set(int n)
{
    for(int i = 1; i <= n; i++)
    {
        dsu[i].clear();
        dsu[i].insert(i);
        parent[i] = i;
        sum[i] = i;
    }
}

int find_set(int a)
{
    return parent[a];
}

bool union_set(int a, int b)
{
    a = find_set(a), b = find_set(b);
    if(a != b)
    {
        if(sz(dsu[a]) < sz(dsu[b]))
            swap(a, b);
        while(!dsu[b].empty())
        {
            int x = *dsu[b].begin();
            dsu[b].erase(dsu[b].begin());
            dsu[a].insert(x);
            parent[x] = a;
            sum[a] += x;
            sum[b] -= x;
        }
    }
    return a != b;
}

bool move_set(int a, int b)
{
    // move a to b
    int u = find_set(a), v = find_set(b);
    if(u != v)
    {
        dsu[v].insert(a);
        dsu[u].erase(a);
        parent[a] = v;
        sum[v] += a;
        sum[u] -= a;
    }
    return u != v;
}

void cp()
{
    int n, m;
    while(cin >> n >> m)
    {
        make_set(n);
        while(m--)
        {
            int t, u, v;
            cin >> t;
            if(t == 1)
            {
                cin >> u >> v;
                union_set(u, v);
            }
            else if(t == 2)
            {
                cin >> u >> v;
                move_set(u, v);
            }
            else
            {
                cin >> u;
                u = find_set(u);
                cout << sz(dsu[u]) << " " << sum[u] << endl;
            }
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