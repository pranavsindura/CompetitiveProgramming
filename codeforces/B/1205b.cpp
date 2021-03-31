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

int best;
int bfs(int S, int T, vector<vector<int>> adj)
{
    int n = sz(adj);
    vector<bool> vis(n);
    queue<pi> q;
    q.push({S, 0});
    while(!q.empty())
    {
        pi u = q.front();
        q.pop();
        if(u.ss + 1 >= best) continue;
        if(u.ff == T) return u.ss;
        vis[u.ff] = 1;
        for(int v = 0; v < n; v++)
            if(adj[u.ff][v] && !vis[v])
                q.push({v, u.ss + 1}), vis[v] = 1;
    }
    return inf;
}

void cp()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;
    sort(allr(arr));
    while(!arr.empty() && arr.back() == 0) arr.pop_back();
    n = sz(arr);
    vector<int> cnt(63);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 63; j++)
            cnt[j] += (arr[i] >> j) & 1;
    if(count_if(all(cnt), [&](int x){return x >= 3;})) cout << 3 << endl;
    else
    {
        vector<vector<int>> adj(n, vector<int>(n));
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(arr[i] & arr[j])
                    adj[i][j] = adj[j][i] = 1;

        best = inf;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(arr[i] & arr[j])
                {
                    adj[i][j] = adj[j][i] = 0;
                    best = min(best, bfs(i, j, adj) + 1);
                    adj[i][j] = adj[j][i] = 1;
                }

        if(best == inf) best = -1;
        cout << best << endl;
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
