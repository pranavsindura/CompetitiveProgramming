#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define FASTIO                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
using namespace std;
ll fac[1000001];
ll power(ll x, ll y, ll p)
{

    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)

            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;

    }
    return res;
}



ll modInverse(ll n, ll p)
{
    return power(n, p - 2, p);
}

ll ncr(ll n, ll r, ll p)
{
    if (r == 0)
        return 1;
	else	
	    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
void init()
{
    fac[0] = 1;
    for(ll i = 1; i <= 1000000; i++)
    {
        fac[i] = (fac[i - 1] % mod * i % mod) % mod;
    }
}
int main()
{
    FASTIO;
    init();
    int t;
    cin >> t;
    while(t--)
    {
        ll n, onea = 0, oneb = 0, ans = 0;
        string a, b;
        cin >> n >> a >> b;
        for(char x : a)
        {
            if(x == '1')
                onea++;
        }
        for(char x : b)
        {
            if(x == '1')
                oneb++;
        }
        ll start = abs(onea - oneb);
        for(ll i = min(onea, oneb), j = start; i >= 0 && onea + oneb - i <= n; i--, j += 2)
        {
            ans += ncr(n, j, mod) % mod;
            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}