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
    vector<vector<int>> adj(n, vector<int>(n));
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    vector<int> nodes(n);
    iota(all(nodes), 0);
    int ITR = 100;
    vector<int> ans;
    bool ok = false;
    while(ITR-- && !ok)
    {
        random_shuffle(all(nodes));
        int half = n / 2;
        int pairs = 0;
        for(int i = 0; i < half; i++)
            for(int j = i + 1; j < half; j++)
                pairs += adj[nodes[i]][nodes[j]];
        for(int i = half; i < n; i++)
            for(int j = i + 1; j < n; j++)
                pairs += adj[nodes[i]][nodes[j]];
        if(pairs * 2 <= m)
            ok = true, ans = nodes;
    }

    if(ok)
    {
        int half = (n + 1) / 2;
        cout << half << endl;
        for(int i = n - half; i < n; i++)
            cout << ans[i] + 1 << " ";
        cout << endl;
    }
    else
        cout << "Impossible\n\n";
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        cp();
    }
    return 0;
}
