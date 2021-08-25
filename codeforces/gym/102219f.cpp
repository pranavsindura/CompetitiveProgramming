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
const int MAXN = 2e3 + 5;

// x x x x x
//   o o o o o
//  -2-1 0 1 2
//   4 3 2 1 0
int n, e, k;
bool not_allowed[MAXN][MAXN];

ll dp[MAXN][1 << 10];

ll solve(int i, int mask)
{
    if(i == n) return 1;

    ll &ret = dp[i][mask];
    if(~ret) return ret;

    ll ans = 0;
    for(int p = 0; p < 2 * e + 1; p++)
        if(((mask >> p) & 1) == 0)
        {
        	if(i + e - p < 0 || i + e - p >= n) continue;
        	if(not_allowed[i][i + e - p]) continue;
            int nmask = mask;
            nmask ^= 1 << p;
            nmask &= ~(1 << (2 * e));
            nmask <<= 1;
            ans = (ans + solve(i + 1, nmask)) % mod;
        }
    return ret = ans;
}

void cp()
{
    cin >> n >> e >> k;
    for(int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        not_allowed[u][v] = true;
    }
    clr(dp, -1);
    int mask = (1 << e) - 1;
    mask <<= e + 1;
    ll ans = solve(0, mask);
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
