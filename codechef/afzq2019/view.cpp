#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define FASTIO                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
using namespace std;
ll g, x, y;
void gcd(ll a, ll b)
{
    if (b == 0)
    {
        g = a;
        x = 1;
        y = 0;
    }
    else
    {
        gcd(b, a % b);
        ll temp = x;
        x = y;
        y = temp - (a / b) * y;
    }
}
ll sol(ll a, ll b, ll d)
{
    ll m = d / g;
    ll left = ceil(double(-x * m) * double(g) / double(b));
    ll right = floor(double(y * m) * double(g) / double(a));
    if (left <= right)
        return (right - left + 1);
    else
        return 0LL;
}
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while (t--)
    {
        ll h1, h2;
        cin >> h1 >> h2;
        gcd(h1, h2);
        ll ans = (h1 * h2) - (h1 + h2);
        cout << max(ans, 0LL) << endl;
    }
    return 0;
}