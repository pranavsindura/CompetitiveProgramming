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

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<set<int>> adj(n);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    // assign groups
    // pick a node not picked yet, put all nodes that are not its neighbours
    // and also not picked, in the same set
    vector<int> id(n, -1);
    for(int i = 0; i < 3; i++)
    {
        int u = -1;
        for(int v = 0; v < n && u == -1; v++)
            if(id[v] == -1) u = v;
        if(u == -1)
        {
            cout << -1 << endl;
            return;
        }
        for(int v = 0; v < n; v++)
            if(id[v] == -1 && !adj[u].count(v))
                id[v] = i;
    }

    if(count(all(id), -1) > 0)
    {
        cout << -1 << endl;
        return;
    }

    // verify if this is a solution
    // every set must have edges to other set
    vector<set<int>> group(3);
    for(int u = 0; u < n; u++)
        group[id[u]].insert(u);

    int cnt = 0;
    for(int i = 0; i < 3; i++)
        for(int j = i + 1; j < 3; j++)
            for(int u : group[i])
                for(int v : group[j])
                {
                    if(adj[u].count(v)) cnt++;
                    else
                    {
                        cout << -1 << endl;
                        return;
                    }
                }

    if(cnt != m)
    {
        cout << -1 << endl;
        return;
    }
    // hope jury doesnt find a solution
    for(int x : id)
        cout << x + 1 << " ";
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
