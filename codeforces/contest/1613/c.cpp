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
    int n;
    ll h;
    cin >> n >> h;
    vector<ll> A(n);
    for(ll &x : A)
        cin >> x;

    ll ans = -1;
    ll lo = 0, hi = 1e18;
    while(lo <= hi)
    {
        ll mid = (lo + hi) >> 1;
        ll damage = 0;
        ll from = 1, to = 0;
        for(ll p : A)
        {
            to = min(to, p - 1);
            damage += to - from + 1;
            from = p;
            to = p + mid - 1;
        }
        damage += to - from + 1;
        if(damage >= h) ans = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    assert(~ans);
    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}
