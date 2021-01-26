#include <bits/stdc++.h>
#define ll long long int
#define all(arr) arr.begin(), arr.end()
using namespace std;

int main()
{
    int n, c;
    cin >> n >> c;
    vector<int> a(n), b(n);
    for (int i = 0; i < n - 1; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
        cin >> b[i];
    int dp[n][2];
    dp[0][0] = 0;
    dp[0][1] = c;
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = min(dp[i - 1][0] + a[i - 1], dp[i - 1][1] + a[i - 1]);
        dp[i][1] = min(dp[i - 1][1] + b[i - 1], dp[i - 1][0] + c + b[i - 1]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << min({dp[i][0], dp[i][1]}) << " ";
    }
}