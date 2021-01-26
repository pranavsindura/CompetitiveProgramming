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
const int MAXN = 5e3 + 5;

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
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    vector<pi> edges;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(arr[i] != arr[j])
                edges.pb({i, j});

    make_set(n);
    vector<int> tree;
    for(int i = 0; i < sz(edges); i++)
    {
        if(union_set(edges[i].ff, edges[i].ss))
            tree.pb(i);
    }

    cout << "TREE: ";
    for(int x : tree)
        cout << x << " ";
    cout << endl;

    if(sz(tree) < n - 1)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        for(int i : tree)
            cout << edges[i].ff + 1 << " " << edges[i].ss + 1 << endl;
    }
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