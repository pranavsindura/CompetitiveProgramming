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

void cp()
{
    int k;
    string s;
    cin >> s >> k;

    ll ans = 0;
    ll v = fpow(2, ln(s));
    ll u = inv((v - 1 + mod) % mod);
    ll w = (fpow(v, k) - 1 + mod) % mod;

    for(int i = 0; i < ln(s); i++)
    {
        if(s[i] == '0' || s[i] == '5')
        {
            ll a = fpow(2, i);
            a = (a * w) % mod;
            a = (a * u) % mod;
            ans = (ans + a) % mod;
        }
    }
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

