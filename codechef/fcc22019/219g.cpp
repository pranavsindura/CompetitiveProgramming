#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x, max = 0;
        vector<ll> arr;
        cin >> n;
        int dp[n][n];
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            arr.push_back(x);
            max += x;
        }
        if (n == 2)
        {
            cout<<max<<endl;
        }
        else
        {
            for(int i=0;i<n;i+=2)
            {
                for(int j=i;j<n;j+=2)
                {
                    
                }
            }
            cout << max << endl;
        }

        
    }
    return 0;
}