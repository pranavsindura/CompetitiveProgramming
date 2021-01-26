#include <bits/stdc++.h>
#define ll long long int
#define all(arr) arr.begin(), arr.end()
using namespace std;

int main()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll dp[n][3];
    dp[0][0] = arr[0];
    dp[0][1] = x * arr[0];
    dp[0][2] = arr[0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
        dp[i][1] = max({dp[i - 1][1] + x * arr[i], x * arr[i], dp[i - 1][0] + x * arr[i]});
        dp[i][2] = max({dp[i - 1][1] + arr[i], arr[i], dp[i - 1][2] + arr[i]});
    }
    ll ans = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        ans = max({dp[i][0], dp[i][1], dp[i][2], ans});
    }
    ans = max(ans, 0LL);
    cout << ans;
}