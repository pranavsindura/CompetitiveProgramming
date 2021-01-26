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
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

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

ll inv(ll a)
{
    return fpow(a, mod - 2);
}

array<int, MAXN> arr, cnt, Inv;
array<ll, MAXN> ans;

void init()
{
    for(int i = 0; i < MAXN; i++)
        Inv[i] = inv(i);
}

void cp()
{
    int n;
    cin >> n;
    fill(all(cnt), 0);
    for(int i = 0; i < n; i++)
        cin >> arr[i], cnt[arr[i]]++;

    fill(all(ans), 0);
    for(int i = MAXN - 1; i > 0; i--)
    {
        ll u = 0;
        for(int j = i; j < MAXN; j += i)
            u = (u + (cnt[j] * 1LL * j)) % mod;
        u = (u * u) % mod;
        ans[i] = (u * Inv[i]) % mod;
        for(int j = 2 * i; j < MAXN; j += i)
        {
            u = (ans[j] * 1LL * j) % mod;
            u = (u * Inv[i]) % mod;
            ans[i] = (ans[i] - u + mod) % mod;
        }
    }
    ll sum = 0;
    for(int i = 1; i < MAXN; i++)
        sum = (sum + ans[i]) % mod;
    cout << sum << endl;
}

int main()
{
    FASTIO;
    freopen("lcm.in", "r", stdin);
    int t;
    t = 1;
    cin >> t;
    init();
    while(t--)
    {
        cp();
    }
    return 0;
}

