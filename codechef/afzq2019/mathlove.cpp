#include<bits/stdc++.h>
using namespace std;
int dp[1000005];
int main()
{
    int i, j;
    dp[0] = 0;
    dp[1] = 0;
    for(i = 2; i < 1000005; i++)
    {
        int a, m = INT_MAX;
        if(i - 2 > 0)
        {
            a = dp[i - 2] + 1;
            m = min(a, m);
        }
        if(i - 3 > 0)
        {
            a = dp[i - 3] + 1;
            m = min(a, m);
        }
        if(i - 5 > 0)
        {
            a = dp[i - 5] + 1;
            m = min(a, m);
        }
        if(i % 2 == 0)
        {
            a = dp[i / 2] + 1;
            m = min(a, m);
        }
        if(i % 3 == 0)
        {
            a = dp[i / 3] + 1;
            m = min(a, m);
        }
        if(i % 5 == 0)
        {
            a = dp[i / 5] + 1;
            m = min(a, m);
        }
        dp[i] = m;
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
}