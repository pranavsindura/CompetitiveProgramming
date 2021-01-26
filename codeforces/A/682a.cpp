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
    int n, m;
    cin>>n>>m;
    //00, 14, 23, 32, 41
    ll countn[5], countm[5];
    for(ll i = 0; i < 5; i++)
    {
        ll b = floor((double(n-i) - double(i)) / 5.0) * 1LL;
        ll a = ceil((double(1-i) - double(i)) / 5.0) * 1LL;
        countn[i] = max(0LL, b - a + 1);
    }
    for(ll i = 0; i < 5; i++)
    {
        ll b = floor((double(m-i) - double(i)) / 5.0) * 1LL;
        ll a = ceil((double(1-i) - double(i)) / 5.0) * 1LL;
        countm[i] = max(0LL, b - a + 1);
    }
    ll ans = 0;
    ans += countn[0]*countm[0];
    ans += countn[1]*countm[4];
    ans += countn[2]*countm[3];
    ans += countn[3]*countm[2];
    ans += countn[4]*countm[1];
    cout<<ans;
    return 0;
}