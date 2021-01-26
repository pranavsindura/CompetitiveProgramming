#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1073741824

//Compiler version g++ 6.3.0
ll dp[1000005];

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    ll ans = 0;
    fill(dp, dp + 1000005, -1);
    for(int i = 1; i <= a; i++)
    {
        for(int j = 1; j <= b; j++)
        {
            for(int k = 1; k <= c; k++)
            {
                ll a = i * j * k * 1LL;
                if(dp[a] != -1)
                    ans += dp[a];
                else
                {
                    ll x = 0;
                    for(int d = 1; d <= sqrt(a); d++)
                    {
                        if(a % d == 0)
                        {
                            if(d == a / d)
                                x++;
                            else x += 2;
                        }
                    }
                    dp[a] = x;
                    ans += dp[a];
                }
                ans %= mod;
            }
        }
    }

    cout << ans;
    return 0;
}