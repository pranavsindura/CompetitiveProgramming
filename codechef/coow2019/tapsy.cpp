#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll dp[10000000];
ll p2[10000000];
void init()
{
    p2[0] = 1;
    for (int i = 1; i <= 1000000; i++)
        p2[i] = (2LL * (p2[i - 1] % mod)) % mod;
    fill(dp, dp + 10000000, -1);
    dp[0] = 0;
    dp[1] = 2;
    dp[2] = 5;
    // dp[3] = 13;
}
ll calc(int m)
{
    if (dp[m] != -1)
        return dp[m];
    else
    {
        ll ans = (p2[m] % mod + ((m - 1) % mod * (calc(m-2) % mod)) % mod + ((m - 2) % mod * calc(m - 3) % mod) % mod) % mod;
        return dp[m] = ans;
    }
}
int main()
{
    init();
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << calc(n) << endl;
    }
}