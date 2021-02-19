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
    vector<array<ll, 2>> arr(n);
    vector<vector<int>> adj(n);
    for(auto &v : arr)
        cin >> v[0] >> v[1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> idx(n);
    iota(all(idx), 0);
    sort(all(idx), [&](int a, int b)
    {
        return arr[a][0] - arr[a][1] < arr[b][0] - arr[b][1];
    });

    vector<ll> X(n), Y(n), val(n);
    for(int i = 0; i < n; i++)
        X[i] = arr[idx[i]][0], Y[i] = arr[idx[i]][1], val[i] = X[i] - Y[i];
    partial_sum(all(X), X.begin());
    partial_sum(all(Y), Y.begin());

    vector<ll> ans(n);
    for(int i = 0; i < n; i++)
    {
        int p = lower_bound(all(val), arr[i][0] - arr[i][1]) - begin(val);
        ans[i] += (n - p) * arr[i][0] + Y[n - 1] - (p ? Y[p - 1] : 0);
        ans[i] -= arr[i][0] + arr[i][1];
        ans[i] += p * arr[i][1] + (p ? X[p - 1] : 0);
    }

    for(int i = 0; i < n; i++)
    {
        vector<ll> XY(sz(adj[i]), arr[i][0]), YX(sz(adj[i]), arr[i][1]);
        for(int j = 0; j < sz(adj[i]); j++)
            XY[j] += arr[adj[i][j]][1];
        for(int j = 0; j < sz(adj[i]); j++)
            YX[j] += arr[adj[i][j]][0];
        for(int j = 0; j < sz(adj[i]); j++)
            ans[i] -= min(XY[j], YX[j]);
    }

    for(ll x : ans)
        cout << x << " ";
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
