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
const int MAXN = 2e5 + 5;

// Factorial
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

void cp()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cnt(n + 1);
    for(int i = 0, x; i < n; i++)
        cin >> x, cnt[x]++;

    for(int i = 1; i <= n; i++)
        cnt[i] += cnt[i - 1];

    ll ans = 0;

    for(int i = 1; i <= n; i++)
    {
        if(!cnt[i]) continue;
        int r = i + k;
        r = min(r, n);
        int have = cnt[r] - cnt[i - 1];
        ans = (ans + ncr(have, m)) % mod;
        have = cnt[r] - cnt[i];
        ans = (ans - ncr(have, m) + mod) % mod;
    }

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

