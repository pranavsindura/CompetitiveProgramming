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
ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}
int main()
{
    FASTIO;
    int n, k, x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    int ans;
    if (x == 1)
    {
        ans = n;
    }
    else
    {
        //nothing
        int c1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] - '0')
                c1++;
        }
        ans = c1;
    }
    cout << ans;
    return 0;
}