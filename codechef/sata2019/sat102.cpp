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
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        int arr[x][y];
        ll dp[x][y];
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                cin >> arr[i][j];
                dp[i][j] = arr[i][j];
            }
        }
        for (int i = 1; i < y; i++)
            dp[0][i] = dp[0][i - 1] + arr[0][i];
        for (int i = 1; i < x; i++)
            dp[i][0] = dp[i - 1][0] + arr[i][0];
        for (int i = 1; i < x; i++)
        {
            for (int j = 1; j < y; j++)
            {
                dp[i][j] += max({dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]});
            }
        }
        cout << dp[x - 1][y - 1] << endl;
    }
    return 0;
}
