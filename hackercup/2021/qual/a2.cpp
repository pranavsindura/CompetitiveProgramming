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

void cp()
{
    string s;
    cin >> s;

    vector<vector<int>> adj(26, vector<int>(26, inf));
    for(int i = 0; i < 26; i++) adj[i][i] = 0;

    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        char u, v;
        cin >> u >> v;
        adj[u - 'A'][v - 'A'] = 1;
    }

    for(int k = 0; k < 26; k++)
        for(int i = 0; i < 26; i++)
            for(int j = 0; j < 26; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    int ans = inf;
    for(char make = 'A'; make <= 'Z'; make++)
    {
        int cnt = 0;
        for(char x : s)
            cnt += adj[x - 'A'][make - 'A'];
        ans = min(ans, cnt);
    }
    if(ans >= inf) ans = -1;
    cout << ans << endl;
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
