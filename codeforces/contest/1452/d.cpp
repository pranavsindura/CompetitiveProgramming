#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 998244353;
const ll inf = 1LL << 30;
const int MAXN = 2e5 + 5;

ll fpow(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}

ll inv(ll a)
{
    return fpow(a, mod - 2);
}

ll dp[MAXN][2];

int n;
ll solve(int i, int par)
{
    if(i == n)
        return par;

    ll &ret = dp[i][par];
    if(~ret)
        return ret;

    ll ans = 0;
    if(par) // prev is already odd
    {
        // end that, start new, one element -> me
        ans += solve(i + 1, 1);
        ans %= mod;
        // continue;
        ans += solve(i + 1, 0);
        ans %= mod;
    }
    else // cannot end, must continue;
    {
        ans += solve(i + 1, 1);
        ans %= mod;
    }
    return ret = ans;
}

void cp()
{
    cin >> n;
    clr(dp, -1);
    ll num = solve(0, 0);
    ll den = fpow(2, n);
    ll iden = inv(den);
    ll ans = (num % mod * iden % mod) % mod;
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