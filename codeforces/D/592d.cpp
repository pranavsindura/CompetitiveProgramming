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

vector<vector<int>> adj;
vector<int> attack, city, subattack, subdepth;

int subtree_attack(int u, int par)
{
    subattack[u] = attack[u];
    for(int v : adj[u])
        if(v != par)
            subattack[u] += subtree_attack(v, u);
    return subattack[u];
}

int subtree_depth(int u, int par)
{
    subdepth[u] = 0;
    for(int v : adj[u])
        if(v != par && subattack[v])
            subdepth[u] += 1 + subtree_depth(v, u);
    return subdepth[u];
}

int bfs(int S)
{
    queue<vector<int>> q;
    q.push({S, -1, 0});
    int mxd = 0, leaf = S;
    while(!q.empty())
    {
        vector<int> nd = q.front();
        q.pop();
        int u = nd[0], par = nd[1], d = nd[2];
        if(d > mxd || (d == mxd && u < leaf)) mxd = d, leaf = u;
        for(int v : adj[u])
            if(v != par && subattack[v])
                q.push({v, u, d + 1});
    }
    return leaf;
}

int dfs(int u, int par)
{
    int ans = inf;
    int total = 0;
    vector<int> child;
    for(int v : adj[u])
        if(v != par && subattack[v])
            child.push_back(v), total += subdepth[v] + 1;

    if(child.empty()) return 0;

    for(int v: child)
    	ans = min(ans, 1 + dfs(v, u) + 2 * (total - subdepth[v] - 1));

    return ans;
}

void cp()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for(int i = 0, u, v; i < n - 1; i++)
        cin >> u >> v, u--, v--, adj[u].push_back(v), adj[v].push_back(u);
    attack.resize(n);
    for(int i = 0, x; i < m; i++)
        cin >> x, x--, attack[x] = 1, city.push_back(x);

    subattack.assign(n, 0);
    subtree_attack(city[0], -1);

    int R = bfs(city[0]);

    subattack.assign(n, 0);
    subtree_attack(R, -1);

    int L = bfs(R);

    subattack.assign(n, 0);
    subtree_attack(L, -1);

    L = min(L, bfs(L));

    subdepth.assign(n, 0);
    subtree_depth(L, -1);

    int ans = dfs(L, -1);

    cout << L + 1 << endl;
    cout << ans << endl;
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
