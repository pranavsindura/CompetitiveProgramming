#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
ll dp[1000005];
void init()
{
    for (int i = 1; i <= 100005; i++)
    {
        dp[i] = i % mod;
        dp[i] = ((dp[i]) % mod * (i + 1) % mod) % mod;
        dp[i] = ((dp[i]) % mod * (i + 2) % mod) % mod;
        dp[i] = ((dp[i]) % mod * (i + 3) % mod) % mod;
        dp[i] %= mod;
    }
    for (int i = 1; i <= 100005; i++)
    {
        dp[i] = ((dp[i] % mod) + (dp[i - 1] % mod)) % mod;
        dp[i] %= mod;
    }
}
int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        cout << (dp[r] % mod - dp[l - 1] % mod + mod) % mod << endl;
    }
    return 0;
}