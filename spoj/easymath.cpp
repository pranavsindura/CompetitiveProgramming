#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    else
        return gcd(b % a, a);
}
ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}
ll solve(ll n, ll a, ll d)
{
    ll res = 0;
    ll ap[6];
    ap[1] = a;
    ap[2] = a + 1LL * d;
    ap[3] = a + 2LL * d;
    ap[4] = a + 3LL * d;
    ap[5] = a + 4LL * d;
    for (int i = 1; i <= 5; i++)
    {
        res += (n / ap[i]);
        // cout << i << ": " << n / ap[i] << endl;
    }
    for (int i = 1; i <= 5; i++)
    {
        for (int j = i + 1; j <= 5; j++)
        {
            res -= (n / lcm(ap[i], ap[j]));
            // cout << i << ", " << j << ": " << n / lcm(ap[i], ap[j]) << endl;
        }
    }
    for (int i = 1; i <= 5; i++)
    {
        for (int j = i + 1; j <= 5; j++)
        {
            for (int k = j + 1; k <= 5; k++)
            {
                ll x = lcm(ap[i], ap[j]);
                x = lcm(x, ap[k]);
                res += (n / x);
                // cout << i << ", " << j << ", " << k << ": " << n / x << endl;
            }
        }
    }
    for (int i = 1; i <= 5; i++)
    {
        for (int j = i + 1; j <= 5; j++)
        {
            for (int k = j + 1; k <= 5; k++)
            {
                for (int l = k + 1; l <= 5; l++)
                {
                    ll x = lcm(ap[i], ap[j]);
                    x = lcm(x, ap[k]);
                    x = lcm(x, ap[l]);
                    res -= (n / x);
                    // cout << i << ", " << j << ", " << k << ", " << l << ": " << n / x << endl;
                }
            }
        }
    }
    for (int i = 1; i <= 5; i++)
    {
        for (int j = i + 1; j <= 5; j++)
        {
            for (int k = j + 1; k <= 5; k++)
            {
                for (int l = k + 1; l <= 5; l++)
                {
                    for (int m = l + 1; m <= 5; m++)
                    {
                        ll x = lcm(ap[i], ap[j]);
                        x = lcm(x, ap[k]);
                        x = lcm(x, ap[l]);
                        x = lcm(x, ap[m]);
                        res += (n / x);
                        // cout << i << ", " << j << ", " << k << ", " << l << ", " << m << ": " << n / x << endl;
                    }
                }
            }
        }
    }
    res = n - res;
    return res;
}
int main()
{
    ll t, n, m, a, d;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> a >> d;
        cout << solve(m, a, d) - solve(n - 1, a, d) << endl;
    }

    return 0;
}