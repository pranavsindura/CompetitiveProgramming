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
const int MAXN = 1e2 + 5;

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
    int n, m;
    cin >> n >> m;
    make_set(n);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        union_set(u, v);
    }
    int comp = 0;
    for(int i = 0; i < n; i++)
        comp += find_set(i) == i;
    if(n == m && n >= 3 && comp == 1)
        cout << "FHTAGN!\n";
    else
        cout << "NO\n";
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
