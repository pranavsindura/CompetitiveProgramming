#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    ll x, ans = 0;
    cin >> x;
    while(x)
    {
    	ll a = 1;
        while(a * 2LL <= x)
            a *= 2LL;
        ans++;
        x -= a;
    }
    cout<<ans;
    return 0;
}