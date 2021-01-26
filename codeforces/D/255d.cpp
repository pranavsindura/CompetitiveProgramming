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
const int MAXN = 1e5 + 5;
ll n, x, y, c;
ll get(ll mid)
{
    ll total = 2 * (mid + 1) * (mid + 1) - (2 * mid + 1);

    ll topd = n - y;
    if(topd < mid)
        total -= (mid - topd) * (mid - topd);

    ll botd = y - 1;
    if(botd < mid)
        total -= (mid - botd) * (mid - botd);

    ll rightd = n - x;
    if(rightd < mid)
        total -= (mid - rightd) * (mid - rightd);

    ll leftd = x - 1;
    if(leftd < mid)
        total -= (mid - leftd) * (mid - leftd);

    ll k = mid - 1;
    if(topd < mid && rightd < mid)
    {
        k -= topd + rightd;
        k = max(k, 0LL);
        total += k * (k + 1) / 2;
    }

    k = mid - 1;
    if(topd < mid && leftd < mid)
    {
        k -= topd + leftd;
        k = max(k, 0LL);
        total += k * (k + 1) / 2;
    }

    k = mid - 1;
    if(botd < mid && leftd < mid)
    {
        k -= botd + leftd;
        k = max(k, 0LL);
        total += k * (k + 1) / 2;
    }

    k = mid - 1;
    if(botd < mid && rightd < mid)
    {
        k -= botd + rightd;
        k = max(k, 0LL);
        total += k * (k + 1) / 2;
    }

    return total;
}

void cp()
{
    cin >> n >> x >> y >> c;
    if(c == 1)
    {
        cout << 0 << endl;
        return;
    }
    ll ans = -1;
    ll lo = 1, hi = 1e9;
    while(lo <= hi)
    {
        ll mid = (lo + hi) >> 1;
        ll total = get(mid);

        if(total >= c)
            ans = mid, hi = mid - 1;
        else
            lo = mid + 1;
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

