#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;

ll f(ll x)
{
    return x * (x + 1) / 2;
}
void hehe()
{
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = 0;
    if (a > b)
    {
        swap(a, b);
    }
    a--;
    b--;
    ll diff = b - a;
    ll x = 0, y = 0;
    x = min(diff, n);
    n -= x;
    if (n % 2 == 0)
    {
        x += n / 2;
        y += n / 2;
    }
    else
    {
        x += n / 2;
        x++;
        y += n / 2;
    }
    ans = f(a + x) - f(a) + f(b + y) - f(b);
    // cout << a << " " << x << " " << b << " " << y << endl;
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        hehe();
    }

    return 0;
}