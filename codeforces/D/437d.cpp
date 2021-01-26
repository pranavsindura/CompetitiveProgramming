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
const int MAXN = 1e5 + 5;

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for(int &x : A)
        cin >> x;
    vector<vector<int>> edges(m, vector<int>(2));
    for(auto &v : edges)
        cin >> v[0] >> v[1], v[0]--, v[1]--;
    sort(all(edges), [&](vector<int> a, vector<int> b)
    {
        return min(A[a[0]], A[a[1]]) < min(A[b[0]], A[b[1]]);
    });

    int parent[n], sz[n];

    auto make_set = [&](int n)
    {
        iota(parent, parent + n, 0);
        fill(sz, sz + n, 1);
    };
    function<int(int)> find_set = [&](int v)
    {
        if(v == parent[v])
            return v;
        else
            return parent[v] = find_set(parent[v]);
    };
    auto union_set = [&](int a, int b)
    {
    	int u = a, v = b;
        a = find_set(a), b = find_set(b);
        if(sz[a] < sz[b])
            swap(a, b);
        ll val = 0;
        if(a != b)
        {
            val += sz[a] * 1LL * sz[b] * min(A[u], A[v]);
            parent[b] = a, sz[a] += sz[b];
        }
        return val;
    };

    make_set(n);

    double total = 0;

    while(!edges.empty())
    {
        auto E = edges.back();
        edges.pop_back();
        int u = E[0], v = E[1];
        total += union_set(u, v);
    }

    total /= n;
    total /= (n - 1);
    total *= 2;
    fix(10);

    cout << total << endl;
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

