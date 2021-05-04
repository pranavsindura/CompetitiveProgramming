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
using pi = pair<ll, ll>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 2e5 + 5;

ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}

map<pi, int> comp;
int get_idx(pi a)
{
    if(!comp.count(a))
        comp[a] = sz(comp) - 1;
    return comp[a];
}

bool vis[MAXN], vis2[2 * MAXN];
map<int, vector<pi>> adj;
vector<array<int, 2>> group;

int dfs(int u)
{
    if(vis2[u]) return -1;
    vis2[u] = 1;
    vector<int> rem;
    for(auto &e : adj[u])
    {
        int v = e.ff, w = e.ss;
        if(vis[w]) continue;
        vis[w] = 1;
        int c = dfs(v);
        if(~c) group.push_back({c, w});
        else rem.push_back(w);
    }

    while(sz(rem) > 1)
    {
        int a = rem.back();
        rem.pop_back();
        int b = rem.back();
        rem.pop_back();
        group.push_back({a, b});
    }
    if(rem.empty()) return -1;
    else return rem.back();
}

void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        // (a/b, c/d)
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        // (a/b+1, c/d)
        // ((a + b)/b, c/d)
        // dy/dx = c/d * b/(a + b)
        ll y1 = c * b;
        ll x1 = d * (a + b);
        ll g = gcd(x1, y1);
        y1 /= g, x1 /= g;
        // (a/b, c/d+1)
        // (a/b, (c + d)/d)
        // dy/dx = (c + d)/d * b/a
        ll y2 = (c + d) * b;
        ll x2 = d * a;
        g = gcd(x2, y2);
        y2 /= g, x2 /= g;
        adj[get_idx(mp(x1, y1))].push_back({get_idx(mp(x2, y2)), i});
        adj[get_idx(mp(x2, y2))].push_back({get_idx(mp(x1, y1)), i});
    }

    for(int i = 0; i < sz(comp); i++)
        if(!vis2[i])
            dfs(i);

    cout << sz(group) << endl;
    for(auto v : group)
        cout << v[0] + 1 << " " << v[1] + 1 << endl;
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
