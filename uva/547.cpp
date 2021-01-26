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
const int MAXN = 3e3 + 5;

vector<int> adj(MAXN, -1);
vector<bool> vis(MAXN), instack(MAXN);
vector<int> factor_digit_sum(MAXN), subtree(MAXN);

int dfs(int u)
{
    vis[u] = 1;
    instack[u] = 1;
    subtree[u] = 1;

    if(!vis[adj[u]]) subtree[u] += dfs(adj[u]);
    else if(instack[adj[u]]) {} // ignore
    else subtree[u] += subtree[adj[u]];

    instack[u] = 0;
    return subtree[u];
}

void gen_path(int u, vector<int> &path)
{
    vis[u] = 1;
    path.pb(u);
    if(!vis[adj[u]])
        gen_path(adj[u], path);
}

void init()
{
    for(int i = 1; i < MAXN; i++)
    {
        for(int j = 1; j <= sqrt(i); j++)
        {
            if(i % j) continue;
            int p = j;
            while(p) factor_digit_sum[i] += p % 10, p /= 10;
            p = i / j;
            if(p == j) continue;
            while(p) factor_digit_sum[i] += p % 10, p /= 10;
        }
        adj[i] = factor_digit_sum[i];
        assert(~adj[i]);
    }

    for(int i = 1; i < MAXN; i++)
        if(!vis[i])
            dfs(i);
}

void cp()
{
    init();
    int tc = 1;
    int l, r;
    while(cin >> l >> r)
    {
        int mx = -1, best = -1;
        for(int i = min(l, r); i <= max(l, r); i++)
            if(subtree[i] > mx)
                mx = subtree[i], best = i;

        vis.assign(MAXN, false);
        vector<int> path;
        gen_path(best, path);
        cout << "Input" << tc << ": " << l << " " << r << endl;
        cout << "Output" << tc << ": ";
        for(int x : path) cout << x << " \n"[x == path.back()];
        tc++;
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

