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

ll sum(ll l, ll r)
{
    return r * (r + 1) / 2 - l * (l - 1) / 2;
}

void cp()
{
    ll n;
    int tc = 0;
    while(cin >> n && n)
    {
        ll ans = 0, d = 2;
        while(d <= n)
        {
            ll lo = d, hi = n;
            ll x = d;
            while(lo <= hi)
            {
                ll mid = (lo + hi) >> 1;
                if(n / d == n / mid) x = mid, lo = mid + 1;
                else hi = mid - 1;
            }
            // all numbers from d to x have are divisors of n/d numbers
            // ans += (n / d - 1) * sum(d, x)
            ans += (n / d  - 1) * sum(d, x);
            d = x + 1;
        }
        cout << "Case " << ++tc << ": " << ans << endl;
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
