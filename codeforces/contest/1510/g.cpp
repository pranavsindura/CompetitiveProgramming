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

vector<vector<int>> adj;
vector<int> subtree;

int get_subtree(int u)
{
    subtree[u] = 1;
    for(int v : adj[u])
        subtree[u] += get_subtree(v);
    return subtree[u];
}

int dp[105][105];
int dfs(int u, int k)
{
    k--;
    if(k == 0) return 0; // u itself
    int &ret = dp[u][k];
    if(~ret) return ret;
    int ans = inf;
    int T = subtree[u];
    for(int p = 1; p <= k; p++)
    {
        int me = inf;
        for(int v : adj[u])
            if(subtree[v] >= p && T - subtree[v] - 1 >= k - p)
                me = min(me, dfs(v, p));
        me += 2 * (k - p) + 1;
        ans = min(ans, me);
    }
    return ret = ans;
}

vector<int> path;

void claim(int u, int k)
{
    if(k == 0) return;
    path.push_back(u);
    k--;
    for(int v : adj[u])
    {
        int take = min(k, subtree[v]);
        if(take == 0) break;
        claim(v, take);
        path.push_back(u);
        k -= take;
    }
}

void trace(int u, int k)
{
    k--;
    if(k == 0)
    {
        path.push_back(u);
        return;   // u itself
    }
    int T = subtree[u];
    int ans = dfs(u, k + 1);
    for(int p = k; p >= 1; p--)
    {
        int me = inf, to = -1;
        for(int v : adj[u])
        {
            if(subtree[v] >= p && T - subtree[v] - 1 >= k - p && me > dfs(v, p))
                me = dfs(v, p), to = v;
        }
        me += 2 * (k - p) + 1;
        if(me == ans)
        {
            int rem = k - p;
            for(int v : adj[u])
            {
                if(v == to) continue;
                int take = min(rem, subtree[v]);
                if(take == 0) break;
                rem -= take;
                path.push_back(u);
                claim(v, take);
            }
            assert(!rem);
            path.push_back(u);
            trace(to, p);
            return;
        }
    }
    assert(false);
}

void cp()
{
    int n, k;
    cin >> n >> k;
    adj.assign(n + 1, vector<int>());
    for(int i = 2, p; i <= n; i++)
        cin >> p, adj[p].push_back(i);

    subtree.assign(n + 1, 0);
    get_subtree(1);

    clr(dp, -1);
    int len = dfs(1, k);
    path.clear();
    trace(1, k);
    cout << len << endl;
    for(int x : path)
        cout << x << " ";
    cout << endl;
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
