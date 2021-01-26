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
const int MAXN = 500 + 5;

// DSU by Size
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
    int n, m, q;
    cin >> n >> m;
    vector<vector<int>> edges(m), query;
    for(auto &v : edges)
        v.resize(2), cin >> v[0] >> v[1], v[0]--, v[1]--;

    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        query.push_back({l, r, i});
    }

    vector<vector<vector<int>>> suff(m);

    make_set(n);
    for(int i = m - 1; i >= 0; i--)
    {
        union_set(edges[i][0], edges[i][1]);
        suff[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            suff[i][j].push_back(find_set(j));
            suff[i][find_set(j)].push_back(j);
        }
    }

    vector<int> ans(q);

    sort(all(query));
    reverse(all(query));

    make_set(n);
    for(int i = 0; i < m; i++)
    {
        vector<int> parent_cp(parent, parent + n);
        vector<int> sz_cp(sz, sz + n);

        while(!query.empty() && query.back()[0] == i)
        {
            int r = query.back()[1] + 1, idx = query.back()[2];
            query.pop_back();
            for(int u = 0; u < n && r < m; u++)
                for(int v : suff[r][u])
                    union_set(u, v);

            int comp = 0;
            for(int u = 0; u < n; u++)
                comp += find_set(u) == u;

            ans[idx] = comp;

            for(int u = 0; u < n; u++)
                parent[u] = parent_cp[u], sz[u] = sz_cp[u];
        }

        union_set(edges[i][0], edges[i][1]);
    }

    for(int i = 0; i < q; i++)
        cout << ans[i] << endl;
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

