#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long int power(long long int x, long long int y, long long int p)
{
    long long int res = 1;

    x = x % p;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;

        y = y / 2;
        x = (x * x) % p;
    }
    return res;
}

long long int modinv(long long int n, long long int p)
{
    return power(n, p - 2, p);
}

long long int ncr(long long int n, long long int r, long long int p)
{
    if (r == 0)
        return 1;

    long long int fac[n + 1];
    fac[0] = 1;
    for (long long int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % p;

    return (fac[n] * modinv(fac[r], p) % p *
            modinv(fac[n - r], p) % p) %
           p;
}

int main()
{
    long long int k, n, distinct = 0;
    cin >> n >> k;
    long long int arr[n];
    map<long long int, long long int> m;
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (!m[arr[i]])
            distinct++;
        m[arr[i]]++;
    }
    long long int res = 0;
    long long int mat[distinct], post[distinct + 2], dis[distinct];
    map<long long int, long long int>::iterator it = m.begin();
    for (long long int i = 0; i < distinct; ++i)
    {
        dis[i] = it->first;
        it++;
    }
    if (distinct == n)
    {
        long long int p = 0;
        for (long long int i = 0; i <= k; i++)
        {
            p += ncr(n, i, mod);
            p %= mod;
        }
        cout << p;
    }
    else if(k<distinct)
    {
        if (k >= 0)
            res += 1;
        if (k >= 1)
        {
            // map<int, int>::reverse_iterator it = m.rbegin();
            post[distinct] = 0;
            for (long long int j = distinct - 1; j >= 0; j--)
            {
                post[j] = (m[dis[j]] + post[j + 1]) % mod;
                // it++;
            }
            res += post[0];
            res %= mod;
            for (long long int i = 2; i <= k; i++)
            {

                for (long long int j = 0; j < distinct; j++)
                {
                    mat[j] = ((m[dis[j]]) % mod * (post[j + 1]) % mod) % mod;
                }
                post[distinct] = 0;
                for (long long int j = distinct - 1; j >= 0; j--)
                {
                    post[j] = (mat[j] + post[j + 1]) % mod;
                }
                res += post[0];
                res %= mod;
            }
        }
        cout << res;
    }
    else
    {
        long long int res = 1;
        for (auto i : m)
        {
            res = (res * (i.second + 1)) % mod;
        }
        cout << res;
    }
    // for (int i = 0; i < distinct; i++)
    //     cout << post[i] << " ";
    // if (distinct == n)
    // {
    //     long long int p = 0;
    //     for (long long int i = 0 ; i <= k; i++)
    //     {
    //         p += ncr(n, i, mod);
    //         p%=mod;
    //     }
    //     cout << p;
    // }
    // else if(k<distinct)
    // {
    //     long long int p = 1;
    //     for (auto i : m)
    //     {
    //         p = (p * (i.second + 1)) % mod;
    //     }
    //     long long int q = 0;
    //     for(int i = 2;i<=k;i++)
    //     {
    //         long long int r = 1;
    //         int t=distinct;
    //         for(int j=i;j>=0;j--,t--)
    //         {
    //             r *= t;
    //             r%=mod;
    //         }
    //         q += r;
    //         q%=mod;
    //     }
    //     cout<<(p%mod - q%mod)%mod;

    // }
    // else
    // {
    //     for (auto i : m)
    //     {
    //         res = (res * (i.second + 1)) % mod;
    //     }
    //     cout << res;
    // }
    return 0;
}