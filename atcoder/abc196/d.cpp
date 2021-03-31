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

ll dp[10][1 << 16];
int n, m;
ll solve(int a, int mask)
{
    if(a == 0) return 1;
    ll &ret = dp[a][mask];
    if(~ret) return ret;
    ll ans = 0;
    // place a as 1x2
    for(int i = 0; i < n && a > 0; i++)
        for(int j = 0; j < m - 1; j++)
            if(((mask >> (i * m + j)) & 1) && ((mask >> (i * m + j + 1)) & 1))
                ans += solve(a - 1, mask ^ (1 << (i * m + j)) ^ (1 << (i * m + j + 1)));
    // place a as 2x1
    for(int i = 0; i < n - 1 && a > 0; i++)
        for(int j = 0; j < m; j++)
            if(((mask >> (i * m + j)) & 1) && ((mask >> ((i + 1) * m + j)) & 1))
                ans += solve(a - 1, mask ^ (1 << (i * m + j)) ^ (1 << ((i + 1) * m + j)));
    return ans;
}


void cp()
{
    int a, b;
    cin >> n >> m >> a >> b;
    clr(dp, -1);
    ll ans = solve(a, (1 << (n * m)) - 1);
    for(int i = 1; i <= a; i++)
        ans /= i;
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
