#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007

char v[1005][1005];
int dp[2][1005];
int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    ll sum = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> v[i][j];
        }
    }
    ll b[1005] = {0};
    ll w[1005] = {0};
    ll cw = 0, cb = 0;
    for(int j = 1; j <= m; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(v[i][j] == '#')
                cb++;
            else
                cw++;
        }
        b[j] = cb;
        w[j] = cw;
    }
    dp[0][0] = 0;
    dp[1][0] = 0;
    for(int i = 1; i <= m; i++)
    {
        ll min0 = INT_MAX, min1 = INT_MAX;
        for(int j = x; j <= y; j++)
        {
            if(i - j < 0)
                continue;

            min0 = min(min0, dp[1][i - j] + w[i] - w[i - j]);
            min1 = min(min1, dp[0][i - j] + b[i] - b[i - j]);
        }
        dp[1][i] = min1;
        dp[0][i] = min0;
    }
    cout << min(dp[1][m], dp[0][m]);
}

