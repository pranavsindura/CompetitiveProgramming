#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

ll ncr[1001][1001]; 
  
long long int power(long long int x, long long int y)
{
    long long int res = 1;

    x = x % mod;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;

        y = y / 2;
        x = (x * x) % mod;
    }
    return res;
}

void init() 
{ 
    ncr[0][0] = 1; 
    for (int i = 1; i < 1001; i++) { 
        ncr[i][0] = 1; 
        for (int j = 1; j < i + 1; j++) { 
            ncr[i][j] = ((ncr[i - 1][j - 1])%mod + (ncr[i - 1][j])%mod)%mod; 
        } 
    } 
} 

int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin>>n>>k;
        ll s[k+1];
    }
    return 0;
}