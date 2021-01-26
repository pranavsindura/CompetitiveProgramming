#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
ll dp[1000000][3];
int main()
{
    FASTIO;
    ll n, l, r;
    cin >> n >> l >> r;
    ll count[3];
    for(ll i = 0; i < 3; i++)
    {
        ll b = floor((double(r-i) - double(i)) / 3.0) * 1LL;
        ll a = ceil((double(l-i) - double(i)) / 3.0) * 1LL;
        count[i] = max(0LL, b - a + 1);
    }
    dp[1][0] = count[0];
    dp[1][1] = count[1];
    dp[1][2] = count[2];
    for(int i = 2; i <= n; i++)
    {
        dp[i][0] = ((dp[i - 1][0] % mod * count[0] % mod) % mod + (dp[i - 1][1] % mod * count[2] % mod) % mod + (dp[i - 1][2] % mod * count[1] % mod) % mod) % mod;
        dp[i][1] = ((dp[i - 1][0] % mod * count[1] % mod) % mod + (dp[i - 1][1] % mod * count[0] % mod) % mod + (dp[i - 1][2] % mod * count[2] % mod) % mod) % mod;
        dp[i][2] = ((dp[i - 1][0] % mod * count[2] % mod) % mod + (dp[i - 1][2] % mod * count[0] % mod) % mod + (dp[i - 1][1] % mod * count[1] % mod) % mod) % mod;
    }
    cout << dp[n][0];
    return 0;
}