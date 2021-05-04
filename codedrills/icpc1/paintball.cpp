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
const int MAXN = 1e6 + 5;

ll fact[MAXN], inv[MAXN], invfact[MAXN];
void init()
{
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fact[i] = (fact[i - 1] % mod * i % mod) % mod;
    inv[0] = inv[1] = 1;
    for(int i = 2; i < MAXN; i++)
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    invfact[0] = invfact[1] = 1;
    for(int i = 2; i < MAXN; i++)
        invfact[i] = (invfact[i - 1] * inv[i]) % mod;
}
// NCR + modular inverse
ll ncr(int n, int r)
{
    if(n < r) return 0;
    ll ans = fact[n];
    // nCr = n!/(n-r)!/r!
    // nCr = n! * inv((n-r)!) * inv(r!)
    ans = (ans % mod * invfact[n - r] % mod) % mod;
    ans = (ans % mod * invfact[r] % mod) % mod;
    return ans;
}

ll fpow(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (res % mod * x % mod) % mod;
        x = (x % mod * x % mod) % mod;
        y >>= 1;
    }
    return res;
}

ll finv(ll a)
{
    return fpow(a, mod - 2);
}

void cp()
{
    int n, k, g;
    cin >> n >> k >> g;
    ll Q = fact[n];
    Q = (Q * invfact[g]) % mod;
    Q = (Q * finv(fpow(fact[n / g], g))) % mod;

    ll P = ncr(n - k - 1, n / g - 1);
    P = (P * fact[n - n / g]) % mod;
    P = (P * invfact[g - 1]) % mod;
    P = (P * finv(fpow(fact[n / g], g - 1))) % mod;

    P = (Q - P + mod) % mod;

    ll ans = (P * finv(Q)) % mod;
    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    init();
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}
